#include <stdio.h>
#include <locale.h>

#define max 10
int negativos(int v[]);
void soma(int v[]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    int i, n, vetor[max];

    for (i=0; i<max; i++){

        printf("Digite o valor para V[%d]: ", i);
        scanf("%d", &vetor[i]);
    }

    n = negativos(vetor);
    soma(vetor);

    printf("\n A quantidade de números negativos do vetor é: %d", n);
}

int negativos(int v[]){
    int x=0, i;

    for(i=0; i<max; i++){
        if(v[i] < 0)
            x = x + 1;
    }

    return x;
}

void soma(int v[]){
    int i, x;

    for(i=0; i<max; i++){
        if(v[i] > 0)
            x = x + v[i];
    }
    
    printf("\n A soma dos números positivos do vetor é: %d", x);
}