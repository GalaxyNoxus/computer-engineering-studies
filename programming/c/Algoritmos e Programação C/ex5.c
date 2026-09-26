/*Faça um programa que receba o salário de um funcionário e o percentual de aumento, calcule e
mostre o valor do aumento e o novo salário.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float salario, percentual, percentual_final, aumento, salario_final;

    // entrada de dados
    printf("Digite o seu salário: ");
    scanf("%f", &salario);
    printf("Digite o percentual de aumento: ");
    scanf("%f", &percentual);


    // processamento
    percentual_final = (percentual/100);
    aumento = (salario*percentual_final);
    salario_final = (salario+aumento);
    printf("\nSeu salário final é: %.2f", salario_final);

    return 0;
}
