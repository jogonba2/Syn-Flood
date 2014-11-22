#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>

#define PCKT_LEN 8192

typedef struct ip_header
{
    unsigned char version:4;
	unsigned char ihl:4;
	unsigned char tos;
	unsigned short total_length;
	unsigned short identification;
	unsigned char zero_flag:1;
	unsigned char do_not_fragments:1;
	unsigned char more_fragments:1;
	unsigned short fragment_offset:13;
	unsigned char ttl;
	unsigned char protocol;
	unsigned short checksum;
	unsigned int source_address:32;
	unsigned int remote_address:32;
}IP_HEADER,*P_IP_HEADER;

typedef struct tcp_header{
	unsigned short source_port;
	unsigned short remote_port;
	unsigned int num_sequence:32;
	unsigned int ack_number:32;
	unsigned char offset:4;
	unsigned char reserved:4;
	unsigned char flag_reduced:1;
	unsigned char flag_echo:1;
	unsigned char flag_urg:1;
	unsigned char flag_ack:1;
	unsigned char flag_push:1;
	unsigned char flag_rst:1;
	unsigned char flag_syn:1;
	unsigned char flag_fin:1;
	unsigned short window;
	unsigned short checksum;
	unsigned short urg_pointer;
}TCP_HEADER,*P_TCP_HEADER;

typedef struct icmp_header{
	unsigned char type:4;
	unsigned char code:4;
    unsigned short checksum;
    unsigned int specific_information:32;
}ICMP_HEADER,*P_ICMP_HEADER;

// Añadir más headers //


