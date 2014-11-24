#define IP_VERSION_V4 4
#define IP_VERSION_V6 6
#define IP_DEFAULT_IHL 5
#define IP_DEFAULT_FRAGMENT_OFFSET 1
#define IP_DEFAULT_IDENTIFICATION 1
#define IP_DEFAULT_TTL 64
#define IP_TCP_PROTOCOL 6
#define IP_UDP_PROTOCOL 17
#define IP_ICMP_PROTOCOL 1
#define IP_DEFAULT_LENGTH 35
#define TCP_DEFAULT_OFFSET 5
#define TCP_DEFAULT_WINDOW 65535
#define TCP_DEFAULT_RESERVED 0
#define TCP_DEFAULT_URG_POINTER 0
#define TCP_DEFAULT_TCP_OPTIONS 0


// Precedence critical,low delay,high throughput and normal reliability
#define IP_CRITIC_TOS 0b1011101
// Precedence Routine,normal delay, normal throughput and normal reliability
#define IP_CURRENT_TOS 0x00
