#include <stdio.h>

int main() {
    int mat[3][3] = { {0} };  

    char letras[3] = {'A', 'B', 'C'};

    for (int j = 0; j < 3; j++) {
        printf("%c ", letras[j]);
        for (int k = 0; k < 3; k++) {
            printf("|%d| ", mat[j][k]);
            }
        printf("\n");
            
        }

    return 0;
}
