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
        void Send();
        std::string RecieveResponse();
        void DNSParseResponse(char* msg_recieved,int* ans_length); 
        

    private:
        const int portNumber = 53; 
        int socketHandle;
        std::string hostName; 
        std::vector<char> buffer; 
        struct addrinfo hints;
        struct addrinfo* srvInfo;
        struct addrinfo* ptr;
        Header header; 
        Question question;
        ResRecord RR;
        
};

#endif 