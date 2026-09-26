#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int numero, menor, soma_1=0, soma_2=0, media, i=0;

    printf("Digite um número: ");
    scanf("%d", &numero);
    menor = numero;

    while (numero!=0){

        if(numero>=10 && numero<=20)
        soma_1 = soma_1 + numero;

        if(numero>=1 && numero<=10){
        i++;
        soma_2 = soma_2 + numero;
        }

        if(numero<menor)
        menor = numero;

        printf("Digite um número: ");
        scanf("%d", &numero);
    }

    media = soma_2 / i;
    printf("A soma dos números que estão no intervalo 10(inc) a 20(inc) é: %d", soma_1);
    printf("\nA média dos números que estão no intervalo de 1(inc) a 10 (exc) é: %d", media);
    printf("\no menor entre os valores lidos é: %d", menor);
}
