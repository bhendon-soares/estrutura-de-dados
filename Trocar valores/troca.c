/*
	Name: troca.cpp
	Author: Bhendon Soares 
	Date: 15/03/23 10:26
	Description: Programa para efetuar a troca de valores entre variáveis
*/

#include <stdio.h>

//Sessão de prototipação
void trocar(int *, int *);

main()
{
	int a, b;
	a = 5;
	b = 12;
	printf("A: %d", a);
	printf("\nB: %d", b);
	
	puts("\n\nApos a troca: ");
	trocar(&a, &b); //passa o endereço das variáveis a e b;
	printf("A: %d", a);
	printf("\nB: %d", b);
}

//passagem de parâmetro por referência (ponteiro)
void trocar(int *a, int *b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
