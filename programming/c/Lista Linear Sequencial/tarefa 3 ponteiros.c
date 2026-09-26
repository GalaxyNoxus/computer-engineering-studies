#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10
#define IA 0
#define FA MAX - 1

struct conta
{
    int num;
    float saldo;
};

void alterarSaldo(struct conta Lista[], int *IL, int *FL);
void Inserir_K(struct conta Lista[], int *IL, int *FL);
void Remover(struct conta Lista[], int *IL, int *FL);
void Mostrar_Lista(struct conta Lista[], int *IL, int *FL);
void Mostrar_Saldo(struct conta Lista[], int *IL, int *FL);
void Tamanho_Lista(struct conta Lista[], int *IL, int *FL);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    struct conta LL[MAX];
    int IL, FL;
    int op;

    // Cria��o da Lista Linear Sequencial
    IL = FL = IA - 1;

    printf("\nESCOLHA A OPERACAO DESEJADA");
    printf("\nDigite 1 para adicionar informacao na lista.");
    printf("\nDigite 2 para remover informacao da lista.");
    printf("\nDigite 3 para exibir a lista.");
    printf("\nDigite 4 para consultar o saldo de uma conta.");
    printf("\nDigite 5 para informar o tamanho da lista.");
    printf("\nDigite 6 para alterar o saldo de uma conta.");
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
            Tamanho_Lista(LL, &IL, &FL);
            break;

        case 6:
            alterarSaldo(LL, &IL, &FL);
            break;

        default:
            printf("\nOpcao invalida!\n");
            break;
        }

        printf("\nESCOLHA A OPERACAO DESEJADA");
        printf("\nDigite 1 para adicionar informacao na lista.");
        printf("\nDigite 2 para remover informacao da lista.");
        printf("\nDigite 3 para exibir a lista.");
        printf("\nDigite 4 para consultar o saldo de uma conta.");
        printf("\nDigite 5 para informar o tamanho da lista.");
        printf("\nDigite 6 para alterar o saldo de uma conta.");
        printf("\nDigite 7 para sair.");
        printf("\n\nOpcao: ");
        scanf("%d", &op);
    }

    printf("\nPrograma encerrado!\n");

    return 0;
}

void alterarSaldo(struct conta Lista[], int *IL, int *FL){
    int numConta;
    int ind;
    int encontrado = 0;
    int K;

    printf("\nDigite o numero da conta: ");
    scanf("%d", &numConta);

    for(ind=*IL; ind<=*FL; ind++) {
        if(Lista[ind].num == numConta) {
            encontrado = 1;
            break;

        } else
            encontrado = 0;
        
        if(encontrado == 1){

            printf("\nDigite o valor para alterar da conta (%d): ", Lista[ind].num);
            scanf("%f", &Lista[ind].saldo);

            printf("\nValor alterado para a conta %d ", Lista[ind].num);

        } else {
            printf("\nNúmero da conta não existe!\n", K);
            encontrado = 0;
            return;
        }
    }
}
void Inserir_K(struct conta Lista[], int *IL, int *FL)
{
    int K;
    int ind;
    int encontrado = -1;
    int numConta;

    printf("\nDigite a posicao em que deseja inserir: ");
    scanf("%d", &K);

    // Lista vazia
    if (*IL == -1) {

        if (K != 1)
            printf("\nImpossivel realizar a insercao!\n");
        else {

            *IL = *FL = IA;

            printf("\nDigite o NÚMERO da conta: ");
            scanf("%d", &numConta);

            for(ind=*IL; ind<=*FL; ind++) {
                if(Lista[ind].num == numConta) {
                encontrado = 1;
                break;
                } else {
                    encontrado = 0;
                }
            }
            
            if(encontrado == 1){
                printf("\nNúmero da conta já existe!\n", K);
                encontrado == -1;
                return;
            }

            Lista[*IL].num = numConta;

            printf("Digite o saldo da conta: ");
            scanf("%f", &Lista[*IL].saldo);

            printf("\nConta inserida com sucesso!\n");

        }

        return;
    }

    // Lista cheia
    if ((*IL == IA) && (*FL == FA))
    {
        printf("\nImpossivel realizar a insercao. A lista esta cheia!\n");
        return;
    }

    // Posicao invalida
    if (K <= 0 || K > (*FL - *IL + 2))
    {
        printf("\nPosicao invalida!\n");
        return;
    }

    printf("\nDigite o numero da conta: ");
    scanf("%d", &numConta);

        for(ind=*IL; ind<=*FL; ind++) {
            if(Lista[ind].num == numConta) {
                encontrado = 1;
                break;
            } else {
                encontrado = 0;
            }
        }
            
        if(encontrado == 1){
            printf("\nNúmero da conta já existe!\n", K);
            encontrado == -1;
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

    Lista[*IL + K - 1].num = numConta;
            
    printf("Digite o saldo da conta: ");
    scanf("%f", &Lista[*IL + K - 1].saldo);

    printf("\nConta inserida com sucesso!\n");
}

void Remover(struct conta Lista[], int *IL, int *FL)
{
    int K;
    int ind;

    if (*IL == -1)
        printf("\nA lista esta vazia!\n");
    else
    {
        printf("\nDigite a posicao da conta que deseja remover: ");
        scanf("%d", &K);

        if (K <= 0 || K > (*FL - *IL + 1))
            printf("\nPosicao invalida!\n");
        else
        {
            for (ind = *IL + K - 1; ind < *FL; ind++)
                Lista[ind] = Lista[ind + 1];

            (*FL)--;

            if (*FL < *IL)
                *IL = *FL = -1;

            printf("\nConta removida com sucesso!\n");
        }
    }
}

void Mostrar_Lista(struct conta Lista[], int *IL, int *FL)
{
    int ind;

    if (*IL == -1)
        printf("\nLISTA VAZIA!\n");
    else
    {
        printf("\nLISTA LINEAR SEQUENCIAL");
        printf("\nPosicao\tConta\tSaldo\n");

        for (ind = *IL; ind <= *FL; ind++)
            printf("%d\t%d\tR$ %.2f\n",
                   ind - *IL + 1,
                   Lista[ind].num,
                   Lista[ind].saldo);
    }
}

void Mostrar_Saldo(struct conta Lista[], int *IL, int *FL)
{
    int numero;
    int encontrado = 0;
    int ind;

    if (*IL == -1)
        printf("\nLISTA VAZIA!\n");
    else
    {
        printf("\nDigite o numero da conta que deseja consultar: ");
        scanf("%d", &numero);

        for (ind = *IL; ind <= *FL; ind++)
        {
            if (Lista[ind].num == numero)
            {
                printf("\nConta: %d", Lista[ind].num);
                printf("\nSaldo: R$ %.2f\n", Lista[ind].saldo);

                encontrado = 1;
                break;
            }
        }

        if (encontrado == 0)
            printf("\nConta nao encontrada!\n");
    }
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