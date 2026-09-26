
#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *prox;
} Nodo;

typedef struct {
    Nodo *topo;
    int qtd;
} Pilha;


void inicializarPilha(Pilha *p) {
    p->topo = NULL;
    p->qtd = 0;
}

void empilhar(Pilha *p, int valor) {
    Nodo *novo = (Nodo *) malloc(sizeof(Nodo));
    if (novo == NULL) {
        printf("Erro de alocacao de memoria!\n");
        exit(1);
    }
    novo->valor = valor;
    novo->prox = p->topo;
    p->topo = novo;
    p->qtd++;
}

int desempilhar(Pilha *p, int *valorRemovido) {
    if (p->topo == NULL) {
        return 0;
    }
    Nodo *aux = p->topo;
    *valorRemovido = aux->valor;
    p->topo = aux->prox;
    free(aux);
    p->qtd--;
    return 1;
}

void exibirPilha(Pilha *p, const char *nome) {
    printf("%s (qtd=%d): ", nome, p->qtd);
    Nodo *atual = p->topo;
    if (atual == NULL) {
        printf("[vazia]");
    }
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

void liberarPilha(Pilha *p) {
    int lixo;
    while (desempilhar(p, &lixo)) {

    }
}


void tratarNegativo(Pilha *par, Pilha *impar) {
    int removido;

    if (par->qtd == 0 && impar->qtd == 0) {
        printf("As duas pilhas estao vazias...\n");
        return;
    }

    if (par->qtd > impar->qtd) {
        if (desempilhar(par, &removido))
            printf("Removido %d da PILHA_PAR\n", removido);
    } else if (impar->qtd > par->qtd) {
        if (desempilhar(impar, &removido))
            printf("Removido %d da PILHA_IMPAR\n", removido);
    } else {

        if (desempilhar(par, &removido))
            printf("Removido %d da PILHA_PAR\n", removido);
        if (desempilhar(impar, &removido))
            printf("Removido %d da PILHA_IMPAR\n", removido);
    }
}


int main(void) {
    Pilha PILHA_PAR, PILHA_IMPAR;
    int numero;

    inicializarPilha(&PILHA_PAR);
    inicializarPilha(&PILHA_IMPAR);

    printf("=== TAREFA 3 - Pilhas de pares e impares ===\n");
    printf("Digite numeros inteiros (0 para encerrar):\n");
    printf("Numeros negativos removem um nodo da pilha com mais elementos.\n\n");

    while (1) {
        printf("Digite um numero: ");
        if (scanf("%d", &numero) != 1) {
            printf("Entrada invalida.\n");
            break;
        }

        if (numero == 0) {
            break;
        } else if (numero < 0) {
            tratarNegativo(&PILHA_PAR, &PILHA_IMPAR);
        } else if (numero % 2 == 0) {
            empilhar(&PILHA_PAR, numero);
            printf("%d inserido na PILHA PAR.\n", numero);
        } else {
            empilhar(&PILHA_IMPAR, numero);
            printf("%d inserido na PILHA IMPAR.\n", numero);
        }

        exibirPilha(&PILHA_PAR, "PILHA PAR");
        exibirPilha(&PILHA_IMPAR, "PILHA IMPAR");
        printf("\n");
    }

    printf("\n=== Estado final das pilhas ===\n");
    exibirPilha(&PILHA_PAR, "PILHA PAR");
    exibirPilha(&PILHA_IMPAR, "PILHA IMPAR");

    liberarPilha(&PILHA_PAR);
    liberarPilha(&PILHA_IMPAR);

    return 0;
}
