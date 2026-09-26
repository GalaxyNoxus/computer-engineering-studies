/*Faça um programa que receba a quantidade de dinheiro em reais e converta esse valor em dólar,
euro e libras esterlinas. Sabe-se que a cotação do dólar é de R$ 4,96, do euro é de R$ 5,38 e da libra
esterlina é de R$ 6,29. O programa deve fazer as conversões e mostrá-las.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float valor, dolar, euro, libras;

    // entrada de dados
    printf("Digite o valor em reais: ");
    scanf("%f", &valor);

    // processamento
    dolar = (valor/4.96);
    euro = (valor/5.38);
    libras = (valor/6,29);

    printf("\nValores convertidos:");
    printf("\n  $%.2f Dólares", dolar);
    printf("\n  €%.2f Euros", euro);
    printf("\n  £%.2f Libras esterlinas", libras);

    return 0;
}
