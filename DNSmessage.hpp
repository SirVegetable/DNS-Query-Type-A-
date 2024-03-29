#ifndef DNSMESSAGE_HPP
#define DNSMESSAGE_HPP


/*
                    DNS Message: 
                +-------------------+
                |      Header       |
                +-------------------+
                |      Question     |
                +-------------------+
                |      Answer       |
                +-------------------+
                |      Authority    |
                +-------------------+
                |      Addtional    |
                +-------------------+
*/


/*
                    Header Format: 
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                      ID                       |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |QR|   Opcode  |AA|TC|RD|RA|   Z    |   RCODE   |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    QDCOUNT                    |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    ANCOUNT                    |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    NSCOUNT                    |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+
    |                    ARCOUNT                    |
    +--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+--+

struct bitfield to hold specify size of each part of the header section
*/
struct Header{
    unsigned short      ID;             // Identification, 2 bytes(16 bits)
    unsigned char       QR: 1;          // Query Response flag : 1 bit
    unsigned char       OPCODE: 4;      // Opcode: 4 bits
    unsigned char       AA: 1;          // Authoritative Answer Flag: 1 bit
    unsigned char       TC: 1;          // Truncate Flag: 1 bit 
    unsigned char       RD: 1;          // Recursion Desired: 1 bit
    unsigned char       RA: 1;          // Recursion Available: 1 bit
    unsigned char       ZERO: 3;        // Zero: 3 reserved bits 
    unsigned char       RCODE: 4;       // Response code: 3 bits 
    unsigned short      QDCOUNT;        // Question Count: 2 bits 
    unsigned short      ANCOUNT;        // Answer Count: 2 bits 
    unsigned short      NSCOUNT;        // Authoritative Record Count: 2 bits 
    unsigned short      ARCOUNT;        // Additonal Record Count: 2 bits 
};

/*
                    Question Format: 
            +-------------------------------+
            |             QNAME             |
            +-------------------------------+
            |             QTYPE             |
            +-------------------------------+
            |             QCLASS            |
            +-------------------------------+

*/

struct Question{
    unsigned short qType;      // Type of question(A, CNAME, NS, etc). 
    unsigned short qClass;     // Internet, CSNET, Chaosnet, etc 
};



struct Query{
    struct Header qHeader;
    struct Question qQuestion; 
}; 

#endif 