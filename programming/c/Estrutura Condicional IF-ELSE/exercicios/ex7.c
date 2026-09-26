/*Faça uma algoritmo que leia uma data (dia, mês e ano), verifique e informe se ela é válida.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int dia, mes, ano;

    // entrada de dados
    printf("Digite o dia: ");
    scanf("%f", &dia);
    printf("Digite o mês: ");
    scanf("%f", &mes);
    printf("Digite o ano: ");
    scanf("%f", &ano);

    // processamento
    if (salario < 500){
        salario_final = salario * 1.30;
        printf("\n O seu novo salário é: : %.1f\n", salario_final);
    }else
        printf("\n Você não tem o direito do aumento do salário\n");

    return 0;
}
