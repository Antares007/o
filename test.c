#include <stdint.h>
#include <stdio.h>
int main() {
  uint64_t v = 'ABC';
  printf("%s\n", (const char *)&v);
  return 9;
}
