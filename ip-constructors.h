#include <stdio.h>
#include <string.h>	
int  get_socket_descriptor();
int  kernel_not_fill_my_header_syn_flood(int);
void set_sockaddr_in(struct sockaddr_in*,char*,char*);
void set_ip_header(IP_HEADER*,char*,char*);
void set_tcp_header_syn_flood(TCP_HEADER*,char*,char*,char*);
void set_eth_frame_mac_spoofing();
void set_icmp_header_icmp_flood();
void set_udp_header_udp_flood();
void set_tcp_header_rst_attack();
void set_tcp_header_xmas_scan();
