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

    // Validação dos limites na vertical para o navio 2
    if (linha_navio2 + tamanho_navio > tamanho_tabuleiro){
        printf("Erro: o navio vertical excede os limites do tabuleiro!\n");
        return 1; // Finaliza o programa em caso de erro.
    }

    // Posicionamento do navio 1 na horizontal
    for (i = 0; i < tamanho_navio; i++){
        // Verifica a sobreposição
        if(tabuleiro[linha_navio1][coluna_navio1 + i] = navio){
            printf("Erro: sobreposição detectada ao posicionar o navio horizontal.\n");
            return 1; // Finaliza o programa em caso de erro
        }
        tabuleiro[linha_navio1][coluna_navio1 + i] = navio;
    }

    // Posicionamento do navio 2 na vertical
    for (i = ; i < tamanho_navio; i++){
        // Verifica a sobreposição
        if (tabuleiro[linha_navio2 + i][coluna_navio2] = navio){
            printf("Erro: sobreposição detectada ao posicionar o navio vertical.\n");
            return 1;
        }
    }
    tabuleiro[linha_navio2 + i][coluna_navio2] = navio;


























}