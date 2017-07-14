/*
* Vamos fazer uma fila, usando como base uma lista encadeada (Linked List)
* e armazenar apenas números inteiros.
*/
#include <stdio.h>
#include <stdlib.h>

//struct posicao para armazenar os dados que ficarão na fila
struct posicao{
	int dado;
	struct posicao *ptr;
}*comeco, *fim, *temp, *comeco1;

//Protótipos
int menu();
void criarFila();
int primeiroElemento();
void colocarFila(int);
void tirarFila();

void mostrarFila();
void tamanhoFila();

int count = 0;

void main(){
	int numero = 0, ch = 0, c = 0;

	criarFila();
	while ( 1 ){
		ch = menu();
		switch ( ch ){
			case 1:
				printf("Digite o Dado: ");
				scanf_s("%d", &numero);
				//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
				while ( (c = getchar()) != '\n' && c != EOF ){}
				colocarFila(numero);
				break;
			case 2:
				tirarFila();
				break;
			case 3:
				exit(0);
				break;
			case 8:
				if ( primeiroElemento() )
					printf("Primeiro Elemento: %d\n", primeiroElemento());
				else
					printf("\n Nenhum elemento na fila.\n");
				//para dar uma parada depois de mostrar o primeiro elemento
				printf("\n");
				system("Pause");
				break;
			case 9:
				mostrarFila();
				break;
			case 10:
				tamanhoFila();
				break;
			default:
				printf("Opcao invalida...\n");
				break;
		}
	}
}


int menu(){
	int ch = 0, c = 0;
	//para limpar a tela todas as vezes que chamar o menu
	system("cls");
	printf("\n 1 - Colocar na Fila");
	printf("\n 2 - Tirar da Fila");
	printf("\n 3 - Sair");

	printf("\n 8 - Primeiro Elemento");
	printf("\n 9 - Mostrar a Fila");
	printf("\n 10 - Tamanho da Fila");
	printf("\n Digite sua Escolha: ");
	scanf_s("%d", &ch);
	//sempre limpe o buffer de teclado depois de usar o scanf/scanf_s
	while ( (c = getchar()) != '\n' && c != EOF ){}
	return ch;
}

/* Create an empty queue */
void criarFila(){
	comeco = fim = NULL;
}

/* Returns queue size */
void tamanhoFila(){
	printf("Tamanho da fila:%d\n", count);
	//para dar uma parada depois de mostrar o tamanho da fila
	printf("\n");
	system("Pause");
}

/* Enqueing the queue */
void colocarFila(int numero){
	if ( fim == NULL ){
		//se o fim ainda é null, não temos nada na fila
		//vamos alocar a memória para esta estrutura dinâmicamente
		fim = (struct posicao *)malloc(1 * sizeof(struct posicao));
		fim->ptr = NULL;
		fim->dado = numero;
		comeco = fim;	//neste momento, comeco e fim estao iguais e apontam para nada
	} else{
		//temos algo na fila
		//vamos alocar memória de forma dinâmica para o temporário
		temp = (struct posicao *)malloc(1 * sizeof(struct posicao));
		//apontamos o fim da fila para o temp
		fim->ptr = temp;
		temp->dado = numero;
		temp->ptr = NULL;

		fim = temp;	//agora o fim é diferente do comeco criamos outra posicao na fila
	}
	count++;
}

/* Displaying the queue elements */
void mostrarFila(){
	//apenas para percorrer a fila sem perder o ponto inicial
	comeco1 = comeco;
	if ( (comeco1 == NULL) && (fim == NULL) ){
		printf("A fila está vazia\n");
		return;
	}
	while ( comeco1 != fim ){
		printf("%d ", comeco1->dado);
		comeco1 = comeco1->ptr;
	}
	if ( comeco1 == fim )
		printf("%d", comeco1->dado);

	//para dar uma parada depois de mostrar a fila
	printf("\n");
	system("Pause");
}

/* Dequeing the queue */
void tirarFila(){
	comeco1 = comeco;

	if ( comeco1 == NULL ){
		printf("A fila está vazia...\n");
		return;
	} else
		if ( comeco1->ptr != NULL ){
			comeco1 = comeco1->ptr;
			printf("Valor retirado da fila: %d\n", comeco->dado);
			free(comeco);
			comeco = comeco1;
		} else{
			printf("Valor retirado da fial: %d\n", comeco->dado);
			free(comeco);
			comeco = NULL;
			fim = NULL;
		}
	count--;

	//para dar uma parada depois de mostrar o valor retirado
	printf("\n");
	system("Pause");
}

/* Returns the comeco element of queue */
int primeiroElemento(){
	if ( (comeco != NULL) && (fim != NULL) )
		return(comeco->dado);
	else
		return 0;
}

