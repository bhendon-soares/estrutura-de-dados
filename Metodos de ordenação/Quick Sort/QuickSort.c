/*
	Name: QuickSort.cpp
	Author: Bhendon Soares
	Date: 17/05/23 10:16
	Description: Implementação do método de ordenação Quick Sort
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//Sessão de prototipação
void quickSort(int *, int, int);
int particionar(int *, int, int);

main()
{
	//int vet[] = {104, 7, 66, 15, -7, 3, 9, 40, 23, 52, -20, 14, 154, 65, 10};
	int i, length;
	int vet[100];
	length = sizeof(vet)/sizeof(int);
	
	//Gera números aleatórios
	srand(time(NULL));
	for(i = 0; i < length; i++)
		vet[i] = rand() % 100;
	
	puts("Vetor desordenado: ");
	for(i = 0; i < length; i++)
		printf(" %d |", vet[i]);

	quickSort(vet, 0, length - 1); //Chamada à função de ordenação
	
	puts("\n\nVetor ordenado pelo Quick Sort: ");
	for(i = 0; i < length; i++)
		printf(" %d |", vet[i]);	
}

void quickSort(int *vet, int inicio, int fim)
{
	int pivo;
	if(fim > inicio)
	{
		pivo = particionar(vet, inicio, fim);
		quickSort(vet, inicio, pivo-1);
		quickSort(vet, pivo+1, fim);
	}
}

int particionar(int *vet, int inicio, int fim)
{
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = fim;
	pivo = vet[inicio];
	
	while(esq < dir)
	{
		while(vet[esq] <= pivo)
			esq++;
		while(vet[dir] > pivo)
			dir--;
			
		if(esq < dir)
		{
			aux = vet[esq];
			vet[esq] = vet[dir];
			vet[dir] = aux;
		}
	}//fim do while
	
	vet[inicio] = vet[dir];
	vet[dir] = pivo;
	return dir;
}
