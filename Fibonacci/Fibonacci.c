/*
	Name: Fibonacci.cpp
	Author: Bhendon Soares 
	Date: 08/03/23 10:10
	Description: Programa para demonstrar a sequência de Fibonacci
*/

//sessão de importação
#include <stdio.h>

//prototipação de funções
int fibo(int);

//Variável global
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
