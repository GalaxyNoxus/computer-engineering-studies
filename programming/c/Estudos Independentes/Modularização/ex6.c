

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void processamento(int homen1, int homen2, int mulher1, int mulher2);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int h1, h2, m1, m2;

    printf("Digite a idade do primeiro homem: ");
    scanf("%d", &h1);
    printf("Digite a idade do segundo homem: ");
    scanf("%d", &h2);
    printf("Digite a idade da primeira mulher: ");
    scanf("%d", &m1);
    printf("Digite a idade da segunda mulher: ");
    scanf("%d", &m2);

    processamento(h1, h2, m1, m2);

    return 0;
}

void processamento(int homen1, int homen2, int mulher1, int mulher2){
    int homem_mais_velho, homem_mais_novo;
    int mulher_mais_velha, mulher_mais_nova;
    int soma, produto;

        if (homen1 > homen2){
        homem_mais_velho = homen1;
        homem_mais_novo = homen2;
    }else{
        homem_mais_velho = homen2;
        homem_mais_novo = homen1;
    }

    if (mulher1 > mulher2){
        mulher_mais_velha = mulher1;
        mulher_mais_nova = mulher2;
    }else{
        mulher_mais_velha = mulher2;
        mulher_mais_nova = mulher1;
    }

    soma = homem_mais_velho + mulher_mais_nova;
    produto = homem_mais_novo * mulher_mais_velha;

    
    printf("\nSoma (%d + %d)= %d\n", homem_mais_velho, mulher_mais_nova, soma);
    printf("Produto (%d * %d)= %d\n", homem_mais_novo, mulher_mais_velha, produto);

}