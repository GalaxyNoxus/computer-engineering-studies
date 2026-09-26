#include <stdio.h>
#include <locale.h>

float calculo(float alt_total, int cont);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int i_1=0, i_2=0;
    float altura=1, altura_total=0, media;
    
    while(altura!=0){
        printf("Digite a altura do aluno: ");
        scanf("%f", &altura);
        altura_total = altura_total + altura;
        i_1++;

        if(altura > 1,60 && altura < 1,75);
            i_2++;
    }

    media = calculo(altura_total, i_1);

    printf("A média das alturas é: %.2f", media);
    printf("A quantidade de alunos com altura entre 1.60 e 1.75 é: %d", i_2);
}

float calculo(float alt_total, int cont){
    float x;
    x = alt_total / cont;

    return x;
}

