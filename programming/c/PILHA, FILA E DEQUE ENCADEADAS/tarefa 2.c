#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct FILA{
    int info;
    struct FILA *prox;
}FILA;

typedef struct Descritor {
    FILA* inicio;
    FILA* fim;
} PTDfila;

void inserir(PTDfila **Ptd){
    FILA *ptnovo;
    int dados;

    ptnovo = (FILA*)malloc(sizeof(FILA*));

    printf("\nDigite o valor que deseja inserir: ");
    scanf("%d", &dados);

    ptnovo->info = dados;
    ptnovo->prox = NULL;

    if((*Ptd)->inicio == NULL){
        (*Ptd)->inicio = ptnovo;
    } else {
        (*Ptd)->fim = ptnovo;
    }

    (*Ptd)->fim = ptnovo;

    printf("Valor Inserido!\n");
}

void remover(PTDfila **PtD){
    FILA **ptaux;

    if((*PtD)->inicio == NULL){
        printf("Fila Vazia...\n");
        return;
    }

    *ptaux = (*PtD)->inicio;
    (*PtD)->inicio = (*ptaux)->prox;
    free(*ptaux);

    if((*PtD)->inicio == NULL){
        (*PtD)->fim = NULL;
    }

}

void consultar(PTDfila **PtD){

    if((*PtD)->inicio == NULL){
        printf("Fila Vazia...\n");
        return;
    }

    printf("Valor do Inicio da Fila: %d\n", (*PtD)->inicio->info);
}

int main()
{
    setlocale(LC_ALL,"Portuguese");

    PTDfila *PtD = (PTDfila*)malloc(sizeof(PTDfila));
    PtD->inicio=NULL;
    PtD->fim=NULL;

    int op;

    do{
        printf("\n--- FILA ENCADEADA ---");
        printf("\nEscolha uma op��o: ");
        printf("\n1. Inserir nodo");
        printf("\n2. Remover nodo");
        printf("\n3. Consultar nodo");
        printf("\n4. Sair");
        printf("\nOpção: ");
        scanf("%d",&op);

        switch(op){
        case 1:
            inserir(&PtD);
            break;
        case 2:
            remover(&PtD);
            break;
        case 3:
            consultar(&PtD);
            break;
        case 4:
            printf("Saindo...");
            break;
        }
    }while(op!=4);
}