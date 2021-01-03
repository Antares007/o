CC=clang -O3 -g -std=gnu99 `sdl2-config --cflags`

sE.out: sE.c
	${CC} $^ -o $@ `sdl2-config --libs` -lm -lSDL2_ttf
s.out: s.c
	${CC} $^ -o $@ `sdl2-config --libs` -lm -lSDL2_ttf

parse.out: parse.c g.o
	${CC} $^ -o $@ 

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
	${CC} $^ -o $@ 

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
