/*
	Name: troca.cpp
	Author: Bhendon Soares 
	Date: 15/03/23 10:26
	Description: Programa para efetuar a troca de valores entre vari�veis
*/

#include <stdio.h>

//Sess�o de prototipa��o
void trocar(int *, int *);

main()
{
	int a, b;
	a = 5;
	b = 12;
	printf("A: %d", a);
	printf("\nB: %d", b);
	
	puts("\n\nApos a troca: ");
	trocar(&a, &b); //passa o endere�o das vari�veis a e b;
	printf("A: %d", a);
	printf("\nB: %d", b);
}

//passagem de par�metro por refer�ncia (ponteiro)
void trocar(int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
