#include<stdio.h>
#include<stdlib.h>



struct Umidade{

	int data;	
	int valor;
	
};




int opcao(int x);
void insertionSort(struct Umidade ar[6]);
void mergeSort(struct Umidade *ar, int inicio, int fim);
void merge(struct Umidade *ar, int inicio, int meio, int fim);
void print(struct Umidade *ar);







int main(int argc, const char *argv[]){

struct Umidade ar[6] = {{20181002, 100}, {20180328, 35}, {20180112, 69}, {20180101, 45}, {20181212, 97}, {20180731, 85}};

int inicio = 0;
int fim = 5;
int x;


int option = opcao(x);

switch(option){

	case 1:
	insertionSort(ar);
	print(ar);

	break;

	case 2:

	mergeSort(ar, inicio, fim);
	print(ar);

	break;

	case 3:

	print(ar);

	break;

	default:

	printf("opcao invalida\n");
	break;
}





return 0;

}


void print(struct Umidade *ar){

int i;

for(i = 0; i <= 5; i++){
		
		printf("%d - %d\t", ar[i].data, ar[i].valor);

	}

}

int opcao(int x){

	printf("Digite a opcao desejada\n");
	printf("1 - para ordenar pelo InsertionSort\n");
	printf("2 - para ordenar pelo MergeSort\n");
	printf("3 - para imprimir\n\n");

	scanf("%d", &x);

	return x;


}




void insertionSort(struct Umidade *ar){

	//struct Umidade aux[6];

	int i, j, aux1, aux2;

		for(i = 0; i <= 5; i++){
			aux1 = ar[i].data;
			aux2 = ar[i].valor;
			//printf("%d\n\n", ar[i].data);
			
			for(j = i; (j > 0) && (aux1 <  ar[j-1].data); j--){
				ar[j].data = ar[j-1].data;
				ar[j].valor = ar[j-1].valor;
				
			}

			ar[j].data =  aux1;
			ar[j].valor = aux2;

		}

		

		
}


void mergeSort(struct Umidade *ar, int esquerda, int direita){


	if(esquerda == direita)
		return;
	

	int meio = (esquerda + direita )/2;

		mergeSort(ar, esquerda, meio);
		mergeSort(ar, meio+1, direita);
		merge(ar, esquerda, meio, direita);

		return;
	}




void merge(struct Umidade *ar, int esquerda, int meio, int direita){
	
	
	int i, j, k;

	int temp_tam = meio - esquerda+1;
	int  aux_tam = direita - meio;
	
	struct Umidade *temp = malloc(sizeof(struct Umidade) * temp_tam);
	struct Umidade *aux = malloc(sizeof(struct Umidade) * aux_tam);


		for(i = 0; i < temp_tam; i++){

			temp[i] = ar[i+esquerda];
		}

		for(i = 0; i < aux_tam; i++)

			aux[i] = ar[i+meio+1];
			

		for(i = 0, j = 0, k = esquerda; k <= direita; k++){

			if( i == temp_tam){

				ar[k] = aux[j++];

			}else if(j == aux_tam){
				ar[k] = temp[i++];
			
			}else 
				if(temp[i].data < aux[j].data) {
				ar[i] = temp[i++];
				

			}else{
				ar[k] = aux[j++];


			}
			
		}

			
         	
			free(temp);
			free(aux);
			

	}
	
		
		

	


