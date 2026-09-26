/*Faça um programa que preencha e mostre a média dos
elementos da diagonal principal de uma matriz 10 x 10. Utilize
uma função sem retorno.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define L 4
#define C 4

void matriz_format(float m[L][C]);
void media(float m[L][C]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i, j;
    float matriz[L] [C];

    for (i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("Digite um valor para Matriz [%d] [%d]: ", i, j);
            scanf("%f", &matriz[i] [j]);
        }
        
    }

    matriz_format(matriz);
    media(matriz);

    return 0;
}

void media(float m[L][C]){
    int i, j, cont=0;
    float media, soma=0;

    for (i=0;i<L;i++){
        for(j=0;j<C;j++){
            if (i==j){
                soma=soma+m[i][j];
                cont++;
            }
        }
        
    }
    
    media = soma/cont;
    printf("A média dos elementos da diagonal principal da matriz é: %.2f", media);
}

void matriz_format(float m[L][C]){
    int i, j;

    printf("\n=========== MATRIZ ===========\n");
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("%.2f\t", m[i][j]);
        }
    printf("\n");
    }
    printf("\n");
}