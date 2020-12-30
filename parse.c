#include "wyhash.h"
#include <stdint.h>
#include <stdio.h>
#include <time.h>
#define C(h, t)                                                                \
  (void *[]) { (void *)h, (void *)t }
#define B(a, o, b) ((pith_t)(a))((o), 0, 0, (b))

typedef void (*pith_t)(void *, void *, void *, void *[2]);

extern void E(void *, void *, void *, void *[2]);

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
int main() {
  time_t seed = time(0);
  wyhash64_seed(seed);
  printf("wyhash64_seed(%lu)\n", seed);
  for (int i = 0; i < 36; i++) {
    printf("%d ", i);
    E(pith, 0, 0, C(0, 39));
  }
  return 9;
}
