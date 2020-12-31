#include "wyhash.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define C(h, t)                                                                \
  (void *[]) { (void *)h, (void *)t }
#define B(a, o, b) ((pith_t)(a))((o), 0, 0, (b))

typedef void (*pith_t)(void *, void *, void *, void *[2]);

void ps(uint64_t v, uint8_t *buff) {
  for (int i = 0; i < sizeof(v); i++)
    buff[i] = *((uint8_t *)(&v) + i);
}
void pith(void *m, void *h, void *t, void *v[2]) {
  uint64_t mol = (uint64_t)m;
  if ('C' == mol) {
    B((t && ((wyhash64() & 1) || (int64_t)v[1] < 0)) ? t : h, pith, v);
  } else if ('A' == mol) {
    B(h, pith, C(C(t, v[0]), (int64_t)v[1] - 1));
  } else if ('T' == mol) {
    uint8_t buf[9];
    ps((uint64_t)h, buf);
    printf("%s", buf);
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
extern void expression(void *, void *, void *, void *[2]);
extern void declaration(void *, void *, void *, void *[2]);
extern void identifier(void *, void *, void *, void *[2]);
extern void constant(void *, void *, void *, void *[2]);
extern void decimal_constant(void *, void *, void *, void *[2]);
extern void decimal_floating_constant(void *, void *, void *, void *[2]);
extern void direct_declarator(void *, void *, void *, void *[2]);
extern void additive_expression(void *, void *, void *, void *[2]);
extern void S(void *, void *, void *, void *[2]);
#define MSTACK 4096
#define V(a) ((void *)(a))
#define P(a) ((pith_t)(a))
// void push(void *stack, void *value, void* o){
//  ((pith_t)o)('ERROR',0,0,0);
//}

void makeStack(void *o, void *b, void *a, void *d) {
  uint64_t *stack = malloc(MSTACK * 8);
  if (!stack)
    return P(o)(V('L'), 0, 0, d);
  P(o)(V('R'), stack, 0, d);
  free(stack);
}
void stackpith(void *a, void *b, void *c, void *d) {
  printf("%s\n", (char *)&a);
  //
}
int main() {
  makeStack(stackpith, 0, 0, 0);
  // uint64_t *stack = calloc(MSTACK, 8);
  // printf("%p\n", stack);
  // if (!stack)
  //  printf("cant malloc mem\n");
  return 0;
  time_t seed = time(0);
  wyhash64_seed(seed);
  printf("wyhash64_seed(%lu)\n", seed);
  for (int i = 0; i < 12; i++) {
    printf("%d ", i);
    E(pith, 0, 0, C(0, 39));
    // printf("%d ", i);
    // S(pith, 0, 0, C(0, 99999));
  }
  return 9;
}
