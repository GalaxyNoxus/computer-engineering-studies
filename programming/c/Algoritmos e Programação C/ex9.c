/*Faça um programa que receba o ano de nascimento de uma pessoa e o ano atual, calcule e
mostre:
a) a idade dessa pessoa em anos;
b) a idade dessa pessoa em meses;
c) a idade dessa pessoa em dias;
d) a idade dessa pessoa em semanas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float ano_atual, ano_nascimento, idade, idade_meses, idade_dias, idade_semanas;

    // entrada de dados
    printf("Digite o seu ano de nascimento: ");
    scanf("%f", &ano_nascimento);
    printf("Digite o ano atual: ");
    scanf("%f", &ano_atual);

    // processamento
    idade = (ano_atual-ano_nascimento);
    idade_meses = (idade*12);
    idade_semanas = (idade_meses*4);
    idade_dias = (idade_meses*30);

    printf("\nIdade: %.0f", idade);
    printf("\nIdade em mêses: %.0f", idade_meses);
    printf("\nIdade em semanas: %.0f", idade_semanas);
    printf("\nidade em dias: %.0f", idade_dias);

    return 0;
}