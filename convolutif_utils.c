#include "convolutif_utils.h"

mot init_mot() {
    mot M = (mot) malloc(sizeof(struct mot_t));
    M->l = 0;
    return M;
}

void grow_word(mot M, int length) {
    for (int i = 0; i < length; i++) {
        M->code[i + M->l] = '0';
    }
    M->l += length; //grow length
}
