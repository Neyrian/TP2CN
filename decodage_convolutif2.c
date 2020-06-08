#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "convolutif_utils2.h"
#define NB_CHEMIN_MAX 64

int main(int argc, char const *argv[]) {
  if (argc < 2) {
    printf("Utilisation : codage_convolutif2 f1 f2 f3 f4 f5 ...\n");
    exit(1);
  }

  mot word = init_mot();
  word->l = argc - 1;
  if (word->l > 16) {
    printf("La mémoire est bornée à t=8, donc le mot codé est taille maximum 16 (donc le mot décodé est de taille 8)\n");
    exit(1);
  }

  for (int i = 0; i < word->l; i++)
    sscanf(argv[i + 1], "%f", &(word->code[i]));
  //initilisation de la liste de chemin, au début tous partent de l'état initial.
  chemin l_chemin_t[4];
  chemin l_chemin_t_suivant[4];
  for (int i = 0; i < 4; i ++) {
    l_chemin_t[i].poids = -1;
    l_chemin_t_suivant[i].poids = -1;
  }
  etat e = init_automate();
  creer_chemin(l_chemin_t, 0,NULL, 0, e);
  for (int d = 0; d < word->l; d += 2) {
    for (int n_chemin = 0; n_chemin < 4; n_chemin ++) {
      if (l_chemin_t[n_chemin].poids != -1) {
        //transition 0
        chemin tmp_chemin;
        creer_chemin(&tmp_chemin, l_chemin_t[n_chemin].poids, l_chemin_t[n_chemin].code, l_chemin_t[n_chemin].length, l_chemin_t[n_chemin].act);
        tmp_chemin.code[tmp_chemin.length] = 0;
        tmp_chemin.length ++;
        tmp_chemin.poids += (word->code[d]);
        tmp_chemin.poids += (word->code[d+1]);
        tmp_chemin.act = tmp_chemin.act->trans_0;

        if (l_chemin_t_suivant[tmp_chemin.act->name].poids == -1) {
          l_chemin_t_suivant[tmp_chemin.act->name] = tmp_chemin;
        } else {
          if (l_chemin_t_suivant[tmp_chemin.act->name].poids >= tmp_chemin.poids) {
            l_chemin_t_suivant[tmp_chemin.act->name] = tmp_chemin;
          }
        }

        //transition 1
        creer_chemin(&tmp_chemin, l_chemin_t[n_chemin].poids, l_chemin_t[n_chemin].code, l_chemin_t[n_chemin].length, l_chemin_t[n_chemin].act);
        tmp_chemin.code[tmp_chemin.length] = 1;
        tmp_chemin.length ++;
        tmp_chemin.poids += (1-word->code[d]);
        tmp_chemin.poids += (1-word->code[d+1]);
        tmp_chemin.act = tmp_chemin.act->trans_1;

        if (l_chemin_t_suivant[tmp_chemin.act->name].poids == -1) {
          l_chemin_t_suivant[tmp_chemin.act->name] = tmp_chemin;
        } else {
          if (l_chemin_t_suivant[tmp_chemin.act->name].poids > tmp_chemin.poids) {
            creer_chemin(&l_chemin_t_suivant[tmp_chemin.act->name], tmp_chemin.poids, tmp_chemin.code, tmp_chemin.length, tmp_chemin.act);
          }
        }
      }
    }

    for (int i = 0; i < 4; i ++) {
      creer_chemin(&(l_chemin_t[i]), l_chemin_t_suivant[i].poids, l_chemin_t_suivant[i].code, l_chemin_t_suivant[i].length, l_chemin_t_suivant[i].act);
      l_chemin_t_suivant[i].poids = -1;
    }
  }

  int min = -1;
  for (int i = 0; i < 4; i ++) {
    if (l_chemin_t[i].poids != -1) {
      if (min == -1){
        min = i;
      } else if (l_chemin_t[i].poids < l_chemin_t[min].poids) {
        min = i;
      }
    }
  }
  printf("Le message décodé est : ");
  for (int i = 0; i < l_chemin_t[min].length; i ++) {
    printf("%d", l_chemin_t[min].code[i]);
  }
  if (l_chemin_t[min].poids >= 3) {
    printf(". Attention, il y a 3 ou + erreurs.\n");
  } else {
    printf(". Il y a %f erreurs.\n", l_chemin_t[min].poids);
  }
  return 0;
}
