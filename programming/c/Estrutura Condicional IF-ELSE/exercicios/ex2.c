/*Faça um programa que receba quatro notas, calcule e mostre a média aritmética das notas e a
mensagem de aprovado ou reprovado, considerando para aprovação média 7.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float nota1, nota2, nota3, nota4, media;

    // entrada de dados
    printf("Digite o valor da primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite o valor da segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite o valor da terceira nota: ");
    scanf("%f", &nota3);
    printf("Digite o valor da quarta nota: ");
    scanf("%f", &nota4);
    
    // processamento
    media = (nota1 + nota2 + nota3 + nota4) / 4;

    // saida
    if (media >= 7)
        printf("\n Aprovado com média: %.1f\n", media);
    else
        printf("\n Reprovado com média: %.1f\n", media);

    return 0;
}
