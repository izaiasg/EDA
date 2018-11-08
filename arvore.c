#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
};

void inserir(struct No **arvore, int numero);
void mostrar(struct No **arvore);
int min(struct No **arvore);
int max(struct No **arvore);

void testeBusca(struct No **arvore);

int main(int argc, char *argv[]){
    struct No *arvore = NULL;

    inserir(&arvore, 4);
    inserir(&arvore, 10);
    inserir(&arvore, 2);

    mostrar(&arvore);
    
    printf("Menor: %d\n", min(&arvore));
    printf("Maior: %d\n", max(&arvore));

    testeBusca(&arvore);

    return 0;
}

void inserir(struct No **arvore, int numero){
    //Caso base
    if(*arvore == NULL){
        struct No *temp = malloc(sizeof(struct No));
        temp->valor = numero;
        temp->esquerda = NULL;
        temp->direita = NULL;
        *arvore = temp;
    }else{ //Caso já tenha
        if(numero > (*arvore)->valor){
            inserir(&((*arvore)->direita), numero);
        }else{
            inserir(&((*arvore)->esquerda), numero);
        }
    }
}

void mostrar(struct No **arvore){
    if(*arvore == NULL){
        return;
    }else{
        printf("%d\n", (*arvore)->valor);

        mostrar(&((*arvore)->direita));
        mostrar(&((*arvore)->esquerda));
    }
}

int min(struct No **arvore){
    if((*arvore)->esquerda == NULL){
        return (*arvore)->valor;
    }else{
        min(&((*arvore)->esquerda));
    }
}

int max(struct No **arvore){
    if((*arvore)->direita == NULL){
        return (*arvore)->valor;
    }else{
        min(&((*arvore)->direita));
    }
}

void testeBusca(struct No **arvore){
    if(*arvore == NULL){
        return;
    }else{
        if((*arvore)->esquerda != NULL){
            if((*arvore)->esquerda->valor > (*arvore)->valor){
                printf("Deu merda\n");
                return;
            }
        }

        if((*arvore)->direita != NULL){
            if((*arvore)->direita->valor <= (*arvore)->valor){
                printf("Deu merda");
                return;
            }
        }

        testeBusca(&((*arvore)->esquerda));
        testeBusca(&((*arvore)->direita));
    }
    printf("Essa arvore e de Deus!!!\n");
}