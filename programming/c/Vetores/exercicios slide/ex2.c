#include <stdio.h>
#include <locale.h>

#define max 7
void temp_mais_alta(float vetor[]);

int main(){
    setlocale(LC_ALL, "Portuguese");

    float vetor[max];
    int i;

    for (i=0; i<max; i++){
        printf("Digite a temperadtura do dia %d: ", i);
        scanf("%f", &vetor[i]);
    }

    temp_mais_alta(vetor);
}

void temp_mais_alta(float vetor[]){
    int x, dia;
    float maior_temp = vetor[0];

    for(x=0; x<max; x++){
        if(vetor[x] >= maior_temp){
            maior_temp = vetor[x];
            dia = x;
        }
    }
    
    if(dia==0)
        printf("\nA maior temperatura registrada foi no domingo: %.2f graus", maior_temp);
    else if(dia==1)
        printf("\nA maior temperatura registrada foi na segunda-feira: %.2f graus", maior_temp);
    else if(dia==2)
        printf("\nA maior temperatura registrada foi na terça-feira: %.2f graus", maior_temp);
    else if(dia==3)
        printf("\nA maior temperatura registrada foi na quarta-feira: %.2f graus", maior_temp);
    else if(dia==4)
        printf("\nA maior temperatura registrada foi na quinta-feira: %.2f graus", maior_temp);
    else if(dia==5)
        printf("\nA maior temperatura registrada foi na sexta-feira: %.2f graus", maior_temp);
    else if(dia==6)
        printf("\nA maior temperatura registrada foi no sábado: %.2f graus", maior_temp);
}