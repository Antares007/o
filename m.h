#pragma once
#include "a.h"
#include <stdlib.h>
static N(mnar) {
  void *m = malloc(4096 * 1024);
  if (m == 0)
    return o(-1, s, e, b);
  o(0, m, m + 4096 * 1024, b);
  free(m);
}
