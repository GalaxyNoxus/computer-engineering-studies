/*Faça um programa para calcular e exibir na tela a área de um triângulo de base b e altura h, em
que os valores de b e de h são fornecidos pelo usuário via teclado.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    //Reconhecer acentua��o
    setlocale(LC_ALL, "Portuguese");

    float altura, base, area;

    //Entrada de dados
    printf("Digite o valor da base do triângulo: ");
    scanf("%f", &base);
    //%f - float
    //& - endereço de memória

    printf("Digite o valor da altura do triângulo: ");
    scanf("%f", &altura);

    //Processamento
    area = (base * altura)/2;

    //Saída de dados
    printf("\nA área do triângulo é %.2f\n\n", area);
}
