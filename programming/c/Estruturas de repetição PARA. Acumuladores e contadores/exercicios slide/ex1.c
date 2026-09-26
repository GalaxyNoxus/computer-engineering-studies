
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void funcao(int num);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int numero;

    printf("Digite um número: ");
    scanf("%d", &numero);

    funcao(numero);

    return 0;
}

void funcao(int num){
    int x, r;
    for (x = 1; x <= 10; x++)
    {
        r = num * x;
        printf("\n%d * %d = %d", num, x, r);

    }
    printf("\n");
}