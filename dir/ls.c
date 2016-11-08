#include "apue.h"
#include <stdio.h>
#include <dirent.h>

int
main(int argc, char *argv[])
{
    DIR *dp;
    struct dirent   *dirp;

    if (argc != 2) {
        err_quit("Usage: ls <directory_name>");
        return 1;
    }

    if ((dp = opendir(argv[1])) == NULL) {
        err_sys("can't open %s\n", argv[1]);
        return 1;
    }

    while ((dirp = readdir(dp)) != NULL)
        printf("%s\n", dirp->d_name);
    printf("\n");
    closedir(dp);
    return 0;
}