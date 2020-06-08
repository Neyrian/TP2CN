#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CRC-utils.h"

int main(int argc, char * argv[]) {
    if (argc != 3) {
        fprintf(stderr, "utilisation : %s <code> <polynome_générateur>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //Définition de C(x)
    mot C = init_mot();
    C->l = strlen(argv[1]);
    for (int i = 0; i < C->l; i++)
        C->code[i] = argv[1][i];

    //Définition de G(x)
    mot G = init_mot();
    while(argv[2][0] == '0') argv[2]++;
    G->l = strlen(argv[2]);
    for (int i = 0; i < G->l; i++)
        G->code[i] = argv[2][i];

    if (check_integrity(C) == -1) {
        fprintf(stderr, "<code : %s> n'est pas sous forme binaire\n", C->code);
        exit(EXIT_FAILURE);
    }

    if (check_integrity(G) == -1) {
        fprintf(stderr, "<p_g : %s> n'est pas sous forme binaire\n", G->code);
        exit(EXIT_FAILURE);
    }

    //Calcul du Reste R(x)
    mot R = reste_euclidien(C, G);

    printf("\n\tCode à analyser : \t %s\n", argv[1]);
    printf("\tCode générateur : \t %s\n", argv[2]);
    printf("\t-> Calcul du reste : \t %s\n", R->code);
    printf("\t-> Présence d'erreurs :\t %s\n\n", (is_zero(R) == 0) ? "Non" : "Oui");

    free(C);
    free(G);
    return EXIT_SUCCESS;
}