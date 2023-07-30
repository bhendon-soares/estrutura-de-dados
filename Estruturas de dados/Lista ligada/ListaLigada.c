/*
	Name: ListaLigada.cpp
	Author: Bhendon Soares
	Date: 22/03/23 09:49
	Description: Implementação da Lista Encadeada simples
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//Estrutura para um nó da lista, contendo duas informações
//valor e o endereço de memória para o próximo nó
typedef struct No
{
	int valor;
	struct No *proximo; //aponta para o próximo nó
};

//estrutura que é a própria lista ligada com os vários nós
typedef struct Lista
{
	No *inicio, *fim;
	int tamanho;
};

//Função para inserir elementos no inicio da lista
void inserirInicio(Lista *lista, int vlr)
{
	No *novo = (No*) malloc(sizeof(No));
	novo->valor = vlr;
	
	if(lista->inicio == NULL) //se a lista estiver vazia
	{
		novo->proximo = NULL;
		lista->inicio = novo;
		lista->fim = novo;
	}
	else //se a lista não estiver vazia, ou seja, já contém elementos
	{
		novo->proximo = lista->inicio;
		lista->inicio = novo;
	}
	lista->tamanho++;
}

//Função para inserir elementos no fim da lista
void inserirFim(Lista *lista, int vlr)
{
	No *novo = (No*) malloc(sizeof(No)); //cria o novo nó
	novo->valor = vlr;
	novo->proximo = NULL;
	
	if(lista->inicio == NULL)
	{
		lista->inicio = novo;
		lista->fim = novo;
	}
	else
	{
		lista->fim->proximo = novo;
		lista->fim = novo;
	}
	lista->tamanho++;
}

//Função para exibir todo o conteúdo da lista
void imprimirLista(Lista *lista)
{
	No *inicio = lista->inicio;
	printf("Tamanho da lista: %d\n\n", lista->tamanho);
	
	//Laço para percorrer todos os Nós da lista
	while(inicio != NULL)
	{
		printf("%d ", inicio->valor);
		inicio = inicio->proximo;
	}
	printf("\n\n");
}

//Função para remover um item (Nó) da lista
void removerNoLista(Lista *lista, int vlr)
{
	No *inicio = lista->inicio; //ponteiro para o inicio da lista
	No *noARemover = NULL; //ponteiro para o nó a ser removido da lista
	
	if(inicio != NULL && lista->inicio->valor == vlr) //remove o 1º elemento da Lista
	{
		noARemover = lista->inicio;
		lista->inicio = noARemover->proximo;
		
		if(lista->inicio == NULL)
			lista->fim = NULL;
	}
	else //Remover nó do meio ou do fim da lista
	{
		while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != vlr)
		{
			inicio = inicio->proximo;
		}
		if(inicio != NULL && inicio->proximo != NULL)
		{
			noARemover = inicio->proximo;
			inicio->proximo = noARemover->proximo;
			if(inicio->proximo == NULL) //Se o ultimo elemento for removido
				lista->fim = inicio;
		}
	}
	if(noARemover)
	{
		free(noARemover);
		lista->tamanho--;
	}
}

main()
{
	Lista listaNumeros;
	//É necessário passar a lista como parametro com o "&" pois na função foi declarada como um ponteiro.
	
	int opc, vlr;
	listaNumeros.inicio = NULL;
	listaNumeros.fim = NULL;
	listaNumeros.tamanho = 0;
	
	while(1)
	{
		system("cls");
		printf("MENU DE OPCOES PARA LISTA LIGADA");
		printf("\n---------------------------------");
		printf("\n1 - Inserir no Inicio\n2 - Inserir no Fim\n3 - Exibir Lista\n4 - Remover item da Lista\n5 - Sair");
		printf("\n\nEscolha a sua opcao: ");
		scanf("%d", &opc);
		
		switch(opc)
		{
			case 1:
				printf("\nDigite um valor para inserir no inicio da lista: ");
				scanf("%d", &vlr);
				inserirInicio(&listaNumeros, vlr);
				break;
				
			case 2:
				printf("\nDigite um valor para inserir no fim da lista: ");
				scanf("%d", &vlr);
				inserirFim(&listaNumeros, vlr);
				break;
				
			case 3:
				printf("\nConteudo da Lista:\n");
				imprimirLista(&listaNumeros);
				break;
			
			case 4:
				imprimirLista(&listaNumeros);
				printf("\nDigite um valor a ser removido: ");
				scanf("%d", &vlr);
				removerNoLista(&listaNumeros, vlr);
				break;
				
			case 5:
				printf("\n\nFinalizando...\n");
				exit(0);
				
			default:
				printf("\n\n====> Opcao INVALIDA <====");
				
		}//fim do switch
		puts("\n\nPressione qualquer tecla para continuar");
		getch();
	}//fim do while
	
}//fim do main
