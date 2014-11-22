#include "ip-headers.h"
#include "ip-constructors.c"

int main(int argc,char* argv[]){
    if(argc==0){
		// Añadir configuración //}
	}
	int sock = get_socket_descriptor();
	int optval = 1;
	char buffer[PCKT_LEN]; memset(buffer,0,PCKT_LEN);
	struct sockaddr_in myaddr;
	fprintf(stdout,"filling sockaddr_in ...\n");
	set_sockaddr_in(&myaddr);
	fprintf(stdout,"filled sockaddr_in ! \n");
	IP_HEADER *ip_hdr   = (IP_HEADER *)buffer;
	TCP_HEADER *tcp_hdr = (TCP_HEADER *) (buffer + sizeof(IP_HEADER));
	fprintf(stdout,"filling IP_HEADER ...\n");
	
	 
	return 0;
}




