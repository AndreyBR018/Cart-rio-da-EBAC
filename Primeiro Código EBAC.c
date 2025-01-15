#include <stdio.h> //biblioteca referente a comunicação com usuário
#include <stdlib.h> //biblioteca referente a alocação do espaço em disco
#include <locale.h> //biblioteca referente a alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variável/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação de variável/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo, "w" significa: escrever.
	fprintf(file,cpf); //salva o local da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo em alteração, "a" significa: alterar.
	fprintf(file, ","); //inclui a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o NOME a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",nome); //%s refere-se a strings
	
	file = fopen(arquivo, "a");	//abre o arquivo em alteração, "a" significa: alterar.
	fprintf(file, nome); //salva o local da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo em alteração, "a" significa: alterar.
	fprintf(file, ","); //inclui a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o SOBRENOME a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",sobrenome); //%s refere-se a strings
	
	file = fopen(arquivo, "a"); //abre o arquivo em alteração, "a" significa: alterar.
	fprintf(file,sobrenome); //salva o local da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo em alteração, "a" significa: alterar.
	fprintf(file, ","); //inclui a vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o CARGO a ser cadastrado: "); //coletando informações do usuário
	scanf("%s",cargo); //%s refere-se a strings
	
	file = fopen(arquivo, "a"); //abre o arquivo em alteração, "a" significa: alterar.
	fprintf(file,cargo); //salva o local da variável
	fclose(file); //fecha o arquivo
	
	system("pause"); //congela a tela "pressione qualquer tecla para continuar . . ."
	
	
}

int consulta()
{
    	setlocale(LC_ALL, "Portuguese"); //inclusão da regionalização	
		
	char cpf[40]; //inclusão da variável CPF inclusa no registro
	
	printf("Digite o CPF a ser consultado: "); //pede para o usuário inserir o CPF
	scanf("%s",cpf); //refere-se a string CPF
	
	FILE *file; //cria o arquivo
	file = fopen(cpf,"r");//abre o arquivo em leitura, "r" significa: ler.
	
	if(file == NULL) //gera uma suposição "SE..."
	{
		printf("\nCPF digitado incorretamente ou inexistente, tente novamente!\n\n"); //mensagem de apoio ao usuário
	}
	
	while(fgets(cpf, 40, file) != NULL)
	{
		printf("\nEssas são as informações do usuário!: ");
		
		printf("%s",cpf,"\n");
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40]; //inclui a variável
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf); //refere-se a sting de cpf criada no registro
	
	
	FILE *file; //cria o arquvio
	file = fopen(cpf,"r"); //abre o arquivo em leitura, "r" significa: ler.
	
	if(file == NULL) //gera uma suposição "SE..."
	{
		printf("O usuário não foi encontrado!\n");
		system("pause");
	}
		
	else //inclui uma segunda opção
	
	{
		fclose(file); //fecha o arquivo
		remove(cpf); // função de exclusão		
		printf("\nUsuário deletado com sucesso!\n\n");
		system("pause");
	}
	
		
}

int inexistente()
{
	printf("Função inexistente!\n\n");
	system("pause");	
}


int main ()
{
	int opcao=0; //definindo variáveis
	int rep=1;
	
	for(rep=1;rep=1;)
	{
	
		system("cls");
    	setlocale(LC_ALL, "Portuguese"); //inclusão da regionalização
    	
		printf(" ###Cartório de Registro de Usuários da EBAC###\n\n"); //início do menu
		printf("\t1 - Registrar Usuário\n");
		printf("\t2 - Consultar Usuário\n");
		printf("\t3 - Deletar Usuário\n\n\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("opção:"); //fim do menu
		
		scanf("%d", &opcao); //armazenando a escolha do usuário

    	system("cls"); //comando para limpar a tela
    
    	switch(opcao) //inicio da seleção de funções
    	{
			case 1:
			registro(); //chamada de funções
    		break;
    		
    		case 2:
			consulta(); //chamada de funções
    		break;
    		
    		case 3:
    		deletar(); //chamada de funções   				
    		break;

    		case 4:
    		printf("Obrigado por utilizar o sistema!\n\n");
    		return 0;
    		break;    		
    		
    		default:
    		inexistente(); //chamada de funções	
    		break;
    	} //fim da seleção
		
	}
}
	



    


