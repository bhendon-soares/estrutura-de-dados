/*
	Name: LoginSenha.cpp
	Author: Bhendon Soares
	Date: 08/03/23 08:03
	Description: Programa que simula o login do Windows
*/

# include <stdio.h>

//variável global - deve ser declarada fora do main
char nome = 'B';
int senha = 123;

//Sessão de prototipação
void verLogin();
void verSenha();

main()
{
	verLogin();
}

//a função deve ter o verbo no infinitivo!
void verLogin()
{
	char usuario;
	printf("Digite o usuario: ")/
	scanf(" %c", &usuario);
	
	if(usuario == nome)
		verSenha();
	else
		verLogin();
}

void verSenha()
{
	int pwd = 0;
	printf("Senha: ");
	scanf("%d", &pwd);
	
	if(pwd == senha)
		puts("Login efetuado com sucesso!");
	else
		verLogin();
}
