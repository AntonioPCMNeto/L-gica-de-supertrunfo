#include <stdio.h>

// Estrutura da carta com os dados
struct Carta {
    char nomePais[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica;
};

int main() {
    // Cartas com os dados preenchidos
    struct Carta carta1 = {"Brasil", 213000000, 8515767.0, 2200.0, 150};
    struct Carta carta2 = {"Argentina", 45300000, 2780400.0, 600.0, 80};

    // Calculando densidade demográfica
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    int escolha1, escolha2;

    printf("=== SUPER TRUNFO ===\n");
    printf("Carta 1: %s\n", carta1.nomePais);
    printf("Carta 2: %s\n\n", carta2.nomePais);

    // Mostrando opções para o primeiro atributo
    printf("Escolha o primeiro atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &escolha1);

    // Menu dinâmico: não mostrar o mesmo atributo para a segunda escolha
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    if (escolha1 != 1) printf("1 - População\n");
    if (escolha1 != 2) printf("2 - Área\n");
    if (escolha1 != 3) printf("3 - PIB\n");
    if (escolha1 != 4) printf("4 - Pontos Turísticos\n");
    if (escolha1 != 5) printf("5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &escolha2);

    // Verifica se o jogador escolheu o mesmo atributo duas vezes
    if (escolha1 == escolha2) {
        printf("Erro: você escolheu o mesmo atributo duas vezes.\n");
        return 1;
    }

    // Pegando os valores escolhidos para cada carta
    float valor1_c1 = 0, valor2_c1 = 0;
    float valor1_c2 = 0, valor2_c2 = 0;

    // Atributo 1
    if (escolha1 == 1) {
        valor1_c1 = carta1.populacao;
        valor1_c2 = carta2.populacao;
    } else if (escolha1 == 2) {
        valor1_c1 = carta1.area;
        valor1_c2 = carta2.area;
    } else if (escolha1 == 3) {
        valor1_c1 = carta1.pib;
        valor1_c2 = carta2.pib;
    } else if (escolha1 == 4) {
        valor1_c1 = carta1.pontosTuristicos;
        valor1_c2 = carta2.pontosTuristicos;
    } else if (escolha1 == 5) {
        valor1_c1 = carta1.densidadeDemografica;
        valor1_c2 = carta2.densidadeDemografica;
    }

    // Atributo 2
    if (escolha2 == 1) {
        valor2_c1 = carta1.populacao;
        valor2_c2 = carta2.populacao;
    } else if (escolha2 == 2) {
        valor2_c1 = carta1.area;
        valor2_c2 = carta2.area;
    } else if (escolha2 == 3) {
        valor2_c1 = carta1.pib;
        valor2_c2 = carta2.pib;
    } else if (escolha2 == 4) {
        valor2_c1 = carta1.pontosTuristicos;
        valor2_c2 = carta2.pontosTuristicos;
    } else if (escolha2 == 5) {
        valor2_c1 = carta1.densidadeDemografica;
        valor2_c2 = carta2.densidadeDemografica;
    }

    // Comparação dos dois atributos
    int pontosCarta1 = 0, pontosCarta2 = 0;

    // Comparação do primeiro atributo
    printf("\n--- Comparando primeiro atributo ---\n");
    printf("%s: %.2f\n", carta1.nomePais, valor1_c1);
    printf("%s: %.2f\n", carta2.nomePais, valor1_c2);

    if (escolha1 == 5) {
        if (valor1_c1 < valor1_c2) pontosCarta1++;
        else if (valor1_c2 < valor1_c1) pontosCarta2++;
    } else {
        if (valor1_c1 > valor1_c2) pontosCarta1++;
        else if (valor1_c2 > valor1_c1) pontosCarta2++;
    }

    // Comparação do segundo atributo
    printf("\n--- Comparando segundo atributo ---\n");
    printf("%s: %.2f\n", carta1.nomePais, valor2_c1);
    printf("%s: %.2f\n", carta2.nomePais, valor2_c2);

    if (escolha2 == 5) {
        if (valor2_c1 < valor2_c2) pontosCarta1++;
        else if (valor2_c2 < valor2_c1) pontosCarta2++;
    } else {
        if (valor2_c1 > valor2_c2) pontosCarta1++;
        else if (valor2_c2 > valor2_c1) pontosCarta2++;
    }

    // Soma dos valores
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    // Resultado final
    printf("\n--- Resultado Final ---\n");
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nomePais, soma1);
    printf("%s: %.2f\n", carta2.nomePais, soma2);

    if (soma1 > soma2) {
        printf("Vencedor: %s\n", carta1.nomePais);
    } else if (soma2 > soma1) {
        printf("Vencedor: %s\n", carta2.nomePais);
    } else {
        printf("Empate!\n");
    }

    return 0;
}
