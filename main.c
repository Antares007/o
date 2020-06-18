#include "utils.h"
#include <stdio.h>
#include <string.h>

extern void bark(void (*o)(uint64_t n, void *, void *));
extern void tc();
int (*plus)(int, int);


void pith(uint64_t n, void *f, void *t) {
  print0(n, f, t);
  if (n == 'sulp') {
    plus = f;
    return;
  }
  ((void (*)(void *))t)(pith);
}

int main() {
  tc();
  bark(pith);
  if (plus)
    printf("%d\n", plus(4, 5));
  return 0;
}
