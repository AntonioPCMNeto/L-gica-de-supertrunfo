#include <stdio.h>

// Estrutura para representar a carta
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

int main() {
    // Duas cartas já cadastradas
    struct Carta carta1 = {"Brasil", 213000000, 8515767.0, 2200.0, 150, 0};
    struct Carta carta2 = {"Argentina", 45300000, 2780400.0, 600.0, 80, 0};

    // Cálculo da densidade demográfica (População / Área)
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    int escolha;

    // Exibição do menu
    printf("=== SUPER TRUNFO - Comparação de Cartas ===\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n\n", carta2.nomePais);
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua escolha: ");
    scanf("%d", &escolha);

    // Variáveis para guardar os valores comparados
    float valor1 = 0, valor2 = 0;
    int resultado = 0; // 0 = empate, 1 = carta1 vence, 2 = carta2 vence
    char nomeAtributo[50];

    // Estrutura switch para identificar o atributo
    switch (escolha) {
        case 1:
            valor1 = carta1.populacao;
            valor2 = carta2.populacao;
            resultado = (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
            sprintf(nomeAtributo, "População");
            break;

        case 2:
            valor1 = carta1.area;
            valor2 = carta2.area;
            resultado = (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
            sprintf(nomeAtributo, "Área");
            break;

        case 3:
            valor1 = carta1.pib;
            valor2 = carta2.pib;
            resultado = (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
            sprintf(nomeAtributo, "PIB");
            break;

        case 4:
            valor1 = carta1.pontosTuristicos;
            valor2 = carta2.pontosTuristicos;
            resultado = (valor1 > valor2) ? 1 : (valor2 > valor1) ? 2 : 0;
            sprintf(nomeAtributo, "Pontos Turísticos");
            break;

        case 5:
            valor1 = carta1.densidadeDemografica;
            valor2 = carta2.densidadeDemografica;

            // Densidade: menor valor vence
            if (valor1 < valor2) {
                resultado = 1;
            } else if (valor2 < valor1) {
                resultado = 2;
            } else {
                resultado = 0;
            }
            sprintf(nomeAtributo, "Densidade Demográfica");
            break;

        default:
            printf("\nOpção inválida! Tente novamente com um número de 1 a 5.\n");
            return 1; // Termina o programa
    }

    // Exibindo resultado da comparação
    printf("\n--- Resultado da Comparação ---\n");
    printf("Atributo Comparado: %s\n", nomeAtributo);
    printf("%s: %.2f\n", carta1.nomePais, valor1);
    printf("%s: %.2f\n", carta2.nomePais, valor2);

    if (resultado == 1) {
        printf("Vencedor: %s\n", carta1.nomePais);
    } else if (resultado == 2) {
        printf("Vencedor: %s\n", carta2.nomePais);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
