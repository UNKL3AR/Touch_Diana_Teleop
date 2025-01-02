#ifndef _TCP_SOCK_HPP_
#define _TCP_SOCK_HPP_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netdb.h> 
#include <vector>

#include <Eigen/Dense>

class TCPClient{
public:
    TCPClient();
    bool setup(std::string address, int port);
    bool Send(std::string data);
    std::string receive(int size = 4096);
    bool GetADCounts(Eigen::MatrixXd &pdBuffer);
    bool GetChParameter(Eigen::MatrixXd &pdBuffer);
    bool readrecieveBuffer(Eigen::MatrixXd &pdBuffer);
    std::string read();
    void exit();

private:
    int sock;
    std::string address;
    int port;
    struct sockaddr_in server;
};

#endif
