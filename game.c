#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int dificuldade;
	int valor1;
	int valor2;
	int operacao;
	int resultado;
} Calcular;

void jogar();
void mostrarInfo(Calcular calc);
int somar(int resposta, Calcular calc);
int diminuir(int resposta, Calcular calc);
int multiplicar(int resposta, Calcular calc);

int pontos = 0;

int main(){

	//Deve ser chamado apenas uma vez
	srand(time(NULL));

	jogar();

	return 0;
}

void jogar(){
	Calcular calc;
	int dificuldade;

	printf("Informe o n�vel de dificuldade desejada [1, 2, 3 ou 4]: \n");
	fflush(stdout);
	scanf("%d", &dificuldade);
	calc.dificuldade = dificuldade;

	//Gera um inteiro rand�mico entre 0 e 2
	//0 == somar, 1 == diminuir, 2 == multiplicar
	calc.operacao = rand() % 3;

	if(calc.dificuldade == 1){
		//f�cil
		calc.valor1 = rand() % 11; //0 a 10
		calc.valor2 = rand() % 11;
	}else if(calc.dificuldade ==2){
		//m�dia
		calc.valor1 = rand() % 101; //0 a 100
		calc.valor2 = rand() % 101;
	}else if(calc.dificuldade == 3){
		//dif�cil
		calc.valor1 = rand() % 1001; //0 a 1000
		calc.valor2 = rand() % 1001;
	}else if(calc.dificuldade == 4){
		//insano
		calc.valor1 = rand() % 10001; //0 a 10000
		calc.valor2 = rand() % 10001;
	}else{
		//ultra
		calc.valor1 = rand() % 100001; // 0 a 100000
		calc.valor2 = rand() % 100001;
	}

	int resposta;
	printf("Informe o resultado para a seguinte opera��o: \n");
	fflush(stdout);

	//Somar
	if(calc.operacao == 0){
		printf("%d + %d\n", calc.valor1, calc.valor2);
		fflush(stdout);
		scanf("%d", &resposta);

		if(somar(resposta, calc)){
			pontos += 1;
			printf("Voc� tem %d ponto(s)\n", pontos);
			fflush(stdout);
		}
	}//Diminuir
	else if(calc.operacao == 1){
		printf("%d - %d\n", calc.valor1, calc.valor2);
		fflush(stdout);
		scanf("%d", &resposta);

		if(diminuir(resposta, calc)){
			pontos += 1;
			printf("Voc� tem %d ponto(s)\n", pontos);
			fflush(stdout);
		}
	}//Multiplicar
	else if(calc.operacao == 2){
		printf("%d * %d\n", calc.valor1, calc.valor2);
		fflush(stdout);
		scanf("%d", &resposta);

		if(multiplicar(resposta, calc)){
		pontos += 1;
		printf("Voc� tem %d ponto(s)\n", pontos);
		fflush(stdout);
		}
	}//Desconhecida
	else{
		printf("A opera��o %d n�o � reconhecida!\n", calc.operacao);
		fflush(stdout);
	}

	//mostrarInfo
	//mostrarInfo(calc);

	//Recome�ar o jogo?
	printf("Deseja continuar jogando? [1 - sim; 0 - n�o]\n");
	fflush(stdout);
	int continuar;
	scanf("%d", &continuar);

	if(continuar == 1){
		jogar();
	}else{
		printf("Voc� finalizou com %d ponto(s)\n", pontos);
		printf("At� a pr�xima!");
		fflush(stdout);
		exit(0);
	}
}

void mostrarInfo(Calcular calc){
	char opcao[25];

	if(calc.operacao == 0){//0 == somar
		sprintf(opcao, "Somar");
	}else if(calc.operacao == 1){//1 == diminuir
		sprintf(opcao, "Diminuir");
	}else if(calc.operacao == 2){//2 == multiplicar
		sprintf(opcao, "Multiplicar");
	}else{
		sprintf(opcao, "Opera��o desconhecida");
	}
	printf("Valor 1: %d \nValor 2: %d \nDificuldade: %d \nOpera��o: %s\n\n",
			calc.valor1, calc.valor2, calc.dificuldade, opcao);
	fflush(stdout);
}

int somar(int resposta, Calcular calc){
	int resultado = calc.valor1 + calc.valor2;
	calc.resultado = resultado;
	int certo = 0;//0 == errou, 1 == acertou

	if(resposta == calc.resultado){
		printf("Resposta correta!\n");
		fflush(stdout);
		certo = 1;
	}else{
		printf("Resposta errada!\n");
		fflush(stdout);
	}
	printf("%d + %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
	fflush(stdout);

	return certo;
}

int diminuir(int resposta, Calcular calc){
	int resultado = calc.valor1 - calc.valor2;
	calc.resultado = resultado;
	int certo = 0;//0 == errou, 1 == acertou

	if(resposta == calc.resultado){
		printf("Resposta correta!\n");
		fflush(stdout);
		certo = 1;
	}else{
		printf("Resposta errada!\n");
		fflush(stdout);
	}
	printf("%d - %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
	fflush(stdout);

	return certo;
}

int multiplicar(int resposta, Calcular calc){
	int resultado = calc.valor1 * calc.valor2;
	calc.resultado = resultado;
	int certo = 0;//0 == errou, 1 == acertou

	if(resposta == calc.resultado){
		printf("Resposta correta!\n");
		fflush(stdout);
		certo = 1;
	}else{
		printf("Resposta errada!\n");
		fflush(stdout);
	}
	printf("%d * %d = %d\n", calc.valor1, calc.valor2, calc.resultado);
	fflush(stdout);

	return certo;
}
