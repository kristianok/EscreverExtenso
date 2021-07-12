#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

//Função para retornar o texto equivalente a unidade e os casos especiais de 11 até 19 de um numero
char* escreverUnidade(int unidade){
	if(unidade == 1){
		return "um";
	}
	
	else if(unidade == 2){
		return "dois";
	}
	
	else if(unidade == 3){
		return "tres";
	}
	
	else if(unidade == 4){
		return "quatro";	
	}
	
	else if(unidade == 5){
		return "cinco";	
	}
	
	else if(unidade == 6){
		return "seis";		
	}
	
	else if(unidade == 7){
		return "sete";		
	}
	
	else if(unidade == 8){
		return "oito";		
	}
	
	else if(unidade == 9){
		return "nove";		
	}
	
	else if(unidade == 10){
		return "dez";
	}
	
	else if(unidade == 11){
		return "onze";
	}
	
	else if(unidade == 12){
		return "doze";	
	}
	
	else if(unidade == 13){
		return "treze";	
	}
	
	else if(unidade == 14){
		return "quatorze";		
	}
	
	else if(unidade == 15){
		return "quinze";		
	}
	
	else if(unidade == 16){
		return "dezesseis";		
	}
	
	else if(unidade == 17){
		return "dezessete";		
	}
	else if(unidade == 17){
		return "dezoito";		
	}
	else if(unidade == 17){
		return "dezenove";		
	}

}
// Função para retornar o texto referente a casa dos milhares de um numero através do uso da função das unidades
char* escreverMilhar (int milhar) {
	static char unidade[10] = "";
	char valorMilharExtenso[5];
	if(milhar == 1){
		return unidade;
	}
	else{
    strcpy(unidade, escreverUnidade(milhar));
	return unidade;
	}
	
}

//Função para escrever os valores da casa das centenas
char* escreverCentena (int centena){
	static char centenaEx[15];
	if(centena == 1){
		 return "cento";
	}
	
	else if(centena == 2){
		return "duzentos";
	}
	
	else if(centena == 3){
		return "trezentos";
	}
	
	else if(centena == 4){
		return "quatrocentos";	
	}
	
	else if(centena == 5){
		 return "quinhentos";	
	}
	
	else if(centena == 6){
		 return "seiscentos";		
	}
	
	else if(centena == 7){
		return "setecentos";		
	}
	
	else if(centena == 8){
		return "oitocentos";		
	}
	
	else if(centena == 9){
		return "novecentos";		
	}
}
//Função para retornar o texto equivalente as dezenas
char* escreverDezena (int dezena){
	
	if(dezena == 2){
		return "vinte";
	}
	
	else if(dezena == 3){
		return "trinta";
	}
	
	else if(dezena == 4){
		return "quarenta";	
	}
	
	else if(dezena == 5){
		return "cinquenta";	
	}
	
	else if(dezena == 6){
		return "sessenta";		
	}
	
	else if(dezena == 7){
		return "setenta";		
	}
	
	else if(dezena == 8){
		return "oitenta";		
	}
	
	else if(dezena == 9){
		return "noventa";		
	}
}

void main (void) {
	float valor,resto;
	int milhar,centena,dezena,unidade;
	// booleano utilizado para confirmar a existencia de numeros anteriores que requerem o uso da conjunção e
	bool conjun = false;
	//Leitura do valor a ser transformado
	printf("Digite o valor em reais: ");
	scanf("%f",&valor);
	//separação do valor em cada uma das casas dos numeros
	while(valor != 10000){
	//Lendo o valor em centavos
	int centavos = round(fabs((valor - ((long)valor)))* 100);
	resto = valor;	
	if(valor >= 1000){
		milhar = (int) valor / 1000;
		//Escrever o valor da unidade na casa dos milhares adicionando mil ao texto. Caso a unidade do milhar sseja 1 %s tera valor de "" e apenas mil será escrito
	    printf("%s mil ", escreverMilhar(milhar)); 
		resto = (int) valor % 1000;
		conjun = true;
	}
	//caso especial no qual deve ser escrito cem e não cento
	if(resto == 100){
	    printf("cem");
	}
	if(resto > 100){
		centena = (int) resto / 100;
		//Escrita do texto da centena
	    printf("%s", escreverCentena(centena)); 
		resto = (int) resto % 100;
		conjun = true;
	}
	if(resto >= 10){
		dezena = (int) resto / 10;
		if(dezena != 1){
			if(conjun){
				//Escrita da conjunção e
				printf(" e ");
			}
			//Escrita do texto da dezena
	    printf("%s", escreverDezena(dezena)); 
		resto = (int) resto % 10;
		conjun = true;
		}
	}
	if(resto >= 1){
		unidade = (int) resto;
		if(conjun){
			    //Escrita da conjunção e
				printf(" e ");
		}
			//Escrita do texto da unidade
	    printf("%s", escreverUnidade(unidade)); 
	}
	//concordancia gramatical caso o valor seja uma unidade
	if(valor < 2 && valor > 1){
		printf(" real");
		if(centavos != 0){
		printf(" e ");
		}	
	}
	else {
	//escrita de reais ao final do numero
		if((int)valor > 0){
		printf(" reais");
		if(centavos != 0){
		printf(" e ");
		}
	}
	}
	//Caso especial zero
	if(valor == 0){
		printf("zero");
	}
	

	
	//testes para escrever os centavos se houver
	if(centavos != 0){
		resto = centavos;
		if(centavos <= 19){
		printf("%s", escreverUnidade((int)resto));	
		}
		else{
		 dezena = resto / 10;
		 printf("%s", escreverDezena(dezena)); 
		 resto -= dezena * 10;
		 if(resto != 0){
		 printf(" e ");
		 printf("%s", escreverUnidade(resto));
		}
		}
		if(centavos == 1){
			printf(" centavo");
		}
		else {
		printf(" centavos");
		}
	}
	conjun = false;
	printf("\nDigite o valor em reais: ");
	scanf("%f",&valor);
}
}


