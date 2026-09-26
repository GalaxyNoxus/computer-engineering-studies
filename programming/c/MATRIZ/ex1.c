/*Elabore um programa que preencha uma matriz 6 x 4 com números inteiros, calcule e mostre quantos
elementos dessa matriz são maiores que 30 e, em seguida, monte uma segunda matriz com os elementos
diferentes de 30. No lugar do número 30 da segunda matriz, coloque o número zero.*/

#include <stdio.h>
#include <locale.h>

#define L 6
#define C 4

int cont(int matriz[L][C]);
void matriz_format(int mat[L][C]);
void matriz_2(int matriz[L][C]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int matriz[L][C];
    int i, j, contagem;

    for(i=0; i<L; i++){
        for(j=0; j<C; j++){

            printf("Digite um número intero para Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }

        printf("\n");
    }

    matriz_format(matriz);
    contagem = cont(matriz);
    printf("\nA matriz possui %d números maiores que 30.", contagem);
    matriz_2(matriz);
}

void matriz_2(int matriz[L][C]){
    int i, j, cont=0;

    printf("\n\n===== MATRIZ 2 =====\n");
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            if(matriz[i][j] == 30){
            matriz[i][j] = 0;
            }
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int cont(int matriz[L][C]){
    int i, j, cont=0;

    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            if(matriz[i][j] > 30)
                cont++;
        }
    }

    return cont;
}

void matriz_format(int mat[L][C]){
    int i, j;

    printf("\n=== MATRIZ FORMATADA ===\n\n");
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}