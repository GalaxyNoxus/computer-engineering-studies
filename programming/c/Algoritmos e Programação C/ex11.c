/* João recebeu seu salário e precisa pagar duas contas que estão atrasadas. Como as contas estão
atrasadas, João terá de pagar multa de 2% sobre cada conta. Faça um programa que calcule e mostre
quanto restará do salário do João. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float salario, conta1, conta2, calculo_c1, calculo_c2, salario_final;

    // entrada de dados
    printf("Digite o seu salário: ");
    scanf("%f", &salario);
    printf("Digite o valor da primeira conta: ");
    scanf("%f", &conta1);
    printf("Digite o valora da segunda conta: ");
    scanf("%f", &conta2);

    // processamento
    calculo_c1 = (conta1*0.02) + conta1;
    calculo_c2 = (conta2*0.02) + conta2;
    salario_final = salario - (calculo_c1 + calculo_c2);
    printf("\nO salário final é: %.2f", salario_final);


    return 0;
}
