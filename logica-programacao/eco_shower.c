#include <stdio.h>

int main(void) {
    // Declaração de variáveis
    float duracao, vazao, preco_m3;
    float litros, custo;

    printf("=== EcoShower - Calculadora de Consumo de Água no Banho ===\n");

    // Entrada de dados
    printf("\nInforme a duração do banho (minutos): ");
    scanf("%f", &duracao);

    printf("Informe a vazão do chuveiro (litros por minuto): ");
    scanf("%f", &vazao);

    printf("Informe o preço do m³ de água (em R$): ");
    scanf("%f", &preco_m3);

    // Processamento
    litros = duracao * vazao;
    custo = (litros / 1000.0) * preco_m3;

    // Saída dos resultados
    printf("\n=== RESULTADOS ===\n");
    printf("Volume de água consumido: %.1f litros\n", litros);
    printf("Custo estimado: R$ %.2f\n", custo);

    // Classificação do consumo
    if (litros > 70) {
        printf("\nAlerta: Consumo ALTO! Considere reduzir o tempo de banho.\n");
    } else if (litros > 40) {
        printf("\nConsumo MODERADO. Tem espaço para economia.\n");
    } else {
        printf("\nÓtimo! Consumo BAIXO. Continue assim!\n");
    }

    return 0;
}
