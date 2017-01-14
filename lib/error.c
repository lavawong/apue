#include "apue.h"
#include <errno.h>
#include <stdarg.h>

static void err_doit(int, int, const char *, va_list);

void err_sys(const char *fmt, ...)
{
    va_list a_list;

    va_start(a_list, fmt);
    err_doit(1, errno, fmt, a_list);
    va_end(a_list);
    exit(1);
}

void err_quit(const char *fmt, ...)
{
    va_list a_list;

    va_start(a_list, fmt);
    err_doit(0, 0, fmt, a_list);
    va_end(a_list);
    exit(1);
}

static void err_doit(
                int errnoflag,
                int error,
                const char *fmt,
                va_list a_list
            )
{
    char buf[MAXLINE];
    vsnprintf(buf, MAXLINE, fmt, a_list);

    if (errnoflag)
    {
        size_t buf_len = strlen(buf);
        snprintf(buf+buf_len, MAXLINE-strlen(buf), ": %s", strerror(error));
    }

    strcat(buf, "\n");
    fflush(stdout);
    fputs(buf, stderr);
    fflush(NULL);
}

