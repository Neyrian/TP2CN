#include "CRC-utils.h"

mot init_mot() {
    mot M = (mot) malloc(sizeof(struct mot_t));
    M->l = 0;
    return M;
}

int check_integrity(mot M) {
    for(int i = 0; i < M->l; i++)
        if (M->code[i] != '0' && M->code[i] != '1') return -1;
    return 0;
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

mot reste_euclidien(mot divise, mot diviseur) {
    //bonne chance pour lire ce code...
    int op_l = diviseur->l;
    int total_l = divise->l;
    char code1[divise->l];
    char code2[op_l];
    char* res;
    int offset = 0;

    for(int i = 0; i < total_l; i++)
        code1[i] = divise->code[i];
    for(int i = 0; i < op_l; i++)
        code2[i] = diviseur->code[i];
    
    while(code1[offset] == '0') offset++;
    while (offset <= total_l - op_l) {
        res = xor(code1, offset, code2, op_l);
        for (int i = 0; i < op_l; i++) code1[i + offset] = res[i]; 
        if (offset < total_l - op_l) offset++;
        while(code1[offset] == '0') offset++;
        free(res);
    }

    mot R = init_mot();
    R->l = max_degree(diviseur);
    for (int i = 0; i < R->l; i++) R->code[i] = '0';
    for (int i = 0; i < R->l; i++) R->code[R->l - 1 - i] = code1[total_l - 1 - i];

    return R;
}