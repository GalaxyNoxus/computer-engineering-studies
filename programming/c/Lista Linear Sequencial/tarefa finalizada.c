#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX 10
#define IA 0
#define FA MAX - 1

struct conta {
    int num;
    char nome[100];
    float saldo;
};

void Inserir_K(struct conta Lista[], int *IL, int *FL);
void Remover(struct conta Lista[], int *IL, int *FL);
void Mostrar_Lista(struct conta Lista[], int *IL, int *FL);
void Mostrar_Saldo(struct conta Lista[], int *IL, int *FL);
void Alterar_Saldo(struct conta Lista[], int *IL, int *FL);
void Tamanho_Lista(struct conta Lista[], int *IL, int *FL);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct conta LL[MAX];
    int IL, FL;
    int op;

    // Criacao da Lista Linear Sequencial
    IL = FL = IA - 1;

    printf("\nESCOLHA A OPERACAO DESEJADA");
    printf("\nDigite 1 para adicionar informacao na lista (posicao K).");
    printf("\nDigite 2 para remover informacao da lista.");
    printf("\nDigite 3 para exibir a lista.");
    printf("\nDigite 4 para consultar o saldo de uma conta.");
    printf("\nDigite 5 para alterar o saldo de uma conta.");
    printf("\nDigite 6 para informar o tamanho da lista.");
    printf("\nDigite 7 para sair.");
    printf("\n\nOpcao: ");
    scanf("%d", &op);

    while (op != 7)
    {
        switch (op)
        {
            case 1:
                Inserir_K(LL, &IL, &FL);
                break;

            case 2:
                Remover(LL, &IL, &FL);
                break;

            case 3:
                Mostrar_Lista(LL, &IL, &FL);
                break;

            case 4:
                Mostrar_Saldo(LL, &IL, &FL);
                break;

            case 5:
                Alterar_Saldo(LL, &IL, &FL);
                break;

            case 6:
                Tamanho_Lista(LL, &IL, &FL);
                break;

            default:
                printf("\nOpcao invalida!\n");
                break;
        }

        printf("\nESCOLHA A OPERACAO DESEJADA");
        printf("\nDigite 1 para adicionar informacao na lista (posicao K).");
        printf("\nDigite 2 para remover informacao da lista.");
        printf("\nDigite 3 para exibir a lista.");
        printf("\nDigite 4 para consultar o saldo de uma conta.");
        printf("\nDigite 5 para alterar o saldo de uma conta.");
        printf("\nDigite 6 para informar o tamanho da lista.");
        printf("\nDigite 7 para sair.");
        printf("\n\nOpcao: ");
        scanf("%d", &op);
    }

    printf("\nPrograma encerrado!\n");

    return 0;
}


// Funcao auxiliar que faz a busca sequencial de uma conta pelo numero
// Retorna a posicao (indice real) se encontrar, ou -1 se nao encontrar
int Busca_Conta(struct conta Lista[], int *IL, int *FL, int num)
{
    int ind;

    if (*IL == -1)
        return -1;

    for (ind = *IL; ind <= *FL; ind++)
    {
        if (Lista[ind].num == num)
            return ind;
    }

    return -1;
}


void Inserir_K(struct conta Lista[], int *IL, int *FL)
{
    int K;
    int ind;
    int num;
    int achou;

    // Lista cheia
    if ((*IL == IA) && (*FL == FA))
    {
        printf("\nImpossivel realizar a insercao. A lista esta cheia!\n");
        return;
    }

    printf("\nDigite o numero da conta: ");
    scanf("%d", &num);

    // Busca sequencial para nao permitir conta repetida
    achou = Busca_Conta(Lista, IL, FL, num);

    if (achou != -1)
    {
        printf("\nJa existe uma conta com esse numero! Insercao cancelada.\n");
        return;
    }

    printf("Digite a posicao em que deseja inserir: ");
    scanf("%d", &K);

    // Lista vazia
    if (*IL == -1)
    {
        if (K != 1)
        {
            printf("\nImpossivel realizar a insercao!\n");
            return;
        }

        *IL = *FL = IA;
    }
    else
    {
        // Posicao invalida
        if (K <= 0 || K > (*FL - *IL + 2))
        {
            printf("\nPosicao invalida!\n");
            return;
        }

        // Existe espaco no final
        if (*FL != FA)
        {
            for (ind = *FL; ind >= *IL + K - 1; ind--)
                Lista[ind + 1] = Lista[ind];

            (*FL)++;
        }
        else
        {
            for (ind = *IL; ind <= *IL + K - 2; ind++)
                Lista[ind - 1] = Lista[ind];

            (*IL)--;
        }
    }

    Lista[*IL + K - 1].num = num;

    // Limpa o "lixo" que fica no buffer depois do scanf de numero
    getchar();

    printf("Digite o nome e sobrenome do cliente: ");
    fgets(Lista[*IL + K - 1].nome, 100, stdin);

    // Tira o \n que o fgets deixa no final da string
    Lista[*IL + K - 1].nome[strcspn(Lista[*IL + K - 1].nome, "\n")] = '\0';

    printf("Digite o saldo da conta: ");
    scanf("%f", &Lista[*IL + K - 1].saldo);

    printf("\nConta inserida com sucesso!\n");
}


void Remover(struct conta Lista[], int *IL, int *FL)
{
    int K;
    int ind;
    int pos_real;
    int tamanho;
    int meio;

    if (*IL == -1)
    {
        printf("\nA lista esta vazia!\n");
        return;
    }

    printf("\nDigite a posicao da conta que deseja remover: ");
    scanf("%d", &K);

    tamanho = *FL - *IL + 1;

    if (K <= 0 || K > tamanho)
    {
        printf("\nPosicao invalida!\n");
        return;
    }

    pos_real = *IL + K - 1;
    meio = tamanho / 2;

    if (K <= meio)
    {
        // Esta na primeira metade: desloca os elementos ANTES dela
        // para a direita (da esquerda para a direita), pois sao menos elementos
        for (ind = pos_real; ind > *IL; ind--)
            Lista[ind] = Lista[ind - 1];

        (*IL)++;
    }
    else
    {
        // Esta na segunda metade: desloca os elementos DEPOIS dela
        // para a esquerda (para cima), pois sao menos elementos
        for (ind = pos_real; ind < *FL; ind++)
            Lista[ind] = Lista[ind + 1];

        (*FL)--;
    }

    if (*FL < *IL)
        *IL = *FL = -1;

    printf("\nConta removida com sucesso!\n");
}


void Mostrar_Lista(struct conta Lista[], int *IL, int *FL)
{
    int ind;

    if (*IL == -1)
        printf("\nLISTA VAZIA!\n");
    else
    {
        printf("\nLISTA LINEAR SEQUENCIAL");
        printf("\nPosicao\tConta\tNome\t\t\tSaldo\n");

        for (ind = *IL; ind <= *FL; ind++)
            printf("%d\t%d\t%-20s\tR$ %.2f\n",
                   ind - *IL + 1,
                   Lista[ind].num,
                   Lista[ind].nome,
                   Lista[ind].saldo);
    }
}


void Mostrar_Saldo(struct conta Lista[], int *IL, int *FL)
{
    int numero;
    int achou;

    if (*IL == -1)
    {
        printf("\nLISTA VAZIA!\n");
        return;
    }

    printf("\nDigite o numero da conta que deseja consultar: ");
    scanf("%d", &numero);

    achou = Busca_Conta(Lista, IL, FL, numero);

    if (achou == -1)
        printf("\nConta nao encontrada!\n");
    else
    {
        printf("\nConta: %d", Lista[achou].num);
        printf("\nNome: %s", Lista[achou].nome);
        printf("\nSaldo: R$ %.2f\n", Lista[achou].saldo);
    }
}


void Alterar_Saldo(struct conta Lista[], int *IL, int *FL)
{
    int numero;
    int achou;
    float novo_saldo;

    if (*IL == -1)
    {
        printf("\nA lista esta vazia!\n");
        return;
    }

    printf("\nDigite o numero da conta que deseja alterar o saldo: ");
    scanf("%d", &numero);

    achou = Busca_Conta(Lista, IL, FL, numero);

    if (achou == -1)
    {
        printf("\nConta nao encontrada!\n");
        return;
    }

    printf("Nome do cliente: %s\n", Lista[achou].nome);
    printf("Saldo atual: R$ %.2f\n", Lista[achou].saldo);

    printf("Digite o novo saldo: ");
    scanf("%f", &novo_saldo);

    Lista[achou].saldo = novo_saldo;

    printf("\nSaldo alterado com sucesso!\n");
}


void Tamanho_Lista(struct conta Lista[], int *IL, int *FL)
{
    int tamanho;

    if (*IL == -1)
        printf("\nA lista esta vazia!\n");
    else
    {
        tamanho = *FL - *IL + 1;

        printf("\nA lista possui %d conta(s).\n", tamanho);
    }
}