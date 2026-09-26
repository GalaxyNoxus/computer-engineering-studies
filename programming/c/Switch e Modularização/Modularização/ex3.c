#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float conversao(float val);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float valor;

    printf("Digite o valor em reais: ");
    scanf("%f", &valor);
    conversao(valor);

    return 0;
}

float conversao(float val){

    float dolar, euro, libras;

    dolar = (val/4.96);
    euro = (val/5.38);
    libras = (val/6,29);

    printf("\nValores convertidos:");
    printf("\n  $%.2f Dólares", dolar);
    printf("\n  €%.2f Euros", euro);
    printf("\n  £%.2f Libras esterlinas", libras);
}