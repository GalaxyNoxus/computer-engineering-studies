#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct pilha
{
    int info;
    struct pilha *elo;
} pilha;

void inserir(pilha **ptpilha) {
    pilha *ptnovo;
    int dados;

    printf("\nDigite o valor que deseja inserir: ");
    scanf("%d", &dados);

    ptnovo = (pilha*)malloc(sizeof(pilha));

    if(ptnovo == NULL) {
        printf("\nNao foi possivel alocar memoria!\n");
        return;
    }   

    ptnovo->info = dados;
    ptnovo->elo = *ptpilha;
    *ptpilha = ptnovo;

    printf("Valor Inserido!\n");
}

void remover(pilha **ptpilha){
    pilha *ptaux;

    if(*ptpilha == NULL){
        printf("A pilha já está vazia...");
        return;
    }

    ptaux = *ptpilha;
    *ptpilha = (*ptpilha)->elo;
    free(ptaux);
    printf("\nRemovido um nodo do topo da pilha!\n");
}

void consulta(pilha **ptpilha){
    
    if(*ptpilha == NULL){
        printf("A pilha está vazia...\n");
        return;
    }

    printf("Valor do topo: %d\n", (*ptpilha)->info);
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    pilha *ptpilha;
    int op, count;

    ptpilha = NULL;
    count = 0;

    do {
        printf("\n===================================");
        printf("\nEscolha a opcao desejada:");
        printf("\n1. Inserir um valor na Fila");
        printf("\n2. Remover um valor da Fila");
        printf("\n3. Consultar o topo da Lista");
        printf("\n4. Sair");
        printf("\n===================================");
        printf("\nOpcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                inserir(&ptpilha);
                break;
            case 2:
                remover(&ptpilha);
                break;
            case 3:
                consulta(&ptpilha);
                break;
            case 4:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(op != 4);

    return 0;
}