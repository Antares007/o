#include "a.h"

#include <stdio.h>
#include <stdlib.h>

N(hello) {}

typedef struct s_t {
  float m[4][4];
} s_t;
#define Case(...)
#define s32x1(a) P(int, 's32') P(int, 1) P(int, a)

#define fx1(a) P(int, 'f') P(int, 1) P(float, a)
#define fx2(a, b) P(int, 'f') P(int, 2) P2(float, a, b)
#define fx4(a, b, c, d) P(int, 'f') P(int, 4) P4(float, a, b, c, d)
#define fx8(a, b, c, d, e, f, g, h)                                            \
  P(int, 'f') P(int, 8) P8(float, a, b, c, d, e, f, g, h)
#define fx16(a1, b1, c1, d1, e1, f1, g1, h1, a2, b2, c2, d2, e2, f2, g2, h2)   \
  P(int, 'f')                                                                  \
  P(int, 16)                                                                   \
  P16(float, a1, b1, c1, d1, e1, f1, g1, h1, a2, b2, c2, d2, e2, f2, g2, h2)

enum mgl { mgl_drawPixel, mgl_drawLine, mgl_setColor, mgl_present, mgl_length };

#define R(...)                                                              \
  C(o,0,__VA_ARGS__)

N(nar1) {
  o(-1, s, e, b);
  R(s32x1(mgl_drawLine) fx2(0, 0) fx2(1, 1));
  R(s32x1(mgl_drawLine) fx4(1, 1, 1, 0));
  R(s32x1(mgl_drawLine) fx4(1, 0, 0, 0));
}

int main() {
  void *m = calloc(1024, 1);
  void *s = m;
  void *e = s + 1024;
  free(m);
  return 0;
}
