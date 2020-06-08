PROG=code_hamming decode_hamming CRC-4 CRC-check codage_convolutif decodage_convolutif random_word decodage_convolutif2
all: $(PROG)

OPTIONS_COMPIL = -Werror -Wall -g

CRC-4 : CRC-4.o CRC-utils.o
	gcc -o $@ $^

CRC-check : CRC-check.o CRC-utils.o
	gcc -o $@ $^

CRC-utils.o : CRC-utils.c CRC-utils.h
	gcc $(OPTIONS_COMPIL) -c $<

CRC-4.o : CRC-4.c CRC-utils.h
	gcc $(OPTIONS_COMPIL) -c $<

CRC-check.o : CRC-check.c CRC-utils.h
	gcc $(OPTIONS_COMPIL) -c $<

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

convolutif_utils.o: convolutif_utils.c convolutif_utils.h
	gcc $(OPTIONS_COMPIL) -c $<

convolutif_utils2.o: convolutif_utils2.c convolutif_utils2.h
	gcc $(OPTIONS_COMPIL) -c $<

codage_convolutif.o: codage_convolutif.c convolutif_utils.h
	gcc $(OPTIONS_COMPIL) -c $<

codage_convolutif: codage_convolutif.o convolutif_utils.o
	gcc -o $@ $^ -lm

decodage_convolutif.o: decodage_convolutif.c convolutif_utils.h
	gcc $(OPTIONS_COMPIL) -c $<

decodage_convolutif: decodage_convolutif.o convolutif_utils.o
	gcc -o $@ $^ -lm

decodage_convolutif2.o: decodage_convolutif2.c convolutif_utils2.h
	gcc $(OPTIONS_COMPIL) -c $<

decodage_convolutif2: decodage_convolutif2.o convolutif_utils2.o
	gcc -o $@ $^ -lm

random_word: random_word.c
	gcc -o $@ $<

.PHONY: clean test

test: codage_convolutif decodage_convolutif
	./codage_convolutif 00101110
	./decodage_convolutif 0000111000011001
	./decodage_convolutif 0100111000011001
	./decodage_convolutif 1000111000011001
	./decodage_convolutif 0000011000011001
	./decodage_convolutif 0010101000011001
	./decodage_convolutif 0001011000111001
	./decodage_convolutif 1001011000111001

clean:
	rm -f *.o $(PROG) *~
