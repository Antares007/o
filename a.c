#define A(n, v) void n() v
A(name, { int i = 1; })
typedef void (*pith_t)(int, int, void *);
typedef void (*bark_t)(pith_t, int, void *);
void push(void *, void *);
void *pop(void *);

void f(pith_t o, int a, void *b) {
  o(0, a + 1, b); //
}
void g(pith_t o, int a, void *b) {
  o(0, a * 3, b); //
}
void pf(int m, int a, void *b) {
  pith_t o = pop(b);
  bark_t n = pop(b);
  if (m)
    o(m, a, b);
  else
    n(o, a, b);
}
void fg(pith_t o, int a, void *b) {
  push(b, g);
  push(b, o);
  f(pf, a, b); //
}
