/*Ler um valor e escrever se é positivo, negativo ou zero*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void calculo(int val);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int valor;

    printf("Digite o valor: ");
    scanf("%d", &valor);

    calculo(valor);

    return 0;
}

void calculo(int val){

    if(val > 0)
        printf("\n%d é Positivo\n", val);
    else if(val < 0)
        printf("\n%d é Negativo\n", val);
    else if(val = 0)
        printf("\nO número fornecido é zero\n");

}