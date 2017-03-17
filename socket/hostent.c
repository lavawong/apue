/**
 * test gethostent function
 */
#include "apue.h"
#include <netdb.h>

int
main(void)
{
    struct hostent  *ent;
    char            **host_aliase;
    char            **host_addr;
    ent = gethostent();
    host_aliase=ent->h_aliases;
    host_addr=ent->h_addr_list;
    printf("h_name: %s\n", ent->h_name);
    printf("h_addrtype: %d\n", ent->h_addrtype);
    printf("h_length: %d\n", ent->h_length);
    while((*host_aliase) != NULL)
    {
        printf("h_aliases: %s\n", *host_aliase++);
    }
    while((*host_addr) != NULL)
    {
        printf("h_addr_list: %s\n", *host_addr++);
    }

    exit(0);
}
