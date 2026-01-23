#include <stdio.h>

int main() {

    int linhas [10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // Exibição de numeros para as linhas do tabuleiro
    char colunas [10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' }; //Exibição de letras para as colunas do tabuleiro
    int tabuleiro[10][10] = {0};

    /*
    
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

    */

    // Definindo a posição da habilidade de Cone
    // Ponto de origem (topo do cone): Linha 5, Coluna 2
    int cone_topo_linha = 5;
    int cone_topo_coluna = 2;

    // Loop para as 3 linhas do cone
    for (int i = 0; i < 3; i++) { // i controla as 3 linhas de altura
        // A cada linha i, o preenchimento começa em (topo - i) e vai até (topo + i)
        for (int j = cone_topo_coluna - i; j <= cone_topo_coluna + i; j++) {
            // Verificação de segurança para não sair dos limites do tabuleiro (0-9)
            if (cone_topo_linha + i < 10 && j >= 0 && j < 10) {
                tabuleiro[cone_topo_linha + i][j] = 3;
            }
        }
    }

    // Definindo a posicção da habilide Cruz
    // 1. Preenchimento Vertical (Linha 0 até 4 na Coluna 3)
    int coluna_fixa = 3;
    for (int i = 0; i <= 4; i++) {
        // Verifica se a linha i e a coluna_fixa estão entre 0 e 9
        if (i >= 0 && i < 10 && coluna_fixa >= 0 && coluna_fixa < 10) {
            tabuleiro[i][coluna_fixa] = 3;
        }
    }

    // 2. Preenchimento Horizontal (Coluna 1 até 5 na Linha 2)
    int linha_fixa = 2;
    for (int j = 1; j <= 5; j++) {
        // Verifica se a linha_fixa e a coluna j estão entre 0 e 9
        if (linha_fixa >= 0 && linha_fixa < 10 && j >= 0 && j < 10) {
            tabuleiro[linha_fixa][j] = 3;
        }
    }

    // Definindo a posição da habilidade Octaedro
    int centro_l = 5; // Centro entre linha 3 e 7
    int centro_c = 7;
    int espalhamento = 0;

    for (int i = 3; i <= 7; i++) {
        // Calcula quanto deve expandir para os lados
        // No topo (3) e base (7), espalhamento é 0. No centro (5), é 2.
        if (i <= centro_l) {
            espalhamento = i - 3; 
        } else {
            espalhamento = 7 - i;
        }

        for (int j = centro_c - espalhamento; j <= centro_c + espalhamento; j++) {
            // Verificação de segurança para limites do tabuleiro 10x10
            if (i >= 0 && i < 10 && j >= 0 && j < 10) {
                tabuleiro[i][j] = 3;
            }
        }
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