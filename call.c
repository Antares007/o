#include <stdio.h>
#define P(T, v)                                                                \
  *(T *)b = v;                                                                 \
  b += sizeof(T);
#define A(T, n)                                                                \
  T n = *(T *)b;                                                               \
  b += sizeof(T);
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
#define C(n, p, ...)                                                           \
  {                                                                            \
    void *start = s;                                                           \
    __VA_ARGS__;                                                               \
    (n)((p), start, e, b);                                                     \
    s = start;                                                                 \
  }
void *m();

void test(void (*o)(int, void *, void *), void *b, void *e) {
  P(long long, 11);
  o(0, b, e);
  P(int, 22);
  o(0, b, e);
  P(short, 33);
  o(0, b, e);
}
void tests(void (*o)(int, void *, void *,void*), void *b, void *e, void*r) {
  void *a;
  a = b;
  P(short, 0x36);
  P(long int, 0x63);
  P(int, 0x99);
  o(0, a, b, r);
  b = a;
  P(int, 0x99);
  P(long int, 0x63);
  P(short, 0x36);
  o(0, a, b, r);
  o(-1,0,0,r);
}
void run() {
  test(0, 0, 0);
}
