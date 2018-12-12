#include <stdio.h>
#include <stdlib.h>
#define n 14


struct No{
	int valor ;
	struct No *prox;
};

// Protótipos das funções
void init(struct No grafo[n]);
void inserirLigacao(int vertice1, int vertice2, struct No grafo[n]);
void inserir(int numero, struct No **fila);
void snapshot(struct No grafo[n]);
void printar(struct No **fila);
void buscaProfundidade(struct No grafo[n], int inicial, int *visitado);
void buscaProfundidadeAux(struct No **fila, int inicial, int *visitado, int cont);


// Função main
int main(int argc, char const *argv[]){
	
	struct No grafo[n];
    int visitado[n];
    int vertceInicial = 1;

	init(grafo);

	inserirLigacao(1,2,grafo);
    inserirLigacao(1,3,grafo);
    inserirLigacao(1,7,grafo);
    inserirLigacao(2,1,grafo);
    inserirLigacao(2,3,grafo);
    inserirLigacao(3,1,grafo);
    inserirLigacao(3,2,grafo);
    inserirLigacao(3,4,grafo);
    inserirLigacao(3,5,grafo);
    inserirLigacao(4,3,grafo);
    inserirLigacao(4,5,grafo);
    inserirLigacao(5,3,grafo);
    inserirLigacao(5,4,grafo);
    inserirLigacao(5,6,grafo);
    inserirLigacao(6,5,grafo);
    inserirLigacao(6,8,grafo);
    inserirLigacao(6,9,grafo);
    inserirLigacao(7,1,grafo);
    inserirLigacao(7,8,grafo);
    inserirLigacao(8,7,grafo);
    inserirLigacao(8,6,grafo);
    inserirLigacao(8,9,grafo);
    inserirLigacao(9,6,grafo);
    inserirLigacao(9,8,grafo);
    inserirLigacao(9,10,grafo);
    inserirLigacao(9,13,grafo);
    inserirLigacao(10,9,grafo);
    inserirLigacao(10,11,grafo);
    inserirLigacao(10,13,grafo);
    inserirLigacao(11,10,grafo);
    inserirLigacao(11,12,grafo);
    inserirLigacao(12,11,grafo);
    inserirLigacao(12,13,grafo);
    inserirLigacao(13,9,grafo);
    inserirLigacao(13,10,grafo);
    inserirLigacao(13,12,grafo);

	snapshot(grafo);


    buscaProfundidade(grafo, vertceInicial, visitado);
	

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


// largura ---------------------------------------------------


// profundidade ---------------------------------------------------

// Função auxiliar para realizar o calculo da busca
void buscaProfundidadeAux(struct No **fila, int inicial, int *visitado, int cont){
    int i;
    visitado[inicial] = cont;

    // percorrer todas as arestas que partem desse vertice
    if(*fila == NULL){
        printf("Entrou no if e retornou");
		return;
	}else{

		struct No *tmp = *(fila);

		while(tmp != NULL){
			
            if(!visitado[tmp[i].valor]){
                buscaProfundidadeAux(&(tmp[i].prox),tmp[i].valor,visitado,cont+1);
            }
            
			tmp = tmp->prox;
		}	
	}
}

// Função principal que faz a interação com o usuário
void buscaProfundidade(struct No grafo[n], int inicial, int *visitado){
    int i, cont = 1;
    for(i=0; i < n; i++){
        visitado[i] = 0;
        buscaProfundidadeAux(&(grafo[i].prox),inicial,visitado,cont);
    }

    for(i=0; i < n; i++){
        printf("%d -> %d\n",i,visitado[i]);
    }
}

