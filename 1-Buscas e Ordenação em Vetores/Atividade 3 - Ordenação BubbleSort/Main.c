#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Ordena_bubbleSort(int *v,int n);

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

    Ordena_bubbleSort(vetor, quant);
    printf("\n\nOrdenado por metodo bubbleSort:\n\nVetor já ordenado: ");
    for(i=0;i<quant;i++){
        printf("%d ", vetor[i]);
    }

    printf("\n\n");
}

void Ordena_bubbleSort(int *v,int n){
    int i, continua, aux, fim=n;
    do{
        continua=0;
        for(i=0;i<fim-1;i++){
            if(v[i] > v[i+1]){
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                continua = i;
            }
        }
        fim--;
    }while(continua !=0);
}
