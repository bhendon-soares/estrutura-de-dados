/*
	Name: SelecionSort.cpp
	Author: Bhendon Soares
	Date: 03/05/23 09:57
	Description: Implementação do algoritmo de ordenação por seleção - 1964
*/

#include <stdio.h>

main()
{
	//int vet[] = {7, 202, 14, 25, 17, 8, 13, 19};
	//int vet[] = {13, 215, 7, -8, 4, 170, 8, 20};
	int vet[] = {7, 8, 13, 14, 17, 19, 25, 202};
	int tam = sizeof(vet) / sizeof(int);
	int i, j, menor, aux;
	int trocas = 0;  //variável para totalizar a qtd de trocas
	int comp = 0;	//variável para totalizar a qtd de comparações
	
	//Imprimir vetor sem ordenação
	puts("Vetor DESORDENADO!");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
	
	
	for(i = 0; i < tam; i++)
	{
		menor = i;
		for(j = i + 1; j < tam; j++)
		{
			if(vet[j] < vet[menor])
				menor = j;
				
			comp++;
		}
		
		comp++;
		if(i != menor)
		{
			aux = vet[i];
			vet[i] = vet[menor];
			vet[menor] = aux;
			trocas++;
		}
	}
	
	//Imprimir vetor Ordenado
	puts("\n\nVetor ORDENADO pelo Selection Sort!");
	for(i = 0; i < tam; i++)
		printf("%d|", vet[i]);
		
	printf("\nQuantidade de trocas: %d", trocas);
	printf("\nQuantidade de comparacoes: %d", comp);
}

