main.out: main.c b.o
	clang $^ -o $@ 

b.o: m.A

gui.out: gui.c
	clang -O3 $< -o $@ -lX11 -lGL

%.out: %.o
	ld $< -o $@

%.bin: %.o
	objcopy -O binary $< $@

%.o: %.A
	nasm -f elf64 $< -o $@

clean:
	rm -f *.out *.o *.bin
	rm -f main mmap gui
