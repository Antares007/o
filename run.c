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
  int fd = open(filename, O_RDWR);
  struct stat sb;
  if (fd == -1)
    handle_error(filename);
  if (fstat(fd, &sb) == -1)
    handle_error("fstat");
  if (size)
    *size = sb.st_size;
  void *addr =
      mmap((void *)0x666666666000, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_SHARED | MAP_FIXED, fd, 0);

  close(fd);
  return addr;
}

typedef void (*pith_t)(uint64_t, void *, void *);
typedef void (*bark_t)(pith_t);
typedef void (*absurd)();

void pith(uint64_t n, void *h, void *t) {
  printf("hello %p %p\n", h, t);
  if (t)
    ((void (*)(pith_t))t)(pith);
  printf("end %p %p\n", h, t);
}
int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("%s filenameToRun\n", argv[0]);
    return -1;
  }
  size_t size;
  void *addr = mapfile(argv[1], &size);
  bark_t b = addr;
  ((uint8_t *)addr)[size - 1] = 0xc3;
  b(pith);
  printf("done\n");
  return 0;
}
