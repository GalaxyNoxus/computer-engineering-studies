#include <stdio.h>
#include <locale.h>

int soma(int n);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int numero, resultado;

    printf("Digite um número: ");
    scanf("%d", &numero);

    while (numero>0){
        resultado = soma(numero);

        printf("Soma = %d\n", resultado);
        printf("Digite um numero: ");
        scanf("%d", &numero);

    }
}

int soma(int n) {
    int x, soma = 0;

    for (x = 1; x <= n; x++) {
        soma = soma + x;
    }

    return soma;
}