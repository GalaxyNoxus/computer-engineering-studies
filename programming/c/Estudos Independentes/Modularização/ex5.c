

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculo(float valor, int parcel);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    float preco, total, prestacao;
    int parcelas;

    printf("Digite o preço a vista do produto: ");
    scanf("%f", &preco);
    printf("Digite o numero de parcelas (3 ou 5): ");
    scanf("%d", &parcelas);
    
    total = calculo(preco, parcelas);
    prestacao = total / parcelas;

    printf("\nTotal a pagar: R$ %.2f\n", total);
    printf("Valor de cada prestacao: R$ %.2f\n", prestacao);
    
    return 0;
}

float calculo(float valor, int parcel){
    float valor_final;

    if (parcel == 3)
        valor_final = valor * 1.10;
    else if (parcel == 5)
        valor_final = valor * 1.20;
    else
        printf("Numero de parcelas invalido!\n");
    
    return valor_final;
}