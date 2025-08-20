#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

// Nível Novato - Posicionamento dos Navios
// Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
// Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
// Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

// Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
// Sugestão: Expanda o tabuleiro para uma matriz 10x10.
// Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
// Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

// Nível Mestre - Habilidades Especiais com Matrizes
// Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
// Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
// Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

// Exemplos de exibição das habilidades:
// Exemplo para habilidade em cone:
// 0 0 1 0 0
// 0 1 1 1 0
// 1 1 1 1 1

// Exemplo para habilidade em octaedro:
// 0 0 1 0 0
// 0 1 1 1 0
// 0 0 1 0 0

// Exemplo para habilidade em cruz:
// 0 0 1 0 0
// 1 1 1 1 1
// 0 0 1 0 0


// Definições de tamanho do tabuleiro
#define TABULEIRO_LARGURA 10
#define TABULEIRO_ALTURA 10

void posicionarNavio(int tamanho, int x, int y, char orientacao, int simbolo, int tabuleiro[TABULEIRO_LARGURA][TABULEIRO_ALTURA]) {
    // Função para posicionar navios no tabuleiro
    // Implemente a lógica para posicionar navios verticalmente e horizontalmente

    //valida a posição do navio
    if(y < 0 || y >= TABULEIRO_ALTURA || x < 0 || x >= TABULEIRO_LARGURA) {
        printf("Posição inválida!\n");
        return;
    }

    switch (orientacao) {
        case 'H': // Horizontal
            //verifica se o navio cabe na horizontal
            if(x + tamanho > TABULEIRO_LARGURA) {
                printf("Navio não cabe na horizontal!\n");
                return;
            }
            //checa se a posição já está ocupada
            for (int i = 0; i < tamanho; i++) {
                if (tabuleiro[x + i][y] != 0) {
                    printf("Posição já ocupada!\n");
                    return;
                }
            }
            // Marca a posição do navio
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[x + i][y] = simbolo;
            }
            break;

        case 'V': // Vertical
            //verifica se o navio cabe na vertical
            if(y + tamanho > TABULEIRO_ALTURA) {
                printf("Navio não cabe na vertical!\n");
                return;
            }
            //checa se a posição já está ocupada
            for (int i = 0; i < tamanho; i++) {
                if (tabuleiro[x][y + i] != 0) {
                    printf("Posição já ocupada!\n");
                    return;
                }
            }
            // Marca a posição do navio
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[x][y + i] = simbolo;
            }
            break;

        case 'D': // Diagonal Direita
            //verifica se o navio cabe na diagonal direita
            if(x + tamanho > TABULEIRO_LARGURA || y + tamanho > TABULEIRO_ALTURA) {
                printf("Navio não cabe na diagonal direita!\n");
                return;
            }
            //checa se a posição já está ocupada
            for (int i = 0; i < tamanho; i++) {
                if (tabuleiro[x + i][y + i] != 0) {
                    printf("Posição já ocupada!\n");
                    return;
                }
            }
            // Marca a posição do navio
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[x + i][y + i] = simbolo;
            }
            break;

        case 'E': // Diagonal Esquerda
            //verifica se o navio cabe na diagonal esquerda
            if(x - tamanho < -1 || y + tamanho > TABULEIRO_ALTURA) {
                printf("Navio não cabe na diagonal esquerda!\n");
                return;
            }
            //checa se a posição já está ocupada
            for (int i = 0; i < tamanho; i++) {
                if (tabuleiro[x - i][y + i] != 0) {
                    printf("Posição já ocupada!\n");
                    return;
                }
            }
            // Marca a posição do navio
            for (int i = 0; i < tamanho; i++) {
                tabuleiro[x - i][y + i] = simbolo;
            }
            break;
            /*
            Os Navios posicionados diagonalmente podem se cruzar, no futuro,
            pode ser interessante implementar uma lógica que impeça o cruzamento de navios.
            */
        default:
            printf("Orientação inválida! Use 'H' para horizontal, 'V' para vertical, 'D' para diagonal direita, 'E' para diagonal esquerda.\n");
    }
}

void desenharTabuleiro(int tabuleiro[TABULEIRO_LARGURA][TABULEIRO_ALTURA]) {
    //4 espaços para o label de colunas ficar alinhado
    printf("    "); 
    
    // Labelação das colunas inciando em A e seguindo a tabela ASCII
    for (char x = 0; x < TABULEIRO_LARGURA; x++) {
        printf("%c ", x + 65); // 65 é o valor ASCII de 'A', cada letra seguinte é incrementada por 1
    }
    printf("\n");

    // For externo par as linhas
    for (int y = 0; y < TABULEIRO_ALTURA; y++) {
        //numeração das linhas + dois espaços
        printf("%2d  ", y + 1);

        // For interno para as colunas
        for (int x = 0; x < TABULEIRO_LARGURA; x++) {
            printf("%d ",tabuleiro[x][y]); // Exibe o tabuleiro
        }
        printf("\n");
    }
}

int main() {
    
    
    // Inicializa o tabuleiro 10x10 com zeros
    // Por padrão no C, uma matriz de inteiros é inicializada com zeros, não é necessário fazer isso manualmente.
    int tabuleiro[TABULEIRO_LARGURA][TABULEIRO_ALTURA] = {0};

    // ============================
    // Como usar a função posicionarNavio:
    //
    // posicionarNavio(
    //     tamanho,      // Comprimento do navio (quantas casas ocupa)
    //     x,            // Coluna inicial (índice de 0 a 9)
    //     y,            // Linha inicial (índice de 0 a 9)
    //     orientacao,   // Direção do navio:
    //                   //   'H' - horizontal (para a direita)
    //                   //   'V' - vertical (para baixo)
    //                   //   'D' - diagonal direita (para baixo e direita)
    //                   //   'E' - diagonal esquerda (para baixo e esquerda)
    //     simbolo,      // Valor inteiro para marcar as casas do navio (ex: 3)
    //     tabuleiro     // Matriz 10x10 representando o tabuleiro
    // );
    // ============================
    posicionarNavio(3, 1, 1, 'H', 3, tabuleiro);
    posicionarNavio(3, 2, 3, 'V', 3, tabuleiro); 
    posicionarNavio(3, 5, 1, 'D', 3, tabuleiro);
    posicionarNavio(3, 7, 7, 'E', 3, tabuleiro);

    //Denha o tabuleiro
    desenharTabuleiro(tabuleiro);

    return 0;
}
