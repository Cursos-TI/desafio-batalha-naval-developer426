#include <stdio.h>

#define tamanho_tabuleiro 10 // Tamanho do tabuleiro (10x10)
#define tamanho_navio 3 // Tamanho dos navios
#define agua 0 // Representa a água no tabuleiro
#define navio 3 // Representa o navio no tabuleiro

int main(){
    int tabuleiro[tamanho_tabuleiro][tamanho_tabuleiro];
    int i, j;

    // Tabuleiro com definição 0 (água)
    for (i = 0; i < tamanho_tabuleiro; i++){
        for (j = 0; j < tamanho_tabuleiro; j++){
            tabuleiro[i][j] = agua;
        }
    }

    // Determinação das coordenadas dos navios
    
    // Coordenadas do navio 1
    int linha_navio1 = 6;
    int coluna_navio1 = 7;

    // Coordenadas navio 2
    int linha_navio2 = 1;
    int coluna_navio2 = 6;

    // Validação dos limites na horizontal para o navio 1
    if (coluna_navio1 + tamanho_navio > tamanho_tabuleiro){
        printf("Erro: o navio na horizontal excede os limites do tabuleiro!\n");
        return 1; // Finaliza o programa em caso de erro
    }

    
























}