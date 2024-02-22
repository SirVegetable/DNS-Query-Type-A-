#include <iostream>
#include <netdb.h>


class Client{

    public: 
        Client();
        ~Client(); 

    void Send();
    std::string RecieveResponse(); 

    private: 
        int socketHandle;
        std::vector<char> buffer; 
        struct addrinfo hints;
        struct addrinfo* srvInfo; 

}; 