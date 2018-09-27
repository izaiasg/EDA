/*
* Na maioria das vezes se usa array em filas
*/

// Bibliotecas

#include <stdio.h>

// Protótipos

void empilhar(int numero, int fila[], int *s);
//int desenpilhar(int fila[], int *s, int *t);

// MAIN

int main(){
    int MAX = 5;
    int fila[MAX];
    int s=0;
    int num = 5;

    // Chamando a função inserir
    empilhar(num, fila, &s);

    printf("Primeiro da fila: %d", fila[0]);

}

// Função inserir

void empilhar(int numero, int fila[], int *s){
    /*if(*t==MAX){
        printf("lista cheia\n");
    } else fila[(*t)++] = numero;*/

    fila[(*s)++] = numero;

}

// Função remover

int remover(int fila[], int *s, int *t){
    // Terminar
}