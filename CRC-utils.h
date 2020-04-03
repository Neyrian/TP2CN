#include <stdlib.h>

#define MAX_WORD_SIZE 64

typedef struct mot_t {
    char code[MAX_WORD_SIZE]; //code binaire
    int l; //length;
} * mot;

mot init_mot();

int max_degree(mot M);

void grow_word(mot M, int length);

mot division_euclidienne(mot divise, mot diviseur);