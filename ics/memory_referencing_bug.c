// From:
// http://www.cs.cmu.edu/afs/cs/academic/class/15213-f17/www/lectures/01-overview.pdf
#include <stdio.h>
typedef struct {
    int a[2];
    double d;
} struct_t;

double fun(int i) {
    volatile struct_t s; // compiler not optimize with volatile
    s.d = 3.14;
    s.a[i] = 1073741824; /* Prossibly out of bounds*/
    return s.d;
}

int main(void) {
    double a0 = fun(0);
    double a1 = fun(1);
    // bugs flow
    double a2 = fun(2);
    double a3 = fun(3);
    double a4 = fun(4);
    printf("a0: %f, a1: %f, a2: %f, a3: %f, a4: %f\n", a0, a1, a2, a3, a4);

    // double a6 = fun(6);
    // printf("a6: %f\n", a6);
    return 0;
}