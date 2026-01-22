#include <stdio.h>

int main() {

    int linhas [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Exibição de numeros para as linhas do tabuleiro
    char colunas [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' }; //Exibição de letras para as colunas do tabuleiro
    int tabuleiro[10][10] = {0};

    // Definindo a posição do navio horizontal: Linha 4 (índice 3), Colunas C, D, E (índices 2, 3, 4)
    int navioHorizontal_linha = 3;
    int navioHorizontal_colunas[3] = {2, 3, 4};

    for (int k = 0; k < 3; k++) {
        tabuleiro[navioHorizontal_linha][navioHorizontal_colunas[k]] = 3;
    }

    // Definindo a posição do navio vertical: Coluna H (índice 7), Linhas 7, 8, 9 (índices 6, 7, 8)
    int navioV_coluna = 7;
    int navioV_linhas[3] = {6, 7, 8};

    for (int k = 0; k < 3; k++) {
        tabuleiro[navioV_linhas[k]][navioV_coluna] = 3;
    }

        // Definindo a posição do primeiro navio na diagonal: Coluna B, C e D (índice 1, 2, 3), Linhas 1, 2, 3 (índices 1, 2, 3)
    int navioD1_coluna [3]= {1, 2, 3};
    int navioD1_linhas[3] = {1, 2, 3};

    for (int k = 0; k < 3; k++) {
        tabuleiro[navioD1_linhas[k]][navioD1_coluna[k]] = 3;
    }

    // Definindo a posição do segundo navio na diagonal: Coluna B, C e D (índice 1, 2, 3), Linhas 7, 8, 9 (índices 6, 7, 8)
    int navioD2_coluna [3]= {1, 2, 3};
    int navioD2_linhas[3] = {6, 7, 8};

    for (int k = 0; k < 3; k++) {
        tabuleiro[navioD2_linhas[k]][navioD2_coluna[k]] = 3;
    }


    // Exibição do Tabuleiro
    printf("EXIBICAO DO TABULEIRO: \n");
    // 1. Imprimir o cabeçalho das colunas (letras de A até J) 
    printf("    "); // Espaço inicial para compensar a coluna de números
    for (int j = 0; j < 10; j++) 
    {
        printf("%c ", colunas[j]);
    }
    printf("\n");

     for (int i = 0; i < 10; i++)
        {   
            // 2. Imprimir os valores das linhas (numeros de 1 até 10) 
            printf(" %2d", linhas[i]); // O %2d irá alinhar os numeros das linhas
            
            for (int j = 0; j < 10; j++)
            {   
                // 3. Exibir o valor de cada indice da matriz, sendo zero = agua e três = navio
                printf(" %d", tabuleiro[i][j]);
            }

            printf("\n");
        }
        

    return 0;
}