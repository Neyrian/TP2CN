#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TAILLE_MOT 32

int main(int argc, char const *argv[]) {
  if (argc != 6) {
    printf("Utilisation : codage_convolutif N K M taille_mot mot\n");
    exit(1);
  }

  int N, K, M, length;
  if (sscanf(argv[1], "%d", &N) == 0) || (sscanf(argv[2], "%d", &K) == 0) || (sscanf(argv[3], "%d", &M) == 0) || (sscanf(argv[4], "%d", &length) == 0) {
    printf("Erreur argument\n");
    exit(1);
  }

  char *mot = (int)* malloc(sizeof(int) * length);
  for (int i = 0; i < length; i ++) {
    sscanf(argv[5][i], "%d",mot[i]);
  }
  return 0;
}
