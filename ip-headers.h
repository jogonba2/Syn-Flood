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

typedef struct udp_header{
	unsigned short source_port;
	unsigned short remote_port;
	unsigned short datgram_length;
	unsigned short checksum;
}UDP_HEADER,*P_UDP_HEADER;

typedef struct eth_frame{
	unsigned long remote_mac:48;
	unsigned long source_mac:48;
	unsigned short type;
	unsigned int frame_check_sequence;
}ETH_FRAME,*P_ETH_FRAME;

typedef struct dhcp_header{
	unsigned char opcode;
	unsigned char htype;
	unsigned char hlen;
	unsigned char hops;
	unsigned int transaction_id;
	unsigned short seconds;
	unsigned short flags;
	unsigned int client_addr;
	unsigned int assigned_addr;
	unsigned int boot_server_addr;
	unsigned int relay_agent_addr;
	unsigned long long int client_hw_addr;
	unsigned char[64] server_host_name;
	unsigned char[128] boot_filename;
}DHCP_HEADER,*P_ETH_FRAME;

/** DNS session layer (test) **/
typedef struct dns_header{
	unsigned short identification;
	unsigned char qr_flags:1;
	unsigned char opcode:4;
	unsigned char dns_flags:7;
	unsigned char rcode:4;
	unsigned short total_questions;
	unsigned short total_answers;
	unsigned short total_authority;
	unsigned short total_additional;
}DNS_HEADER,*P_DNS_HEADER;

// Añadir más headers //