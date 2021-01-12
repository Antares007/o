#include <stdio.h>
#define P(T, v)                                                                \
  *(T *)b = v;                                                                 \
  b += sizeof(T);
#define A(T, n)                                                                \
  T n = *(T *)b;                                                               \
  b += sizeof(T);
#define N(n)                                                                   \
  void n(void (*o)(int, void *, void *, void *), void *b, void *e, void *r)
#define P2(t, a, b)                                                            \
  P(t, a)                                                                      \
  P(t, b)
#define P4(t, a, b, c, d)                                                      \
  P2(t, a, b)                                                                  \
  P2(t, c, d)
#define P8(t, a, b, c, d, e, f, g, h)                                          \
  P4(t, a, b, c, d)                                                            \
  P4(t, e, f, g, h)
#define P16(t, a1, b1, c1, d1, e1, f1, g1, h1, a2, b2, c2, d2, e2, f2, g2, h2) \
  P8(t, a1, b1, c1, d1, e1, f1, g1, h1)                                        \
  P8(t, a2, b2, c2, d2, e2, f2, g2, h2)
#define A2(t, a, b)                                                            \
  A(t, a)                                                                      \
  A(t, b)
#define A4(t, a, b, c, d)                                                      \
  A2(t, a, b)                                                                  \
  A2(t, c, d)
#define A8(t, a, b, c, d, e, f, g, h)                                          \
  A4(t, a, b, c, d)                                                            \
  A4(t, e, f, g, h)
#define A16(t, a1, b1, c1, d1, e1, f1, g1, h1, a2, b2, c2, d2, e2, f2, g2, h2) \
  A8(t, a1, b1, c1, d1, e1, f1, g1, h1)                                        \
  P8(t, a2, b2, c2, d2, e2, f2, g2, h2)
#define C(n, p, ...)                                                           \
  {                                                                            \
    void *start = s;                                                           \
    __VA_ARGS__;                                                               \
    (n)((p), start, e, b);                                                     \
    s = start;                                                                 \
  }

N(mul) {
  // Mb
  // Case(fx1, v1)
  // Case(dx4, v1, v2, v3, v4)
  // Defa()
  // Me
}
N(callee) {
  void *a = b;
  {
    b = a;
    A(int, t);
    A(int, s);
    if (t == 'f' && s == 1) {
      A(float, f);
      //
      return;
    }
  }
  {
    b = a;
    A(int, t);
    A(int, s);
    if (t == 'd' && s == 4) {
      A4(int, i1, i2, i3, i4);
      //
      return;
    }
  }
}

N(caller) {
  void *a = b;

  b = a;
  P(int, 'f');
  P(int, 1);
  P(float, 3.69);
  callee(o, a, b, r);

  b = a;
  P(int, 'd');
  P(int, 4);
  P4(int, 1, 2, 3, 4);
  callee(o, a, b, r);
}
