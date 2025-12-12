#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Protótipos
void telaInicial();
void inicializarTabuleiro(char tab[3][3]);
void exibirTabuleiro(char tab[3][3]);
int verificarVitoria(char tab[3][3]);
int verificarEmpate(char tab[3][3]);
void limparBuffer();

int main() {
    char tabuleiro[3][3];
    int linha, coluna;
    char jogador = 'X';
    int jogoRodando = 1;
    char repetir;

    telaInicial();  // Exibe tela inicial

    do {
        inicializarTabuleiro(tabuleiro);
        jogador = 'X';
        jogoRodando = 1;

        while (jogoRodando) {
            system("clear || cls");

            printf("=========== JOGO DA VELHA ===========\n\n");
            exibirTabuleiro(tabuleiro);

            printf("Jogador atual: %c\n", jogador);
            printf("Informe a linha (1-3): ");
            scanf("%d", &linha);
            printf("Informe a coluna (1-3): ");
            scanf("%d", &coluna);

            linha--;  
            coluna--;

            if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
                printf("\nPosição inválida! Pressione ENTER.\n");
                limparBuffer();
                getchar();
                continue;
            }

            if (tabuleiro[linha][coluna] != ' ') {
                printf("\nPosição ocupada! Pressione ENTER.\n");
                limparBuffer();
                getchar();
                continue;
            }

            tabuleiro[linha][coluna] = jogador;

            if (verificarVitoria(tabuleiro)) {
                system("clear || cls");
                exibirTabuleiro(tabuleiro);
                printf("\n=====================================\n");
                printf("       JOGADOR %c FOI O VENCEDOR!    \n", jogador);
                printf("=====================================\n\n");
                jogoRodando = 0;
            } 
            else if (verificarEmpate(tabuleiro)) {
                system("clear || cls");
                exibirTabuleiro(tabuleiro);
                printf("\n=====================================\n");
                printf("              DEU VELHA!             \n");
                printf("=====================================\n\n");
                jogoRodando = 0;
            } 
            else {
                jogador = (jogador == 'X') ? 'O' : 'X';
            }
        }

        printf("Deseja jogar novamente? (S/N): ");
        limparBuffer();
        scanf("%c", &repetir);
        repetir = toupper(repetir);

    } while (repetir == 'S');

    printf("\nObrigado por jogar! Até a próxima.\n");

    return 0;
}

// Tela inicial
void telaInicial() {
    system("clear || cls");
    printf("=============================================\n");
    printf("         BEM-VINDO AO JOGO DA VELHA          \n");
    printf("=============================================\n\n");
    printf("Desenvolvido em C\n");
    printf("O jogo detecta vencedor ou se deu velha.\n\n");
    printf("Pressione ENTER para começar...\n");
    getchar();
}

// Preenche o tabuleiro com espaços
void inicializarTabuleiro(char tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tab[i][j] = ' ';
        }
    }
}

// Exibe o tabuleiro
void exibirTabuleiro(char tab[3][3]) {
    printf("     1   2   3\n");
    printf("   -------------\n");

    for (int i = 0; i < 3; i++) {
        printf(" %d |", i + 1);
        for (int j = 0; j < 3; j++) {
            printf(" %c |", tab[i][j]);
        }
        printf("\n   -------------\n");
    }
}

// Verifica vitória
int verificarVitoria(char tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (tab[i][0] == tab[i][1] &&
            tab[i][1] == tab[i][2] &&
            tab[i][0] != ' ')
            return 1;
    }

    for (int i = 0; i < 3; i++) {
        if (tab[0][i] == tab[1][i] &&
            tab[1][i] == tab[2][i] &&
            tab[0][i] != ' ')
            return 1;
    }

    if (tab[0][0] == tab[1][1] &&
        tab[1][1] == tab[2][2] &&
        tab[0][0] != ' ')
        return 1;

    if (tab[0][2] == tab[1][1] &&
        tab[1][1] == tab[2][0] &&
        tab[0][2] != ' ')
        return 1;

    return 0;
}

// Verifica empate
int verificarEmpate(char tab[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tab[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

// Limpa buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}