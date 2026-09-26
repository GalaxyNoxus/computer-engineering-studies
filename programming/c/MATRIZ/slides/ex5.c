/*Faça um programa que preencha, na função principal, uma
matriz 10 x 3 com as notas de dez alunos em três provas. O
algoritmo deverá, através de uma função sem retorno, mostrar
um relatório com o número do aluno (número da linha) e a média
das provas.*/

#include <stdio.h>
#include <locale.h>

#define L 4
#define C 3

void media(float matriz[L][C]);
void matriz_format(float MAT[L][C]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    float notas[L][C];
    int i, j;

    for(i=0; i<L; i++){
        for(j=0; j<C; j++){

            printf("Digite a nota do aluno %d: ", i+1);
            scanf("%f", &notas[i][j]);
        }

        printf("\n");
    }
    matriz_format(notas);
    media(notas);

}

void media(float matriz[L][C]){
    int i, j;
    float soma=0, media;

    for(i=0; i<L; i++){
        for(j=0; j<C; j++){
            soma = soma + matriz[i][j];
        }
        media = soma/3;
        printf("\nAluno %d - Média: %.2f", i+1, media);
        soma = 0;
    }
}

void matriz_format(float MAT[L][C]){
    int i, j;

    printf("\n=== MATRIZ FORMATADA ===\n\n");
    for(i=0;i<L;i++){
        for(j=0;j<C;j++){
            printf("%.1f\t", MAT[i][j]);
        }
        printf("\n");
    }
}