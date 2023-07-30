/*
	Name: MergeSort.cpp
	Author: Bhendon Soares
	Date: 16/05/23 11:26
	Description: Implementação do método de ordenação Merge Sort
				(Dividir para conquistar)
*/

#include <stdio.h>
#include <conio.h>

//Sessão de prototipação
void mergeSort(int *, int, int);
void merge(int *, int, int, int);

main()
{
	int vet[] = {13, 215, 7, -8, 4, 170, 8, 20};
	int init, end, i;
	init = 0;
	end = (sizeof(vet)/sizeof(int) - 1);
	
	puts("Vetor desordenado: ");
	for(i = 0; i <= end; i++)
		printf("%d |", vet[i]);
		
	mergeSort(vet, init, end);
	
	puts("\n\nVetor ordenado pelo MergeSort: ");
	for(i = 0; i <= end; i++)
		printf("%d |", vet[i]);
}

void mergeSort(int vet[], int init, int end)
{
	if(init < end)
	{
		int mid = (init + end) / 2;
		mergeSort(vet, init, mid);
		mergeSort(vet, mid + 1, end);
		merge(vet, init, mid, end);
	}
}

void merge(int vet[], int init, int mid, int end)
{
	int with1 = init, with2 = mid + 1,
		withAux = 0, size = (end - init + 1);
	int vetAux[size];
	
	while(with1 <= mid && with2 <= end)
	{
		if(vet[with1] < vet[with2])
		{
			vetAux[withAux] = vet[with1];
			with1++;
		}
		else
		{
			vetAux[withAux] = vet[with2];
			with2++;
		}
		withAux++;
	}
	
	while(with1 <= mid)
	{
		//Caso ainda haja elementos na primeira metade
		vetAux[withAux] = vet[with1];
		with1++;
		withAux++;
	}
	
	while(with2 <= end)
	{
		//Caso ainda haja elementos na segunda metade
		vetAux[withAux] = vet[with2];
		with2++;
		withAux++;
	}
	
	for(withAux = init; withAux <= end; withAux++)
		vet[withAux] = vetAux[withAux - init];
}

