#include<stdint.h>
typedef void (*b_t)(void (*o)(int, void *, void *, void *));
void (*o)(int, void *, void *, void *);
void tail(void (*o)(int, void *, void *, void *)) {
  // o(0, f, t1);
}
void *is[] = {
    'abc',
    0,
    'bcd',
    0,
};
void *ib = is;
void *ie = is + 2 * 2 * sizeof(void *);

void pith(int m, void *b, void *e, void *r) {
  if (m != 0)
    return o(m, b, e, r);
  if (*(uint64_t *)ib == (uint64_t)b) {
    ib += sizeof(void *);
    *(uint64_t *)ib = (uint64_t)e;
    ib += sizeof(void *);
  }
  if (ib < ie) {
    if (r) ((b_t)r)(pith);
    else o(-1, b, e, r);
  }
}

void m() {

  tail(pith);
  if (ib < ie)
    return o(-1, 8, 7, 5);
  o(0, 'name', 3, 4);
}
