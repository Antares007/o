#define NN_(a, b) a##b
#define NN(a, b) NN_(a, b)
#define NNN(a, b, c) NN(NN(a, b), c)
#define NNNN(a, b, c, d) NN(NN(a, b), NN(c, d))
#define MB(ob) (((void **)(ob))[1])
#define MO(ob) (((void **)(ob))[0])
typedef void (*pith_t)(int, void *, void *, void *);
#define PS(g, f, ...)                                                          \
  void NNNN(g, o, f, _pith)(int m, void *s, void *e, void *ob) {               \
    pith_t o = MO(ob);                                                         \
    void *b = MB(ob);                                                          \
    if (m < 0)                                                                 \
      return o(m, s, e, b);
#define PE(g, f)                                                               \
  }                                                                            \
  void NNN(g, o, f)(pith_t o, void *s, void *e, void *b) {                     \
    f(NNNN(g, o, f, _pith), s, e, (void *[]){o, b});                           \
  }

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
void f(void (*o)(int, void *, void *, void *), void *s, void *e, void *b) {
  uint64_t stride = (uint64_t)s;
  size_t size = stride * ((uint64_t)e);
  void *m = malloc(size);
  if (m == 0)
    return o(-1, 0, 0, b);
  o(stride, m, m + size, b);
  free(m);
}
PS(g, f) 
  o(m, s, e, b); //
PE(g, f)
PS(g, gof) 
  o(m, s, e, b); //
PE(g, gof)
PS(a, gogof) 
  o(m, s, e, b); //
PE(a, gogof)

void pith(int m, void *s, void *e, void *b) {
  printf("pith: %d %p %p %p\n", m, s, e, b);
  printf("pith: %ld \n", (e - s));
}

int main() {
  aogogof(pith, (void *)4, (void *)2, (void *)9);
  return 0;
}
