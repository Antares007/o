CC=clang -O3 -std=gnu99

main.out: main.c b.o c.o utils.o
	${CC} $^ -o $@ 

mmap.out: mmap.c bark.bin pith.bin
	${CC} $< -o $@ 

b.o: b.A m.A

gui.out: gui.c
	${CC} $< -o $@ -lX11 -lGL

%.out: %.o
	ld $< -o $@

%.bin: %.o
	objcopy -O binary $< $@

%.fbin: %.A
	nasm -f bin $< -o $@

%.o: %.A
	nasm -f elf64 $< -o $@
%.o: %.c
	${CC} -c $< -o $@

clean:
	rm -f *.out *.o *.bin *.fbin
	rm -f main mmap gui

%.ndisasm: %.fbin
	ndisasm -b64 $<

%.dump: %.o
	objdump -d -Mintel $<
