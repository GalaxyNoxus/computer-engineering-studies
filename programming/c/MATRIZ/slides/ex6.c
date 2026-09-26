/*Elabore um programa que preencha uma matriz 5 x 5 na
função principal. Através de uma função sem retorno crie dois
vetores de cinco posições cada um, que contenham,
respectivamente, as somas das linhas e a soma das colunas da
matriz. Ao final, mostre a matriz e os vetores.*/

#include <stdio.h>
#include <locale.h>

#define L 5
#define C 5

void matriz_format(int MAT[L][C]);
void matriz_format(int matriz[L][C]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int matriz[L][C];
    int i, j;

    for(i=0; i<L; i++){
        for(j=0; j<C; j++){

            printf("Digite um número para matriz [%d][%d]: ", i,j);
            scanf("%d", &matriz[i][j]);
        }

        printf("\n");
    }

    matriz_format(matriz);
}

void matriz_format(int matriz[L][C]){
    int i, j;

    printf("\n===== MATRIZ FORMATADA =====\n");
    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            printf("%d\t", matriz[i][j]);
        }
    printf("\n");
    }

}