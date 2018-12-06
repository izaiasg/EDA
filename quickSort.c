/*
* QuickSort
*/

// Bibliotecas

#include <stdio.h>

// Protótipos
void quickSort (int *V, int inicio, int fim);
int particiona (int *V, int inicio, int final);


// MAIN

int main(){

    int V[] = {5,7,4,1,2,3,6,0};
    int inicio = 0;
    int fim = 7;
    quickSort (V, inicio, fim);

    for(int i = 0; i <= fim; i++){
        printf("%d", V[i]);
    }
    
}

// Função QuickSort

void quickSort (int *V, int inicio, int fim){
    int pivo;
    if(fim > inicio){
        pivo = particiona(V, inicio, fim);
        quickSort(V, inicio, pivo-1);
        quickSort(V, pivo+1, fim);
    }
}

// Função particiona

int particiona (int *V, int inicio, int final){
    int esq, dir, pivo, aux;
    esq = inicio;
    dir = final;
    pivo = V[inicio];
    while(esq < dir){
        while(V[esq] <= pivo){
            esq++;
        }
        while(V[dir] > pivo){
            dir--;
        }
        if(esq < dir){
            aux = V[esq];
            V[esq] = V[dir];
            V[dir] = aux;
        }
    }
    V[inicio] = V[dir];
    V[dir] = pivo;

    printf("Particionou");
    for(int i = 0; i <= 7; i++){
        printf("%d", V[i]);
    }
    printf("\n");

    return dir;
}
