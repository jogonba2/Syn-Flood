#include "ip-constructors.h"
#include "utils.c"
#include "macros.h"
#include "constants.h"

void set_sockaddr_in(struct sockaddr_in* myaddr,char* source_address,char* source_port){
	myaddr->sin_family = AF_INET;
	myaddr->sin_port   = string_htons(source_port);
	myaddr->sin_addr.s_addr  = string_addr(source_address);
	memset(myaddr->sin_zero,0,8);
}

int get_socket_descriptor_raw_tcp(){
	int fd = socket(PF_INET,SOCK_RAW,IPPROTO_TCP);
	if(fd==-1) fprintf(stderr,"Error creating TCP socket.");
	return fd;
}

int get_socket_descriptor_raw_udp(){
	int fd = socket(PF_INET,SOCK_RAW,IPPROTO_UDP);
	if(fd==-1) fprintf(stderr,"Error creating UDP socket.");
	return fd;
}

void set_ip_header(IP_HEADER* ip_hdr,char version,unsigned char ihl,unsigned char tos,unsigned short int total_length,
				  unsigned short identification,unsigned char zero_flag,unsigned char do_not_fragments,
				  unsigned char more_fragments,unsigned short int fragment_offset,unsigned char ttl,
				  unsigned char protocol,unsigned short int checksum,char* source_address,
				  char* remote_address,unsigned int optional){
	ip_hdr->version = version;
	ip_hdr->ihl     = ihl;
	ip_hdr->tos     = tos;
	if(protocol==IP_TCP_PROTOCOL) 		ip_hdr->total_length = sizeof(IP_HEADER)+sizeof(TCP_HEADER);
	else if(protocol==IP_UDP_PROTOCOL)  ip_hdr->total_length = sizeof(IP_HEADER)+sizeof(UDP_HEADER);
	else if(protocol==IP_ICMP_PROTOCOL) ip_hdr->total_length = sizeof(IP_HEADER)+sizeof(ICMP_HEADER);
	else    							ip_hdr->total_length = IP_DEFAULT_LENGTH;
	ip_hdr->identification = identification;
	ip_hdr->zero_flag = zero_flag;
	ip_hdr->do_not_fragments = do_not_fragments;
	ip_hdr->more_fragments   = more_fragments;
	ip_hdr->fragment_offset  = fragment_offset;
	ip_hdr->ttl              = ttl;
	ip_hdr->protocol         = protocol;
	ip_hdr->checksum         = checksum;
	ip_hdr->source_address   = string_addr(source_address);
	ip_hdr->remote_address   = string_addr(remote_address);
	ip_hdr->optional = optional;
}


void set_tcp_header(TCP_HEADER* tcp_hdr,char* source_port,char* remote_port,unsigned int num_sequence,
					unsigned int ack_number,unsigned char offset,unsigned char reserved,unsigned char flag_fin,
					unsigned char flag_syn,unsigned char flag_rst,unsigned char flag_push,unsigned char flag_ack,
					unsigned char flag_urg,unsigned char flag_echo,unsigned char flag_reduced,unsigned short int window,
					unsigned short int urg_pointer,unsigned int tcp_options,char* buffer){
	tcp_hdr->source_port  = string_htons(source_port);
	tcp_hdr->remote_port  = string_htons(remote_port);
	tcp_hdr->num_sequence = num_sequence;
	tcp_hdr->ack_number   = ack_number;
	tcp_hdr->offset       = offset;
	tcp_hdr->reserved     = reserved;
	tcp_hdr->flag_reduced = flag_reduced;
	tcp_hdr->flag_echo    = flag_echo;
	tcp_hdr->flag_urg     = flag_urg;
	tcp_hdr->flag_ack     = flag_ack;
	tcp_hdr->flag_push    = flag_push;
	tcp_hdr->flag_rst     = flag_rst;
	tcp_hdr->flag_syn     = flag_syn;
	tcp_hdr->flag_fin     = flag_fin;
	tcp_hdr->window       = window;
	tcp_hdr->checksum     = checksum_md5((unsigned short*) buffer,(sizeof(IP_HEADER) + sizeof(TCP_HEADER)));
	tcp_hdr->urg_pointer  = urg_pointer;	
}

int kernel_not_fill_my_header(int socket){
    int val = 1;
    const int *pval = &val;
    return setsockopt(socket,IPPROTO_IP,IP_HDRINCL,pval,sizeof(val));
}
