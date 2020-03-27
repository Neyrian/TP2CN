PROG=hamming
all: $(PROG)

OPTIONS_COMPIL  =-Wall -O2 -fPIC

hamming: hamming.o utils_hamming.o
	gcc -o $@ $^ -lm

hamming.o: hamming.c utils_hamming.h
	gcc $(OPTIONS_COMPIL) -c $<

utils_hamming.o: utils_hamming.c utils_hamming.h
	gcc $(OPTIONS_COMPIL) -c $<

clean:
	rm -f *.o $(PROG) *~
