#include <stdlib.h>
#include <stdio.h>
#include "utils_hamming.h"
#include <math.h>

int main(int argc, char const *argv[]) {
  if (argc != 4) {
    printf("Utilisation : decode_hhamming N K mot\n");
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

  printf("Matrice tH :\n");
  int *tH = generer_matrice_tH(N - K, N);
  afficher_matrice(tH, N - K, N);
  int *mot = lire_mot(argv[3], N);
  // calcul

  int syndrome[N - K];

  for (int i = 0; i < N - K; i ++) {
    syndrome[i] = 0;
    for (int j = 0; j < N; j ++) {
      syndrome[i] = ou_exclusif(syndrome[i], mot[j] * tH[i + j * (N - K)]);
    }
  }
  printf("Le syndrome est ");
  int test = 0;
  for (int i = 0; i < N - K; i ++) {
    printf("%d ", syndrome[i]);
    test += syndrome[i];
  }

  printf("\n");
  if (test != 0) {
   printf("Il y a une erreur dans le message lu\n");
   printf("Correction\n");
   int erreur = correction(syndrome, tH, N - K, N);
   mot[erreur] = neg(mot[erreur]);
 }
  printf("Le mot décodé est ");
  for (int i = 0; i < K; i ++) {
    printf("%d ", mot[i]);
  }
  printf("\n");



  return 0;
}
