#include <stdio.h>
#include <stdlib.h> // Responsável para a função abs()

// Definições globais
#define TAMANHO_TABULEIRO 10 // Tamanho do tabuleiro (10x10)
#define TAMANHO_NAVIO 3 // Tamanho dos navios   
#define AGUA 0 // Representa água no tabuleiro
#define NAVIO 3 // Representa o navio no tabuleiro
#define HABILIDADE 5 // Representa área afetada por habilidade
#define TAMANHO_HABILIDADE 5 // Define o tamanho da matriz da habilidade

int main(){
    // Definição da matriz 10x10 que representa o Tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    int i, j; // Variáveis responsáveis pelo controle das repetições

    // --- INICIALIZAÇÃO DO TABULEIRO ---
    // Varre todas as posições do tabuleiro e as inicializa com água(0)
    for (i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // --- DETERMINAÇÃO DAS COORDENADAS DOS NAVIOS ---

    // Coordenadas do navio 1 (horizontal)
    int linha_navio1 = 1;
    int coluna_navio1 = 1;

    // Coordenadas do navio 2 (vertical)
    int linha_navio2 = 3;
    int coluna_navio2 = 8;

    // Coordenadas navio 3 (diagonal - principal)
    int linha_navio3 = 4;
    int coluna_navio3 = 1;

    // Coordenadas do navio 4 (diagonal - secundária)
    int linha_navio4 = 5;
    int coluna_navio4 = 5;

    // --- POSICIONAMENTO E VALIDAÇÃO DOS NAVIOS ---
    // Navio 1 (horizontal)
    if (coluna_navio1 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio1][coluna_navio1 + i] != NAVIO) {
                tabuleiro[linha_navio1][coluna_navio1 + i] = NAVIO;
            }
        }
    }

    // Navio 2 (vertical)
    if (linha_navio2 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio2 + i][coluna_navio2] != NAVIO) {
                tabuleiro[linha_navio2 + i][coluna_navio2] = NAVIO;
            }            
        }
    }
     
    // Navio 3 (diagonal principal)
    if (linha_navio3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna_navio3 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio3 + i][coluna_navio3 + i] != NAVIO) {
                tabuleiro[linha_navio3 + i][coluna_navio3 + i] = NAVIO;
            }
        }
    }
    // Navio 4 (diagonal secundária)
    if (linha_navio4 + TAMANHO_NAVIO <= TAMANHO_TABULEIRO && coluna_navio4 - (TAMANHO_NAVIO - 1) >= 0) {
        for (i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_navio4 + i][coluna_navio4 - i] != NAVIO) {
                tabuleiro[linha_navio4 + i][coluna_navio4 - i] = NAVIO;
            }
        }

    }

    // --- CRIAÇÃO DAS MATRIZES DE HABILIDADE ---
    int habilidade_cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int habilidade_octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int centro = TAMANHO_HABILIDADE / 2;

    // Lógica para contrução das matrizes de habilidade usando laços e condicionais
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Habilidade cone: a largura aumenta com a linha
            // Condição abs(j - centro) <= i cria um triângulo apontado para baixo
            if (abs(j - centro) <= i) {
                habilidade_cone[i][j] = 1;
            } else {
                habilidade_cone[i][j] = 0;
            }

            // Habilidade cruz: afeta a linha e a coluna central
            if (i == centro || j == centro) {
                habilidade_cruz[i][j] = 1;
            } else {
                habilidade_cruz[i][j] = 0;
            }

            // Habilidade octaedro (losango)
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade_octaedro[i][j] = 1;
            } else {
                habilidade_octaedro[i][j] = 0;
            }
        }
    }

















}


