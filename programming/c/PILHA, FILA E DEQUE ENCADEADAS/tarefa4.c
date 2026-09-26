
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

int contadorInsercoes = 0;

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


int pilhasIguais(Pilha *p1, Pilha *p2) {
    if (p1->qtd != p2->qtd) {
        return 0;
    }

    Pilha aux1, aux2;
    inicializarPilha(&aux1);
    inicializarPilha(&aux2);

    int iguais = 1;
    int v1, v2;

    while (p1->topo != NULL) {
        desempilhar(p1, &v1);
        desempilhar(p2, &v2);

        if (v1 != v2) {
            iguais = 0;
        }

        empilhar(&aux1, v1);
        empilhar(&aux2, v2);
    }

    while (aux1.topo != NULL) {
        desempilhar(&aux1, &v1);
        desempilhar(&aux2, &v2);
        empilhar(p1, v1);
        empilhar(p2, v2);
    }

    return iguais;
}


void menuInserir(Pilha *p1, Pilha *p2) {
    int opcao, valor;

    printf("\n--- Inserir ---\n");
    printf("1. Inserir na Pilha 1\n");
    printf("2. Inserir na Pilha 2\n");
    printf("Escolha uma opcao: ");
    if (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida!\n");
        return;
    }

    printf("Digite o valor a inserir: ");
    if (scanf("%d", &valor) != 1) {
        printf("Entrada invalida.\n");
        return;
    }

    if (opcao == 1) {
        empilhar(p1, valor);
        contadorInsercoes++;
        printf("%d inserido na Pilha 1.\n", valor);
    } else if (opcao == 2) {
        empilhar(p2, valor);
        contadorInsercoes++;
        printf("%d inserido na Pilha 2.\n", valor);
    } else {
        printf("Opcao invalida.\n");
        return;
    }

    exibirPilha(p1, "Pilha 1");
    exibirPilha(p2, "Pilha 2");
}

int main(void) {
    Pilha P1, P2;
    int opcao;

    inicializarPilha(&P1);
    inicializarPilha(&P2);

    printf("=== Igualdade de Pilhas ===\n");

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Inserir\n");
        printf("2. Verificar igualdade\n");
        printf("3. Sair\n");
        printf("Escolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida.\n");
            break;
        }

        switch (opcao) {
            case 1:
                menuInserir(&P1, &P2);
                break;

            case 2:
                if (pilhasIguais(&P1, &P2)) {
                    printf("\nAs pilhas P1 e P2 SAO IGUAIS.\n");
                } else {
                    printf("\nAs pilhas P1 e P2 NAO SAO IGUAIS.\n");
                }
                exibirPilha(&P1, "Pilha 1");
                exibirPilha(&P2, "Pilha 2");
                break;

            case 3:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 3);

    printf("\nTotal de insercoes realizadas: %d\n", contadorInsercoes);

    liberarPilha(&P1);
    liberarPilha(&P2);

    return 0;
}
