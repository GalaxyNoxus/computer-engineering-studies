/*Uma empresa decide dar um aumento de 30% aos funcionários com salários inferiores a R$
500,00. Faça um programa que receba o salário do funcionário e mostre o valor do salário
reajustado ou uma mensagem, caso ele não tenha direito ao aumento.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float salario, salario_final;

    // entrada de dados
    printf("Digite o seu salário: ");
    scanf("%f", &salario);

    // processamento
    if (salario < 500){
        salario_final = salario * 1.30;
        printf("\n O seu novo salário é: : %.1f\n", salario_final);
    }else
        printf("\n Você não tem o direito do aumento do salário\n");

    return 0;
}
