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
int *generer_matrice_G(int n, int k) {
  int *g = (int *) malloc(sizeof(int) * n * k);
  int m = 3;
  int b_size = n - k;
  int b[b_size];

  for (int i = 0; i < k; i ++) {
    for (int j = 0; j < k; j ++) {
      if (j == i) {
        g[i * n + j] = 1;
      } else {
        g[i * n + j] = 0;
      }
    }
    initb(b, b_size);
    dualbase(b, m);
    if (ispuissanceofdeux(b, b_size) == 1) {
      m ++;
      initb(b, b_size);
      dualbase(b, m);
    }
    for (int j = 0; j < b_size; j++) {
      g[i * n + j + k] = b[j];
    }
    m ++;
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
    if (arg[i] == 48) {
      mot[i] = 0;
    } else if (arg[i] == 49) {
      mot[i] = 1;
    } else {
      printf("Mot incorrect, doit etre dans {0,1}^k\n");
      exit(1);
    }

  }
  return mot;
}


int ou_exclusif(int a, int b) {
  if ((a == 1) && (b == 1)) {
    return 0;
  } else {
    return a + b;
  }
}
int neg(int a) {
  if (a == 1)
    return 0;
  return 1;
}


int correction(int *syndrome, int *tH, int N, int K) {
  int test;
  for (int i = 0; i < K; i ++) {
    test = 1;
    for (int j = 0; j < N; j ++) {
      if (syndrome[j] != tH[i * N + j]) {
        test = 0;
      }
    }
    if (test == 1) {
      return i;
    }
  }
  return -1;
}
