CC=clang -O3 -std=c99

main.out: main.c b.o c.o utils.o
	${CC} $^ -o $@ 

b.o: b.A m.A

gui.out: gui.c
	${CC} $< -o $@ -lX11 -lGL

%.out: %.o
	ld $< -o $@

%.bin: %.o
	objcopy -O binary $< $@

%.o: %.A
	nasm -f elf64 $< -o $@
%.o: %.c
	${CC} -c $< -o $@

clean:
	rm -f *.out *.o *.bin
	rm -f main mmap gui
