/* Sabe-se que para iluminar de maneira correta os cômodos de uma casa, para cada m2, deve-se
usar 18W de potência. Faça um programa que receba as duas dimensões de um cômodo (em
metros), calcule e mostre a sua área (em m2) e a potência de iluminação que deverá ser utilizada. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculo(float name, float horas_trab, float num_filhos, float sal);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float codigo_funcionario, horas_trabalahadas, filhos, salario;

    printf("Digite o código do do funcionário: ");
    scanf("%f", &codigo_funcionario);
    printf("Digite o salário do funcionário: ");
    scanf("%f", &salario);
    printf("Digite a quantidade de horas trabalhadas: ");
    scanf("%f", &horas_trabalahadas);
    printf("Digite o número de filhos (menores de 18 anos) do funcionario: ");
    scanf("%f", &filhos);

    calculo(codigo_funcionario, horas_trabalahadas, filhos, salario);

    return 0;
}

float calculo(float cod_funcionario, float horas_trab, float num_filhos, float sal){
    float salario_final, horas, filhos;

    horas = 10 * horas_trab;
    filhos = 50 * num_filhos;
    
    salario_final = (sal + horas + filhos) - (sal * 0.09);
    printf("\nO funcionário Cod.%.0f recebera um salário final de RS%.2f", cod_funcionario, salario_final);
}