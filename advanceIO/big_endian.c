//
// Created by LavaWong on 2022/3/14.
//
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    int i = 0x12345678;
    char *c = (char *) &i;

    if (c[0] == 0x12 && c[1] == 0x34 && c[2] == 0x56 && c[3] == 0x78) {
        printf("Big-Endian Mode\n");
    } else {
        printf("Little-Endian Mode\n");
    }
    setlocale(LC_ALL, "");
    wchar_t name[] = L"我的c1";
    wprintf(L"name: %S\n", name);
    wprintf(L"name[0] with %%lc: %lc\n", name[0]);
    char b = name[0];
    printf("name[0] with %%c: %c, code: %d\n", b, b);
    printf("sizeof: %lu\n", sizeof(*name));
    printf("wcslen: %lu\n", wcslen(name));

    return 0;
}