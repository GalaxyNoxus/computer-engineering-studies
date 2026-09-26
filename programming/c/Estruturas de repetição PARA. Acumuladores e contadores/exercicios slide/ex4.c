/* Faça um programa que leia dez conjuntos de dois valores, o
primeiro representando o número do aluno e o segundo
representando a sua altura em centímetros. Encontre o aluno mais
alto e o mais baixo. Mostre o número do aluno mais alto e o número
do aluno mais baixo */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int aluno, numero_aluno, numero_maior, numero_menor;
    float altura_aluno, altura_maior, altura_menor;

    for (aluno = 1; aluno <= 10; aluno++){ // loop para ler os dados de 10 alunos

        printf("Digite o número do aluno: ");
        scanf("%d", &numero_aluno);
        printf("Digite a altura do aluno %d: ", numero_aluno);
        scanf("%f", &altura_aluno);
        printf("\n");
        
        if (aluno == 1){ // para o primeiro aluno, inicializar as variáveis de maior e menor altura
        altura_maior = altura_aluno;
        altura_menor = altura_aluno;
        numero_maior = numero_aluno;
        numero_menor = numero_aluno;

        } else { // para os demais alunos, comparar as alturas e atualizar as variáveis de maior e menor altura

            if (altura_maior < altura_aluno){ // se a altura do aluno atual for maior que a maior altura registrada, atualizar a maior altura e o número do aluno correspondente 
            altura_maior = altura_aluno;
            numero_maior = numero_aluno;
            }
            if (altura_menor > altura_aluno){ // se a altura do aluno atual for menor que a menor altura registrada, atualizar a menor altura e o número do aluno correspondente
            altura_menor = altura_aluno;
            numero_menor = numero_aluno;
            }
        }
    }

    printf("O aluno %d tem a maior altura com %.2f de altura.", numero_maior, altura_maior);
    printf("\nO aluno %d tem a menor altura com %.2f de altura.", numero_menor, altura_menor);

    return 0;
}