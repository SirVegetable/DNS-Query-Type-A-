
#include "client.hpp"
#include <arpa/inet.h> 
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>


Client::Client()
{
    socketHandle = -1;
    query = nullptr; 
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
    delete query; 
}

unsigned char* Client::nameToDNS(std::string hostName){
    unsigned char* qname = new unsigned char[hostName.size()]; 
    int lock = 0;
    std::strcat((char*)hostName.c_str(), ".");
    for(int i = 0; i < std::strlen(hostName.c_str());i++){
        if(hostName[i]=='.'){
            *qname++ = i-lock; 
            for(; lock < i; lock++){
                *qname++=hostName[lock]; 
            }
            lock++;
        }
    }
    *qname++= '\0';
    return qname;
}
void Client::CreateQuery(){
    header.ID = htons(0xFADE);     // Arbitrary value for ID
    header.QR = htons(1);       // Request, set to 0
    header.OPCODE = htons(1); // Standard, set to 0
    header.AA = htons(0);       //
    header.TC = htons(0); 
    header.RD = htons(1); 
    header.RA = htons(0);
    header.ZERO = htons(0); 
    header.RCODE = htons(0); 
    header.QDCOUNT = htons(1); 
    header.ANCOUNT = htons(0); 
    header.NSCOUNT = htons(0); 
    header.ARCOUNT = htons(0);
    question.qType = htons(1); 
    question.qClass = htons(1);
    query = new Query(); 
    query->qHeader = header; 
    query->qQuestion = question;
}
void Client::serialize(){

    packetSize = sizeof(query->qHeader) + sizeof(hostName) +sizeof(query->qQuestion);
    DnsPacket = new unsigned char [packetSize];
    
    std::memcpy(DnsPacket,&query->qHeader,sizeof(query->qHeader));
    std::memcpy(); 

}
void Client::Send(){
    socketHandle = socket(AF_INET,SOCK_DGRAM,IPPROTO_UDP); 
    if(socketHandle < 0){
        std::cout << "error creating socket" << std::endl; 
    }


}



