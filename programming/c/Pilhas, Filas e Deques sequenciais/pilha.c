#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5
#define Base 0
#define Limite MAX - 1

struct pessoa
{
    int idade;
    float altura;
    float peso;
};

void Inserir_nodo(struct pessoa PP[], int *Top);
void Mostrar_Pilha(struct pessoa PP[], int *Top);
void Remover(struct pessoa PP[], int *Top);

int main()
{
    struct pessoa Pilha[MAX];
    int op;
    int Topo = -1;

    do
    {
        printf("\nESCOLHA A OPERAÇÃO DESEJADA");
        printf("\nDigite 1 para inserir nodo na pilha.");
        printf("\nDigite 2 para remover nodo da pilha.");
        printf("\nDigite 3 para exibir a pilha.");
        printf("\nDigite 4 para sair.");
        printf("\n\nOpção: ");
        scanf("%d", &op);

        switch (op)
        {
            case 1:
                Inserir_nodo(Pilha, &Topo);
                break;

            case 2:
                Remover(Pilha, &Topo);
                break;

            case 3:
                Mostrar_Pilha(Pilha, &Topo);
                break;

            case 4:
                printf("\nPrograma encerrado!\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while (op != 4);

    return 0;
}

void Inserir_nodo(struct pessoa PP[], int *Top)
{
    if (*Top < Limite)
    {
        (*Top)++;

        printf("\nDigite a idade: ");
        scanf("%d", &PP[*Top].idade);

        printf("Digite a altura: ");
        scanf("%f", &PP[*Top].altura);

        printf("Digite o peso: ");
        scanf("%f", &PP[*Top].peso);

        printf("\nInserção realizada!\n");
    }
    else
    {
        printf("\nImpossível realizar inserção! Pilha cheia.\n");
    }
}

void Remover(struct pessoa PP[], int *Top)
{
    if (*Top >= Base)
    {
        printf("\nNodo removido da pilha!\n");
        printf("Idade: %d\n", PP[*Top].idade);
        printf("Altura: %.2f\n", PP[*Top].altura);
        printf("Peso: %.2f\n", PP[*Top].peso);

        (*Top)--;
    }
    else
    {
        printf("\nPilha vazia!\n");
    }
}

void Mostrar_Pilha(struct pessoa PP[], int *Top)
{
    int i;

    if (*Top >= Base)
    {
        printf("\n===== PILHA =====\n");

        for (i = *Top; i >= Base; i--)
        {
            printf("\nPessoa %d:\n", i + 1);
            printf("Idade: %d\n", PP[i].idade);
            printf("Altura: %.2f\n", PP[i].altura);
            printf("Peso: %.2f\n", PP[i].peso);
        }
    }
    else
    {
        printf("\nPilha vazia!\n");
    }
}