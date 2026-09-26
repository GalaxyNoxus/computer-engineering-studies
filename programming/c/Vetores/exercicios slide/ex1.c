#include <stdio.h>
#include <locale.h>

#define MAX 10
int soma(int vetor[]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int V[MAX], i, resultado;

    for (i=0; i<MAX; i++){

        printf("Digire o valor para V[%d]: ", i);
        scanf("%d", &V[i]);
    }

    resultado = soma(V);
    printf("\nA soma dos pares do vetor é: %d", resultado);
}

int soma(int vetor[]){
    int x, soma=0;

    for (x=0; x<MAX; x++){
        if(vetor[x] %2==0)
            soma = soma + vetor[x];
    }

    return soma;
}