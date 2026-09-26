/* Faça um programa para calcular e mostrar o salário reajustado de um funcionário. O percentual
de aumento encontra-se na tabela a seguir. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float salario, salario_final, aumento;

    // entrada de dados
    printf("Digite o seu salário: ");
    scanf("%f", &salario);

    // processamento
    if (salario <= 300){
        aumento = salario * 0.35;
        salario_final = aumento + salario;
        printf("\n O seu novo salário é: : %.1f\n", salario_final);
        
    }else if{
        aumento = salario * 0.15;
        salario_final = aumento + salario;
        printf("\n O seu novo salário é: : %.1f\n", salario_final);
    }
    return 0;
}