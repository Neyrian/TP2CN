#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int boolean;
#define true 1;
#define false 0;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Veuillez préciser le nombre de bits a fournir en sortie.\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    srand(time(NULL));

    float a[n];

    for (int i = 0; i < n; i++) {
        float r = (float)rand()/(float)RAND_MAX;
        a[i] = r;
    }

    printf("a[n] = ");
    for (int i = 0; i < n; i++) {
        printf("%1.2f ", a[i]);
    }

    printf("\nMot correspondant (sans erreur)    = ");
    for (int i = 0; i < n; i++) {
        char c = (a[i] > 0.5) ? '1' : '0';
        printf("%c", c);
    }

    printf("\nMot correspondant (avec erreur(s)) = ");
    for (int i = 0; i < n; i++) {
        boolean error = (a[i] > 0.45 && a[i] < 0.55);
        char c = (a[i] > 0.5) ? '1' : '0';
        c = (error) ? ((c == '1') ? '0' : '1') : c;
        printf("%c", c);
    }

    printf("\n");
    exit(EXIT_SUCCESS);
}
