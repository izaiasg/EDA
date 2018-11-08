#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
};

void inserir(struct No **arvore, int numero);
void mostrar(struct No **arvore);

int main(int argc, char *argv[]){
    struct No *arvore = NULL;

    inserir(&arvore, 4);
    inserir(&arvore, 10);
    inserir(&arvore, 2);

    mostrar(&arvore);

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