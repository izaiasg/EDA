#include<stdio.h>
#include<stdlib.h>



int particiona(int *V, int inicio, int final);;

void quickFind(int *V, int inicio, int fim, int elemento);

int main(){

int V[] ={7,1,3,10,17,2,21,9};
int inicio = 0;
int fim = 7;
int i = 0;
int elemento = 5;
//(S,0,7,5)

quickFind(V, inicio, fim, elemento);

for(i = 0; i <= 7; i++){
	if(V[i] == V[elemento])
		printf("O %d menor elemento e: %d\n ", i, V[i]);
	}


}



int particiona(int *V, int inicio, int final){

	int esq, dir, pivo, aux;
	esq = inicio;
	dir = final;
	
	pivo = V[inicio];
	int i;

	while(esq < dir){
		//avança posição da esquerda
		while(V[esq] <= pivo)
			esq++;
		//recua  posição da direita
		while(V[dir]>pivo)
			dir--;
		//trocar esq e dir
		
		if(esq < dir){
			esq++;
		   aux = V[esq];  
			V[esq] = V[dir];
			V[dir] = aux;

		}
	}

	V[inicio] = V[dir];
	V[dir] = pivo;
	for(i=0; i<=final; i++){
		
		printf("%d ", V[i]);
	
}
	printf("\n\n");
	return dir;

}

void quickFind(int *V, int inicio, int fim, int elemento){
	int pivo;
	if(fim > inicio){
		pivo = particiona(V, inicio, fim);
		
		if(elemento < pivo){
		quickFind(V, inicio, pivo-1, elemento);
	}else{
		quickFind(V, pivo+1, fim, elemento);
		}
			
	}
}
