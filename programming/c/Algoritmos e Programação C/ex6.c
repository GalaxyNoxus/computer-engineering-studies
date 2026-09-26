/*Faça um programa que receba o salário-base de um funcionário, calcule e mostre o salário a
receber, sabendo-se que esse funcionário tem gratificação de 5% sobre o salário-base e paga
imposto de 7% sobre o salário-base.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float salario, aumento, imposto, salario_final;

    // entrada de dados
    printf("Digite o seu salário: ");
    scanf("%f", &salario);

    // processamento
    aumento = (salario*0.05);
    imposto = (salario*0.07);

    salario_final = (imposto+aumento);
    printf("\nSeu salário final é: %.2f", salario_final);

    return 0;
}
