/*
* Na maioria das vezes se usa array em filas
*/

// Bibliotecas

#include <stdio.h>

// Protótipos

void inserir(int numero, int fila[], int *s, int *t, int MAX);
int remover(int fila[], int *s, int *t);

// MAIN

int main(){
    int MAX = 5;
    int fila[MAX];
    int s=0;
    int t=0;
    int num = 5;

    // Chamando a função inserir
    inserir(num, fila, &s, &t, MAX);

    printf("Primeiro da fila: %d", fila[0]);

}

// Função inserir

void inserir(int numero, int fila[], int *s, int *t, int MAX){
    if(*t==MAX){
        printf("lista cheia\n");
    } else fila[(*t)++] = numero;
}

// Função remover

int remover(int fila[], int *s, int *t){
    // Terminar
}