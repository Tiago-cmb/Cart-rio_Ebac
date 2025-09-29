#include <stdio.h>// Comunica com o usuário
#include <stdlib.h> // Alocação de memória
#include <string.h> // Criação de strings
#include <locale.h> // Alocação de caracteres do tipo texto


int cadastrar() {// Função responsável por fazer o cadastro

	char opcao[4];

 	char arquivo[200];
 	char cpf[12];
 	char nome[15];
 	char sobrenome[30];
 	char cargo[15];
 	struct datanascimento {
 		char dia[3];
 		char mes[3];
 		char ano[5];
 	};
    struct datanascimento dn;
    // Fim das variáveis
do{
 	printf("Insira seu cpf:\n");// Imprime uma mensagem no monitor
 	fgets(cpf, sizeof(cpf), stdin);// Lê os dados digitados pelo usuário
 	cpf[strcspn(cpf, "\n") - 1] = '\0';// Remove o "\n"
 	strcpy(arquivo, cpf);// Copia o cpf na variável arquivo

 	FILE *file = fopen(arquivo, "w");// Cria o arquivo para armazenar os dados
 	if (file == NULL) {// Validação caso dê erro ao criar
 		perror("Erro ao abrir arquivo:\n");// Imprime uma mensagem e o motivo do erro
 	}
 	fprintf(file, "%s", cpf);// Imprime os dados digitados dentro do arquivo
 	fclose(file);// Fecha o arquivo

 	printf("Digite seu primeiro nome:\n");// Imprime uma mensagem no monitor
 	fgets(nome, sizeof(nome), stdin);// Lê os dados digitados pelo usuário
 	nome[strcspn(nome, "\n") - 1] = '\0';// Remove o "\n"

 	file= fopen(arquivo, "a");// Abre o arquivo para inserir mais dados
 	fprintf(file, "%s", nome);// Imprime os dados digitados dentro do arquivo
 	fclose(file);// Fecha o arquivo

 	printf("Digite seu sobrenome:\n");// Imprime uma mensagem no monitor
 	fgets(sobrenome, sizeof(sobrenome), stdin);// Lê os dados digitados pelo usuário
 	sobrenome[strcspn(sobrenome, "\n") - 1] = '\0';// Remove o "\n"

 	file = fopen(arquivo, "a");// Abre o arquivo para atualizar os dados
 	fprintf(file, "%s", sobrenome);// Imprime os dados dentro do arquivo
 	fclose(file);// Fecha o arquivo

 	printf("Digite seu cargo:\n");// Imprime uma mensagem no monitor
 	fgets(cargo, sizeof(cargo), stdin);// Lé os dados digitados pelo usuário
 	cargo[strcspn(cargo, "\n") - 1] = '\0';// Remove o "\n"

 	file= fopen(arquivo, "a");// Abre o arquivo para ser atualizado
 	fprintf(file, "%s", cargo);// Imprime os dados digitados dentro do arquivo
 	fclose(file);// Fecha o arquivo

 	printf("Digite sua data de nascimento(DD/MM/AAAA)");// Imprime uma mensagem no monitor
 	scanf("%2s %2s %4s", &dn.dia, &dn.mes, &dn.ano);// Lê os dados digitados pelo usuário

 	file= fopen(arquivo, "a");// Abre o arquivo para adicionar mais dados
 	fprintf(file, "%02s/%02s/%04s", dn.dia, dn.mes, dn.ano);// Imprime os dados dentro do arquivo
 	fclose(file);// Fecha o arquivo

    printf("Deseja continuar (sim | não) ?");// Imprime uma mensagem no monitor
 	fgets(opcao, sizeof(opcao), stdin);// Lê os dados digitados pelo aluno

 }while (strcmp(opcao, "sim") == 0);// Condição do laço de repetição
return 0;// Retorna positivo caso a função rode sem erros
}

int consultar() {// Função responsável por consultar os cadastros

    // Inicio das variáveis
	char conteudo[200];
	char cpf[12];
	// Fim das variáveis

	setlocale (LC_ALL, "portuguese");// Função responsável por acrescentar caracteres especiais

	printf("Digite seu cpf:");// Imprime uma mensagem no monitor
	fgets(cpf,  sizeof(cpf), stdin);// Lê os dados digitados pelo usuário

	FILE *file = fopen(cpf, "r");// Irá abrir o arquivo para fazer
	while (conteudo(conteudo, sizeof(conteudo), file) != NULL){// Irá mostrar as informações enquanto os dados estiverem corretos
		printf("%s", conteudo);// Imprime o conteúdo previamente salvo
	}
return 0;// Termina a função com sucesso
}

int excluir() {// Função responsável por excluir os dados

	// Inicio das variáveis
	char cpf[12];
	// Fim das variáveis

	printf("Digite o seu cpf:\n");// Irá imprimir uma mensagem no monitor
	fgets(cpf, sizeof(cpf), stdin);// Lê os dados digitados pelo usuário

	FILE *file= fopen(cpf, "r");
	if (file == NULL) {
		printf("Não foi possivel encontrar o usuário!");
	}else {
		remove(cpf);
		printf("Cadastro excluído com sucesso!");
		return 0;
	}
    fclose(file);
}
int sair() {// Função responsável por sair do progama
    // Inicio das variáveis
	char opcao[4];
   // Fim das variáveis

	printf("Deseja sair do progama? (sim - não)\n");// Imprime uma mensagem no monitor
	scanf("%s", &opcao);// Lê os dados digitados pelo usuário

	if (strcmp (opcao, "sim") == 0){// Validação caso a execução seja feita com sucesso
		exit(1);// Função responsável por sair do progama
	}else{// Validação caso a função de erro ao executar
		printf("Retornando a tela principal!");// Imprime uma mensagem no monitor
	}
return 0;// Termina a função com sucesso
}
int main() {
	// Função principal do progama

	int laco= 1;
	int opcao= 0;


	setlocale(LC_ALL, "portuguese");// Responsável pela alocação de caracteres


	printf("Selecione uma das opções abaixo!\n");
	printf("\t1 - Cadastrar\n");
	printf("\t2 - Consultar\n");
	printf("\t3 - Excluir\n");
	printf("\t4 - Sair\n");

	scanf("%d", &opcao);

	switch (opcao){

		case 1:// Chamada função
			cadastrar();//Chama a função cadastrar
			break;//Fecha

		case 2:// Chamada função
			consultar();// Chama a função consultar
			break;//Fecha

		case 3://Chamada função
			excluir();//Chama a função excluir
			break;//Fecha

		case 4://Chamada função
			sair();// Chama a função sair
			break;//Fecha

		default://Chamada função
			printf("Essa opção não existe!");//Imprime uma mensagem no monitor
			break;//Fecha
	}

	}
}