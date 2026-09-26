/* Sabe-se que para iluminar de maneira correta os cômodos de uma casa, para cada m2, deve-se
usar 18W de potência. Faça um programa que receba as duas dimensões de um cômodo (em
metros), calcule e mostre a sua área (em m2) e a potência de iluminação que deverá ser utilizada. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculo(float dim1, float dim2);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float dimensao1, dimensao2, watts, dimensao_total;

    printf("Digite o valor da primeira largura do cômodo: ");
    scanf("%f", &dimensao1);
    printf("Digite o valor da segunda largura do cômodo: ");
    scanf("%f", &dimensao2);

    calculo(dimensao1, dimensao2);

    return 0;
}

float calculo(float dim1, float dim2){
    float watts, dimensao_total;

    watts = (dim1*dim2)*18;
    dimensao_total = (dim1*dim2);

    printf("\nDeve se usar %.2fW para iluminar este cômodo com %.2f metros quadrados", watts, dimensao_total);
}