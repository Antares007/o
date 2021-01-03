#include "a.h"
#include <stdio.h>
N(test) {
  A(float, v);
  A(float, v2);
  printf("%f\n", v);
  printf("%f\n", v2);
  //
  C(o, 0, P(float, 2); P(float, 3); P(int, 5); P(const char *, "hello"))
  C(o, 0, P(float, 5); P(float, 2); P(int, 3); P(const char *, "hi"))
}
PS(g, test) {
  A(float, x);
  A(float, y);
  A(int, z);
  A(const char *, m);
  printf("%f %f %d %s\n", x, y, z, m);
  C(o, 0, P(int, z *z); P(const char *, "A"));
  C(o, 0, P(int, z *z); P(const char *, "B"));
  C(o, 0, P(int, z *z); P(const char *, "C"));
  C(o, 0, P(int, z *z); P(const char *, "D"));
}
PE(g, test)

PS(g, gotest) {
  A(int, z);
  A(const char *, m);
  printf("%d %s\n", z, m);
  // C(o,0,P(int,0));
}
PE(g, gotest)

#include <stdlib.h>
int main() {

  void *s = malloc(1024);
  void *e = s + 1024;
  int err = 0;
  void *b = &err;
  C(gogotest, pith, P(float, 10.9999); P(float, 20.9999);)
  if (err == 0)
    printf("ok\n");
  else
    printf("err\n");
  printf("free\n");
  free(s);
}
