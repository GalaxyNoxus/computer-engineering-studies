#include <stdio.h>
#include <locale.h>

float calculo(int cod, int quant);
int main(){
    setlocale(LC_ALL, "Portuguesse");

    int codigo, quantidade;
    float valor_total;

    printf("=========== CARDÁPIO ===========\n\n");
    printf("\t\t Cód. \t Preço\n");
    printf("Cachorro Quente\t 100 \t R$1,20\n");
    printf("Bauru Simples \t 101 \t R$1,30\n");
    printf("Bauru com ovo \t 102 \t R$1,50\n");
    printf("Hambúrguer \t 103 \t R$1,20\n");
    printf("Cheeseburguer \t 104 \t R$1,30\n");
    printf("Refrigerante \t 105 \t R$1,00\n\n");
    printf("Digite o código do cardápio: ");
    scanf("%d", &codigo);

    while(codigo > 0){

    printf("Digite a quantidade do item %d: ", codigo);
    scanf("%d", &quantidade);
    
    valor_total = calculo(codigo, quantidade);

        printf("=========== CARDÁPIO ===========\n\n");
        printf("\t\t Cód. \t Preço\n");
        printf("Cachorro Quente\t 100 \t R$1,20\n");
        printf("Bauru Simples \t 101 \t R$1,30\n");
        printf("Bauru com ovo \t 102 \t R$1,50\n");
        printf("Hambúrguer \t 103 \t R$1,20\n");
        printf("Cheeseburguer \t 104 \t R$1,30\n");
        printf("Refrigerante \t 105 \t R$1,00\n\n");

        printf("Digite o código do cardápio: ");
        scanf("%d", &codigo);
    }

    printf("Valor total a pagar: R$%.2f", valor_total);

}

float calculo(int cod, int quant){
    static float valor_total=0; // static faz com que a variavel seja inicializado em zero apenas uma vez
    
    switch(cod){

        case 100:
        valor_total = valor_total + (1.20*quant);
        break;
        case 101:
        valor_total = valor_total + (1.30*quant);
        break;
        case 102:
        valor_total = valor_total + (1.50*quant);
        break;
        case 103:
        valor_total = valor_total + (1.20*quant);
        break;
        case 104:
        valor_total = valor_total + (1.30*quant);
        break;
        case 105:
        valor_total = valor_total + (1*quant);
        break;

        default:
            printf("Código inválido!");
        }
    
    return valor_total;
}