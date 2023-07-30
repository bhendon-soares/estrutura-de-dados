/*
	Name: Fila.cpp
	Author: Bhendon Soares
	Date: 05/04/23 09:40
	Description: Implementação do conceito de filas (FIFO)
*/

#include <conio.h>
#include <stdio.h>
#include <windows.h>

//Sessão de prototipação
void inserir(int); //inserir um elemento no fim da fila
int retirar(); //retira um elemento do começo da fila
int isEmpty(); //testa se a fila está vazia
int isFull(); //testa se a fila está cheia
void imprimirFila(); //mostrar os elementos da fila

int inicio, fim, total; //variáveis globais
int senhas[5]; //Estrutura de fila com 5 elementos - array

main()
{
	inicio = 0;
	fim = 0;
	total = 0;

	while(1)
	{
		int menu = 0;
		printf("1 - Inserir na Fila\n2 - Retirar elemento\n3 - Exibir fila\n4 - Sair");
		printf("\nOpcao: ");
		scanf("%d", &menu);
		
		switch(menu)
		{
			case 1:
				int e;
				e = 0;
				printf("Digite o elemento a incluir: ");
				scanf("%d", &e);
				inserir(e);
				break;
				
			case 2:
				retirar();
				break;
				
			case 3:
				imprimirFila();
				break;
				
			case 4:
				exit(0);
				
			default:
				puts("Opcao invalida!");
		}//fim do switch
		puts("\n\nPressione qualquer tecla para continuar");
		getch();
		system("cls");
	}//fim do while
}//fim do main

//insere um elemento no final do fila
void inserir(int elem)
{
	if(isFull() == 1)
		puts("A fila esta cheia!");
	else
	{
		senhas[fim] = elem;
		fim = (fim+1)%5;
		total++;
	}
}

//retira um elemento do incio da fila
int retirar()
{
	if(isEmpty() == 1)
		puts("A fila está vazia");
	else
	{
		int elemento;
		elemento = senhas[inicio];
		inicio = (inicio+1)%5;
		total--;
		return elemento;
	}
}

//testa se a fila está vazia
int isEmpty()
{
	if(total == 0)
		return 1; //true
	else
		return 0; //false
}

//testa se a fila está cheia
int isFull()
{
	if(total == 5)
		return 1; //true
	else
		return 0; //false
}

//exibe todo o conteúdo da fila
void imprimirFila()
{
	printf("\n");
	int cont, i;
	for(cont = 0, i = inicio; cont < total; cont++)
	{
		printf("%d|", senhas[i++]);
		if(i == 5)
			i = 0;
	}
}
