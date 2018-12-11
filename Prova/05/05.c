#include <stdio.h>
#include <stdlib.h>
#define n 14


struct No{
	int valor ;
    int numeroVizinhos;
	struct No *prox;
};

void init(struct No grafo[n]);
void inserirLigacao(int vertice1, int vertice2, struct No grafo[n]);
void inserir(int numero, struct No **fila);
void snapshot(struct No grafo[n]);
void printar(struct No **fila);

//Busca em largura 
//Busca em profundidade

int main(int argc, char const *argv[]){
	
	struct No grafo[n];
    grafo->numeroVizinhos = 0;
	init(grafo);

    int visitado[n];


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

	

	return 0;
}

void init(struct No grafo[n]){
	for (int i = 0; i < n; i++){
		grafo[i].valor = i;
		grafo[i].prox = NULL;
	}
}

void inserirLigacao(int vertice1, int vertice2, struct No grafo[n]){

	inserir(vertice2, &(grafo[vertice1].prox));

}


void inserir(int numero, struct No **fila){

	if((*fila) == NULL){
		struct No *tmp = malloc(sizeof(struct No));
		tmp->valor = numero;
		tmp->prox = NULL;
        grafo->numeroVizinhos += 1;
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

//Busca em largura (Fila)

void buscaLargura_Grafo(struct No grafo[n], int verticeInicial, int *visitado){
    int i, vertice, cont = 1;
    int *fila, inicioFila = 0, finalFila = 0;

    /* Marcar todos os vertices como não visitados. */
    for(i=0; i < n; i++)
        visitado[i] = 0;

    /* 
    * Cria fila para guardar a ordem de visitacao dos vertices. 
    * e insere "verticeInicial" nela.
    *  */
    fila = (int*) malloc(n * sizeof(int));
    finalFila++;
    fila[finalFila] = verticeInicial;
    visitado[verticeInicial] = cont;

    /*
    * Enquanto a fila nao estiver vazia. Recupera o vertice que está no inicio da fila.
    * */
    while(inicioFila != finalFila){
        inicioFila = (inicioFila + 1) % n;
        vertice = fila[inicioFila];
        cont++;

        /*
        * Visitar todos os vizinhos daquele vertice
        * */
        for(i=0; i<grafo->grau[vertice]; i++){
            if(!visitado[grafo->arestas[vertice][i]]){
                finalFila = (finalFila + 1) % NV;
                fila[finalFila] = grafo->arestas[vertice][i];
                visitado[grafo->arestas[vertice][i]] = cont;
            }
        }
    }
    free(fila);
    for(i=0; i < gr->nro_vertices; i++)
        printf("%d -> %d\n",i,visitado[i]);
}


//Busca em profundidade (Pilha)
