#include <stdio.h>
#include <ctype.h>

int mat[3][3] = { {1,2,3},{4,5,6},{7,8,9} };  
char player1;
char player2;
void mostrar() {
   for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            if (mat[j][k] == 'X' || mat[j][k] == 'O') {
                printf(" %c ", mat[j][k]); 
            } else {
                printf(" %d ", mat[j][k]); 
            }
            if (k < 2) printf("|");
        }
        printf("\n");
        if (j < 2) {
            printf("---|---|---\n");
        }
    }
}

void escolha(char player){
int escolha;
int j = 0;
int k = 0;
printf("Digite sua jogada:\n");
scanf("%d", &escolha);

for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            if (mat[j][k] == escolha) { 
                mat[j][k] = player; 
            }
   
    }

}
}
int verificar_fim(char player) {
    // Verificar linhas
    for (int i = 0; i < 3; i++) {
        if (mat[i][0] == player && mat[i][1] == player && mat[i][2] == player) {
            return 1; 
        }
    }

    // Verificar colunas
    for (int i = 0; i < 3; i++) {
        if (mat[0][i] == player && mat[1][i] == player && mat[2][i] == player) {
            return 1; 
        }
    }

    // Verificar diagonais
    if ((mat[0][0] == player && mat[1][1] == player && mat[2][2] == player) || 
        (mat[0][2] == player && mat[1][1] == player && mat[2][0] == player)) {
        return 1; 
    }

    // Verificar empate (todas as posições preenchidas)
    int preenchidas = 1;
    for (int j = 0; j < 3; j++) {
        for (int k = 0; k < 3; k++) {
            if (mat[j][k] != 'X' && mat[j][k] != 'O') {
                preenchidas = 0; // Ainda há posições livres
            }
        }
    }

    if (preenchidas) {
        return 2; // Empate
    }

    return 0; // Jogo ainda não terminou
}


int main() {
 printf("Bem-vindo ao Jogo da Velha\n");

    printf("Player 1, você deseja ser X ou O? ");
    scanf("%c", &player1); 
    player1 = toupper(player1);

    if (player1 == 'O') {
        player2 = 'X';
    } else {
        player2 = 'O';
    }
    printf("Player 1: %c\nPlayer 2: %c\n\n", player1, player2);

    while (1) {
        mostrar();

        // Jogada do Player 1
        printf("Player 1\n");
        escolha(player1);
        if (verificar_fim(player1) == 1) {
            mostrar();
            printf("Parabéns! Player 1 (%c) venceu!\n", player1);
            printf("          ___________\n");
            printf("         '._==_==_=_.\n");
            printf("         .-\\:      /-.\n");
            printf("        | (|:.     |) |\n");
            printf("         '-|:.     |-'\n");
            printf("           \\::.    /\n");
            printf("            '::. .'\n");
            printf("              ) (\n");
            printf("            _.' '._\n");
            printf("           `\"\"\"\"\"\"\"`\n");
            break;
        } else if (verificar_fim(player1) == 2) {
            mostrar();
            printf("Empate!\n");
            break;
        }

        mostrar();

        // Jogada do Player 2
        printf("Player 2\n");
        escolha(player2);
        if (verificar_fim(player2) == 1) {
            mostrar();
            printf("Parabens! Player 2 (%c) venceu!\n", player2);
            printf("          ___________\n");
            printf("         '._==_==_=_.\n");
            printf("         .-\\:      /-.\n");
            printf("        | (|:.     |) |\n");
            printf("         '-|:.     |-'\n");
            printf("           \\::.    /\n");
            printf("            '::. .'\n");
            printf("              ) (\n");
            printf("            _.' '._\n");
            printf("           `\"\"\"\"\"\"\"`\n");
            break;
        } else if (verificar_fim(player2) == 2) {
            mostrar();
            printf("Empate!\n");
            break;
        }
    }

    return 0;
}
