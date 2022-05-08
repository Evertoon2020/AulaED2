#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Ordena_insertionSort(int *v,int n);
int main()
{

    setlocale(LC_ALL,"Portuguese");

    int vetor[10]= {120,150,110,130,100,160,140,190,180,170};
    int quant = 10;
    int i;

    printf("Vetor desordenado: ");
    for(i=0; i<quant; i++)
    {
        printf("%d ",vetor[i]);
    }

    Ordena_insertionSort(vetor, quant);
    printf("\n\nOrdenado por metodo insertionSort:\n\nVetor já ordenado: ");
    for(i=0;i<quant;i++){
        printf("%d ", vetor[i]);
    }

    printf("\n\n");
}

void Ordena_insertionSort(int *v,int n){
    int i, j, aux;
    for(i=1;i<n;i++){
        aux=v[i];
        for(j=i;(j>0)&&(aux<v[j-1]);j--){
            v[j]=v[j-1];
        }
        v[j]=aux;
    }
}
