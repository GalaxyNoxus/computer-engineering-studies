/*Faça um programa que receba quatro notas, calcule e mostre a média aritmética das notas e a
mensagem de aprovado ou reprovado, considerando para aprovação média 7.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int calculo(int valor1, int valor2, int valor3, int valor4);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int nota1, nota2, nota3, nota4, media;

    printf("Digite o valor da primeira nota: ");
    scanf("%d", &nota1);
    printf("Digite o valor da segunda nota: ");
    scanf("%d", &nota2);
    printf("Digite o valor da terceira nota: ");
    scanf("%d", &nota3);
    printf("Digite o valor da quarta nota: ");
    scanf("%d", &nota4);
    
    media = calculo(nota1, nota2, nota3, nota4);

    if (media >= 7)
        printf("\n Aprovado com média: %d\n", media);
    else
        printf("\n Reprovado com média: %d\n", media);

    return 0;
}

int calculo(int valor1, int valor2, int valor3, int valor4){
    int valor_final;
    valor_final = (valor1 + valor2 + valor3 + valor4) / 4;

    return valor_final;
}