#include"TCP_sock.hpp"

TCPClient::TCPClient(){
    sock = -1;
    port = 0;
    address = "";
}

bool TCPClient::setup(std::string address , int port){
  	if(sock == -1){
		sock = socket(AF_INET , SOCK_STREAM , 0);
		if (sock == -1){
      			std::cout << "Could not create socket" << std::endl;
    		}
        }
  	if(inet_addr(address.c_str()) == -1){
    		struct hostent *he;
    		struct in_addr **addr_list;
    		if ( (he = gethostbyname( address.c_str() ) ) == NULL){
		      herror("gethostbyname");
      		      std::cout<<"Failed to resolve hostname\n";
		      return false;
    		}
	   	addr_list = (struct in_addr **) he->h_addr_list;
    		for(int i = 0; addr_list[i] != NULL; i++){
      		      server.sin_addr = *addr_list[i];
		      break;
    		}
  	}
  	else{
    		server.sin_addr.s_addr = inet_addr( address.c_str() );
  	}
  	server.sin_family = AF_INET;
  	server.sin_port = htons( port );
  	if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0){
    		perror("connect failed. Error");
    		return false;
  	}
  	return true;
}

bool TCPClient::Send(std::string data){
	if(sock != -1) {
		if( send(sock , data.c_str() , strlen( data.c_str() ) , 0) < 0){
			std::cout << "Send failed : " << data << std::endl;
			return false;
		}
	}
	else
		return false;
	return true;
}

std::string TCPClient::receive(int size){
  	char buffer[size];
	memset(&buffer[0], 0, sizeof(buffer));

  	std::string reply;
	if( recv(sock , buffer , size, 0) < 0){
	    	std::cout << "receive failed!" << std::endl;
		return nullptr;
  	}
	buffer[size-1]='\0';
  	reply = buffer;
  	return reply;
}

std::string TCPClient::read(){
  	char buffer[1] = {};
  	std::string reply;
  	while (buffer[0] != '\n') {
    		if( recv(sock , buffer , sizeof(buffer) , 0) < 0){
      			std::cout << "receive failed!" << std::endl;
			return nullptr;
    		}
		reply += buffer[0];
	}
	return reply;
}

bool TCPClient::readrecieveBuffer(Eigen::MatrixXd &pdBuffer){
    int PointCounter=-1;
    int dataNo=-1;

    unsigned char buffer[4096];
    memset(&buffer[0], 0, sizeof(buffer));
    //string reply;
    PointCounter=recv(sock,buffer, 4096, 0);
    if(PointCounter< 0){
        std::cout << "receive failed!" << std::endl;
        return false;
    }
    if(PointCounter<4096){
        if((buffer[PointCounter-19]==0xAA)&& buffer[PointCounter-18]==0x55){
            //cout << "ok:!"<< endl;
            int Index=6;
            for(unsigned int i = 0; i < 6; i++){
                pdBuffer(0,i)=buffer[PointCounter-19+Index]*256 + buffer[PointCounter-19+Index+1];
                Index=Index+2;
            }
        }
    }

    return true;
}

bool TCPClient::GetADCounts(Eigen::MatrixXd &pdBuffer){
    unsigned char buffer[4096];
    memset(&buffer[0], 0, sizeof(buffer));

    if( recv(sock , buffer , 4096, 0) < 0){
        std::cout << "receive failed!" << std::endl;
        return false;
    }
    if((buffer[0]==0xAA && buffer[1]==0x55)){
            int Index=6;
            for(unsigned int i = 0; i < 6; i++){
                pdBuffer(0,i)=buffer[Index]*256 + buffer[Index+1];
                Index=Index+2;
            }
        }
    return true;
}

bool TCPClient::GetChParameter(Eigen::MatrixXd &pdBuffer){
    unsigned char buffer[4096];
    char CharTemp[50] = {0x00};
    memset(&buffer[0], 0, sizeof(buffer));
    double dTemp=0.00;
    std::string aa;
    if( recv(sock , buffer , 4096, 0) < 0){
        std::cout << "receive failed!" << std::endl;
        return false;
    }
    if((buffer !=NULL)){
        unsigned int compare_step=0;
        for (unsigned int i = 0; i < 7; i++){
            unsigned int k=0;
            memset(&CharTemp[0], 0, sizeof(CharTemp));
            while (buffer[compare_step] != ';' && buffer[compare_step] != '\r'&& buffer[compare_step] != '$'&&buffer[compare_step] != '='){
                 memcpy(&CharTemp[k], &buffer[compare_step], 1*sizeof(char));
                 k++;
                 compare_step++;
                 if (k >= 50){
                     return false;
                 }
            }
            compare_step++;
            if(i>=1) {
                if (sscanf(CharTemp, "%lf", &dTemp) != 1) return false;
                pdBuffer(0, i - 1) = dTemp;
            }
        }
    }
    return true;
}

void TCPClient::exit(){
    close( sock );
}