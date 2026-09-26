/*Ler dois números inteiros e determinar o maior e menor deles.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float numero1, numero2;

    // entrada de dados
    printf("Valor 1: ");
    scanf("%f", &numero1);

    printf("Valor 2: ");
    scanf("%f", &numero2);

    // processamento
    if(numero1==numero2){
        printf("\n Os números são iguais");
        return 0;
        
    }else
        if(numero1>numero2){
            printf("\n%.2f é maior que %.2f", numero1, numero2);
        }else
            printf("\n%.2f é maior que %.2f", numero2, numero1);

    return 0;
}
