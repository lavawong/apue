// From:
// http://www.cs.cmu.edu/afs/cs/academic/class/15213-f17/www/lectures/01-overview.pdf
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
void init(int src[2048][2048]) {
    int i, j;
    for (i = 0; i < 2048; i++) {
        for (j = 0; j < 2048; j++) {
            src[i][j] = i + j;
        }
    }
}
void copyij(int src[2048][2048], int dst[2048][2048]) {
    int i, j;
    for (i = 0; i < 2048; i++) {
        for (j = 0; j < 2048; j++) {
            dst[i][j] = src[i][j];
        }
    }
}

void copyji(int src[2048][2048], int dst[2048][2048]) {
    int i, j;
    for (j = 0; j < 2048; j++) {
        for (i = 0; i < 2048; i++) {
            dst[i][j] = src[i][j];
        }
    }
}

int main(void) {
    // time_t rawtime;
    // struct tm* timeinfo;

    // time(&rawtime);
    struct timespec start, end;
    int i = 2048;

    int(*src)[i][i] = malloc(sizeof(*src));
    int(*dst)[i][i] = malloc(sizeof(*dst));
    init(*src);
    uint64_t delta_us1, delta_us2;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    copyij(*src, *dst);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    delta_us1 = (end.tv_nsec - start.tv_nsec) * 1e-6 +
                (end.tv_sec - start.tv_sec) * 1000;
    printf("copyij took %lu ms\n", delta_us1);

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    copyji(*src, *dst);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    delta_us2 = (end.tv_nsec - start.tv_nsec) * 1e-6 +
                (end.tv_sec - start.tv_sec) * 1000;
    printf("copyji took %lu ms\n", delta_us2);
    free(src);
    free(dst);
}