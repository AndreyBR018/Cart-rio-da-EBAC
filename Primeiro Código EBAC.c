#include <stdio.h> //biblioteca referente a comunica��o com usu�rio
#include <stdlib.h> //biblioteca referente a aloca��o do espa�o em disco
#include <locale.h> //biblioteca referente a aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�vel/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da cria��o de vari�vel/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" significa: escrever.
	fprintf(file,cpf); //salva o local da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo em altera��o, "a" significa: alterar.
	fprintf(file, ","); //inclui a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o NOME a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",nome); //%s refere-se a strings
	
	file = fopen(arquivo, "a");	//abre o arquivo em altera��o, "a" significa: alterar.
	fprintf(file, nome); //salva o local da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo em altera��o, "a" significa: alterar.
	fprintf(file, ","); //inclui a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o SOBRENOME a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",sobrenome); //%s refere-se a strings
	
	file = fopen(arquivo, "a"); //abre o arquivo em altera��o, "a" significa: alterar.
	fprintf(file,sobrenome); //salva o local da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo em altera��o, "a" significa: alterar.
	fprintf(file, ","); //inclui a v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o CARGO a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s",cargo); //%s refere-se a strings
	
	file = fopen(arquivo, "a"); //abre o arquivo em altera��o, "a" significa: alterar.
	fprintf(file,cargo); //salva o local da vari�vel
	fclose(file); //fecha o arquivo
	
	system("pause"); //congela a tela "pressione qualquer tecla para continuar . . ."
	
	
}

int consulta()
{
    	setlocale(LC_ALL, "Portuguese"); //inclus�o da regionaliza��o	
		
	char cpf[40]; //inclus�o da vari�vel CPF inclusa no registro
	
	printf("Digite o CPF a ser consultado: "); //pede para o usu�rio inserir o CPF
	scanf("%s",cpf); //refere-se a string CPF
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r");//abre o arquivo em leitura, "r" significa: ler.
	
	if(file == NULL) //gera uma suposi��o "SE..."
	{
		printf("\nCPF digitado incorretamente ou inexistente, tente novamente!\n\n"); //mensagem de apoio ao usu�rio
	}
	
	while(fgets(cpf, 40, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio!: ");
		
		printf("%s",cpf,"\n");
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40]; //inclui a vari�vel
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf); //refere-se a sting de cpf criada no registro
	
	
	FILE *file; //cria o arquvio
	file = fopen(cpf,"r"); //abre o arquivo em leitura, "r" significa: ler.
	
	if(file == NULL) //gera uma suposi��o "SE..."
	{
		printf("O usu�rio n�o foi encontrado!\n");
		system("pause");
	}
		
	else //inclui uma segunda op��o
	
	{
		fclose(file); //fecha o arquivo
		remove(cpf); // fun��o de exclus�o		
		printf("\nUsu�rio deletado com sucesso!\n\n");
		system("pause");
	}
	
		
}

int inexistente()
{
	printf("Fun��o inexistente!\n\n");
	system("pause");	
}


int main ()
{
	int opcao=0; //definindo vari�veis
	int rep=1;
	
	for(rep=1;rep=1;)
	{
	
		system("cls");
    	setlocale(LC_ALL, "Portuguese"); //inclus�o da regionaliza��o
    	
		printf(" ###Cart�rio de Registro de Usu�rios da EBAC###\n\n"); //in�cio do menu
		printf("\t1 - Registrar Usu�rio\n");
		printf("\t2 - Consultar Usu�rio\n");
		printf("\t3 - Deletar Usu�rio\n\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("op��o:"); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usu�rio

    	system("cls"); //comando para limpar a tela
    
    	switch(opcao) //inicio da sele��o de fun��es
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
    		printf("Obrigado por utilizar o sistema!\n\n");
    		return 0;
    		break;    		
    		
    		default:
    		inexistente(); //chamada de fun��es	
    		break;
    	} //fim da sele��o
		
	}
}
	



    


