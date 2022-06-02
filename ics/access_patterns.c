// From:
// http://www.cs.cmu.edu/afs/cs/academic/class/15213-f17/www/lectures/01-overview.pdf
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
int** malloc2darr(int m, int n) {
    int** arr = (int**)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        *(arr + i) = malloc(n * sizeof(int));
    }
    return arr;
}
void free2darr(int** arr, int m) {
    for (int i = 0; i < m; i++) {
        if (*arr != NULL) {
            free(*(arr + i));
        }
    }
    free(arr);
}

int** init(int m, int n) {
    int i, j;
    int** arr = malloc2darr(m, n);
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            *(*(arr + i) + j) = i + j;
        }
    }
    return arr;
}
void copyij(int** src, int** dst, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            *(*(dst + i) + j) = *(*(src + i) + j);
        }
    }
}

void copyji(int** src, int** dst, int size) {
    int i, j;
    for (j = 0; j < size; j++) {
        for (i = 0; i < size; i++) {
            *(*(dst + i) + j) = *(*(src + i) + j);
        }
    }
}

int main(void) {
    // time_t rawtime;
    // struct tm* timeinfo;

    // time(&rawtime);
    struct timespec start, end;
    int size = 2048;

    int** dst = malloc2darr(size, size);
    // malloc2darr(src, i, i, sizeof(int));
    // malloc2darr(dst, i, i, sizeof(int));
    int** src = init(size, size);
    uint64_t delta_us1, delta_us2;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    copyij(src, dst, size);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    delta_us1 = (end.tv_nsec - start.tv_nsec) * 1e-6 +
                (end.tv_sec - start.tv_sec) * 1000;
    printf("copyij took %ld ms\n", delta_us1);

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    copyji(src, dst, size);
    clock_gettime(CLOCK_MONOTONIC_RAW, &end);
    delta_us2 = (end.tv_nsec - start.tv_nsec) * 1e-6 +
                (end.tv_sec - start.tv_sec) * 1000;
    printf("copyji took %ld ms\n", delta_us2);
    // for (int i = 0; i < size; i++) {
    //     for (int j = 0; j < size; j++) {
    //         if (j != 0 && j % 8 == 0) {
    //             printf("\n");
    //         }
    //         printf("%10d ", *(*(dst + i) + j));
    //     }
    //     printf("\n");
    // }
    free2darr(src, size);
    free2darr(dst, size);
    return 0;
}