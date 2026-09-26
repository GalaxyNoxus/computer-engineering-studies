/*Ler um valor e escrever se é positivo, negativo ou zero*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int valor;

    // entrada de dados
    printf("Digite o valor: ");
    scanf("%d", &valor);

    // processamento
    if(valor > 0)
        printf("\n%d é Positivo\n", valor);
    else if(valor < 0)
        printf("\n%d é Negativo\n", valor);
    else if(valor = 0)
        printf("\nO número fornecido é zero\n");

    return 0;
}
