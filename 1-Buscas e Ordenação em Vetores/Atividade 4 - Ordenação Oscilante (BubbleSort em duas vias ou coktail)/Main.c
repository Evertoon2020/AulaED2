#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void Ordena_Oscilante(int *v,int n);

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

    Ordena_Oscilante(vetor, quant);
    printf("\n\nOrdenado por metodo Ordenação Oscilante:\n\nVetor já ordenado: ");
    for(i=0;i<quant;i++){
        printf("%d ", vetor[i]);
    }

    printf("\n\n");
}

void Ordena_Oscilante(int *v,int n){
    register int i;
    int continua;
    register int aux;
    do{
        continua=0;
        for(i=n-1;i>0;--i){
            if(v[i-1] > v[i]){
                aux = v[i-1];
                v[i-1] = v[i];
                v[i] = aux;
                continua = 1;
            }
        }
        for(i=1;i<n;++i){
            if(v[i-1] > v[i]){
                    aux = v[i-1];
                v[i-1] = v[i];
            v[i] = aux;
            continua = 1;
            }
        }
    }
    while(continua);
}
