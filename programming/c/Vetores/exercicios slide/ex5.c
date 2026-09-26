#include <stdio.h>
#include <locale.h>

#define max 5
void posicao(int vetor[]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i, vetor[max];

    for (i=0; i<max; i++){

        printf("Digite o valor para V[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    posicao(vetor);
}

void posicao(int vetor[]){
    int maior=vetor[0], menor=vetor[0], pos_maior, pos_menor, i;
    
    for(i=0; i<max; i++){

        if(vetor[i] >= maior){
            maior = vetor[i];
            pos_maior = i;
        }

        if(vetor[i] <= menor){
            menor = vetor[i];
            pos_menor = i;
        }

    }

    printf("\nO maior valor é %d na posição [%d] do vetor", maior, pos_maior);
    printf("\nO menor valor é %d na posição [%d] do vetor", menor, pos_menor);
}