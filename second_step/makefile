all: my_forth

my_forth: my_forth.o
	ld -o my_forth my_forth.o

rebuild: clean my_forth.o
	ld -o my_forth my_forth.o

my_forth.o: my_forth.asm
	nasm -f elf64 -g -F dwarf my_forth.asm -o my_forth.o

clean:
	rm -f *.o
	rm -f my_forth
