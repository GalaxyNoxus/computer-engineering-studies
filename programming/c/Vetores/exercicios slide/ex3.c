#include <stdio.h>
#include <locale.h>

#define max 15
void pares(float v[]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    float vetor[max];
    int i;

    for (i=0; i<max; i++){

        printf("Digite o valor para V[%d]: ", i);
        scanf("%f", &vetor[i]);
    }

    pares(vetor);
}

void pares(float v[]){
    int x;

    for(x=0; x<max; x++){
        if(x %2==0)
            printf("\nPosição par %d: %.2f", x, v[x]);
    }
}