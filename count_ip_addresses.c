#include <inttypes.h>
#include <inttypes.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

#define IP2UINT32(i1,i2,i3,i4)  i1<<24|i2<<16|i3<<8|i4
// Implement a function that receives two IPv4 addresses, and returns the number of addresses between them
// (including the first one, excluding the last one).

// All inputs will be valid IPv4 addresses in the form of strings. The last address will always be greater than the first one.

// Examples
// * With input "10.0.0.0", "10.0.0.50"  => return   50 
// * With input "10.0.0.0", "10.0.1.0"   => return  256 
// * With input "20.0.0.10", "20.0.1.0"  => return  246

uint32_t ips_between (const char *start, const char *end)
{
  uint32_t is[4], ie[4], s, e;

  sscanf(start, "%d.%d.%d.%d", &is[0], &is[1], &is[2], &is[3]);
  sscanf(end, "%d.%d.%d.%d", &ie[0], &ie[1], &ie[2], &ie[3]);

  s = IP2UINT32(is[0], is[1], is[2], is[3]);
  e = IP2UINT32(ie[0], ie[1], ie[2], ie[3]);
  
  return e - s;
}

int main(void)
{
    char start[] = "0.0.0.0";
    char end[] = "255.255.255.255";
    printf("%ld\n", ips_between(start, end));

    return 0;
}