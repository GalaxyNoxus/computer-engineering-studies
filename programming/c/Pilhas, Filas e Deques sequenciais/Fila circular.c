#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

struct PESSOA
{
    int idade;
    float altura;
    float peso;
    char nome[100];
};

void insercao(struct PESSOA FILA[], int *INICIO, int *FIM, int *QTD);
void remocao(struct PESSOA FILA[], int *INICIO, int *FIM, int *QTD);
void consulta(struct PESSOA FILA[], int INICIO, int QTD);

int main()
{
    struct PESSOA FILA[MAX];

    int INICIO = 0;
    int FIM = 0;
    int QTD = 0;
    int op;

    do
    {
        printf("\n==============================");
        printf("\n       FILA CIRCULAR");
        printf("\n==============================");
        printf("\n1 - Inserir nodo");
        printf("\n2 - Remover nodo");
        printf("\n3 - Consultar fila");
        printf("\n4 - Sair");
        printf("\n\nOpcao: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                insercao(FILA, &INICIO, &FIM, &QTD);
                break;

            case 2:
                remocao(FILA, &INICIO, &FIM, &QTD);
                break;

            case 3:
                consulta(FILA, INICIO, QTD);
                break;

            case 4:
                printf("\nPrograma encerrado!\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while(op != 4);

    return 0;
}


void insercao(struct PESSOA FILA[], int *INICIO, int *FIM, int *QTD)
{
    if(*QTD < MAX)
    {
        printf("\nDigite o nome: ");
        scanf(" %[^\n]", FILA[*FIM].nome);

        printf("Digite a idade: ");
        scanf("%d", &FILA[*FIM].idade);

        printf("Digite a altura: ");
        scanf("%f", &FILA[*FIM].altura);

        printf("Digite o peso: ");
        scanf("%f", &FILA[*FIM].peso);

        *FIM = (*FIM + 1) % MAX;
        (*QTD)++;

        printf("\nPessoa inserida com sucesso!\n");
    }
    else
    {
        printf("\nFila cheia!\n");
    }
}


void remocao(struct PESSOA FILA[], int *INICIO, int *FIM, int *QTD)
{
    if(*QTD > 0)
    {
        printf("\nRemovendo pessoa:\n");
        printf("Nome: %s\n", FILA[*INICIO].nome);
        printf("Idade: %d\n", FILA[*INICIO].idade);
        printf("Altura: %.2f\n", FILA[*INICIO].altura);
        printf("Peso: %.2f\n", FILA[*INICIO].peso);

        *INICIO = (*INICIO + 1) % MAX;
        (*QTD)--;

        printf("\nPessoa removida com sucesso!\n");
    }
    else
    {
        printf("\nFila vazia!\n");
    }
}


void consulta(struct PESSOA FILA[], int INICIO, int QTD)
{
    int i;
    int pos;

    if(QTD > 0)
    {
        printf("\n========== FILA ==========\n");

        pos = INICIO;

        for(i = 0; i < QTD; i++)
        {
            printf("\nPessoa %d:\n", i + 1);
            printf("Nome: %s\n", FILA[pos].nome);
            printf("Idade: %d\n", FILA[pos].idade);
            printf("Altura: %.2f\n", FILA[pos].altura);
            printf("Peso: %.2f\n", FILA[pos].peso);

            pos = (pos + 1) % MAX;
        }

        printf("\n==========================\n");
    }
    else
    {
        printf("\nFila vazia!\n");
    }
}