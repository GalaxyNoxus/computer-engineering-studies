/* João recebeu seu salário e precisa pagar duas contas que estão atrasadas. Como as contas estão
atrasadas, João terá de pagar multa de 2% sobre cada conta. Faça um programa que calcule e mostre
quanto restará do salário do João. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculo(float sal, float cont1, float cont2);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float salario, conta1, conta2, salario_final;

    printf("Digite o seu salário: ");
    scanf("%f", &salario);
    printf("Digite o valor da primeira conta: ");
    scanf("%f", &conta1);
    printf("Digite o valora da segunda conta: ");
    scanf("%f", &conta2);

    salario_final = calculo(salario, conta1, conta2);
    printf("\nO salário final é: %.2f", salario_final);

    return 0;
}

float calculo(float sal, float cont1, float cont2) {
    float sal_final, calculo_c1, calculo_c2;
    calculo_c1 = (cont1*0.02) + cont1;
    calculo_c2 = (cont2*0.02) + cont2;
    sal_final = sal - (calculo_c1 + calculo_c2);
    return sal_final;
}