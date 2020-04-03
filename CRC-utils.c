#include "CRC-utils.h"

mot init_mot() {
    mot M = (mot) malloc(sizeof(struct mot_t));
    M->l = 0;
    return M;
}

int max_degree(mot M) {
    return M->l - 1;
}

void grow_word(mot M, int length) {
    for (int i = 0; i < length; i++) {
        M->code[i + M->l] = '0';
    }
    M->l += length; //grow length
}

char* xor (char code1[], int offset_1, char code2[], int len) {
    char* res = (char*) malloc(sizeof(char)*len);
    for(int i = 0; i < len; i++) {
        res[i] = (code1[i + offset_1] != code2[i]) ? '1' : '0';
    }
    return res;
}

mot division_euclidienne(mot divise, mot diviseur) {
    //TODO
    mot R = init_mot();

    //TODO.

    return R;
}