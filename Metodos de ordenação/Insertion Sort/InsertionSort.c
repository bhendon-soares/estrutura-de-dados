/*
	Name: InsertionSort.cpp
	Author: Bhendon Soares
	Date: 16/05/23 11:16
	Description: Implementação do método de ordenação Insertion Sort
*/

#include <stdio.h>
#include <conio.h>

//Sessão de prototipação
void insertionSort (int *, int);

main()
{
	int vet [] = {13, 215, 7, -8, 4, 170, 8, 20};
	int i;
	int length = sizeof(vet)/sizeof(int);
	
	puts("Vetor Desordenado: ");
	for(i = 0; i < length; i++)
		printf("| %d ", vet[i]);

	insertionSort(vet, length);

	puts("\n\nVetor Ordenado pelo Insertion Sort: ");
	for(i = 0; i < length; i++)
		printf("| %d", vet[i]);

}

void insertionSort(int vet[], int length)
{
	int i, j, key;
	
	for(i = 1; i < length; i++)
	{
		key = vet[i];
		j = i - 1;
		while(j >= 0 && vet[j] > key)
		{
			vet[j+1] = vet[j];
			j = j - 1;
		}
		vet[j+1] = key;
	}	
}

