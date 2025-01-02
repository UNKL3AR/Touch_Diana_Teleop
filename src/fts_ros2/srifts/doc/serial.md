# 部分代码注释

Function: 从串口读取数据
读取6轴力传感器数据并解析（一个数据包有2+2+2+24+1=31个byte)
example: 55 00 1B D1 EB 41 A3 A4 3E CA D1 B4 3F 36 06 12 BE 6A 6F 83 3B 24 02 56 BB 00 EA 3C 37 8B AA 
帧头-1：0x55 
数量-2：0x00 0x1B(27-byte不含帧头和数量) 
数据包index-2: 0xD1 0xEB 
数据位-24：0x41 0xA3 0xA4 0x3E 0xCA 0xD1 0xB4 0x3F 0x36 0x06 0x12 0xBE 0x6A 0x6F 0x83 0x3B 0x24 0x02 0x56 0xBB 0x00 0xEA 0x3C 0x37 
sum校验(仅仅对数据位求和校验)-1： 0x8B
帧尾-1：0xAA 



```cpp
bool TurnOnSensor::Get_Sensor_Data(){
    short j = 0, Header_Pos = 0, Tail_Pos = 0;  //中间变量
    uint8_t Receive_Data_Pr[RECEIVE_DATA_SIZE] = {0};
    unsigned char byte[4] = {0};
    M8128_Serial.read(Receive_Data_Pr, sizeof(Receive_Data_Pr));   //读串口数据

    // step1: 找到帧头和尾
    for(j=0;j<31;j++){
        if(Receive_Data_Pr[j]==FRAME_HEADER)
            Header_Pos=j;
        else if(Receive_Data_Pr[j]==FRAME_TAIL)
            Tail_Pos=j;    
    }

    // step2: 根据不同情况写入数据帧原始数据
    // 情况1-帧头和尾的间隔30
    if(Tail_Pos==(Header_Pos+30)){
        //ROS_INFO("1----");
        memcpy(Receive_Data.rx, Receive_Data_Pr, sizeof(Receive_Data_Pr));
    }
    // 情况2-帧头和尾相邻
    else if(Header_Pos==(1+Tail_Pos)){
        //ROS_INFO("2----");
        for(j=0;j<31;j++)
          Receive_Data.rx[j]=Receive_Data_Pr[(j+Header_Pos)%31];
    }
    // 情况3-读出出错
    else {
        //ROS_INFO("3----");
        return false;
    }    

    // 取出数据帧原始数据的头和尾
    Receive_Data.Frame_Header = Receive_Data.rx[0]; //数据的第一位是帧头（固定值）
    Receive_Data.Frame_Tail = Receive_Data.rx[30];  //数据的最后一位是帧尾（数据校验位）

    // 判断数据可靠性
    
    if (Receive_Data.Frame_Header == FRAME_HEADER ){
        //判断帧头
        if (Receive_Data.Frame_Tail == FRAME_TAIL) {
            //判断帧尾 
            if (Receive_Data.rx[29] == Check_Sum()){
                //校验位检测

                // 数据无误可以保存
                M8128_data.frame_number =  Receive_Data.rx[3]*256 + Receive_Data.rx[4]; // frame number

                // 六轴数据
                byte[0] = Receive_Data.rx[5];
                byte[1] = Receive_Data.rx[6];
                byte[2] = Receive_Data.rx[7];
                byte[3] = Receive_Data.rx[8];
                Byte_to_Float(&(M8128_data.X_force), byte);

                byte[0] = Receive_Data.rx[9];
                byte[1] = Receive_Data.rx[10];
                byte[2] = Receive_Data.rx[11];
                byte[3] = Receive_Data.rx[12];
                Byte_to_Float(&(M8128_data.Y_force), byte);

                byte[0] = Receive_Data.rx[13];
                byte[1] = Receive_Data.rx[14];
                byte[2] = Receive_Data.rx[15];
                byte[3] = Receive_Data.rx[16];
                Byte_to_Float(&(M8128_data.Z_force), byte);

                byte[0] = Receive_Data.rx[17];
                byte[1] = Receive_Data.rx[18];
                byte[2] = Receive_Data.rx[19];
                byte[3] = Receive_Data.rx[20];
                Byte_to_Float(&(M8128_data.X_torque), byte);

                byte[0] = Receive_Data.rx[21];
                byte[1] = Receive_Data.rx[22];
                byte[2] = Receive_Data.rx[23];
                byte[3] = Receive_Data.rx[24];
                Byte_to_Float(&(M8128_data.Y_torque), byte);

                byte[0] = Receive_Data.rx[25];
                byte[1] = Receive_Data.rx[26];
                byte[2] = Receive_Data.rx[27];
                byte[3] = Receive_Data.rx[28];
                Byte_to_Float(&(M8128_data.Z_torque), byte);
                
                return true;
            }
        }
    } 
    return false;
}
```



# 官方文档

如需自己写代码，与 M8128 采集卡通信获取数据，请参考以下指令流程:
Step 1 ： 通 过 SMPF 指 令 设 置 期 望 数 据 上 传 的 频 率 ； 比 如 期 望 100Hz 采样,AT+SMPF=100\r\n
Step 2：通过指令 GOD 或 GSD 实现单点或连续上传实时数据。



## GSD 连续获取数据 IEEE 格式浮点数

### Description:

此命令用于连续获取采样数据，即从机连续上传数据，不间断。

### Command Syntax: 

AT+GSD

### 从机回应数据的格式如下：

| 数据帧头  | PackageLength | PackageNo | Data                  | CRC32/SUM   |
| --------- | ------------- | --------- | --------------------- | ----------- |
| 0xAA,0x55 | HB,HL         | 2Byte     | (ChNum\*N\*DNpCH)Byte | 4Byte/1Byte |

0xAA ,0x55：数据帧头。

PackageLength：16bit 整型变量，占用 2B，高字节在前，低字节在后。数据大小

表示为（HB*256+LB），使用 SUM 校验整个数据包长度等于 ChNum*N*DNpCH；

使用 CRC32 检验整个数据包长度等于ChNum*N*DNpCH；
ChNum：上传的通道数，默认是 6
N：上传数据的单位，默认是 4
DNpCH：上传通道数据的点数，默认是 1

PackageNo：数据包编号，该编号从 0 到 65535 顺序递增并循环，可用于检查是否丢包。

Data：通道 1 至 6 的数据，低位在前，高位在后。

CRC32/SUM：CRC32(或 SUM)只对 Data 部分进行校验，默认是使用 SUM 校验方式，可以通过 DCKMD 指令来修改校验方法；CRC32 的 C 语言源代码见随机光盘，调用函数 MyCRC_GetCRC32(uint8_t *pData,uint16_t Length)。


Example:
发送：AT+DCKMD=SUM\r\n
回应：ACK+DCKMD=SUM$OK\r\n
发送：AT+GOD\r\n
回应：AA 55 00 1B C4 C7 01 6A F4 C0 EF 7D 33 C0 49 62 C9 C0 A2 5C C6 BD A6
19 8F BD AF DA 69 3E 6E
解析：
AA 55：数据帧头；
00 1B：包长度 2+6*4*1+1=27 字节；
C4 C7：数据包编号 50375；
通道 1 工程单位：016AF4C0，单精度（C0F46A01）转换成浮动数等于-7.637940；
通道 2 工程单位：EF 7D 33 C0，单精度（C0337DEF）转换成浮动数等于-2.804561；
通道 3 工程单位：49 62 C9 C0，单精度（C0C96249）转换成浮动数等于-6.293248；
通道 4 工程单位：A2 5C C6 BD，单精度（BDC65CA2）转换成浮动数等于-0.096856；
通道 5 工程单位：A6 19 8F BD，单精度（BD8F19A6）转换成浮动数等于-0.069873；
通道 6 工程单位：AF DA 69 3E，单精度（3E69DAAF）转换成浮动数等于 0.228373
校验和结果 6E

