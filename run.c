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
    handle_error(filename);
  if (fstat(fd, &sb) == -1)
    handle_error("fstat");
  if (size)
    *size = sb.st_size;
  void *addr =
      mmap((void *)0x666666666000, sb.st_size,
           PROT_READ | PROT_WRITE | PROT_EXEC, MAP_PRIVATE | MAP_FIXED, fd, 0);
  close(fd);
  return addr;
}

typedef void (*pith_t)(uint64_t, void *, void *);
typedef void (*bark_t)(pith_t);
typedef void (*absurd)();

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("%s filenameToRun\n", argv[0]);
    return -1;
  }
  absurd a = mapfile(argv[1], NULL);
  a();
  return 0;
}
