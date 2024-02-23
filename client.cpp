
#include "client.hpp"
#include <arpa/inet.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


Client::Client()
{
    socketHandle = -1; 
    std::memset(&serverAddr, 0, sizeof(serverAddr)); 
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(portNumber); 
    int status = inet_pton(AF_INET,IP.c_str(),&serverAddr.sin_addr); 
    if(status != 1){
        std::cout << "failed to convert to network byte order" << std::endl;
        exit(1); 
    }
    std::memset(&header,0, sizeof(header)); 
    std::memset(&question,0,sizeof(header));

}

Client::~Client()
{
    close(socketHandle); 
    socketHandle = 0;
}
Query Client::CreateQuery(const std::string& hostname){
    header.ID = 0xFADE;     // Arbitrary value for ID
    header.QR = 1;       // Request, set to 0
    header.OPCODE = 1; // Standard, set to 0
    header.AA = 0;       //
    header.TC = 0; 
    header.RD = 1; 
    header.RA = 0;
    header.ZERO = 0; 
    header.RCODE = 0; 
    header.QDCOUNT = 1; 
    header.ANCOUNT = 0; 
    header.NSCOUNT = 0; 
    header.ARCOUNT = 0;
    std::strncpy(question.name,hostname.c_str(), sizeof(hostname)); 
    question.qType = 1; 
    question.qClass = 1; 
    struct Query* query = new struct Query(); 
    query->qHeader = header; 
    query->qQuestion = question;
    return *query; 
}

void Client::Send(){
    socketHandle = socket(AF_INET,SOCK_DGRAM,0); 
    if(socketHandle < 0){
        std::cout << "error creating socket" << std::endl; 
    }

}

