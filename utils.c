#include "utils.h"

unsigned short checksum(unsigned short *buffer, int length)
{
    unsigned long sum;
    for(sum=0; length>0; length--){
        sum += *buffer++;
        sum = (sum >> 16) + (sum & 0xffff);
        sum += (sum >> 16);
    }
    return (unsigned short)(~sum);
}
