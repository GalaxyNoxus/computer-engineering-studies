/* Faça um programa para calcular e mostrar o salário reajustado de um funcionário. O percentual
de aumento encontra-se na tabela a seguir. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float preco, total, prestacao;
    int parcelas;

    // entrada de dados
    printf("Digite o preco a vista do produto: ");
    scanf("%f", &preco);
    printf("Digite o numero de parcelas (3 ou 5): ");
    scanf("%d", &parcelas);
    
    // processamento
    if (parcelas == 3)
        total = preco * 1.10;
    else if (parcelas == 5)
        total = preco * 1.20;
    else
        printf("Numero de parcelas invalido\n");

    prestacao = total / parcelas;

    printf("\nTotal a pagar: R$ %.2f\n", total);
    printf("Valor de cada prestacao: R$ %.2f\n", prestacao);
    
    return 0;
}