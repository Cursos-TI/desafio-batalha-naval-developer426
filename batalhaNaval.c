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

    // --- DEFINIÇÃO DOS PONTOS DE ORIGEM DAS HABILIDADE ---
    int linha_origem_cone = 0;
    int coluna_origem_cone = 4;

    int linha_origem_cuz = 8;
    int coluna_origem_cruz = 2;

    int linha_origem_octaedro = 7;
    int coluna_origem_octaedro = 7;

    // --- SOBREPOSIÇÃO DAS HABILIDADES NO TABULEIRO ---

    // Habilidade CONE
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Confere se a posição na amtriz de habilidade precisa ser ativada (valor 1)
            if (habilidade_cone[i][j] == 1) {
                // Determina a posição equivalente no tabuleiro principal
                // A operação (i - centro) ajusta o ponto de referência, fazendo com que a origem da habilidade fique alinhada ao centro da matriz
                int target_linha = linha_origem_cone + i; // Para o cone, a origem é o topo e não o centro
                int target_coluna = coluna_origem_cone + (j - centro);

                // Validação para respeitar os limites do tabuleiro
                if (target_linha >= 0 && target_linha < TAMANHO_TABULEIRO &&
                    target_coluna >= 0 && target_coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[target_linha][target_coluna] = HABILIDADE;
                }
            }
        }
    }

    // Habilidade CRUZ
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_cruz[i][j] == 1) {
                int target_linha = linha_origem_cuz + (i - centro);
                int target_coluna = coluna_origem_cruz + (j - centro);

                if (target_linha >= 0 && target_linha < TAMANHO_TABULEIRO &&
                    target_coluna >= 0 && target_coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[target_linha][target_coluna] = HABILIDADE;
                }                    
            }
        }
    }

    // Habilidade OCTAEDRO
    for (i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (habilidade_octaedro[i][j] == 1) {
                int target_linha = linha_origem_octaedro + (i - centro);
                int target_coluna = coluna_origem_octaedro + (j - centro);

                if (target_linha >= 0 && target_linha < TAMANHO_TABULEIRO &&
                    target_coluna >= 0 && target_coluna < TAMANHO_TABULEIRO) {
                    tabuleiro[target_linha][target_coluna] = HABILIDADE;
                }
            }
        }
    }

    // --- EXIBIÇÃO DO TABULEIRO ---
printf("\n  --- TABULEIRO BATALHA NAVAL ---\n");
printf("\n");

// 1. Impressão do cabeçalho das colunas (0 a 9)
// Pula 4 espaços para alinhar com o "Índice da Linha" ("%2d | ")
printf("    |");
for (j = 0; j < TAMANHO_TABULEIRO; j++) {
    printf("%3d", j); // Agora usa "%3d" para garantir 3 espaços (2 para o número + 1 de espaço)
}
printf("\n");

// 2. Impressão da linha separadora
// Pula 4 hífens para alinhar com o "Índice da Linha" (os 4 primeiros caracteres)
printf("----"); 
// Multiplica o número de hífens por 3 (pois cada coluna ocupa 3 espaços)
for (j = 0; j < TAMANHO_TABULEIRO * 3; j++) {
    printf("-");
}
printf("\n");


// 3. Impressão das linhas e do conteúdo do tabuleiro
for (i = 0; i < TAMANHO_TABULEIRO; i++) {
    printf("%2d |", i); // Impressão do índice da linha
    for (j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%3d", tabuleiro[i][j]); // Usa "%3d" para 3 espaços de coluna
    }
    printf("\n");
}

// Legenda dos atributos
printf("\nLegenda: 0 = Água | 3 = Navio | 5 = Área de habilidade\n");

    return 0;
}


