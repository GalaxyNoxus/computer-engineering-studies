#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculo (float calculo);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float sal, x;

    printf("Digite o seu salário: ");
    scanf("%f", &sal);

    x = calculo(sal);

    printf("\nSeu salário final é: %.2f", x);

    return 0;
}

float calculo(float salario){
    float salario_receber;
    salario_receber = salario + (salario*0.05) - (salario*0.07);

    return salario_receber;
}
