#include <stdio.h>//Faz a comunicação com o usuário.
#include <stlib.h>//Alocação de memória.
#include <locale.h>//Alocação de caracteres tipo texto.
#include <string.h>//Criação de strings.


int cadastrar() { //Função responsavel por fazer o cadastro do usuário
    int opcao;

 do{//Laço de repetição

    //Inicio das variaveis da função cadastrar
	char arquivo[200];
	char cpf[11];
	char nome[20];
	char sobrenome[50];
	char cargo[30];
    struct data_nascimento { //Usei o struct pra agrupar as variaveis dia, mes e ano.

		int dia[2];
		int mes[2];
        int ano[4];
	}
    //Fim da variaveis

    printf("Digite seu cpf:\n");//Imprime informações no monitor
	scanf("%s", cpf);//Ira ler os dados digitados .

	strncpy(arquivo, cpf, sizeof(arquivo));//Copia os valores da string cpf para o arquivo
	arquivo[sizeof(arquivo) - 1] = 0;

	FILE *file; //Cria o arquivo.
	file =fopen(arquivo, "w");//Cria o arquivo.
	if (!file) {// Validação caso de erro
	    perror("Erro ao criar arquivo:"); return 1;// Mostra o motivo do erro
	    }
	fprintf(file, "cpf:%s\n", cpf);//Imprimi dentro do arquivo
	fclose(file);//Fecha o arquivo

	//Troquei o scanf pelo fgets para fazer a leitura completa do nome e cargo.
	
	printf("Digite o seu nome:\n");//Imprime informações no monitor
	fgets(nome, sizeof(nome), stdin);//Irá ler as informações do printf.
	nome[strcspn (nome,"\n")] = '\0';//Remove o "\n"

	file =fopen(arquivo, "a");//Abre o arquivo para ser escrito
	fprintf(file, "nome:%s", nome);//Imprimi dentro do arquivo
	fclose(file);//Fechar o arquivo

	printf("Digite o seu sobrenome:\n");//Imprime informações no monitor
	fgets(sobrenone, sizeof(sobrenome), stdin);//Lê as informações do printf
	sobrenome[strcspn(sobrenome, "\n")] = '\0';//Remove o "\n"

	file =fopen(arquivo, "a");//Abre o arquivo para ser escrito
	fprintf(file, "Sobrenome: %s", sobrenome);//Imprimi dentro do arquivo
	fclose(file);//Fecha o arquivo

	printf("Digite o seu cargo:\n");//Imprime informações no montitor
	fgets(cargo, sizeof(cargo), stdin);//Lê os dados digitados pelo usuário
    cargo[strcspn(cargo, "\n")] = '\0';//Remove o "\n"

	printf("Digite sua data de nascimento (DD/MM/YYYY):");//Imprime informações no monitor
	scanf("%d/%d/%d", data_nascimento);//Lê os dados digitados pelo usuário

    file =fopen(arquivo, "a");//Abre o arquivo para ser escrito
	fprintf(file, "Data de nascimento: %02d/%02d/%04d", data_nascimento);//imprime as informações dentro do arquivo
	fclose(file);//FEcha o arquivo

    printf("Gostaria de adicionar mais algum cadastro? (sim - não)");//Imprime informações no monitor
    scanf("%d", opcao);//Lê os dados digitados
   } while (strcmp(opcao == 'sim') = 0 || strcmp(opcao == 'Sim') = 0);//Laço de repetição caso queira adicionar mais cadastros

 return 0;//Retorna sem erro
}
 
 int consultar(){// Função responsavel por consultar o cadastro.

     //Começo das variaveis
     char conteudo[200];
     char cpf[11];
     //Fim das variaveis

     printf("Digite o seu cpf:\n")://imprime dados no monitor
     scanf("%s", cpf);//Lê os dados digitados
     
     FILE *file = fopen(cpf, "r");//Abre o arquivo para ler
      if (file == false){ //Validação caso o arquivo não seja encontrado
       }else{
          printf("Essas são as informações do usuário:\n");//Imprime uma mensagem para o usuário
          while(fgets(conteudo, sizeof(conteudo), file) != NULL);//laço de repetição para continuar imprimindo os dados
          printf("%s",conteudo);//Imprime os dados do usuário
        }
    fclose(file);//Fecha o arquivo
    printf("\n");//Pula uma linha
 }
 
 int excluir(){//Função responsavel por excluir os dados

     //Começo das variaveis
     char cpf[11];
     //Fim das variaveis

     printf("Digite o seu cpf:\n");//Imprime dados no monitor
     scanf("%s", cpf);//Lê os dados digitados
     
     remove(cpf);//Remove o cpf/cadastro
     
     FILE *file;//Cria o arquivo
     file =fopen(cpf , "r");//Abre o arquivo
     
     if(file == NULL){//Validação caso o usuáio náo seja encontrado
         printf("Usuário não encontrado!");//Imprime a mensagem no montior
         system("pause");//Pausa a mensagem
     }else{//Validação caso seja encontrado
         printf("Cadastro excluido com sucesso!");//Imprime a mensagem no monitor
         system("pause");//Pausa a mensagem
     }

 }
 int sair(){//Função responsável por sair do progama

    //Começo das variaveis
    int opcao;
    //Fim da variaveis

    printf("Deseja sair do progama (sim = 1 | não = 0):\n");//Imprime a opcão de saida ano monitor
    scanf("%d", &opcao);//lê os dados digitados

    if (opcao == 1){//Estrutura de decisão caso a opção seja 1 "sim"
    exit (1);//Função de saida
     else{//Estrutura de decisão caso seja
      printf("Retornando ao menu principal!\n");//imprimi a mensagem no monitor
    return 0;//Retorna sem erros
   }
  }
 return 0;//Retorna sem erro
}

int main{//Função principal do progama
     
     setlocale(LC_ALL, "portuguese");//Adiciona caracteres especiais
     
     //inicio das funções
     int laco = 1;
     int opcao = 0;
     //Fim da funções

     while(laco == 1){//Laço de repetição para ele continuar no menu caso ele não saia
         
         printf("Seja bem vindo ao cartório da ebac!\n");//Imprime a mensagem no monitor
         printf("Escolha uma das opções abaixo.\n");//Inicio do menu
         printf("\t1 - Cadastrar.\n");//Imprime a primeira opção no monitor
         printf("\t2 - Consultar cadastro.\n");//Imprime a segunda opção no monitor
         printf("\t3 - Excluir cadastro.\n");//Imprime a 4 opção no monitor
         printf("\t4 - Sair.\n");//Imprime a quarta opção no monitor
         scanf("%d", opcao);//Lê a opção escolhida
         
         switch(opcao){//Chamada de função
             
             case 1://Abre o case
             cadastrar();//Chamada da primeira função
             break;//Fecha o case
             
             case 2://Abre o case
             consultar();//Chamada da segunda função
             break;//Fecha o case
             
             case 3://Abre o case
             excluir();//Chamada da terceira função
             break;//Fecha o case

             case 4;//Abre o case
             sair();//Chamada da terceira função
             break;//Fecha o case

             default://Quinta opção caso escolha outra opção alem dessas
             printf("Opção inválida, Por favor tente novamente.");//Imprime a mensagem no monitor
             

            }
     }
 
     return 0;//Retorna sem erro
 }