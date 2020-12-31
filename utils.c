#include "utils.h"
#include <stdio.h>

#define N(n)                                                                   \
  ((const char[]){(n >> 0 * 8) & 0xff, (n >> 1 * 8) & 0xff,                    \
                  (n >> 2 * 8) & 0xff, (n >> 3 * 8) & 0xff,                    \
                  (n >> 4 * 8) & 0xff, (n >> 5 * 8) & 0xff,                    \
                  (n >> 6 * 8) & 0xff, (n >> 7 * 8) & 0xff, 0})

void print0(const uint64_t n, const void *f, const void *t) {
  printf("%s %lx %p %x\n", N(n), n, f, *(uint8_t *)t);
}

void putstr(uint64_t n) { printf("%s", N(n)); }

void putuiq(uint64_t i) { printf("%lu", i); }
void putuid(uint32_t i) { printf("%u", i); }

void putiq(int64_t i) { printf("%ld", i); }
void putid(int32_t i) { printf("%d", i); }
