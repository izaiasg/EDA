/***************************************************************************************************************

UPE - CARUARU - EDA


	Agenda simplesmente encadeada para criar uma agenda telefonica. 
	Inserindo já de uma forma ordenada (Alfabeticamente).


		# Será passado um arquivo onde:

	F = inserir na frente;
	A = inserir atrás;
	R = remover; //Caso o elemento solicitado não exista retorna "X" e Para remover é preciso buscar;
	P = imprime todos os elementos.
		
		# Exemplo:
		
	Entrada  Saída

	F adriano 123    | adriano 123, izaias 456, rick 789  // 3º comando Contato caso o (P)
	A izaias 456     | adriano 123, rick 789    // 5º comando (P) que imprime apenas o 20 pois o 1 foi removido
        A erick 789      | erick 789, Contato nao cadastrado na agenda!  // 7 e 8 comandos busca
	P                |     
	R izaias         | 
	P                |
	B erick          | 
	B maria          |
	


***************************************************************************************************************/

// Bibliotecas 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declarando a estrutura

	struct Contato
		{
			int telefone;
            char nome[20];
			struct Contato *prox;
		};

//Protótipos

struct Contato * buscar(struct Contato * cabeca, char nome[20]); // Fazer a funcao buscar comparando o nome
void inserirf(struct Contato * cabeca, int telefone, char nome[20]); // Refazer
void inserirb(struct Contato * cabeca, int telefone, char nome[20]); // Refazer
void remover(struct Contato * cabeca, char nome[20], FILE * agenda_res); // Refazer
void print(struct Contato * cabeca, FILE * agenda_res); // Refazer
void exibeBusca(struct Contato * cabeca, char nome[20], FILE * agenda_res);


// Função principal (main)

int main(int argc, char const *argv[])
{

// Aloca dinamicamente a cabeca da agenda

	int quantidade, telefone;
    char nome[20];
	char op;
	struct Contato *cabeca;
	cabeca = malloc (sizeof(struct Contato));
	cabeca->prox = NULL;

// Abre o aquivo atravez do diretorio que foi passado por linha de comando (Leitura)

	FILE * agenda = fopen(argv[1], "r");
	FILE * agenda_res = fopen(argv[2], "w");

	// Verifica se esta tudo OK com os arquivos
		
		if (agenda == NULL)
		{
			printf("Erro ao abrir o arquivo!\n");
			return 1;
		}

		if (agenda_res == NULL)
		{
			printf("Erro ao abrir o arquivo!\n");
			return 1;
		}


		while(fscanf(agenda, "%c", &op) != EOF)
		{

			if (op == 'F')
			{
                fscanf(agenda, "%s", &nome);
				fscanf(agenda, "%d", &telefone);
				inserirf(cabeca, telefone, nome);
			}

			if (op == 'A')
			{
                fscanf(agenda, "%s", &nome);
				fscanf(agenda, "%d", &telefone);
				inserirb(cabeca, telefone, nome);
			}

			if (op == 'R')
			{
				fscanf(agenda, "%s", &nome);
				remover(cabeca, nome, agenda_res);
			}

            if (op == 'B')
			{
				fscanf(agenda, "%s", &nome);
				exibeBusca(cabeca, nome, agenda_res);
			}

			if (op == 'P')
			{
				print(cabeca, agenda_res);
			}


		}

	fclose(agenda);
	fclose(agenda_res);

	return 0;
}


// Função insere Contato começo

void inserirf(struct Contato * cabeca, int telefone, char nome[20])
{
	
	struct Contato *novo;
	novo = malloc(sizeof(struct Contato));
	novo->telefone = telefone;
    strcpy(novo->nome, nome);
	novo->prox = cabeca->prox;
	cabeca->prox = novo;

}


// Função inserir atrás

void inserirb(struct Contato * cabeca, int telefone, char nome[20])
{
	struct Contato * novo;
	
	if(cabeca->prox == NULL)
	{
		inserirf(cabeca, telefone, nome);
	}else{
		
		struct Contato * ultimo = cabeca;

		while(ultimo->prox != NULL)
		{
			ultimo = ultimo->prox;
		}

		novo = malloc(sizeof(struct Contato));
		novo->telefone = telefone;
        strcpy(novo->nome, nome);
		novo->prox = NULL;
		ultimo->prox = novo;
	}

}


// Função print

void print(struct Contato * cabeca, FILE * agenda_res)
{

	struct Contato * ultimo = cabeca;

	while(ultimo->prox != NULL)
	{
		ultimo = ultimo->prox;
		fprintf(agenda_res, "%s %d, ", ultimo->nome, ultimo->telefone);
	}

	fprintf(agenda_res, "\n");


}

// Função Buscar

struct Contato * buscar(struct Contato * cabeca, char nome[20])
{

	struct Contato * ultimo = cabeca;

	while(ultimo->prox != NULL)
	{
		ultimo = ultimo->prox;
		if (strcmp(ultimo->nome, nome) == 0)
		{
			break;
		}
	}

	return ultimo;


}


// Função Remover

void remover(struct Contato * cabeca, char nome[20], FILE * agenda_res)
{

	struct Contato * percorre;
	struct Contato * proximo;
	struct Contato * verifica;
	percorre = cabeca;
	proximo = cabeca->prox;

	verifica = buscar(cabeca, nome);

	if (strcmp(verifica->nome, nome) != 0)
	{
		fprintf(agenda_res, "x \n");
	}

	while(proximo != NULL && strcmp(verifica->nome, nome) != 0)
	{
		percorre = proximo;
		proximo = proximo->prox;
	}
	if (proximo != NULL)
	{
		percorre->prox = proximo->prox;
		free(proximo);
	}

}

// Funcao que exibe a busca

void exibeBusca(struct Contato * cabeca, char nome[20], FILE * agenda_res)
{
    struct Contato * buscando;

    buscando = buscar(cabeca, nome);

    if (strcmp(buscando->nome, nome) != 0)
	{
		fprintf(agenda_res, "Contato nao cadastrado na agenda! \n");
	} else {
        fprintf(agenda_res, "%s %d, ", buscando->nome, buscando->telefone);
    }
}
