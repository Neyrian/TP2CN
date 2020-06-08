#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "convolutif_utils.h"


int main(int argc, char const *argv[]) {
  if (argc != 2) {
    printf("Utilisation : codage_convolutif mot\n");
    exit(1);
  }

  mot word = init_mot();
  word->l = strlen(argv[1]);
  for (int i = 0; i < word->l; i++)
      word->code[i] = argv[1][i];

  etat etat_act = init_automate();

  printf("Le mot à coder est : %s. Son code est : ", word->code);
  for (int i = 0; i < word->l; i++) {
    if (word->code[i] == '0') {
      printf("%c%c", etat_act->sortie_0[0], etat_act->sortie_0[1]);
      etat_act = etat_act->trans_0;
    } else if (word->code[i] == '1') {
      printf("%c%c", etat_act->sortie_1[0], etat_act->sortie_1[1]);
      etat_act = etat_act->trans_1;
    }
  }
  printf("\n");
  return 0;
}
