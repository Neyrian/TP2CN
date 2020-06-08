#include <stdlib.h>

#define MAX_WORD_SIZE 256

typedef struct mot_t {
    char code[MAX_WORD_SIZE]; //code binaire
    int l; //length;
} * mot;

mot init_mot();

void grow_word(mot M, int length);
