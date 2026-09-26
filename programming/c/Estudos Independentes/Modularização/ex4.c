

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculo(float sal);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    float salario, salario_final;

    printf("Digite o seu salário: ");
    scanf("%f", &salario);

    salario_final = calculo(salario);
    printf("\n O seu novo salário é: : %.1f\n", salario_final);
    
    return 0;
}

float calculo(float sal){
    float salario_final;
    if (sal <= 300){
        salario_final = sal * 1.35;
    }else{
        salario_final = sal * 1.15;
    }

    return salario_final;
}