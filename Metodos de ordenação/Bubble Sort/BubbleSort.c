/*
	Name: BubbleSort.cpp
	Author: Bhendon Soares
	Date: 06/06/23 15:50
	Description: Implementação do método de ordenação BubbleSort
*/

#include <stdio.h>

main()
{
	int vet[] = {13, 12, -5, 19, 28, -2, 3, 9, 33, 20};
	int length = sizeof(vet)/sizeof(int);
	int i, aux, j;
	
	puts("Vetor desordenado: ");
	for(i = 0; i < length; i++)
		printf(" %d |", vet[i]);
	
	//Implementação do BubbleSort
	for(j = 1; j < length; j++)
	{
		for(i = 0; i < length-1; i++)
		{
			if(vet[i] > vet[i+1])
			{
				aux = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = aux;
			}
		}
	}
	
	puts("\n\nVetor ordenado pelo BubbleSort: ");
	for(i = 0; i < length; i++)
		printf(" %d |", vet[i]);	
}
