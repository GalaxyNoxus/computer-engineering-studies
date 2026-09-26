/*Faça um programa que receba o ano de nascimento de uma pessoa e o ano atual, calcule e
mostre:
a) a idade dessa pessoa;
b) quantos anos essa pessoa terá em 2050.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float ano_atual, ano_nascimento, idade, idade_2050;

    // entrada de dados
    printf("Digite o seu ano de nascimento: ");
    scanf("%f", &ano_nascimento);
    printf("Digite o ano atual: ");
    scanf("%f", &ano_atual);

    // processamento
    idade = (ano_atual-ano_nascimento);
    idade_2050 = (2050-ano_nascimento);

    printf("\nSua idade é: %.0f", idade);
    printf("\nVocê vai ter %.0f anos em 2050.", idade_2050);

    return 0;
}