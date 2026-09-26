
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calculo(float som, int cont);
int main()
{
    setlocale(LC_ALL, "Portuguese");

    int idade, pessoa, contador=0;
    float altura, soma=0, resultado;

    for (pessoa = 1; pessoa <= 10; pessoa++){ // loop para ler os dados de 10 pessoas
        printf("=== PESSOA %d ===", pessoa);
        printf("\nDigite a idade: ");
        scanf("%d", &idade);
        printf("Digite a altura: ");
        scanf("%f", &altura);
        printf("\n");

        if (idade > 50){
            soma = soma + altura;
            contador = contador + 1;
        }
    }

    resultado = calculo(soma, contador);
    printf("A média das alturas das pessoas com mais de 50 anos é: %.2f", resultado);
    
    getchar(); // esperar o usuário pressionar Enter para fechar o programa
    return 0;
}
float calculo(float som, int cont){
    float media;
    media = som/cont;
    return media;
}