/*
	Name: ShellSort.cpp
	Author: Bhendon Soares
	Date: 17/05/23 09:44
	Description: Implementa��o do m�todo de ordena��o Shell Sort
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//Sess�o de prototipa��o
void shellSort(int *, int);

main()
{
	//int vet[] = {104, 7, 66, 15, -7, 3, 9, 40, 23, 52, -20, 14, 154, 65, 10};
	int i, length;
	int vet[1000];
	length = sizeof(vet)/sizeof(int);
	
	//Gera n�meros aleat�rios at� o "% (valor), neste exemplo de 0 at� 1000"
	srand(time(NULL));
	for(i = 0; i < length; i++)
		vet[i] = rand() % 1000;
	
	puts("Vetor desordenado: ");
	for(i = 0; i < length; i++)
		printf(" %d |", vet[i]);
		
	shellSort(vet, length); //Chamada � fun��o de ordena��o
	
	puts("\n\nVetor ordenado pelo Shell Sort: ");
	for(i = 0; i < length; i++)
		printf(" %d |", vet[i]);
}//fim do programa

void shellSort(int *vet, int size)
{
	int i, j, valor;
	int h = 1; //vari�vel do salto
	
	while(h < size)
	{
		h = 3*h+1;
	}
	
	while(h > 0)
	{
		for(i = h; i < size; i++)
		{
			valor = vet[i];
			j = i;
			while(j > h-1 && valor <= vet[j-h])
			{
				vet[j] = vet[j-h];
				j = j - h;
			}
			vet[j] = valor;
		}
		h = h/2;
	}
}//fim da fun��o shellSort

