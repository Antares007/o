#pragma once
#define NN_(a, b) a##b
#define NN(a, b) NN_(a, b)
#define NNN(a, b, c) NN(NN(a, b), c)
#define NNNN(a, b, c, d) NN(NN(a, b), NN(c, d))
#define MB(ob) (((void **)(ob))[1])
#define MO(ob) (((pith_t *)(ob))[0])
#define L(n) NN(n, __LINE__)
#define N(n) void n(pith_t o, void *s, void *e, void *b)
#define PS(g, f, ...)                                                          \
  void NNNN(g, o, f, _pith)(int m, void *s, void *e, void *ob) {               \
    pith_t o = MO(ob);                                                         \
    void *b = MB(ob);                                                          \
    if (m != 0)                                                                \
      return o(m, s, e, b);
#define PE(g, f)                                                               \
  }                                                                            \
  void NNN(g, o, f)(pith_t o, void *s, void *e, void *b) {                     \
    f(NNNN(g, o, f, _pith), s, e, (void *[]){o, b});                           \
  }
#define P(T, v)                                                                \
  *(T *)s = v;                                                                 \
  s += sizeof(T);

#define A(T, n)                                                                \
  T n = *(T *)s;                                                               \
  s += sizeof(T);
#define SE(n, ...)                                                             \
  void *n[2];                                                                  \
  n[0] = s;                                                                    \
  __VA_ARGS__;                                                                 \
  n[1] = s;

#define C(n, p, ...)                                                           \
  {                                                                            \
    void *start = s;                                                           \
    __VA_ARGS__;                                                               \
    (n)((p), start, e, b);                                                     \
    s = start;                                                                 \
  }
typedef void (*pith_t)(int, void *, void *, void *);
#define A2(t, a, b)                                                            \
  A(t, a)                                                                     \
  A(t, b)
#define A4(t, a, b, c, d)                                                      \
  A2(t, a, b)                                                                 \
  A2(t, c, d)
#define A8(t, a, b, c, d, e, f, g, h)                                          \
  A4(t, a, b, c, d)                                                           \
  A4(t, e, f, g, h)
#define A16(t, a1, b1, c1, d1, e1, f1, g1, h1, a2, b2, c2, d2, e2, f2, g2, h2) \
  A8(t, a1, b1, c1, d1, e1, f1, g1, h1)                                       \
  A8(t, a2, b2, c2, d2, e2, f2, g2, h2)
#define P2(t, a, b)                                                            \
  P(t, a)                                                                     \
  P(t, b)
#define P4(t, a, b, c, d)                                                      \
  P2(t, a, b)                                                                 \
  P2(t, c, d)
#define P8(t, a, b, c, d, e, f, g, h)                                          \
  P4(t, a, b, c, d)                                                           \
  P4(t, e, f, g, h)
#define P16(t, a1, b1, c1, d1, e1, f1, g1, h1, a2, b2, c2, d2, e2, f2, g2, h2) \
  P8(t, a1, b1, c1, d1, e1, f1, g1, h1)                                       \
  P8(t, a2, b2, c2, d2, e2, f2, g2, h2)
