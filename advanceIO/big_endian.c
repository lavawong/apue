//
// Created by LavaWong on 2022/3/14.
//
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <wchar.h>

int main(void) {
    int i = 0x12345678;
    char *c = (char *) &i;

    if (c[0] == 0x12 && c[1] == 0x34 && c[2] == 0x56 && c[3] == 0x78) {
        printf("Big-Endian Mode\n");
    } else {
        printf("Little-Endian Mode\n");
    }
    wchar_t *name = "我的";
    printf("%s\n", name);
    printf("%lu\n", sizeof(*name));
    printf("%lu\n", wcslen(name));

    return 0;
}