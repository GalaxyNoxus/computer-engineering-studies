/*Faça um programa que carregue uma matriz 4x4 de números
reais na função principal. Através de uma função com retorno
calcule e mostre a soma dos elementos da diagonal secundária.*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define L 4
#define C 4

void matriz_format(float m[L][C]);
float diag_secun(float m[L][C]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i, j;
    float matriz[L] [C], resultado;

    for (i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("Digite um valor para Matriz [%d] [%d]: ", i, j);
            scanf("%f", &matriz[i] [j]);
        }
        
    }

    matriz_format(matriz);
    resultado = diag_secun(matriz);
    printf("A soma dos elementos da diagonal secundária é: %.2f", resultado);

    return 0;
}

float diag_secun(float m[L][C]){
    int i, j;
    float soma=0;

    for (i=0;i<L;i++){
        for(j=0;j<C;j++){
            if (i+j==L-1)
                soma=soma+m[i][j];
        }
        
    }
    
    return soma;
}

void matriz_format(float m[L][C]){
    int i, j;

    printf("======= MATRIZ FORMATADA =======\n");
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("%.2f\t", m[i][j]);
        }
    printf("\n");
    }
    printf("\n");
}