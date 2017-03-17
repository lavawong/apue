/**
 * test getnet function
 */
#include "apue.h"
#include <netdb.h>

int
main(void)
{
    struct netent   *ent;
    char            **network_aliase;

    printf("AF_INET: %d\n", AF_INET);

    ent = getnetent();
    network_aliase = ent->n_aliases;
    printf("n_name: %s\n", ent->n_name);
    printf("n_addrtype: %d\n", ent->n_addrtype);
    printf("n_net: %d\n", ent->n_net);
    while((*network_aliase) != NULL)
    {
        printf("network_aliases: %s\n", *network_aliase++);
    }
    exit(0);
}
