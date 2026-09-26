#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 10

#define IA 0
#define FA MAX-1

struct conta {
    int num;
    float saldo;
};

int IL, FL, ind;

void Inserir_Inicio(struct conta Lista[]);
void Mostrar_Lista(struct conta Lista[]);
void Inserir_Fim(struct conta Lista[]);
void Inserir_K(struct conta Lista[]);
void remover(struct conta Lista[]);
void Consultar_Saldo(struct conta Lista[]);
void Tamanho_Lista(void);

int main() {
    setlocale(LC_ALL, "Portuguese");
    struct conta LL[MAX];
    int op;

    //Criação da Lista Linear Sequencial
    IL = FL = IA-1;

    printf("\nESCOLHA A OPERAÇÃO DESEJADA");
    printf("\nDigite 1 para adicionar informação na lista.");
    printf("\nDigite 2 para remover informação da lista.");
    printf("\nDigite 3 para exibir a lista.");
    printf("\nDigite 4 para consultar o saldo de uma conta.");
    printf("\nDigite 5 para informar o tamanho da lista.");
    printf("\nDigite 6 para sair.");
    printf("\n\nOpção: ");
    scanf("%d", &op);

    while(op!=6) {

        switch (op){
        case 1:
            printf("\nOPERAÇÃO DE INSERÇÃO:");
            printf("\nDigite 1 para Inserir no INICIO da Lista Linear");
            printf("\nDigite 2 para Inserir no FINAL da Lista Linear");
            printf("\nDigite 3 para Inserir no MEIO (k) da Lista Linear.");
            printf("\n\nOpção: ");
            scanf("%d", &op);

                if(op==1)
                    Inserir_Inicio(LL);
                else if(op==2)
                    Inserir_Fim(LL);
                else if(op==3)
                    Inserir_K(LL);
                else
                    printf("Opção Inválida!");

            break;

        case 2:
            remover(LL);
            break;

        case 3:
            Mostrar_Lista(LL);
            break;

        case 4:
            Consultar_Saldo(LL);
            break;

        case 5:
            Tamanho_Lista();
            break;
        }

    printf("\nESCOLHA A OPERAÇÃO DESEJADA");
    printf("\nDigite 1 para adicionar informação na lista.");
    printf("\nDigite 2 para remover informação da lista.");
    printf("\nDigite 3 para exibir a lista.");
    printf("\nDigite 4 para consultar o saldo de uma conta.");
    printf("\nDigite 5 para informar o tamanho da lista.");
    printf("\nDigite 6 para sair.");
    printf("\n\nOpção: ");
    scanf("%d", &op);
    }
}

//FUNÇÃO PARA INSERIR NO INICIO DA LISTA LINEAR SEQUENCIAL
void Inserir_Inicio(struct conta Lista[]) {

    if(IA==IL && FA==FL) {
        printf("\nImpossível inserir o nodo na LISTA!!\n");
        return;
    }

    if(IL==-1)
        IL=FL=IA;

    else if (IL>IA)
        IL--;

    else {
        for(ind=FL; ind>=IL; ind--)
            Lista[ind+1] = Lista[ind];

        FL++; //está fora do for
    }

    printf("\nDigite o NÚMERO da conta: ");
    scanf("%d", &Lista[IL].num);
    printf("Digite o SALDO da conta: ");
    scanf("%f", &Lista[IL].saldo);
    printf("Conta %d adicionada com sucesso!!\n", Lista[IL].num);
}

//FUNÇÃO PARA INSERIR NO FIM DA LISTA LINEAR SEQUENCIAL
void Inserir_Fim(struct conta Lista[]) {

    if(IA==IL && FA==FL) {
        printf("\nImpossível inserir o nodo na LISTA!!\n");
        return;
    }

    else if(IL==-1)
        IL=FL=IA;

    else if (FL<FA)
        FL = FL+1;

    else {
        for(ind=IL; ind>=FL; ind++)
            Lista[ind-1] = Lista[ind];

        IL = IL-1; // está fora do for
    }

    printf("\nDigite o NÚMERO da conta: ");
    scanf("%d", &Lista[FL].num);
    printf("Digite o SALDO da conta: ");
    scanf("%f", &Lista[FL].saldo);
    printf("Conta %d adicionada com sucesso!!\n", Lista[FL].num);
}

void Inserir_K(struct conta Lista[]){
    int K;
    int encontrado = -1;
    int numConta;

    printf("Insira a posição que deseja inserir: ");
    scanf("%d", &K);

    if((IA==IL && FA==FL) || (K > FL-IL+2) || (K <= 0) || (IL == -1 && K != 1)){
        printf("\nImpossível realizar a inserção!\n");
        return;
    }

    printf("\nDigite o NÚMERO da conta: ");
    scanf("%d", &numConta);

    for(ind=IL; ind<=FL; ind++) {
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

    if(IL == -1)
        IL = FL = IA;

    if(FL != FA){
        for(ind= FL; ind>=IL+K-1; ind--)
            Lista[ind+1] = Lista[ind];
            FL++;

    }else if(IL > IA){
        for(ind=IL; ind<=IL+K-2; ind++)
            Lista[ind-1] = Lista[ind];
            IL--;
        }

    Lista[IL+K-1].num = numConta;
    printf("Digite o SALDO da conta: ");
    scanf("%f", &Lista[IL+K-1].saldo);
    printf("Conta %d adicionada com sucesso!!\n", Lista[IL].num);
}

void remover(struct conta Lista[]){
    int K;

    printf("Informe a K-ésima posição que deseja remover: ");
    scanf("%d", &K);

    if ((K <= 0) || (K > FL-IL+1))
        printf("\nImpossível remover!\n");

    else {
        for(ind=IL+K-1; ind<=FL-1; ind++)
            Lista[ind] = Lista[ind+1];
        FL--;

        if (FL == IL-1)
            IL = FL = -1;

        printf("Remoção realizada com sucesso!\n");
    }

}

//FUNÇÃO PARA MOSTRAR AS INFORMAÇÕES ARMAZENADAS NA LISTA LINEAR SEQUENCIAL
void Mostrar_Lista(struct conta Lista[]) {

    if(IL!=-1) {
        printf("\n--- LISTA SEQUENCIAL DE CONTAS ---");
        for(ind=IL; ind<=FL; ind++)
            printf("\nPosição %d - Conta: %d - Saldo: R$ %.2f", ind, Lista[ind].num, Lista[ind].saldo);

        printf("\n");

    } else
        printf("\nLISTA VAZIA...\n");
}

//FUNÇÃO PARA CONSULTAR O SALDO DE UMA CONTA PELO NÚMERO DA CONTA
void Consultar_Saldo(struct conta Lista[]) {
    int numConta;
    int encontrado = -1;

    if(IL == -1) {
        printf("\nLISTA VAZIA...\n");
        return;
    }

    printf("\nDigite o NÚMERO da conta que deseja consultar: ");
    scanf("%d", &numConta);

    for(ind=IL; ind<=FL; ind++) {
        if(Lista[ind].num == numConta) {
            printf("\nConta %d encontrada! Saldo: R$ %.2f\n", Lista[ind].num, Lista[ind].saldo);
            encontrado = 1;
            break;
        } else {
            encontrado == 0;
        }
    }

    if(encontrado == 0){
        printf("\nConta %d não encontrada na lista!\n", numConta);
        encontrado == -1;
    }
}

//FUNÇÃO PARA INFORMAR O TAMANHO (QUANTIDADE DE ELEMENTOS) DA LISTA
void Tamanho_Lista(void) {

    if(IL == -1)
        printf("\nA lista está vazia. Tamanho: 0\n");
    else
        printf("\nTamanho atual da lista: %d de %d posições ocupadas.\n", FL-IL+1, MAX);
}