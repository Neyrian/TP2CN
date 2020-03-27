PROG=huffman
all: $(PROG)

OPTIONS_COMPIL  =-Wall -O2 -fPIC

huffman: huffman.o
	gcc -o $@ $^

huffman.o: huffman.c
	gcc $(OPTIONS_COMPIL) -c $<

clean:
	rm -f *.o $(PROG) *~
