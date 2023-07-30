/*
	Name: BuscaBinaria.cpp
	Author: Bhendon Soares
	Date: 06/06/23 21:51
	Description: Implementação do método de busca binária
*/

#include <stdio.h>

//Sessão de prototipação
void buscaBinaria(int *, int, int);

int achou = 0;

main()
{
	int vet[] = {13, 12, -5, 19, 28, -2, 3, 9, 33, 20};
	int length = sizeof(vet)/sizeof(int);
	int i, j, aux;
	int elemento = 0;
	
	puts("Vetor desordenado: ");
	for(i = 0; i < length; i++)
		printf(" %d |", vet[i]);
		
	//Implementação do BubbleSort
	for(j = 1; j < length; j++)
	{
		for(i = 0; i < length; i++)
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
		
	printf("\n\nDigite um elemento para ser buscado no vetor: ");
	scanf("%d", &elemento);
	
	buscaBinaria(vet, elemento, length);
}

void buscaBinaria(int *vet, int elemento, int length)
{
	int inicio, meio, fim;
	inicio = 0;
	fim = length - 1; //ultimo indice
	int comparacoes = 0;
	
	while(inicio <= fim)
	{
		meio = (inicio+fim)/2;
		comparacoes++;
		
		//O elemento é igual a meio?
		if(elemento == vet[meio])
		{
			achou = 1;
			break;
		}
		else if(elemento < vet[meio])
			fim = meio - 1;
		else
			inicio = meio + 1;
	}
	
	if(achou == 0)
		puts("Elemento não encontrado!");
	else
		printf("Elemento %d encontrado na posicao %d", elemento, (meio+1));
		
	printf("\nO numero de comparacoes feitas foram: %d", comparacoes);
}
