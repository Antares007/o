CC=clang -O3 -std=gnu99

main.out: main.c b.o c.o utils.o
	${CC} $^ -o $@ 

run.bark: run bark.bin
	./run bark.bin 
run.pith: run bark.bin pith.bin b2.bin b1.bin
	cat pith.bin b2.bin b1.bin bark.bin > a.bin
	./run a.bin 

b.o: b.A m.A

gui.out: gui.c
	${CC} $< -o $@ -lX11 -lGL

%.out: %.o
	ld $< -o $@

%.fbin: %.o
	objcopy -O binary $< $@

%.bin: %.A
	nasm -f bin $< -o $@

%.o: %.A
	nasm -f elf64 $< -o $@
%.o: %.c
	${CC} -c $< -o $@

clean:
	git clean -Xf
	rm -f main mmap gui

%.ndisasm: %.fbin
	ndisasm -b64 $<

%.dump: %.o
	objdump -d -Mintel $<
