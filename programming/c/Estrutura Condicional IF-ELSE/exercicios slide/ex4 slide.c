/*escreva um programa para determinar o tipo de bilhete que cada visitante de um parque de diversoes deve comprar. O tipo de bilhete é determinado em função da idade do visitante, de acordo com a tabela*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int idade;

    // entrada de dados
    printf("Digite sua idade: ");
    scanf("%d", &idade);

    // processamento
    if(idade<6)
        printf("\n Seu bilhete é isento de pagamento\n");
    else if((idade>5)&&(idade<13))
        printf("\n Seu bilhete é de criança\n");
    else if((idade>12)&&(idade<66))
        printf("\n Seu bilhete é normal\n");
    else if(idade>65)
        printf("\n Seu bilhete é de terceira idade\n");
        
    return 0;
}
