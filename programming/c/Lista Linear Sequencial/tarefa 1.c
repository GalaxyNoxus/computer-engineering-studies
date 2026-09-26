#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX 5

#define IA 0
#define FA MAX-1

int IL, FL, ind;

void Inserir_Inicio(int Lista[]);
void Mostrar_Lista(int Lista[]);
void Inserir_Fim(int Lista[]);
void Inserir_K(int Lista[]);
void remover(int Lista[]);

int main() {
    setlocale(LC_ALL, "Portuguese");
    int LL[MAX], op;

    //Criação da Lista Linear Sequencial
    IL = FL = IA-1;

    printf("\nESCOLHA A OPERAÇÃO DESEJADA");
    printf("\nDigite 1 para adicionar informação na lista.");
    printf("\nDigite 2 para remover informação da lista.");
    printf("\nDigite 3 para exibir a lista.");
    printf("\nDigite 4 para sair.");
    printf("\n\nOpção: ");
    scanf("%d", &op);

    while(op!=4) {

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
        }

    printf("\nESCOLHA A OPERAÇÃO DESEJADA");
    printf("\nDigite 1 para adicionar informação na lista.");
    printf("\nDigite 2 para remover informação da lista.");
    printf("\nDigite 3 para exibir a lista.");
    printf("\nDigite 4 para sair.");
    printf("\n\nOpção: ");
    scanf("%d", &op);
    }
}

//FUNÇÃO PARA INSERIR NO INICIO DA LISTA LINEAR SEQUENCIAL
void Inserir_Inicio(int Lista[]) {

    if(IA==IL && FA==FL)
        printf("\nImpossível inserir o nodo na LISTA!!\n");

    if(IL==-1)
        IL=FL=IA;

    else if (IL>IA)
        IL--;

    else {
        for(ind=FL; ind>=IL; ind--)
            Lista[ind+1] = Lista[ind];

        FL++; //est� fora do for
    }

    printf("\nDigite o NÚMERO que deseja adicionar: ");
    scanf("%d", &Lista[IL]);
    printf("Número %d adicionado com sucesso!!\n", Lista[IL]);
}

//FUNÇÃO PARA INSERIR NO FIM DA LISTA LINEAR SEQUENCIAL
void Inserir_Fim(int Lista[]) {

    if(IA==IL && FA==FL)
        printf("\nImpossível inserir o nodo na LISTA!!\n");

    else if(IL==-1)
        IL=FL=IA;

    else if (FL<FA)
        FL = FL+1;

    else {
        for(ind=IL; ind>=FL; ind++)
            Lista[ind-1] = Lista[ind];

        IL = IL-1; // está fora do for
    }

    printf("\nDigite o NÚMERO que deseja adicionar: ");
    scanf("%d", &Lista[IL]);
    printf("Número %d adicionado com sucesso!!\n", Lista[IL]);
}

void Inserir_K(int Lista[]){
    int K;

    printf("Insira a posição que deseja inserir: ");
    scanf("%d", &K);

    if((IA==IL && FA==FL) || (K > FL-IL+2) || (K <= 0) || (IL == -1 && K != 1))
        printf("\nImpossível realizar a inserção!\n\n");

    else if(IL == -1)
        IL = FL = IA;

    else if(FL != FA) {
        for(ind = FL; ind>=IL+K-1; ind--)
            Lista[ind+1] = Lista[ind];
        IL++;

    } else if(IL > IA) {
        for(ind=IL; ind<=IL+K-2; ind++)
            Lista[ind-1] = Lista[ind];
        IL--;
    }

    printf("\nDigite o NÚMERO que deseja adicionar: ");
    scanf("%d", &Lista[IL]);
    printf("Número %d adicionado com sucesso!!\n", Lista[IL]);

}

void remover(int Lista[]){
    int K;

    printf("Informe a K-ésima posição que deseja remover: ");
    scanf("%d", &K);

    if ((K <= 0) || (K > FL-IL+1))
        printf("\nImpossível remover!\n\n");

    else {
        for(ind=IL+K-1; ind<=FL-1; ind++)
            Lista[ind] = Lista[ind+1];
        FL--;

        if (FL == IL-1)
            IL = FL = -1;
    }

    printf("Remoção realizada com sucesso!\n");

}

//FUNÇÃO PARA MOSTRAR AS INFORMA��ES ARMAZENADAS NA LISTA LINEAR SEQUENCIAL
void Mostrar_Lista(int Lista[]) {

    if(IL!=-1) {
        printf("\n--- LISTA SEQUENCIAL ---");
        for(ind=IL; ind<=FL; ind++)
            printf("\nPosição %d - Informação: %d", ind, Lista[ind]);

        printf("\n");

    } else
        printf("\nLISTA VAZIA...\n");
}