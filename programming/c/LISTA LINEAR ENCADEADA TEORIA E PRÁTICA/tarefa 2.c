#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct LISTA
{
    int info;
    struct LISTA *elo;
} LISTA;

void inserir(LISTA **PtLista, int *cont);
void remover(LISTA **PtLista, int *cont);
void consultar(LISTA **PtLista);
void mostra_lista(LISTA **PtLista);
int conta_nodos(LISTA **PtLista);
void verifica_ocorrencias(LISTA **PtLista);
void maior_valor(LISTA **PtLista);
void menor_valor(LISTA **PtLista);

int main() {
    setlocale(LC_ALL, "Portuguese");

    LISTA *PtLista;
    int op, cont = 0;

    PtLista = NULL;

    do {
        printf("\n===================================");
        printf("\nEscolha a opcao desejada:");
        printf("\n1. Inserir um valor na Lista");
        printf("\n2. Remover um valor da Lista");
        printf("\n3. Consultar um valor na Lista (por posicao K)");
        printf("\n4. Mostrar a Lista Linear Encadeada");
        printf("\n5. Mostrar o numero total de nodos da Lista");
        printf("\n6. Verificar quantas vezes um valor aparece na Lista");
        printf("\n7. Mostrar o maior valor armazenado na Lista");
        printf("\n8. Mostrar o menor valor armazenado na Lista");
        printf("\n9. Sair");
        printf("\n===================================");
        printf("\nOpcao: ");
        scanf("%d", &op);

        switch(op) {
            case 1:
                inserir(&PtLista, &cont);
                break;
            case 2:
                remover(&PtLista, &cont);
                break;
            case 3:
                consultar(&PtLista);
                break;
            case 4:
                mostra_lista(&PtLista);
                break;
            case 5:
                printf("\nNumero total de nodos na Lista: %d\n", conta_nodos(&PtLista));
                break;
            case 6:
                verifica_ocorrencias(&PtLista);
                break;
            case 7:
                maior_valor(&PtLista);
                break;
            case 8:
                menor_valor(&PtLista);
                break;
            case 9:
                printf("\nSaindo...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while(op != 9);

    return 0;
}

void inserir(LISTA **PtLista, int *cont) {
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
        (*cont)++;
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
            (*cont)++;
            printf("\nInserido com sucesso!\n");
        }
    }
}

void remover(LISTA **PtLista, int *cont) {
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
        (*cont)--;
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

int conta_nodos(LISTA **PtLista) {
    LISTA *PtAtual = *PtLista;
    int total = 0;

    while(PtAtual != NULL) {
        total++;
        PtAtual = PtAtual->elo;
    }

    return total;
}

void verifica_ocorrencias(LISTA **PtLista) {
    LISTA *PtAtual = *PtLista;
    int valor, pos = 1, ocorrencias = 0;

    if(PtAtual == NULL) {
        printf("\nA lista esta vazia!\n");
        return;
    }

    printf("\nDigite o valor que deseja verificar: ");
    scanf("%d", &valor);

    printf("\nPosicoes em que o valor %d aparece: ", valor);
    while(PtAtual != NULL) {
        if(PtAtual->info == valor) {
            printf("%d ", pos);
            ocorrencias++;
        }
        pos++;
        PtAtual = PtAtual->elo;
    }

    if(ocorrencias == 0)
        printf("\nO valor %d nao foi encontrado na Lista.\n", valor);
    else
        printf("\nO valor %d aparece %d vez(es) na Lista.\n", valor, ocorrencias);
}

void maior_valor(LISTA **PtLista) {
    LISTA *PtAtual = *PtLista;
    int maior;

    if(PtAtual == NULL) {
        printf("\nA lista esta vazia!\n");
        return;
    }

    maior = PtAtual->info;
    PtAtual = PtAtual->elo;

    while(PtAtual != NULL) {
        if(PtAtual->info > maior)
            maior = PtAtual->info;
        PtAtual = PtAtual->elo;
    }

    printf("\nO maior valor armazenado na Lista e: %d\n", maior);
}

void menor_valor(LISTA **PtLista) {
    LISTA *PtAtual = *PtLista;
    int menor;

    if(PtAtual == NULL) {
        printf("\nA lista esta vazia!\n");
        return;
    }

    menor = PtAtual->info;
    PtAtual = PtAtual->elo;

    while(PtAtual != NULL) {
        if(PtAtual->info < menor)
            menor = PtAtual->info;
        PtAtual = PtAtual->elo;
    }

    printf("\nO menor valor armazenado na Lista e: %d\n", menor);
}