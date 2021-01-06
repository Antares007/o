#pragma once
#include "a.h"
#include <stdlib.h>
static N(mnar) {
  void *m = malloc(4096 * 100);
  if (m == 0)
    return o(-1, s, e, b);
  o(0, m, m + 4096 * 100, b);
  free(m);
}
