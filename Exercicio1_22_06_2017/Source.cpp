/*
Faça um programa para encontrar o fatorial de um número inteiro digitado 
pelo usuário usando a linguagem de programação C.
*/
#include <stdlib.h> 
#include <math.h> 
#include <stdio.h> 

//Você deve lembrar que não poderemos calcular o fatorial de
//números muito grandes. Estamos usando o tipo int. 
//Então, para testar use números menores que 20
//de preferência que você saiba o resultado. Ex.: 10 fatorial 3628800

//protótipo
int factorial(int);

int  main(){
	//sempre inicialize suas variáveis
	int i = 0, c = 0;
	printf("Digite o número desejado:");
	scanf_s("%d", &i);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ( (c = getchar()) != '\n' && c != EOF ){}

	//agora é só imprimir o retorno da função
	printf("Fatorial de %d: %d\n", i, factorial(i));

	system("Pause");
	return 0;
}

//fazendo a função recursiva
int factorial(int i){
	//condição de parada, para evitar o loop infinito
	if ( i <= 1 ){
		return 1;
	}
	//multiplica o valor inicial pelo valor devolvido pela 
	//função chamada com com o valor inicial menos 1
	return i * factorial(i - 1);
}
