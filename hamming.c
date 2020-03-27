#include <stdlib.h>
#include <stdio.h>
#include "utils_hamming.h"
#include <math.h>

int main(int argc, char const *argv[]) {
  if (argc != 4) {
    printf("Utilisation : hamming N K mot\n");
    exit(1);
  }

  int N;
  if (sscanf(argv[1], "%d", &N) == 0) {
    printf("Erreur argument\n");
    exit(1);
  }
  int K;
  if (sscanf(argv[2], "%d", &K) == 0) {
    printf("Erreur argument\n");
    exit(1);
  }

  if (N + 1 != pow(2, N -K)) {
    printf("Argument N et K incorrects\n");
    exit(1);
  }
  printf("Matrice transposée H :\n");
  int *tH = generer_matrice_tH(N-K, N);
  afficher_matrice(tH, N-K, N);
  printf("Matrice G :\n");
  int *G = generer_matrice_G(N, K, tH);
  afficher_matrice(G, N, K);
  int *mot = lire_mot(argv[3], K);
  



  return 0;
}
