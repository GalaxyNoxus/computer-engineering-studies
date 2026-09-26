/*escreva um programa para determinar se o numero é par ou impar.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float numero;

    // entrada de dados
    printf("Insira o número: ");
    scanf("%f", &numero);

    // processamento
    if(numero%2==0) // se número mod 2 for igual a zero. mod é o resto da divisão
        printf("\n O número é par");   
    else
        printf("\n O número é impar");
    return 0;
}
