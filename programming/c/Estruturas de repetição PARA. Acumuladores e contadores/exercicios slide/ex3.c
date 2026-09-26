
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculo(int N);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int numero;
    float resultado;

    printf("Digite um número inteiro: ");
    scanf("%d", &numero);

    resultado = calculo(numero);
    printf("Resultado: %.2f", resultado);

    return 0;
}

float calculo(int N){
    int X;
    float H=0;

    for (X = 1; X <= N; X++){
        H = H + 1/X;
    }

    return H;
}

