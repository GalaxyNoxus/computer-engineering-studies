#include <stdio.h>
#include <locale.h>

void calculo(float alt_total, int contagem);
int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    int idade=1, i=0;
    float altura, altura_total=0;
        
    printf("Digite a idade: ");
    scanf("%d", &idade);

    while (idade > 0)
    {
        printf("Digite a altura: ");
        scanf("%f", &altura);

        if (idade > 50)
        {
        altura_total = altura_total + altura;
        i++;
        }
        printf("\nDigite a idade: ");
        scanf("%d", &idade);
    }

    calculo(altura_total, i);
    
}

void calculo(float alt_total, int contagem){
    float media=0;

    media = alt_total / contagem;

    printf("A média das alturas das pessoas maiores de 50 anos é: %.2f", media);
}