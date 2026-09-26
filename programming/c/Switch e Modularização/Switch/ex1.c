#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int item, quantidade;
    float resultado;

    printf(" \n Escolha uma das opções abaixo: ");
    printf(" \n 100. \tCachorro quente\t\tR$3,50 ");
    printf(" \n 101. \tauru simples\t\tR$4,00 ");
    printf(" \n 102. \tBauru c/ovo\t\tR$4,50 ");
    printf(" \n 103. \tHamburguer\t\tR$4,00 ");
    printf(" \n 104. \tCheeseburger\t\tR$3,00 ");

    printf(" \n\n Digite o número da opção desejada: ");
    scanf("%d", &item);

    // Switch
    switch (item)
        {
        case 100:
            printf(" \n Opção selecionada: 100. Cachorro quente ");
            printf(" \n Digite a quantidade desejada: ");
            scanf("%d", &quantidade);
            resultado = 3.50 * quantidade;
            break;
        case 101:
            printf(" \n Opção selecionada: 101. Bauru simples ");
            printf(" \n Digite a quantidade desejada: ");
            scanf("%d", &quantidade);
            resultado = 4 * quantidade;
            break;
        case 102:
            printf(" \n Opção selecionada: 102. Bauru c/ovo ");
            printf(" \n Digite a quantidade desejada: ");
            scanf("%d", &quantidade);
            resultado = 4.50 * quantidade;
            break;
        case 103:
            printf(" \n Opção selecionada: 103. Hamburguer ");
            printf(" \n Digite a quantidade desejada: ");
            scanf("%d", &quantidade);
            resultado = 4 * quantidade;
            break;
        case 104:
            printf(" \n Opção selecionada: 103. Cheeseburguer ");
            printf(" \n Digite a quantidade desejada: ");
            scanf("%d", &quantidade);
            resultado = 3 * quantidade;
            break;
        
        default: printf("Erro!");
        }

    printf(" \n O valor total do pedido é: R$%.2f ", resultado);
    return 0;
}