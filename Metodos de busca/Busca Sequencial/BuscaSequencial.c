/*
	Name: BuscaSequencial.cpp
	Author: Bhendon Soares
	Date: 26/04/23 08:17
	Description: Busca por um elemento dentro de uma estrutura do tipo array (vetor)
*/

#include <stdio.h>

main()
{
	int senha[] = {7, 202, 14, 25, 17, 8, 13, 19, 33, 51, 206, 81};
	int num, i, length;
	int flag = 0; //variável que apontará quando o número for encontrado
	
	printf("Tamanho do vetor senha em bytes: %d", sizeof(senha));
	printf("\nTamanho de um inteiro em bytes: %d", sizeof(int));
	
	length = sizeof(senha)/sizeof(int);
	printf("\nValor da variavel length: %d", length);
	
	//Trabalhar desta forma com o length do vetor, facilita utilizar uma estrutura de tamanho indefinido (vários elementos por exemplo)
	
	printf("\n");
	//laço para imprimir o vetor
	for(i = 0; i < length; i++)
		printf("%d | ", senha[i]);
	
	printf("\nDigite o numero a localizar: ");
	scanf("%d", &num);
	
	i = 0;
	while(i < length)
	{
		if(num == senha[i])
		{
			printf("\nNumero encontrado na %da posicao", i+1);
			flag = 1;
			break;
		}
			
		i++;
	}
	
	if(flag == 0)
		puts("\n\nNumero nao encontrado!");
	
}//fim do programa

