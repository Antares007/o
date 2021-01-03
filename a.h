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
  {                                                                            \
    T *p = (T *)s;                                                             \
    (*p) = v;                                                                  \
    s += sizeof *p;                                                            \
  }
#define A(T, n)                                                                \
  T n = *(T *)s;                                                               \
  s += sizeof n;
#define C(n, p, ...)                                                           \
  {                                                                            \
    void *start = s;                                                           \
    __VA_ARGS__;                                                               \
    (n)((p), start, e, b);                                                       \
    s = start;                                                                 \
  }
typedef void (*pith_t)(int, void *, void *, void *);
void pith(int m, void *s, void *e, void *b) { *((int *)b) += 1; }
