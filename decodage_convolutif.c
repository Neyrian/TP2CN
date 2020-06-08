#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "convolutif_utils.h"
#define NB_CHEMIN_MAX 64

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("Utilisation : codage_convolutif mot\n");
    exit(1);
  }

  mot word = init_mot();
  word->l = strlen(argv[1]);
  if (word->l > 16) {
    printf("La mémoire est bornée à t=8, donc le mot codé est taille maximum 16 (donc le mot décodé est de taille 8)\n");
    exit(1);
  }
  for (int i = 0; i < word->l; i++)
      word->code[i] = argv[1][i];

  //initilisation de la liste de chemin, au début tous partent de l'état initial.
  chemin l_chemin_t[4];
  chemin l_chemin_t_suivant[4];
  for (int i = 0; i < 4; i ++) {
    l_chemin_t[i] = NULL;
    l_chemin_t_suivant[i] = NULL;
  }
  l_chemin_t[0] = creer_chemin(0,NULL, 0);

  for (int d = 0; d < word->l; d += 2) {
    for (int n_chemin = 0; n_chemin < 4; n_chemin ++) {
      if (l_chemin_t[n_chemin] != NULL) {
        //transition 0
        chemin tmp_chemin = creer_chemin(l_chemin_t[n_chemin]->poids, l_chemin_t[n_chemin]->code, l_chemin_t[n_chemin]->length);
        tmp_chemin->code[tmp_chemin->length] = 0;
        tmp_chemin->length ++;
        if (tmp_chemin->act->sortie_0[0] != word->code[d])
          tmp_chemin->poids ++;
        if (tmp_chemin->act->sortie_0[1] != word->code[d-1])
          tmp_chemin->poids ++;
        tmp_chemin->act = tmp_chemin->act->trans_0;

        if (l_chemin_t_suivant[tmp_chemin->act->name - 1] == NULL) {
          l_chemin_t_suivant[tmp_chemin->act->name - 1] = tmp_chemin;
        } else {
          if (l_chemin_t_suivant[tmp_chemin->act->name - 1]->poids > tmp_chemin->poids) {
            l_chemin_t_suivant[tmp_chemin->act->name - 1] = tmp_chemin;
          }
        }

        //transition 1
        tmp_chemin = creer_chemin(l_chemin_t[n_chemin]->poids, l_chemin_t[n_chemin]->code, l_chemin_t[n_chemin]->length);
        tmp_chemin->code[tmp_chemin->length] = 1;
        tmp_chemin->length ++;
        if (tmp_chemin->act->sortie_1[0] != word->code[d])
          tmp_chemin->poids ++;
        if (tmp_chemin->act->sortie_1[1] != word->code[d-1])
          tmp_chemin->poids ++;
        tmp_chemin->act = tmp_chemin->act->trans_1;

        if (l_chemin_t_suivant[tmp_chemin->act->name - 1] == NULL) {
          l_chemin_t_suivant[tmp_chemin->act->name - 1] = tmp_chemin;
        } else {
          if (l_chemin_t_suivant[tmp_chemin->act->name - 1]->poids > tmp_chemin->poids) {
            l_chemin_t_suivant[tmp_chemin->act->name - 1] = tmp_chemin;
          }
        }
      }
    }

    for (int i = 0; i < 4; i ++) {
      l_chemin_t[i] = l_chemin_t_suivant[i];
      l_chemin_t_suivant[i] = NULL;
    }
  }

  int min = 0;
  for (int i = 0; i < 4; i ++) {
  //  if (l_chemin_t[i] <= l_ch)
  }
  return 0;
}
