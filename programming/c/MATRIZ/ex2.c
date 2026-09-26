/*Crie um programa que utilize uma matriz com as dimensões fornecidas pelo usuário e execute as
solicitações a seguir: Sendo assim, solicite que seja informada a dimensão da matriz. Posteriormente, o
programa deverá realizar a leitura dos elementos que vão compor a matriz. Finalmente, deverá somar e
mostrar os elementos que estão abaixo da diagonal secundária.*/

#include <stdio.h>
#include <locale.h>

void matriz_format(int L, int C, int mat[L][C]);
int somatorio(int L, int C, int mat[L][C]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i, j, L, C, dimensao, resultado;
    
    printf("Digite a dimensao da matriz quadrada: ");
    scanf("%d", &dimensao);
    printf("\nMatriz definida como: %dx%d\n\n", dimensao, dimensao);

    L = dimensao;
    C = dimensao;

    int matriz[L][C];

    for(i=0; i<L; i++){
        for(j=0; j<C; j++){

            printf("Digite um número intero para Matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }

        printf("\n");
    }

    matriz_format(L, C, matriz);
    resultado = somatorio(L, C, matriz);

    printf("\nSoma dos elementos abaixo da diagonal secundaria: %d\n", resultado);

    return 0;
}

int somatorio(int L, int C, int mat[L][C]){

    int i, j;
    int soma = 0;

    for(i = 0; i < L; i++) {
        for(j = 0; j < C; j++) {
            if(i + j > L - 1) {
                soma = soma + mat[i][j];
            }
        }
    }

    return soma;
}

void matriz_format(int L, int C, int mat[L][C]){

    int i, j;

    printf("\n===== MATRIZ FORMATADA =====\n\n");

    for(i = 0; i < L; i++) {
        for(j = 0; j < C; j++) {
            printf("%d\t", mat[i][j]);
        }

        printf("\n");
    }
}