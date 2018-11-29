/*Bubble Sort*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int *v, int n);

int main(int argc, char *argv[]){
    int v[] = {2,1,3,7,5,4,6,8};
    int n = 8;

    bubbleSort(v, n);
    for(int i = 0; i < n; i++){
        printf("%d", v[i]);
    }
}
void bubbleSort(int *v, int n){

    int i, aux, continua;
    int fim = n;

    do{
        continua = 0;
        for(i = 0; i < fim-1; i++){
            if(v[i]>v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua != 0);

}