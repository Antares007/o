#include "a.h"
#include "m.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

PS(g, mnar) {
  printf("%d %p %p %p\n", m, s, e, b);
  printf("%ld\n", e - s);
}
PE(g, mnar)
int run(void (*nar)(pith_t, void *, void *, void *)) {
  int err = 0;
  nar(pith, 0, 0, &err);
  if (err)
    printf("error\n");
  return err;
}
int main() { return run(gomnar); }
