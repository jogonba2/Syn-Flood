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
	unsigned short int total_length;
	unsigned short int identification;
	unsigned char zero_flag:1;
	unsigned char do_not_fragments:1;
	unsigned char more_fragments:1;
	unsigned short int fragment_offset:13;
	unsigned char ttl;
	unsigned char protocol;
	unsigned short int checksum;
	unsigned int source_address:32;
	unsigned int remote_address:32;
	unsigned int optional:32;
}IP_HEADER,*P_IP_HEADER;

typedef struct tcp_header{
	unsigned short int source_port;
	unsigned short int remote_port;
	unsigned int num_sequence:32;
	unsigned int ack_number:32;
	unsigned char offset:4;
	unsigned char reserved:4;
	// cambiar el orden en que se definen los flags //
	unsigned char flag_fin:1;
	unsigned char flag_syn:1;
	unsigned char flag_rst:1;
	unsigned char flag_push:1;
	unsigned char flag_ack:1;
	unsigned char flag_urg:1;
	unsigned char flag_echo:1;
	unsigned char flag_reduced:1;
	unsigned short int window;
	unsigned short int checksum;
	unsigned short int urg_pointer;
	unsigned int tcp_options;
}TCP_HEADER,*P_TCP_HEADER;

typedef struct icmp_header{
	unsigned char type:4;
	unsigned char code:4;
    unsigned short checksum;
    unsigned int specific_information:32;
}ICMP_HEADER,*P_ICMP_HEADER;

// Añadir más headers //


