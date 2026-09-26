#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct CONTA
{
    int num_conta;
    float saldo;
    struct CONTA *prox;
} CONTA;

void inserir(CONTA **PtLista, int *cont);
void remover(CONTA **PtLista, int *cont);
void consultar(CONTA **PtLista);
void mostra_lista(CONTA **PtLista);
int conta_nodos(CONTA **PtLista);
void verifica_ocorrencias(CONTA **PtLista);
void maior_saldo(CONTA **PtLista);
void menor_saldo(CONTA **PtLista);

int main() {
    setlocale(LC_ALL, "Portuguese");

    CONTA *PtLista;
    int op, cont = 0;

    PtLista = NULL;

    do {
        printf("\n===================================");
        printf("\nEscolha a opcao desejada:");
        printf("\n1. Inserir uma conta na Lista");
        printf("\n2. Remover uma conta da Lista (pelo numero da conta)");
        printf("\n3. Consultar uma conta na Lista (pelo numero da conta)");
        printf("\n4. Mostrar a Lista Linear Encadeada");
        printf("\n5. Mostrar o numero total de nodos da Lista");
        printf("\n6. Verificar quantas contas possuem um determinado saldo");
        printf("\n7. Mostrar a conta com o maior saldo");
        printf("\n8. Mostrar a conta com o menor saldo");
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
                maior_saldo(&PtLista);
                break;
            case 8:
                menor_saldo(&PtLista);
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

void inserir(CONTA **PtLista, int *cont) {
    CONTA *PtNovo, *PtAtual, *PtAnt;
    int numero;
    float saldo_conta;

    printf("\nNumero da conta: ");
    scanf("%d", &numero);
    printf("\nSaldo da conta: ");
    scanf("%f", &saldo_conta);

    PtAtual = *PtLista;
    while(PtAtual != NULL) {
        if(PtAtual->num_conta == numero) {
            printf("\nJa existe uma conta com esse numero! Insercao cancelada.\n");
            return;
        }
        PtAtual = PtAtual->prox;
    }

    PtNovo = (CONTA*)malloc(sizeof(CONTA));

    if(PtNovo == NULL) {
        printf("\nNao foi possivel alocar memoria!\n");
        return;
    }

    PtNovo->num_conta = numero;
    PtNovo->saldo = saldo_conta;
    PtNovo->prox = NULL;

    if (*PtLista == NULL) {
        *PtLista = PtNovo;
    }
    else if (numero < (*PtLista)->num_conta) {
        PtNovo->prox = *PtLista;
        *PtLista = PtNovo;
    }
    else {
        PtAnt = *PtLista;
        PtAtual = (*PtLista)->prox;

        while(PtAtual != NULL && PtAtual->num_conta < numero) {
            PtAnt = PtAtual;
            PtAtual = PtAtual->prox;
        }

        PtNovo->prox = PtAtual;
        PtAnt->prox = PtNovo;
    }

    (*cont)++;
    printf("\nConta inserida com sucesso!\n");
}

void remover(CONTA **PtLista, int *cont) {
    CONTA *PtAnt, *PtAtual;
    int numero;

    if(*PtLista == NULL) {
        printf("\nA lista esta vazia! Nao e possivel remover.\n");
        return;
    }

    printf("\nDigite o numero da conta que deseja remover: ");
    scanf("%d", &numero);

    PtAtual = *PtLista;
    PtAnt = NULL;

    while(PtAtual != NULL && PtAtual->num_conta != numero) {
        PtAnt = PtAtual;
        PtAtual = PtAtual->prox;
    }

    if(PtAtual == NULL) {
        printf("\nConta numero %d nao encontrada!\n", numero);
    }
    else {
        if(PtAnt == NULL)
            *PtLista = PtAtual->prox;
        else
            PtAnt->prox = PtAtual->prox;

        free(PtAtual);
        (*cont)--;
        printf("\nConta removida com sucesso!\n");
    }
}

void consultar(CONTA **PtLista) {
    CONTA *PtAtual;
    int numero;

    if(*PtLista == NULL) {
        printf("\nA lista esta vazia!\n");
        return;
    }

    printf("\nDigite o numero da conta que deseja consultar: ");
    scanf("%d", &numero);

    PtAtual = *PtLista;
    while(PtAtual != NULL && PtAtual->num_conta != numero) {
        PtAtual = PtAtual->prox;
    }

    if(PtAtual == NULL)
        printf("\nConta numero %d nao encontrada!\n", numero);
    else
        printf("\nConta %d - Saldo: %.2f\n", PtAtual->num_conta, PtAtual->saldo);
}

void mostra_lista(CONTA **PtLista) {
    CONTA *PtAtual;

    printf("\nLISTA LINEAR ENCADEADA DE CONTAS (ordenada por numero da conta)\n");

    if(*PtLista == NULL) {
        printf("A lista esta vazia!\n");
        return;
    }

    PtAtual = *PtLista;
    while(PtAtual != NULL) {
        printf("Conta: %d\tSaldo: %.2f\n", PtAtual->num_conta, PtAtual->saldo);
        PtAtual = PtAtual->prox;
    }
}

int conta_nodos(CONTA **PtLista) {
    CONTA *PtAtual = *PtLista;
    int total = 0;

    while(PtAtual != NULL) {
        total++;
        PtAtual = PtAtual->prox;
    }

    return total;
}

void verifica_ocorrencias(CONTA **PtLista) {
    CONTA *PtAtual = *PtLista;
    float valor;
    int ocorrencias = 0;

    if(PtAtual == NULL) {
        printf("\nA lista esta vazia!\n");
        return;
    }

    printf("\nDigite o saldo que deseja verificar: ");
    scanf("%f", &valor);

    printf("\nContas com saldo %.2f: ", valor);
    while(PtAtual != NULL) {
        if(PtAtual->saldo == valor) {
            printf("%d ", PtAtual->num_conta);
            ocorrencias++;
        }
        PtAtual = PtAtual->prox;
    }

    if(ocorrencias == 0)
        printf("\nNenhuma conta com o saldo %.2f foi encontrada.\n", valor);
    else
        printf("\n%d conta(s) encontrada(s) com o saldo %.2f.\n", ocorrencias, valor);
}

void maior_saldo(CONTA **PtLista) {
    CONTA *PtAtual = *PtLista;
    CONTA *PtMaior;

    if(PtAtual == NULL) {
        printf("\nA lista esta vazia!\n");
        return;
    }

    PtMaior = PtAtual;
    PtAtual = PtAtual->prox;

    while(PtAtual != NULL) {
        if(PtAtual->saldo > PtMaior->saldo)
            PtMaior = PtAtual;
        PtAtual = PtAtual->prox;
    }

    printf("\nMaior saldo: Conta %d - Saldo: %.2f\n", PtMaior->num_conta, PtMaior->saldo);
}

void menor_saldo(CONTA **PtLista) {
    CONTA *PtAtual = *PtLista;
    CONTA *PtMenor;

    if(PtAtual == NULL) {
        printf("\nA lista esta vazia!\n");
        return;
    }

    PtMenor = PtAtual;
    PtAtual = PtAtual->prox;

    while(PtAtual != NULL) {
        if(PtAtual->saldo < PtMenor->saldo)
            PtMenor = PtAtual;
        PtAtual = PtAtual->prox;
    }

    printf("\nMenor saldo: Conta %d - Saldo: %.2f\n", PtMenor->num_conta, PtMenor->saldo);
}