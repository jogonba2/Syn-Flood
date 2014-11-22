#include <stdio.h>
#include <string.h>

extern void set_sockaddr_in(struct sockaddr_in* myaddr){
	myaddr->sin_family = AF_INET;
	myaddr->sin_port   = ntohl(atoi("1337"));
	myaddr->sin_addr.s_addr  = inet_addr("127.0.0.1");
	memset(myaddr->sin_zero,0,8);
	fprintf(stdout,"%d,,%d",atoi("1337"),ntohl(atoi("1337")));
}

extern int get_socket_descriptor(){
	int fd = socket(PF_INET,SOCK_RAW,IPPROTO_TCP);
	if(fd==-1){
		fprintf(stderr,"Error creating socket.");
	}
	return fd;
}
extern void set_ip_header(IP_HEADER* ip_hdr);
extern void set_tcp_header_syn_flow(TCP_HEADER* ip_hdr);
