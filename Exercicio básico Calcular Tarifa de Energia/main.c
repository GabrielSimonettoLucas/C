#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Programa basico para calcular gasto energetico, considerando a utilizacao de kWh, tarifa, impostos e servicos.

int main() {
	
    //---------------------------------------------
    //Declaracao de todas as variaveis.
	int kWh;
	double tarifa, taxas_impostos, servicos, total;
    //---------------------------------------------

    //Envio de dados pela entrada padrão.

    printf("Informe a Quantia de kWh Consumida.\n");
	scanf(" %d", &kWh);
    printf("Informe o Valor da Tarifa Por kWh.\n");
	scanf(" %lf", &tarifa);
    printf("Informe a Taxa de Impostos.\n");
	scanf(" %lf", &taxas_impostos);
    printf("Informe a Taxa de Serviços.\n");
	scanf(" %lf", &servicos);

    //---------------------------------------------
    //Calculo do valor final.
	total = (kWh * tarifa) + taxas_impostos + servicos;

    //---------------------------------------------

    //impressao dos valores finais.

	printf("Dados do faturamento:\n");
	printf("Consumo............:%d kWh\n", kWh);
	printf("Tarifa (R$)........:%.3lf\n", tarifa);
	printf("Total (R$).........:%.2lf\n", kWh * tarifa);
	printf("Taxas e impostos...:%.2lf\n", taxas_impostos);
	printf("Serviços...........:%.2lf\n", servicos);
	printf("VALOR (R$).........:%.2lf\n", total);
	setlocale(LC_ALL, "Portuguese");
	
    //---------------------------------------------
    
	return 0;
}