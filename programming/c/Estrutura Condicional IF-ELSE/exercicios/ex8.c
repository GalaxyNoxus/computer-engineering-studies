/*

Faça um algoritmo que lê um código (1, 2, 3 ou 4) e dois valores do tipo inteiro, calcula e
fornece:
– A adição dos números para código =1
– A subtração dos números para código =2
– A multiplicação dos números para código =3
– A divisão dos números para código = 4.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int num_codigo;
    float valor1, valor2, resultado;

    printf("Digite o primeiro valor: ");
    scanf("%f", &valor1);
    printf("Digite o segundo valor: ");
    scanf("%f", &valor2);
    printf("Digite o número do código (1,2,3,4): \n\nA adição dos números para código = 1\nA subtração dos números para código = 2\nA multiplicação dos números para código = 3 \nA divisão dos números para código = 4\n");
    scanf("%d", &num_codigo);

    if(num_codigo=1)
        resultado = (valor1 + valor2);
    else if(num_codigo=2)
        resultado = (valor1 - valor2);
    else if(num_codigo=3)
        resultado = (valor1 * valor2);
    else if(num_codigo=4)
        resultado = (valor1 / valor2);
    else 
        printf("Código inválido");
        
    printf("\nResultado: %.2f", resultado);

    return 0;
}