#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "CRC-utils.h"

int main(int argc, char * argv[]) {
    if (argc != 3 || argv[1][0] == '0' || argv[2][0] == '0') {
        fprintf(stderr, "utilisation : %s <mot> <polynome_générateur>\n\t\
-> les paramètres doivent commencer par un '1'.\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    //Définition de D(x)
    mot D = init_mot();
    D->l = strlen(argv[1]);
    for (int i = 0; i < D->l; i++)
        D->code[i] = argv[1][i];

    //Définition de G(x)
    mot G = init_mot();
    G->l = strlen(argv[2]);
    for (int i = 0; i < G->l; i++)
        G->code[i] = argv[2][i];

    //Définition de C(x) à partir de D(x)
    mot C = D;
    int original_size = D->l;
    grow_word(C, max_degree(G));

    //Calcul du Reste R(x)
    mot R = division_euclidienne(C, G);

    //Mise à jour de C avec R
    for(int i = 0; i < max_degree(G); i++) {
        C->code[i + original_size] = R->code[i];
    }

    printf("\n\tMot à transmettre : \t %s\n", argv[1]);
    printf("\tCode générateur : \t %s\n", argv[2]);
    printf("\t-> Calcul du reste : \t %s\n", R->code);
    printf("\t-> Message codé : \t %s\n\n", C->code);

    free(C); //C & D ont le même pointeur
    free(R);
    free(G);
    return EXIT_SUCCESS;
}