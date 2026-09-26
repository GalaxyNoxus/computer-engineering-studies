/* Faça um programa que receba uma temperatura e Celsius, calcule e mostre essa temperatura em
Fahrenheit. Sabe-se que F = 180 * (C + 32) / 100 */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float celsius, fahrenheit;

    // entrada de dados
    printf("Digite o valor em celsius: ");
    scanf("%f", &celsius);

    // processamento
    fahrenheit = (celsius*1.8)+32;

    printf("\nO valor em fahrenheit é: %.2f", fahrenheit);
    return 0;
}