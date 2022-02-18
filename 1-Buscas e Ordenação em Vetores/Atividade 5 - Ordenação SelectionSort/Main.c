#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Ordena_selectionSort(int *v,int n);
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

    Ordena_selectionSort(vetor, quant);
    printf("\n\nOrdenado por metodo selectionSort:\n\nVetor já ordenado: ");
    for(i=0;i<quant;i++){
        printf("%d ", vetor[i]);
    }

    printf("\n\n");
}

void Ordena_selectionSort(int *v,int n){
    int i, j, menor, troca;
    for(i=0;i<n-1;i++){
        menor=i;
        for(j=i+1;j<n;j++){
            if(v[j]<v[menor]){
                menor = j;
            }
        }
        if(i!=menor){
            troca=v[i];
            v[i]=v[menor];
            v[menor]=troca;
        }
    }
}
