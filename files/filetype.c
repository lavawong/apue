#include "apue.h"

int main(int argc, char *argv[])
{
    int         i;
    struct stat buf;
    char        *prt;

    for (i = 1; i < argc; i++) {
        printf("%s: ", argv[i]);
        if (lstat(argv[i], &buf) < 0) {
            printf("lstat error\n");
            continue;
        }
        if (S_ISREG(buf.st_mode))
            prt = "regular";
        else if (S_ISDIR(buf.st_mode))
            prt = "directory";
        else if (S_ISCHR(buf.st_mode))
            prt = "character special";
        else if (S_ISBLK(buf.st_mode))
            prt = "block special";
        else if (S_ISFIFO(buf.st_mode))
            prt = "fifo";
        else if (S_ISLNK(buf.st_mode))
            prt = "symbolic link";
        else if (S_ISSOCK(buf.st_mode))
            prt = "socket";
        else
            prt = "** unknown mode **";
        printf("%s\n", prt);
    }
    return 0;
}

