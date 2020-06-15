#include <stdint.h>
#include <stdio.h>
#include <string.h>

extern void bark(void (*o)(uint64_t n, void *, void *));
int (*plus)(int, int);

#define N(n)                                                                   \
  ((const char[]){(n >> 0 * 8) & 0xff, (n >> 1 * 8) & 0xff,                    \
                  (n >> 2 * 8) & 0xff, (n >> 3 * 8) & 0xff,                    \
                  (n >> 4 * 8) & 0xff, (n >> 6 * 8) & 0xff,                    \
                  (n >> 6 * 8) & 0xff, (n >> 7 * 8) & 0xff, 0})

void pith(uint64_t n, void *f, void *t) { ///
  printf("%s %lx %p %x\n", N(n), n, f, *(uint8_t *)t);
  if (n == 'sulp')
    plus = f;
  ((void (*)(void *))t)(pith);
}

int main() {
  bark(pith);
  if (plus)
    printf("%d\n", plus(4, 5));
  return 0;
}
