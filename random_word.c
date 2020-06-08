#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Veuillez préciser le nombre de bits a fournir en sortie.\n");
        exit(1);
    }

    int n = atoi(argv[1]);
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        float r = (float)rand()/(float)RAND_MAX;
        char c = (r > 0.5) ? '1' : '0';
        printf("%c", c);
    }

    printf("\n");
    exit(EXIT_SUCCESS);
}