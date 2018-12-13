#include <stdio.h>
#include <stdlib.h>
#define n 15


struct No{
	int valor ;
	struct No *prox;
};

void init(struct No grafo[n]);
void inserirLigacao(int vertice1, int vertice2, struct No grafo[n]);
void inserir(int numero, struct No **fila);
void snapshot(struct No grafo[n]);
void printar(struct No **fila);

int main(int argc, char const *argv[]){
	
	struct No grafo[n];
	init(grafo);
	inserirLigacao(0,1,grafo);
	inserirLigacao(0,3,grafo);
	inserirLigacao(1,2,grafo);
	inserirLigacao(3,4,grafo);
	inserirLigacao(2,12,grafo);
	inserirLigacao(4,7,grafo);
	inserirLigacao(7,5,grafo);
	inserirLigacao(13,6,grafo);
	inserirLigacao(7,9,grafo);
	inserirLigacao(9,8,grafo);
	inserirLigacao(9,6,grafo);
	inserirLigacao(5,10,grafo);
	inserirLigacao(5,9,grafo);
	inserirLigacao(9,11,grafo);
	inserirLigacao(14,2,grafo);

	snapshot(grafo);

	

	return 0;
}

void init(struct No grafo[n]){
	for (int i = 0; i < n; i++){
		grafo[i].valor = i;
		grafo[i].prox = NULL;
		//printf("%d\n", grafo[i]);
		//printf("\n\n");
	}
}

void inserirLigacao(int vertice1, int vertice2, struct No grafo[n]){
	//printf("vertice1: %d :vertice2: %d\n", vertice1, vertice2);
	inserir(vertice2, &(grafo[vertice1].prox));

}


void inserir(int numero, struct No **fila){

	if((*fila) == NULL){
		struct No *tmp = malloc(sizeof(struct No));
		tmp->valor = numero;
		tmp->prox = NULL;
		(*fila) = tmp;
	}else{
		inserir(numero, &((*fila)->prox));
	}

}

void snapshot(struct No grafo[n]){
	for (int i = 0; i < n; ++i){

		printf("%d -> ", grafo[i].valor);
		printar(&(grafo[i].prox));
		printf("\n");
	}
}

void printar(struct No **fila){
	if(*fila == NULL){
		printf("Nao se relaciona");
	}else{
		struct No *tmp = *(fila);

		while(tmp != NULL){
			printf("%d ", tmp->valor);
			tmp = tmp->prox;
		}	
	}
	
}