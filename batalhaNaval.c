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

void posicionarNavios(int tamanho, int coluna, int linha, char orientacao, int tabuleiro[10][10]) {
    // Função para posicionar navios no tabuleiro
    // Implemente a lógica para posicionar navios verticalmente e horizontalmente

    //valida a posição do navio
    if(linha < 0 || linha >= 10 || coluna < 0 || coluna >= 10) {
        printf("Posição inválida!\n");
        return;
    }

    if (orientacao == 'H') { // Horizontal
        //verifica se o navio cabe na horizontal
        if(linha + tamanho > 10) {
            printf("Navio não cabe na horizontal!\n");
            return;
        }
        //checa se a posição já está ocupada
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha + i][coluna] != 0) {
                printf("Posição já ocupada!\n");
                return;
            }
        }
        // Marca a posição do navio
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha + i][coluna] = 3;
        }
    } else if (orientacao == 'V') { // Vertical
        //verifica se o navio cabe na vertical
        if(coluna + tamanho > 10) {
            printf("Navio não cabe na vertical!\n");
            return;
        }
        //checa se a posição já está ocupada
        for (int i = 0; i < tamanho; i++) {
            if (tabuleiro[linha][coluna + i] != 0) {
                printf("Posição já ocupada!\n");
                return;
            }
        }
        // Marca a posição do navio
        for (int i = 0; i < tamanho; i++) {
            tabuleiro[linha][coluna + i] = 4;
        }
    }
}

int main() {
    
    // labelação de colunas
    char colunas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    
    // Inicializa o tabuleiro 10x10 com zeros
    // Por padrão no C, uma matriz de inteiros é inicializada com zeros.
    int tabuleiro[10][10] = {0};

    // Posiciona navios no tabuleiro
    posicionarNavios(3, 1, 5, 'H', tabuleiro); // Navio horizontal de tamanho 3 na posição
    posicionarNavios(3, 2, 2, 'V', tabuleiro); // Navio vertical de tamanho 4 na posição

    //Denha o label de colunas
    printf("    "); //4 espaços para o label de colunas
    for (int x = 0; x < 10; x++) {
        printf("%c ", colunas[x]);
    }
    printf("\n");

    // Desenha o tabuleiro
    // For externo par as linhas
    for (int y = 0; y < 10; y++) {
        //numeração das linhas + dois espaços
        printf("%2d  ", y + 1);

        // For interno para as colunas
        for (int x = 0; x < 10; x++) {
            printf("%d ",tabuleiro[x][y]); // Exibe o tabuleiro
        }
        printf("\n");
    }

    return 0;
}
