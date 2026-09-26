/* Faça um programa para calcular e mostrar o salário reajustado de um funcionário. O percentual
de aumento encontra-se na tabela a seguir. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int h1, h2, m1, m2;
    int homem_mais_velho, homem_mais_novo;
    int mulher_mais_velha, mulher_mais_nova;
    int soma, produto;

    printf("Digite a idade do primeiro homem: ");
    scanf("%d", &h1);
    printf("Digite a idade do segundo homem: ");
    scanf("%d", &h2);
    printf("Digite a idade da primeira mulher: ");
    scanf("%d", &m1);
    printf("Digite a idade da segunda mulher: ");
    scanf("%d", &m2);

    if (h1 > h2){
        homem_mais_velho = h1;
        homem_mais_novo = h2;
    }else{
        homem_mais_velho = h2;
        homem_mais_novo = h1;
    }

    if (m1 > m2){
        mulher_mais_velha = m1;
        mulher_mais_nova = m2;
    }else{
        mulher_mais_velha = m2;
        mulher_mais_nova = m1;
    }

    soma = homem_mais_velho + mulher_mais_nova;
    produto = homem_mais_novo * mulher_mais_velha;

    // saida
    printf("\nSoma (%d + %d): %d\n", homem_mais_velho, mulher_mais_nova, soma);
    printf("Produto (%d * %d): %d\n", homem_mais_novo, mulher_mais_velha, produto);

    return 0;
}