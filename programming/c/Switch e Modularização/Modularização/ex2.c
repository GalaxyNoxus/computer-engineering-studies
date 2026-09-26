#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculo(float diag_ma, float diag_me);

int main()
{
    float diagonal_maior, diagonal_menor, resultado;

    printf("Digite o valor da diagonal maior: ");
    scanf("%f", &diagonal_maior);
    printf("Digite o valor da diagonal menor: ");
    scanf("%f", &diagonal_menor);

    resultado = calculo(diagonal_maior, diagonal_menor);
    printf("\nSeu salário final é: %.2f", resultado);

    return 0;
}

float calculo(float diag_ma, float diag_me){
    float result;
    result = (diag_ma * diag_me) / 2;

    return result;
}
