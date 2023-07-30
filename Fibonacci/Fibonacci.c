/*
	Name: Fibonacci.cpp
	Author: Bhendon Soares 
	Date: 08/03/23 10:10
	Description: Programa para demonstrar a sequ�ncia de Fibonacci
*/

//sess�o de importa��o
#include <stdio.h>

//prototipa��o de fun��es
int fibo(int);

//Vari�vel global
int limite = 0;

main()
{
	printf("Quantos numeros da sequencia de Fibonacci deseja exibir: ");
	scanf("%d", &limite);
	
	for(int i = 1; i <= limite; i++)
		printf("%d, ", fibo(i));
}

int fibo(int n)
{
	if(n == 1)
		return 1;
	if(n == 2)
		return 1;
		
	return (fibo(n-1) + fibo(n-2));
}
