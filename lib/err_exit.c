#include "apue.h"

void err_exit(int err, const char *str, ...)
{
    printf("%d %s\n", err, str);
    exit(err);
}