#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int cpf, dependentes;
    float renda, qntd_sal_min, imposto, desconto_dep;

    printf("Digite o CPF: ");
    scanf("%d", &cpf);

    while(cpf!=0){
    printf("Digite o numero de depentendes: ");
    scanf("%d", &dependentes);
    printf("Digite sua renda mensal: ");
    scanf("%d", &renda);

    qntd_sal_min = renda / 1621;
    desconto_dep = (1621 * 0.05) * dependentes;

    if(qntd_sal_min < 2)
        imposto = 0;
    else if(qntd_sal_min >= 2 && qntd_sal_min <= 3)
        imposto = (renda * 0.05) - desconto_dep;
    else if(qntd_sal_min > 3 && qntd_sal_min <= 5)
        imposto = (renda * 0.10) - desconto_dep;
    else if(qntd_sal_min > 5 && qntd_sal_min <= 7)
        imposto = (renda * 0.15) - desconto_dep;
    else
        imposto = (renda * 0.20) - desconto_dep;
    
    printf("\n%d - Imposto de renda: %.2f", cpf, imposto);
    printf("\nInforme zero para encerrar ou digite o próximo CPF: ");
    scanf("%d", &cpf);

    }
}