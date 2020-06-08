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

  printf("Matrice G :\n");
  int *G = generer_matrice_G(N, K);
  afficher_matrice(G, N, K);
  int *mot = lire_mot(argv[3], K);


  // calcul

  int mot_code[N];

  for (int i = 0; i < N; i ++) {
    mot_code[i] = 0;
    for (int j = 0; j < K; j ++) {
      mot_code[i] = ou_exclusif(mot_code[i], mot[j] * G[i + j * N]);
    }
  }
  printf("Le mot a codé est ");
  for (int i = 0; i < K; i ++) {
    printf("%d ", mot[i]);
  }
  printf("\nLe mot codé est ");
  for (int i = 0; i < N; i ++) {
    printf("%d ", mot_code[i]);
  }
  printf("\n");



  return 0;
}
