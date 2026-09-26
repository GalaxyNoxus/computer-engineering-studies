/*Faça um programa que receba três notas, calcule e mostre a média aritmética entre elas*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float nota1, nota2, nota3, media;

    // entrada de dados
    printf("Valor da primeira nota: ");
    scanf("%f", &nota1);

    printf("Valor da segunda nota: ");
    scanf("%f", &nota2);

    printf("Valor da terceira nota: ");
    scanf("%f", &nota3);

    // processamento

    media = (nota1+nota2+nota3)/3;

    printf("\nA média aritmética é: %.2f", media);

    return 0;
}
