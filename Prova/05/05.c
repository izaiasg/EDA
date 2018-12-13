#include <stdio.h>
#include <stdlib.h>
#define n 14


struct No{
	int valor ;
	struct No *prox;
};

//Protótipos das funções
void imprimeFila(struct No *fila, const int base[14]);
void imprimePilha(struct No *pilha, const int base[14]);
int buscaFila(struct No *fila, int valor);
int primeiroDaFila(struct No *fila);
void desenfileirar(struct No **fila);
void enfileirar(struct No **fila, int valor);
struct No *buscaLargura(const int grafoMatriz[14][14], int tamanho,int verticeInicial);
struct No *buscaProfundidade(const int grafoMatriz[14][14], int tamanho,int verticeInicial);
void empilhar(struct No **pilha, int valor);
int primeiroDaPilha(struct No *pilha);
int buscaPilha(struct No *pilha, int valor);
void desempilhar(struct No **pilha);




// Função main
int main(int argc, char *argv[]){

    int verticeInicial = 1;

    int base[n];

    // Preencendo o array que servirá como base
    for(int i=0; i<n; i++){
        base[i] = i;
    }
    // Prenchendo a matriz com de acordo com a imagem da questão
                                    /*  0 1 2 3 4 5 6 7 8 9 x z w q */
    int grafoMatriz[n][n]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0, // 0
					  			        0,0,1,1,0,0,0,1,0,0,0,0,0,0, // 1
					  			        0,1,0,1,0,0,0,0,0,0,0,0,0,0, // 2
                                        0,1,1,0,1,1,0,0,0,0,0,0,0,0, // 3
                                        0,0,0,1,0,1,0,0,0,0,0,0,0,0, // 4
                                        0,0,0,1,1,0,1,0,0,0,0,0,0,0, // 5
                                        0,0,0,0,0,1,0,0,1,1,0,0,0,0, // 6
                                        0,1,0,0,0,0,0,0,1,0,0,0,0,0, // 7
                                        0,0,0,0,0,0,1,1,0,1,0,0,0,0, // 8
                                        0,0,0,0,0,0,1,0,1,0,1,0,0,1, // 9
                                        0,0,0,0,0,0,0,0,0,1,0,1,0,1, // 10
                                        0,0,0,0,0,0,0,0,0,0,1,0,1,0, // 11
                                        0,0,0,0,0,0,0,0,0,0,0,1,0,1, // 12
                                        0,0,0,0,0,0,0,0,0,1,1,0,1,0};// 13

    // Imprimindo a busca em largura
    printf("Resultado da busca em largura: ");
    imprimeFila(buscaLargura(grafoMatriz,n,verticeInicial), base);

    // Imprimindo a busca em profundidade
    printf("\nResultado da busca em profundidade: ");
    imprimePilha(buscaProfundidade(grafoMatriz,n,verticeInicial),base);

    return 0;

}

// Função que imprime a fila da busca em largura
void imprimeFila(struct No *fila, const int base[14]){

	if (fila == NULL){
		return;
	}

	if (fila->prox){
		imprimeFila(fila->prox,base);
	}

	printf("%d ", base[fila->valor]);
}

// Função busca em largura
struct No *buscaLargura(const int grafoMatriz[14][14], int tamanho,int verticeInicial){

	// Declarando as filas
	struct No *fila = NULL; 
	struct No *marcado = NULL; // Irá conter o caminho percorrido na busca em largura

	// Lendo os dados 
	enfileirar(&fila,verticeInicial);
	enfileirar(&marcado,verticeInicial);

	for(int j = 0; fila; ++j){
		int primeiroFila = primeiroDaFila(fila);

		for(int i = 0; i < tamanho; ++i){

			if(grafoMatriz[primeiroFila][i] == 1 && buscaFila(marcado, i) == 0){
				enfileirar(&fila,i);
				enfileirar(&marcado,i);
			}
		}

		desenfileirar(&fila);
	}

	return marcado;

}

// Função que retorna o primeiro da fila
int primeiroDaFila(struct No *fila){

	while((fila)->prox){
		(fila) = (fila)->prox;
	}

	return (fila)->valor;
}

// Função que cria e preenche filas (enfileirar)
void enfileirar(struct No **fila, int valor){

	if (!(*fila) ){
		(*fila) = (struct No*)malloc(sizeof(struct No));
		(*fila)->prox = NULL;
		(*fila)->valor = valor;
	}else{

		struct No *aux = (struct No*)malloc(sizeof(struct No));
		aux->valor = valor;
		aux->prox = (*fila);
		(*fila) = aux;
	}
}

// Função que retira da fila (desenfileirar)
void desenfileirar(struct No **fila){

	struct No *cabeca = (*fila);
	struct No *aux = NULL;

	while((*fila)->prox){
		aux = (*fila);
		(*fila) = (*fila)->prox;
	}

	if ((*fila) == cabeca){
		(*fila) = NULL;

	}else{
		aux->prox = NULL;
		(*fila) = cabeca;
	}

}

// Busca na fila 
int buscaFila(struct No *fila, int valor){

	while((fila)){

		if ((fila)->valor == valor){
			return 1;
		}

		fila = fila->prox;
	}
	return 0;
}

// Função que imprime a pilha da busca em profundidade
void imprimePilha(struct No *pilha, const int base[14]){

	if (pilha == NULL){
		return;
	}

	if (pilha->prox){
		imprimePilha(pilha->prox,base);
	}

	printf("%d ", base[pilha->valor]);
}

// Função busca em profundidade
struct No *buscaProfundidade(const int grafoMatriz[14][14], int tamanho,int verticeInicial){

	// Declarando as pilhas
	struct No *pilha = NULL; 
	struct No *marcado = NULL; // Irá conter o caminho percorrido na busca em largura

	// Lendo os dados 
	empilhar(&pilha,verticeInicial);
	empilhar(&marcado,verticeInicial);

	for(int j = 0; pilha; ++j){

		int primeiroPilha = primeiroDaPilha(pilha);
		desempilhar(&pilha);

		for(int i = 0; i < tamanho; ++i){

			if(grafoMatriz[primeiroPilha][i] == 1 && buscaPilha(marcado, i) == 0){
				empilhar(&pilha,i);
				empilhar(&marcado,i);
			}
		}
	}

	return marcado;
}

// Função que empilha os dados
void empilhar(struct No **pilha, int valor){

	if (!(*pilha)){
		
		(*pilha) = (struct No*)malloc(sizeof(struct No));
		(*pilha)->prox = NULL;
		(*pilha)->valor = valor;
	}else{

		struct No *aux = (struct No*)malloc(sizeof(struct No));
		aux->valor = valor;
		aux->prox = (*pilha);
		(*pilha) = aux;
	}
}

// Função que retorna o primeiro da pilha
int primeiroDaPilha(struct No *pilha){

	if (pilha){

		return pilha->valor;
	}
}

// Função que busca na pilha
int buscaPilha(struct No *pilha, int valor){

	while(pilha){

		if (pilha->valor == valor){
			return 1;
		}

		pilha = pilha->prox;
	}

	return 0;
}

// Função que desempilha os dados
void desempilhar(struct No **pilha){

	if((*pilha)->prox){
		(*pilha) = (*pilha)->prox;
	}else{

		(*pilha) = NULL;
	}

}
