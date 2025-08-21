#include <stdio.h>
#include <ctype.h>

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

// O tabuleiro pode ter as suas dimensões alteradas, inclusive para tabuleiros não quadrados.
// Definições de tamanho do tabuleiro
#define TABULEIRO_LARGURA 10
#define TABULEIRO_ALTURA 10

void PosicionarNavio(int tamanho, int x, int y, char orientacao, int simbolo, int tabuleiro[TABULEIRO_LARGURA][TABULEIRO_ALTURA]) {
    // Função para posicionar navios no tabuleiro
    // Implemente a lógica para posicionar navios verticalmente e horizontalmente

    // Verifica se o tamanho do navio é válido
    // O tamanho deve ser entre 2 e 5, caso contrário, exibe uma mensagem de erro
    if (tamanho < 2 || tamanho > 5) {
        printf("Tamanho do navio inválido! Deve ser entre 2 e 5.\n");
        return;
    }

    //valida a posição do navio
    if(y < 0 || y >= TABULEIRO_ALTURA || x < 0 || x >= TABULEIRO_LARGURA) {
        printf("Posição inválida!\n");
        return;
    }

    orientacao = toupper(orientacao); // Converte a orientação para maiúscula para garantir a consistência

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

void DesenharTabuleiro(int tabuleiro[TABULEIRO_LARGURA][TABULEIRO_ALTURA]) {
    //4 espaços para o label de colunas ficar alinhado
    printf("    "); 
    
    // Labelação das colunas inciando em A e seguindo a tabela ASCII
    for (char x = 0; x < TABULEIRO_LARGURA; x++) {
        printf("%c ", x + 'A');
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

void UsarHabilidade(int x, int y, int habilidade[3][5],int simbolo, int tabuleiro[TABULEIRO_LARGURA][TABULEIRO_ALTURA]) {
    // Função para usar habilidades especiais
    // Marca o tabuleiro com as áreas afetadas pela habilidade
    
    // descola o centro da habilidade para o indíce 0 da matriz abilidade
    x = x - 2;
    y = y - 1;

    if (x < 0 || x + 5 > TABULEIRO_LARGURA || y < 0 || y + 3 > TABULEIRO_ALTURA) {
        printf("Habilidade fora dos limites do tabuleiro!\n");
        return;
    }

    // for externo que percorre as linhas da matriz de habilidade
    for (int j = 0; j < 3; j++) {

        // for interno que percorre as colunas da matriz de habilidade
        for (int i = 0; i < 5; i++) {
            
            // Verifica se a posição da matriz de habilidade é 1, se sim, marca no tabuleiro
            if (habilidade[j][i] == 1) {
                tabuleiro[x + i][y + j] = simbolo; // Marca a posição afetada pela habilidade com o símbolo fornecido
            }  
        }  
    }
}

int ColunaToIndice(char coluna) {
    coluna = toupper(coluna); // Converte a letra para maiúscula para garantir a consistência

    // Converte a letra da coluna (A, B, C, ...) para o índice correspondente (0, 1, 2, ...)
    if (coluna >= 'A' && coluna <= 'A' + TABULEIRO_LARGURA -1) {
        return coluna - 'A'; // 'A' se torna 0, 'B' se torna 1, ..., 'J' se torna 9
    }
    return -1; // Retorna -1 se a coluna for inválida
}

int LinhaToIndice(int linha) {
    // Converte o número da linha (1, 2, 3, ...) para o índice correspondente (0, 1, 2, ...)
    if (linha >= 1 && linha <= TABULEIRO_ALTURA) {
        return linha - 1; // 1 se torna 0, 2 se torna 1, ..., 10 se torna 9
    }
    return -1; // Retorna -1 se a linha for inválida
}

int main() {
    // Inicializa o tabuleiro com zeros
    // Por padrão no C, uma matriz de inteiros é inicializada com zeros, não é necessário fazer isso manualmente.
    int tabuleiro[TABULEIRO_LARGURA][TABULEIRO_ALTURA] = {0};

    // Matrizes para as habilidades
    // Cada matriz representa uma habilidade especial que pode ser usada no jogo
    int habilidadeCone[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1}
    };

    int habilidadeCruz[3][5] = {
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0}
    };

    int habilidadeOctaedro[3][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0}
    };

    int simboloNavio = 3; // Simbolo para os navios  
    int simboloHabilidade = 1; // Simbolo para as habilidades

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
    //     tabuleiro     // Matriz representando o tabuleiro
    // );
    // 
    // Exemplo de uso:
    //PosicionarNavio(3, 1, 1, 'H', 3, tabuleiro);
    //PosicionarNavio(3, 2, 3, 'V', 3, tabuleiro); 
    //PosicionarNavio(3, 5, 1, 'D', 3, tabuleiro);
    //PosicionarNavio(3, 7, 7, 'E', 3, tabuleiro);

    // ============================
    // Como usar a função UsarHabilidade:
    //
    // UsarHabilidade(
    //     x,            // Coluna central onde a habilidade será aplicada (índice de 0 a TABULEIRO_LARGURA-1)
    //     y,            // Linha central onde a habilidade será aplicada (índice de 0 a TABULEIRO_ALTURA-1)
    //     habilidade,   // Matriz 3x5 que define o formato da habilidade (ex: abilidadeCone, abilidadeCruz, abilidadeOctaedro)
    //     simbolo,      // Valor inteiro para marcar as casas afetadas pela habilidade (ex: 1)
    //     tabuleiro     // Matriz representando o tabuleiro
    // );
    //
    // Observações:
    // - O ponto (x, y) será o centro da matriz de habilidade no tabuleiro.
    // - Certifique-se de que a matriz de habilidade não ultrapasse os limites do tabuleiro.
    // - O argumento 'habilidade' deve ser uma matriz 3x5, onde 1 indica casa afetada e 0 não afetada.
    //
    // Exemplo de uso:
    //UsarHabilidade(3, 2, habilidadeCone, 4, tabuleiro);
    //UsarHabilidade(5, 5, habilidadeCruz, 5, tabuleiro);
    //UsarHabilidade(7, 8, habilidadeOctaedro, 6, tabuleiro);

    //Denha o tabuleiro
    //DesenharTabuleiro(tabuleiro);

    // Resolvi ir alem e realmente fazer um jogo funcional, abaixo estará o loop principal do jogo.
    // Mas caso queira apenas testar as funções, comente o código abaixo e descomente os exemplos de usos acima.

    // Menu do jogo
    printf("Bem-vindo ao Batalha Naval!\n");
    
    char menuOpcao, habilidade;
    char coluna, orientacao;
    int linha, tamanhoNavio; 

    
    do   
    {
        DesenharTabuleiro(tabuleiro);
        printf("\n");
        printf("Escolha uma opção:\t");
        printf("1. Posicionar Navio\t");
        printf("2. Usar Habilidade\t");
        printf("8. Limpar Tabuleiro\t");
        printf("9. Sair\n");
        scanf(" %c", &menuOpcao);
        
        switch (menuOpcao)
        {
        case '1':
            printf("Informe um navio a coordenada do navio (exemplo: A 1):\n");
            scanf(" %c %d", &coluna, &linha);
            printf("Informe o tamanho do navio (2-5):\n");
            scanf(" %d", &tamanhoNavio);
            printf("Informe a orientação do navio (H - horizontal, V - vertical, D - diagonal direita, E - diagonal esquerda):\n");
            scanf(" %c", &orientacao);
            PosicionarNavio(tamanhoNavio, ColunaToIndice(coluna), LinhaToIndice(linha), orientacao, simboloNavio, tabuleiro);
            break;

        case '2':
            printf("Escolha uma habilidade: 1. Cone - 2. Cruz - 3. Octaedro\n");
            scanf(" %c", &habilidade);
            printf("Informe a posição central da habilidade (exemplo: A 1):\n");
            scanf(" %c %d", &coluna, &linha);
            switch (habilidade)
            {
            case '1':
                UsarHabilidade(ColunaToIndice(coluna), LinhaToIndice(linha), habilidadeCone, simboloHabilidade, tabuleiro);
                break;
            case '2':
                UsarHabilidade(ColunaToIndice(coluna), LinhaToIndice(linha), habilidadeCruz, simboloHabilidade, tabuleiro);
                break;
            case '3':
                UsarHabilidade(ColunaToIndice(coluna), LinhaToIndice(linha), habilidadeOctaedro, simboloHabilidade, tabuleiro);
                break;
            default:
                printf("Habilidade inválida!\n");
            }
            break;

        case '8':
            printf("Tabuleiro limpo.\n");
            for (int i = 0; i < TABULEIRO_LARGURA; i++)
            {
                for (int j = 0; j < TABULEIRO_ALTURA; j++)
                {
                    tabuleiro[i][j] = 0; // Limpa o tabuleiro
                }
            }
            break;
        case '9':
            printf("Saindo do jogo.\n");
            return 0;

        default:
            break;
        }
    } while (1);

}
