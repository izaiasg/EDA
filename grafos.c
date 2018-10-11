/*
Criar um grafo com A, H, G, I, J, B, E, C, D
(A,H)
(A,G)
(H,D)
(D,C)
(D,J)
(J,C)
(J,E)
(E,B)

Passando (I,J) por exemplo, ver se tem ligação e, caso haja, ver a distância.

Fazer a busca em largura (Utilizando Fila)

*/

// Bibliotecas 

#include <stdio.h>
#include <stdlib.h>

// Declarando a estrutura da lista

	struct Nolista
		{
			char letra;
			struct Nolista *prox;
		};

// Declarando a estrutura da lista de lista

	struct NoListaDeLista
		{
			struct Nolista;
			struct NoListaDeLista *prox;
		};

// 

// Função principal (main)

int main(int argc, char const *argv[])
{

    // Aloca dinamicamente a cabeca da lista de lista
    struct No *listaDeLista;
	listaDeLista = malloc (sizeof(struct No));
	listaDeLista->prox = NULL;



}

// Função que insere na lista de listas 

void inserirListaDeLista(struct NoListaDeLista * listaDeLista, struct Nolista * lista){

    

}