#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#define handle_error(msg)                                                      \
  do {                                                                         \
    perror(msg);                                                               \
    exit(EXIT_FAILURE);                                                        \
  } while (0)

void *mapfile(const char *filename, size_t *size) {
  int fd = open(filename, O_RDONLY);
  struct stat sb;
  if (fd == -1)
    handle_error("open");
  if (fstat(fd, &sb) == -1)
    handle_error("fstat");
  if (size)
    *size = sb.st_size;
  void *addr = mmap(NULL, sb.st_size, PROT_READ | PROT_WRITE | PROT_EXEC,
                    MAP_PRIVATE, fd, 0);
  close(fd);
  return addr;
}

typedef void (*pith_t)(uint64_t, void *, void *);
typedef void (*bark_t)(pith_t);

int main(int argc, char *argv[]) {
  bark_t bark;
  pith_t pith;
  size_t length;
  bark = mapfile("bark.bin", &length);
  pith = mapfile("pith.bin", &length);
  printf("%p(%p)\n", bark, pith);
  bark(pith);
  printf("done!\n");
  return 0;
}
