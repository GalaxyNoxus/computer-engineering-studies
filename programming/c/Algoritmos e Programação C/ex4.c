/*Faça um programa que receba o salário de um funcionário, calcule e mostre o novo salário,
sabendo-se que este sofreu um aumento de 20%.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float salario, aumento, salario_final;

    // entrada de dados
    printf("Digite o seu salário: ");
    scanf("%f", &salario);

    // processamento
    aumento = (salario*0.20);
    salario_final = (salario+aumento);
    printf("\nSeu salário é: %.2f", salario_final);

    return 0;
}
