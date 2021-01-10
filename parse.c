#include "wyhash.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define C(h, t)                                                                \
  (void *[]) { (void *)h, (void *)t }
#define B(a, o, b) ((pith_t)(a))((o), 0, 0, (b))

typedef void (*pith_t)(void *, void *, void *, void *[2]);

void pith(void *m, void *h, void *t, void *v[2]) {
  uint64_t mol = (uint64_t)m;
  if ('C' == mol) {
    B((t && ((wyhash64() & 1) || (int64_t)v[1] < 0)) ? t : h, pith, v);
  } else if ('A' == mol) {
    B(h, pith, C(C(t, v[0]), (int64_t)v[1] - 1));
  } else if ('T' == mol) {
    printf("%s", (char *)&h);
    B(t, pith, v);
  } else if ('G' == mol) {
    void **tail = v[0];
    if (v[0])
      B(tail[0], pith, C(tail[1], v[1]));
    else
      printf("\n");
  } else {
    printf("wtf!\n");
  }
}
extern void E(void *, void *, void *, void *[2]);
extern void S(void *, void *, void *, void *[2]);
extern void expression(void *, void *, void *, void *[2]);
extern void declaration(void *, void *, void *, void *[2]);
extern void identifier(void *, void *, void *, void *[2]);
extern void constant(void *, void *, void *, void *[2]);
extern void decimal_constant(void *, void *, void *, void *[2]);
extern void decimal_floating_constant(void *, void *, void *, void *[2]);
extern void direct_declarator(void *, void *, void *, void *[2]);
extern void additive_expression(void *, void *, void *, void *[2]);
int main() {
  time_t seed = time(0);
  wyhash64_seed(seed);
  printf("wyhash64_seed(%lu)\n", seed);
  for (int i = 0; i < 12; i++) {
    printf("%d ", i);
    E(pith, 0, 0, C(0, 99));
    // printf("%d ", i);
    // constant(pith, 0, 0, C(0, 999999));
  }
  return 0;
}
