#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void initb(int *b, int k) {
  for (int i = 0; i < k; i ++) {
    b[i] = 0;
  }
}

void dualbase(int *b, int x) {
  for (int i = 0; x > 0; i ++) {
    b[i] = x%2;
    x = x /2;
  }
}
/*
  Fonction qui vérifie qu'un mot binaire de longueur k est une puissance de 2
*/
int ispuissanceofdeux(int *b, int k) {
  int res = 0;
  for (int i = 0; i < k; i ++) {
    res += b[i];
  }
  return res;
}
/*
  Génère la matrice G de taile N * K suivant ce modèle:
  G = |I A|
  Avec I la matrice identité de taille K * K
  A la matrice des mots binaires de taille K non null (les K première ligne de tH)
*/
int *generer_matrice_G(int n, int k, int *tH) {
  int *g = (int *) malloc(sizeof(int) * n * k);
  for (int i = 0; i < k; i ++) {
    for (int j = 0; j < n; j ++) {
      if (j < k) {
        if (j == i) {
          g[i * n + j] = 1;
        } else {
          g[i * n + j] = 0;
        }
      } else {
        g[i * n + j] = tH[i * (n-k) + (j - k)];
      }
    }
  }
  return g;
}

/*
Génère la matrice transposée de H de taille (N - K) * K suivant ce modèle :
    | A |
H = | I |
Avec I la matrice identité de taille n*n
A la matrice des mots binaires de taille K non null
Ici, les argumetns passés sont n = N - K et k = K
*/
int *generer_matrice_tH(int n, int k) {
  int *th = (int *) malloc(sizeof(int) * n * k);
  int ligne_act = 0;
  int b[n];
  /*
  On remplie d'abord la sous matrice K
  */
  for (int i = 1; i <= k; i++) {
    initb(b, n);
    dualbase(b, i);
    if (ispuissanceofdeux(b, n) != 1) {
      for (int j = 0; j < n; j ++) {
        th[ligne_act * n + j] = b[j];
      }
      ligne_act ++;
    }
  }
  /*
  On complète tH avec la matrice I
  */
  for (int i = 1; i <= k; i *= 2) {
    initb(b, n);
    dualbase(b, i);
    for (int j =0; j < n; j ++) {
      th[ligne_act * n + j] = b[j];
    }
    ligne_act ++;
  }
  return th;
}

/*
Affiche une matrice de taille n*k
*/
void afficher_matrice(int * M, int n, int k) {
  for (int i = 0; i < k; i ++) {
    for (int j = 0; j < n; j ++) {
      printf("%d ", M[i * n + j]);
    }
    printf("\n");
  }
}

int *lire_mot(const char *arg, int k) {
  int* mot = (int *)malloc(sizeof(int) * k);
  if (mot == NULL) {
    printf("Erreur dans l'allocation du mot\n");
    exit(1);
  }

  for (int i = 0; i < k; i ++) {
    mot[i] = arg[i];
  }
  return mot;
}
