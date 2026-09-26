/*escreva um programa que leia dois numeros inteiros e apresente a sua soma se ambos forem pares e o produto se um ou ambos forem impares.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int numero1, numero2, soma, produto;

    // entrada de dados
    printf("Insira o primeiro número: ");
    scanf("%d", &numero1);
    printf("Insira o segundo número número: ");
    scanf("%d", &numero2);

    // processamento
    if((numero1%2==0)&&(numero2%2==0)){
        soma = numero1 + numero2;
        printf("\n A soma é: %d\n", soma);

    }else{
        produto = numero1 * numero2;
        printf("\n O valor do produto é %d\n", produto);

    }return 0;
}
