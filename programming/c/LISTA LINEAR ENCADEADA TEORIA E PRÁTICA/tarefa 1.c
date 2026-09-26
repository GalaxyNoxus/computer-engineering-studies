#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct LISTA
{
    int info;
    struct LISTA *elo;
} LISTA;

void inserir(LISTA **PtLista, int *count);
void remover(LISTA **PtLista, int *count);
void consultar(LISTA **PtLista);
void mostra_lista(LISTA **PtLista);

int main() {
    setlocale(LC_ALL, "Portuguese");

    LISTA *PtLista;
    int op, count;

    PtLista = NULL;
    count = 0;

    do {
        printf("\n===================================");
        printf("\nEscolha a opcao desejada:");
        printf("\n1. Inserir um valor na Lista");
        printf("\n2. Remover um valor da Lista");
        printf("\n3. Consultar um valor na Lista (por posicao K)");
        printf("\n4. Mostrar a Lista Linear Encadeada");
        printf("\n5. Sair");
        printf("\n===================================");
        printf("\nOpcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                inserir(&PtLista, &count);
                break;
            case 2:
                remover(&PtLista, &count);
                break;
            case 3:
                consultar(&PtLista);
                break;
            case 4:
                mostra_lista(&PtLista);
                break;
            case 5:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(op != 10);

    LISTA *tmp;
    while(PtLista != NULL) {
        tmp = PtLista;
        PtLista = PtLista->elo;
        free(tmp);
    }

    return 0;
}

void inserir(LISTA **PtLista, int *count) {
    LISTA *PtNovo, *PtAnt;
    int K, dados;

    printf("\nDigite o valor que deseja inserir: ");
    scanf("%d", &dados);
    printf("\nDigite em qual posicao deseja inserir: ");
    scanf("%d", &K);

    PtNovo = (LISTA*)malloc(sizeof(LISTA));

    if(PtNovo == NULL) {
        printf("\nNao foi possivel alocar memoria!\n");
        return;
    }
    else if(((*PtLista == NULL) && (K != 1)) || (K < 1)) {
        free(PtNovo);
        printf("\nNao e possivel inserir! (valor de K invalido)\n");
    }
    else if(K == 1) {
        PtNovo->info = dados;
        PtNovo->elo = *PtLista;
        *PtLista = PtNovo;
        (*count)++;
        printf("\nInserido com sucesso!\n");
    }
    else {
        PtAnt = *PtLista;
        while((PtAnt->elo != NULL) && (K > 2)) {
            PtAnt = PtAnt->elo;
            K--;
        }
        if(K > 2) {
            free(PtNovo);
            printf("\nNao e possivel inserir!\n");
        } else {
            PtNovo->info = dados;
            PtNovo->elo = PtAnt->elo;
            PtAnt->elo = PtNovo;
            (*count)++;
            printf("\nInserido com sucesso!\n");
        }
    }
}

void remover(LISTA **PtLista, int *count) {
    LISTA *PtAnt, *PtK;
    int K;

    printf("\nDigite qual posicao deseja remover: ");
    scanf("%d", &K);

    if(K < 1 || *PtLista == NULL) {
        printf("\nNao e possivel remover!\n");
        return;
    }

    PtK = *PtLista;
    PtAnt = NULL;

    while(PtK != NULL && K > 1) {
        K--;
        PtAnt = PtK;
        PtK = PtK->elo;
    }

    if(PtK == NULL) {
        printf("\nNao e possivel remover!\n");
    }
    else {
        if(PtAnt == NULL)
            *PtLista = PtK->elo;
        else
            PtAnt->elo = PtK->elo;

        free(PtK);
        (*count)--;
        printf("\nRemovido com sucesso!\n");
    }
}

void consultar(LISTA **PtLista) {
    LISTA *PtK;
    int K, pos;

    printf("\nDigite a posicao que deseja consultar: ");
    scanf("%d", &K);

    if(K < 1 || *PtLista == NULL) {
        printf("\nPosicao invalida ou lista vazia!\n");
        return;
    }

    PtK = *PtLista;
    pos = K;

    while(PtK != NULL && K > 1) {
        K--;
        PtK = PtK->elo;
    }

    if(K > 1)
        printf("\nPosicao nao encontrada!\n");
    else
        printf("\nValor na posicao %d: %d\n", pos, PtK->info);
}

void mostra_lista(LISTA **PtLista) {
    LISTA *PtAtual;

    printf("\nLISTA LINEAR ENCADEADA\n");

    if(*PtLista == NULL) {
        printf("A lista esta vazia!\n");
        return;
    }

    PtAtual = *PtLista;
    while(PtAtual != NULL) {
        printf("%d\t", PtAtual->info);
        PtAtual = PtAtual->elo;
    }
    printf("\n");
}