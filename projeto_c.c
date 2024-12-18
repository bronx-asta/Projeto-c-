#include <stdio.h> //Biblioteca de comunica�ao com o usuario usuario
#include <stdlib.h> //biblioteca de aloca�ao de espa�o em memoria
#include <locale.h> //biblioteca de aloca�ao de texto por regiao
#include <string.h> //biblioteca responsavel por cuidar dos sting

int registro() //fun��o responsavel por cadastrar os usuarios no sistema
{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final cria��o de variaveis/string
	
	printf("digite o CPF a ser cadastrado: "); //coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores dos string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("digite o CPF a ser consultado: "); //recebendo qual �suario a ser consultado
	scanf("%s",cpf); //salva na variavel
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("n�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	char cpf[40];
	
	printf("digite o cpf do usu�rio a ser deletado: ");
	scanf("%s",cpf); //escaneia (salva na variavel)
	
	remove(cpf); //deleta cpf
	
	FILE *file;
	file = fopen(cpf,"r"); //'r' � ler
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main()
{
	int opcao=0; //definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
		
	printf("### NO GAME, NO LIFE ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		system ("cls");
		for(laco=1;laco=1;) //la�o de repeti��o
		{
	
			system("cls"); //fun��o de limpar a tela
	
			setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
			printf("### NO GAME, NO LIFE ###\n\n"); //inicio do menu
			printf("Escolha a op��o desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Op��o:"); //fim do menu
	
			scanf("%d", &opcao); //armazenando a escolha do usuario
	
			system("cls"); //fun��o de limpar a tela
		
			switch(opcao) //inicio da sele��o do menu
			{
				case 1:
				registro(); //chamada de fun��es
				break;
			
				case 2:
				consulta(); //chamada de fun��es
				break;
			
				case 3:
				deletar(); //chamada de fun��es
				break;
			
				case 4:
				printf("Obrigado por utilizar o Sistema!\n");
				return 0;
				break;
			
				default: //error(n�o didponivel)
				printf("esta op��o n�o est� disponivel!\n");
				system("pause");
				break;		
			}	//fim da sele��o
		}
	}
	else
		printf("senha incorreta!");
}

