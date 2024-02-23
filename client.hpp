#ifndef CLIENT_HPP
#define CLIENT_HPP

#include "DNSmessage.hpp"
#include <iostream>
#include <netdb.h>
#include <string> 
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>


class Client{

    public: 
        Client();
        ~Client();
        struct Query CreateQuery(const std::string& hostname); 
        void Send();
        void Decompress(); 
        std::string RecieveResponse();
        void DNSParseResponse(char* msg_recieved,int* ans_length); 
        

    private:
        const std::string IP = "192.168.50.1"; 
        const int portNumber = 53;
        int socketHandle;
        std::string hostName; 
        char* buffer;
        char* DnsRequest;
        unsigned DnsRequestSize; 
        unsigned int bufferSize;
        struct Header header;
        struct Question question; 
        struct sockaddr_in serverAddr;
        
};

#endif 