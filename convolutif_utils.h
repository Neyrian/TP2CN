#include <stdlib.h>

#define MAX_WORD_SIZE 16

typedef struct mot_t {
    char code[MAX_WORD_SIZE]; //code binaire
    int l; //length;
} * mot;

typedef struct etat_t {
    struct etat_t *trans_0; //etat d'arrivé depuis cet état avec en entrée un 0
    struct etat_t *trans_1; //etat d'arrivé depuis cet état avec en entrée un 1
    char sortie_0[2]; //sortie de la transition de cet êtat avec en entrée un 0
    char sortie_1[2]; //sortie de la transition de cet êtat avec en entrée un 1
    int name;
} * etat;

//pour les chemin, on a juste a sauvegarder l'etat au bout du chemin, sont poid et la mot décodé
typedef struct chemin_t {
  etat act;
  int poids;
  char code[MAX_WORD_SIZE];
  int length;
} *chemin;



mot init_mot();

void grow_word(mot M, int length);

etat init_automate();

chemin creer_chemin(int poids, char *code, int length);
