// Biblioteca que permite a entrada e saída de dados
#include <stdio.h> 

int main(){

    // Declarando o tabuleiro (matriz 10x10) e inicializando com zeros
    int tabuleiro[10][10] = {0};

    // Identificadores das colunas (letras A a J)
    char coluna[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    // Tamanho fixo dos navios (3 unidades)
    int tamanhoNavio = 3;

    // Coordenadas iniciais dos navios
    int navio1Coluna = 2, navio1Linha = 3; // Navio 1 será posicionado na horizontal
    int navio2Coluna = 6, navio2Linha = 6; // Navio 2 será posicionado na horizontal
    int navio3Coluna = 6, navio3Linha = 1; // Navio 3 será posicionado na diagonal
    int navio4Coluna = 2, navio4Linha = 5; // Navio 4 será posicionado na diagonal

    // Verificação de limite do Navio 1 (horizontal)
    if(navio1Coluna + tamanhoNavio > 10){
        printf("Erro: Navio 1 ultrapassa os limites do tabuleiro\n");
        return 1;
    }

    // Verificação de limite do Navio 2 (horizontal)
    if(navio2Coluna + tamanhoNavio > 10){
        printf("Erro: Navio 2 ultrapassa os limites do tabuleiro\n");
        return 1;
    }

    // Verificação de limite do Navio 3 (diagonal)
    if(navio3Linha + tamanhoNavio > 10 || navio3Coluna + tamanhoNavio > 10){
        printf("Erro: Navio 3 ultrapassa os limites do tabuleiro\n");
        return 1;
    }

    // Verificação de limite do Navio 4 (diagonal)
    if(navio4Linha + tamanhoNavio > 10|| navio4Coluna + tamanhoNavio > 10){
        printf("Erro: Navio 4 ultrapassa os limites do tabuleiro\n");
        return 1;
    }


    // Verificação de sobreposição entre os navios
    for(int i = 0; i < tamanhoNavio; i++){
        if (tabuleiro[navio1Linha][navio1Coluna + i] != 0 || 
            tabuleiro[navio2Linha ][navio2Coluna + i] != 0 ||
            tabuleiro[navio3Linha + i][navio3Coluna + i] != 0||
            tabuleiro[navio4Linha + i][navio4Coluna + i] != 0 ){
            printf("Erro: Os navios estão se sobrepondo\n");
            return 1;
        }
    }

    // Posicionando o Navio 1 (horizontal)
    for(int i = 0; i < tamanhoNavio; i++){
        tabuleiro[navio1Linha][navio1Coluna + i] = 3;
    }

    // Posicionando o Navio 2 (horizontal)
    for(int i = 0; i < tamanhoNavio; i++){
        tabuleiro[navio2Linha][navio2Coluna + i] = 3;
    }
    
    // Posicionando o Navio 3 (diagonal)
    for(int i = 0; i < tamanhoNavio; i++){
        tabuleiro[navio3Linha + i][navio3Coluna + i]= 3;
    }

    // Posicionando o Navio 4 (diagonal)
    for(int i = 0; i < tamanhoNavio; i++){
        tabuleiro[navio4Linha + i][navio4Coluna + i] = 3;
    }

    // Exibe o tabuleiro com cabeçalhos de coluna
    printf("\nTABULEIRO DE BATALHA NAVAL\n  ");
    for(int i = 0; i < 10; i++){
        printf(" %c ", coluna[i]);
    }
    printf("\n");

    // Exibe as linhas e colunas com índices e valores
    for (int i = 0; i < 10; i++){
        printf("%2d ", i + 1);
        for (int j = 0; j < 10; j++){
            printf("%d  ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    // Indica que o programa terminou
    return 0;
}
