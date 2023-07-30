/*
	Name: Pilhas.cpp
	Author: Bhendon Soares
	Date: 18/04/23 18:18
	Description: Programa para demonstrar o funcionamento do conceito de Pilhas - LIFO
*/

#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <locale.h>

//Sessão de Prototipação
void push (char); //inserir elemento
char pop(); //retira um elemento
int isEmpty(); //se está vazia
int isFull(); //se está cheia
char top(); //aponta pro elemento do topo da pilha
void listarPilha(); //imprime elementos da pilha
void conversorBinario();
void exibirNumBinario();

//Variáveis globais
char pilha[10];
int topo = -1; //recebe -1 para indicar que ele não está apontando para nenhum elemento da pilha

main()
{
	setlocale(LC_ALL, "Portuguese");
	
	while(1)
	{
		int opc = 0;
		printf("\n1 - Inserir elemento\n2 - Retirar elemento\n3 - Exibir elementos\n4 - Conversor binário\n5 - Sair");
		printf("\n\nInsira uma opção: ");
		scanf("%d", &opc);
		
		switch(opc)
		{
			case 1:
				char e;
				printf("Insira um caractere na pilha de letras: ");
				scanf(" %c", &e);
				push(e);
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				listarPilha();
				break;
			
			case 4:
				conversorBinario();
				break;
				
			case 5:
				exit(0);
				
			default:
				printf("Opção inválida, digite novamente");
		}//fim do switch
		
		puts("\n=> Pressione qualquer tecla <=");
		getch();
		system("cls");
		
	}//fim do while
}//fim do main

void push(char elem)
{
	if(isFull() == 1)
	{
		puts("\nPilha cheia => Stack Overflow");
	}
	else
	{
		topo++;
		pilha[topo] = elem;
	}
}//fim do push

char pop()
{
	if(isEmpty() == 1)
	{
		puts("\nPilha vazia");
	}
	else
	{
		char elemento;
		elemento = pilha[topo];
		topo--;
		return elemento;
	}
}//fim do pop

int isEmpty()
{
	if(topo == 1)
		return 1;
	else
		return 0;
}//fim do isEmpty

int isFull()
{
	if(topo == 10)
		return 1;
	else
		return 0;
}//fim do isFull

char top()
{
	return pilha[topo];
}//fim do top

void listarPilha()
{
	puts("\nConteúdo da pilha: ");
	if(isEmpty() == 1)
		puts("\nPilha vazia");
	else for(int i = topo; i >= 0; i--)
	{
		printf("\n %d | %c |", i, pilha[i]);
	}
}//fim do listarPilha

void conversorBinario()
{
	int numBaseDez = 0;
	printf("Digite um número na base dez: ");
	scanf("%d", &numBaseDez);
	
	while(numBaseDez >= 2)
	{
		push(numBaseDez % 2);
		numBaseDez = numBaseDez/2;
	}
	
	push(numBaseDez);
	exibirNumBinario();
}//fim do conversorBinario

void exibirNumBinario()
{
	puts("Equivalente binário: ");
	while(isEmpty() == 0)
	{
		int elemento;
		elemento = pop();
		printf("%d", elemento);
	}
}//fim do exibirNumBinario
