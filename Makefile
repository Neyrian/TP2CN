PROG=code_hamming decode_hamming CRC-4 CRC-check codage_convolutif decodage_convolutif random_word decodage_convolutif2
SRC=source_code/
OBJ=objects/

all: $(PROG)



OPTIONS_COMPIL = -Werror -Wall -g

CRC-4 : $(OBJ)CRC-4.o $(OBJ)CRC-utils.o
	gcc -o $@ $^

CRC-check : $(OBJ)CRC-check.o $(OBJ)CRC-utils.o
	gcc -o $@ $^

$(OBJ)CRC-utils.o : $(SRC)CRC-utils.c $(SRC)CRC-utils.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

$(OBJ)CRC-4.o : $(SRC)CRC-4.c $(SRC)CRC-utils.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

$(OBJ)CRC-check.o : $(SRC)CRC-check.c $(SRC)CRC-utils.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

code_hamming: $(OBJ)code_hamming.o $(OBJ)utils_hamming.o
	gcc -o $@ $^ -lm

$(OBJ)code_hamming.o: $(SRC)code_hamming.c $(SRC)utils_hamming.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

decode_hamming: $(OBJ)decode_hamming.o $(OBJ)utils_hamming.o
	gcc -o $@ $^ -lm

$(OBJ)decode_hamming.o: $(SRC)decode_hamming.c $(SRC)utils_hamming.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

$(OBJ)utils_hamming.o: $(SRC)utils_hamming.c $(SRC)utils_hamming.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

$(OBJ)convolutif_utils.o: $(SRC)convolutif_utils.c $(SRC)convolutif_utils.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

$(OBJ)convolutif_utils2.o: $(SRC)convolutif_utils2.c $(SRC)convolutif_utils2.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

$(OBJ)codage_convolutif.o: $(SRC)codage_convolutif.c $(SRC)convolutif_utils.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

codage_convolutif: $(OBJ)codage_convolutif.o $(OBJ)convolutif_utils.o
	gcc -o $@ $^ -lm

$(OBJ)decodage_convolutif.o: $(SRC)decodage_convolutif.c $(SRC)convolutif_utils.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

decodage_convolutif: $(OBJ)decodage_convolutif.o $(OBJ)convolutif_utils.o
	gcc -o $@ $^ -lm

$(OBJ)decodage_convolutif2.o: $(SRC)decodage_convolutif2.c $(SRC)convolutif_utils2.h
	gcc $(OPTIONS_COMPIL) -c $< -o $@

decodage_convolutif2: $(OBJ)decodage_convolutif2.o $(OBJ)convolutif_utils2.o
	gcc -o $@ $^ -lm

random_word: $(SRC)random_word.c
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
	rm -f *.o $(PROG) $(OBJ)*.o
