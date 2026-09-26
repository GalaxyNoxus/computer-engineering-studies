/*Faça um programa que receba três notas e seus respectivos pesos, calcule e mostre a média
ponderada dessas notas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float nota1, peso1, nota2, peso2, nota3, peso3, media;

    // entrada de dados
    printf("Valor da primeira nota: ");
    scanf("%f", &nota1);
    printf("Valor do peso: ");
    scanf("%f", &peso1);

    printf("Valor da segunda nota: ");
    scanf("%f", &nota2);
    printf("Valor do peso: ");
    scanf("%f", &peso2);

    printf("Valor da terceira nota: ");
    scanf("%f", &nota3);
    printf("Valor do peso: ");
    scanf("%f", &peso3);

    // processamento

    media = ((nota1 * peso1) + (nota2 * peso2) + (nota3 * peso3))/(peso1 + peso2 + peso3);

    printf("\nA média ponderada ?: %.2f", media);

    return 0;
}
