#include <stdio.h>

int main() {
    int mat[3][3] = { {0} };  

    char linhas[3] = {'A', 'B', 'C'};
    int colunas[3] = {1,2,3};
    
    
    printf("  ");
    for (int i = 0; i < 3; i++) {
        printf(" %d  ", colunas[i]);
    
    }   
    printf("\n");
    for (int j = 0; j < 3; j++) {
        
        printf("%c ", linhas[j]);

        for (int k = 0; k < 3; k++) {
            
            printf("|%d| ", mat[j][k]);
          
            }
        printf("\n");
            
        }

    return 0;
}
