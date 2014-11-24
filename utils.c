#include "utils.h"
#include <time.h>
#include <stdlib.h>

unsigned short checksum_md5(unsigned short *buffer, int length)
{
    unsigned long sum;
    for(sum=0; length>0; length--){
        sum += *buffer++;
        sum = (sum >> 16) + (sum & 0xffff);
        sum += (sum >> 16);
    }
    return (unsigned short)(~sum);
}


unsigned int generate_random_ip_v4(){
	char first_byte = (rand()%254)&0x7F;
	char scond_byte = (rand()%254)&0x7F;
	char third_byte = (rand()%254)&0x7F;
	char fourt_byte = (rand()%254)&0x7F;
	return ((((((((0x00000000|first_byte)<<8)|scond_byte)<<8)|third_byte)<<8)|fourt_byte)<<8);
}

unsigned short generate_random_valid_port(){
	return (rand()%65535)&0xFFFF;
}

