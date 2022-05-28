#include<stdio.h>
typedef struct {
  int a[2];
  double d;
} struct_t;

double fun(int i) {
  volatile struct_t s;
  s.d = 3.14;
  s.a[i] = 1073741824; /* Prossibly out of bounds*/
  return s.d;
}

int main(void) {
  fun(0);
  fun(1);
  fun(3);
  fun(4);
  // fun(6);
  return 0;
}