/*Selection sort*/

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int *v, int n);

int main(int argc, char *argv[]){
    int v[] = {5,3,10,1,2,7,8,9};
    int n = 8;

    selectionSort(v, n);
    for(int i = 0; i < n; i++){
        printf("%d", v[i]);
    }
}
void selectionSort(int *v, int n){
    int i, j, menor, troca;
    for(i = 0; i < n-1; i++){
        menor = i;
        for(j = i+1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}