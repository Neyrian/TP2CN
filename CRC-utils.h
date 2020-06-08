#include <stdlib.h>

#define MAX_WORD_SIZE 256

typedef struct mot_t {
    char code[MAX_WORD_SIZE]; //code binaire
    int l; //length;
} * mot;

mot init_mot();

int check_integrity(mot M);

int is_zero (mot M);

int max_degree(mot M);

void grow_word(mot M, int length);

mot reste_euclidien(mot divise, mot diviseur);