/* Crie um programa que preencha uma matriz 2 x 4 com
números inteiros na função principal. Através de funções com
retorno, calcule e mostre:
a) A quantidade de elementos entre 12 e 20 em cada linha;
b) A média dos elementos pares da matriz. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define L 2
#define C 4

void matriz_format(int m[L][C]);
void quantidade(int m[L][C]);
float mediaPares(int m[L][C]);

int main(){

    setlocale(LC_ALL,"Portuguese");

    int matriz[L][C], i,j;
    float media;

    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("Digite Matriz[%d][%d]: ",i,j);
            scanf("%d",&matriz[i][j]);
        }
    }

    matriz_format(matriz);
    quantidade(matriz);
    media = mediaPares(matriz);

    printf("\nMedia dos elementos pares: %.2f", media);

    return 0;
}

void matriz_format(int m[L][C]){
    int i, j;

    printf("\n====== MATRIZ ======\n");
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
}

void quantidade(int m[L][C]){
    int i, j, cont=0;

    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            if(m[i][j] >= 12 && m[i][j] <=20){
                cont++;
            }
        }

        printf("Linha %d possui %d elementos entre 12 e 20\n", i+1, cont);
        cont=0;
    }
}

float mediaPares(int m[L][C]){
    int i,j;
    int soma=0, cont=0, media;

    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            if(m[i][j] % 2 == 0){
                soma = soma+m[i][j];
                cont++;
            }
        }
    }

    media = soma/cont;

    if(cont==0){
        return 0;
    }

    return media;
}