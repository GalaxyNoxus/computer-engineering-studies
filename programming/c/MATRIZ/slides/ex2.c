/*Fa�a um programa que preencha uma matriz M 2 x 2 na
fun��o principal. Atrav�s de uma fun��o sem retorno calcule e
mostre a matriz resultante da multiplica��o dos elementos de M
pelo seu maior elemento.*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define L 2
#define C 2

void matriz_format(float MAT[L][C]);
void multiplica_maior(float mat[L][C]);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float M[L][C], resultado;
    int i, j;

    //entrada de dados
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("Digite o valor M[%d][%d]: ", i, j);
            scanf("%f", &M[i][j]);
        }
    }
    matriz_format(M);
    multiplica_maior(M);
}

void multiplica_maior(float mat[L][C]){
    int i, j;
    float maior = mat[0][0];

    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            if(mat[i][j]>maior)
                maior = mat[i][j];
        }
    }
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            mat[i][j] = mat[i][j] * maior;
        }
    }
    matriz_format(mat);
}

void matriz_format(float MAT[L][C]){
    int i, j;

    printf("\nMATRIZ FORMATADA\n");
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("%.1f\t", MAT[i][j]);
        }
        printf("\n");
    }
}