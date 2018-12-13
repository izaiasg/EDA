#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct No{

	char nome[20];
	int valor;
	struct No *esquerda;
	struct No *direita;



};




void inserir(struct No **arvore, int numero, char *nomeContato);
void mostrar(struct No **arvore);
struct No *MaiorDireita(struct No **arvore);
struct No *MenorEsquerda(struct  No **arvore);
void buscar(struct No **arvore, char *nomeContato);

//void testeBusca(struct No **arvore);
void excluir(struct No **arvore, char *nomeContato);



int main(int argc, const char *argv[]){

struct No *arvore = NULL;

inserir(&arvore,99885422,"Carlos");
inserir(&arvore,96934192,"Ancelmo");
inserir(&arvore,96260008,"Caio");
inserir(&arvore,21031313,"Jonatan");
inserir(&arvore,37193113,"Joedyson");
inserir(&arvore,21021000,"Cleber");
inserir(&arvore,93481622,"Isaias");
inserir(&arvore,88025423,"Erik");
inserir(&arvore,88011110,"Ronaldo");
inserir(&arvore,92312334,"Adriano");


//testeBusca(&arvore);

mostrar(&arvore);

printf("\n\n");




excluir(&arvore,"Ancelmo");

//testeBusca(&arvore);

mostrar(&arvore);

printf("\n\n");

//printf("%d\n", *MaiorDireita(&arvore));
//printf("%d\n", *MenorEsquerda(&arvore));

//mostrar(&arvore);



buscar(&arvore, "Adriano");


return 0;



}


void inserir(struct No **arvore, int numeroTelefone, char *nomeContato){

	if(*arvore == NULL){

		struct No *temp = malloc(sizeof(struct No));
		strcpy((temp)->nome,nomeContato);
		temp->valor = numeroTelefone;
		temp->direita = NULL;
		temp->esquerda = NULL;
		*arvore = temp;

	}else{
			if(strcmp((*arvore)->nome,nomeContato) > 0 ){
			
			inserir(&(*arvore)->direita, numeroTelefone, nomeContato);
		
			}else{

			inserir(&(*arvore)->esquerda, numeroTelefone, nomeContato);
				
				}
}
	
}



void buscar(struct No**arvore, char *nomeContato){

if(*arvore == NULL){
	printf("Esse Contato não existe");

} else 
	
	if(strcmp((*arvore)->nome,nomeContato) == 0);

		if(strcmp((*arvore)->nome,nomeContato) > 0){
			
				buscar(&((*arvore)->direita),nomeContato);
		}
		if(strcmp((*arvore)->nome,nomeContato) < 0){

			  buscar(&((*arvore)->esquerda), nomeContato);

		}if (strcmp((*arvore)->nome,nomeContato) == 0){

			printf("O Contato de %s e: %d\n", (*arvore)->nome, (*arvore)->valor);
		
		}
		
}


	
	






void mostrar(struct No **arvore){
	if(*arvore == NULL){
		return;
	}else{

		printf("%s - %d\n", (*arvore)->nome, (*arvore)->valor);
		mostrar(&((*arvore)->direita));
		mostrar(&((*arvore)->esquerda));

	}



}


struct No *MaiorDireita(struct No **arvore){
    if((*arvore)->direita != NULL) 
       return MaiorDireita(&(*arvore)->direita);
    else{
       struct No *aux = *arvore;
       if((*arvore)->esquerda != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da esquerda!
          *arvore = (*arvore)->esquerda;
       else
          *arvore = NULL;
       return aux;
       }
}

struct No *MenorEsquerda(struct No **arvore){
    if((*arvore)->esquerda != NULL) 
       return MenorEsquerda(&(*arvore)->esquerda);
    else{
       struct No *aux = *arvore; 
       if((*arvore)->direita != NULL) // se nao houver essa verificacao, esse nó vai perder todos os seus filhos da direita!
          *arvore = (*arvore)->direita;
       else
          *arvore = NULL;
       return aux;
       }
}


void excluir(struct No **arvore, char *nomeContato){
	
	
	
	if((*arvore) == NULL){
		printf("Esse numero informado ja nao existe\n");
		return;
	}else{
		if(strcmp((*arvore)->nome,nomeContato) < 0 ){
		
			excluir(&((*arvore)->esquerda),nomeContato);
	    
	    }else 
			if(strcmp((*arvore)->nome,nomeContato) > 0 ){

			excluir(&((*arvore)->direita),nomeContato);

		}else{	

			struct No *aux = *arvore;

			if(((*arvore)->esquerda == NULL) && ((*arvore)->direita = NULL)){
				free(aux);
				(*arvore) = NULL;
			}else{
				if((*arvore)->esquerda == NULL){
					(*arvore) = (*arvore)->direita;
					aux = aux->direita;
					*arvore = aux;
					aux->direita == NULL;
					free(aux);
					aux = NULL;

				}else{
					if((*arvore)->direita == NULL){
						(*arvore) = (*arvore)->esquerda;
						aux->esquerda == NULL;
						free(aux);
						aux = NULL;

					}else{

						aux = MenorEsquerda(&(*arvore)->direita);
						aux->esquerda = (*arvore)->esquerda;
						aux->direita = (*arvore)->direita;
						(*arvore)->direita = (*arvore)->esquerda = NULL;
						free((*arvore));
						(*arvore) = aux;
						aux = NULL;
					}
				}

			}
			}
		}
}
