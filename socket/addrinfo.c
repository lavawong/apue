#include "apue.h"
#include <sys/socket.h>
#include <netdb.h>

int
main(void)
{
    char *host;
    char *service;
    struct addrinfo hint;
    struct addrinfo *res, *aip;
    const char      *addr;
    int             err;
    char            abuf[INET_ADDRSTRLEN];

    hint.ai_flags = AI_CANONNAME;
    hint.ai_family = 0;
    hint.ai_socktype = 0;
    hint.ai_protocol = 0;
    hint.ai_addrlen = 0;
    hint.ai_canonname = NULL;
    hint.ai_addr = NULL;
    hint.ai_next = NULL;

    if (getaddrinfo(host, service, &hint, &res) != 0)
        err_quit("getaddrinfo() error!\n");

    for (aip=res; aip != NULL; aip = aip->ai_next) {
        
    }
    return 0;
}
