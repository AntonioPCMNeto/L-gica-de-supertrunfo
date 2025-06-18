#include <stdio.h>

// Estrutura para representar uma carta do jogo
struct Carta {
    char estado[50];
    char codigo[20];
    char nomeCidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
};

int main() {
    // Criação das duas cartas com dados preenchidos manualmente
    struct Carta carta1 = {"São Paulo", "SP01", "São Paulo", 12300000, 1521.11, 700000.0, 50};
    struct Carta carta2 = {"Rio de Janeiro", "RJ02", "Rio de Janeiro", 6700000, 1182.30, 450000.0, 45};

    // Cálculo da Densidade Populacional: População / Área
    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    // Cálculo do PIB per capita: PIB / População
    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // =============================================
    // ESCOLHA DO ATRIBUTO DE COMPARAÇÃO:
    // Altere a variável abaixo para:
    // 1 - População
    // 2 - Área
    // 3 - PIB
    // 4 - Densidade Populacional
    // 5 - PIB per capita
    // =============================================
    int atributoEscolhido = 3; // <<< Altere aqui para trocar o atributo comparado

    // Variáveis auxiliares para armazenar os valores comparados
    float valor1 = 0, valor2 = 0;
    char nomeAtributo[50];

    // Escolher o atributo com base no número
    if (atributoEscolhido == 1) {
        valor1 = carta1.populacao;
        valor2 = carta2.populacao;
        sprintf(nomeAtributo, "População");
    } else if (atributoEscolhido == 2) {
        valor1 = carta1.area;
        valor2 = carta2.area;
        sprintf(nomeAtributo, "Área");
    } else if (atributoEscolhido == 3) {
        valor1 = carta1.pib;
        valor2 = carta2.pib;
        sprintf(nomeAtributo, "PIB");
    } else if (atributoEscolhido == 4) {
        valor1 = carta1.densidadePopulacional;
        valor2 = carta2.densidadePopulacional;
        sprintf(nomeAtributo, "Densidade Populacional");
    } else if (atributoEscolhido == 5) {
        valor1 = carta1.pibPerCapita;
        valor2 = carta2.pibPerCapita;
        sprintf(nomeAtributo, "PIB per capita");
    } else {
        printf("Atributo inválido selecionado.\n");
        return 1;
    }

    // Mostrar os valores das cartas
    printf("=== Comparando Cartas do Super Trunfo ===\n");
    printf("Atributo: %s\n\n", nomeAtributo);
    printf("Carta 1 - %s (%s): %.2f\n", carta1.nomeCidade, carta1.estado, valor1);
    printf("Carta 2 - %s (%s): %.2f\n", carta2.nomeCidade, carta2.estado, valor2);

    // Lógica de comparação
    if (atributoEscolhido == 4) {
        // Para densidade populacional, menor valor vence
        if (valor1 < valor2) {
            printf("\nVencedora: %s\n", carta1.nomeCidade);
        } else if (valor2 < valor1) {
            printf("\nVencedora: %s\n", carta2.nomeCidade);
        } else {
            printf("\nEmpate!\n");
        }
    } else {
        // Para os demais atributos, maior valor vence
        if (valor1 > valor2) {
            printf("\nVencedora: %s\n", carta1.nomeCidade);
        } else if (valor2 > valor1) {
            printf("\nVencedora: %s\n", carta2.nomeCidade);
        } else {
            printf("\nEmpate!\n");
        }
    }

    return 0;
}
