PROG=code_hamming decode_hamming codage_convolutif
all: $(PROG)

OPTIONS_COMPIL  =-Wall -O2 -fPIC

code_hamming: code_hamming.o utils_hamming.o
	gcc -o $@ $^ -lm

code_hamming.o: code_hamming.c utils_hamming.h
	gcc $(OPTIONS_COMPIL) -c $<

decode_hamming: decode_hamming.o utils_hamming.o
	gcc -o $@ $^ -lm

decode_hamming.o: decode_hamming.c utils_hamming.h
	gcc $(OPTIONS_COMPIL) -c $<

utils_hamming.o: utils_hamming.c utils_hamming.h
	gcc $(OPTIONS_COMPIL) -c $<

clean:
	rm -f *.o $(PROG) *~
