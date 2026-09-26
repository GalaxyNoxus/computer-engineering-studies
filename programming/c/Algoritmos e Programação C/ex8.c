/*Faça um programa que calcule e mostre a área de um losango.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float diagonal_maior, diagonal_menor, calculo;

    // entrada de dados
    printf("Digite o valor da diagonal maior: ");
    scanf("%f", &diagonal_maior);

    printf("Digite o valor da diagonal menor: ");
    scanf("%f", &diagonal_menor);


    // processamento
    calculo = (diagonal_maior * diagonal_menor)/2;

    printf("\nA área do losango é: %.2f", calculo);

    return 0;
}
