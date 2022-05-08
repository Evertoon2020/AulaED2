#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int buscaLinear(int *vetor, int n, int elem);
int buscaOrdenada(int *vetor, int n, int elem);
int buscaBinaria(int *vetor, int n, int elem);



int main()
{

    setlocale(LC_ALL,"Portuguese");

    int vetor1[9]= {4,7,5,9,1,3,2,6,8};
    int aux;
    int quant = 9;
    int i, num;

    printf("Vetores da Lista: ");
    for(i=0; i<quant; i++)
    {
        printf("%d ",vetor1[i]);
    }


    for(i=0; i<quant; i++)
    {
        for(int j=i; j<quant; j++)
        {
            if(vetor1[i]>vetor1[j])
            {
                aux = vetor1[i];
                vetor1[i] = vetor1[j];
                vetor1[j] = aux;
            }

        }
    }

    printf("\nDigite o número para busca: ");
    scanf("%d",&num);

    if(buscaOrdenada(vetor1, quant, num) != -1)
    {
        printf("\nValor %d, foi encontrado na Busca Ordenada\nVetores da Lista Ordenados: ",num);
        for(i=0; i<quant; i++)
        {
            printf("%d ",vetor1[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nValor %d, NÃO foi encontrado na Busca Ordenada!\n", num);
    }

    printf("\n\n");
    system("pause");
}


int buscaOrdenada(int *vetor, int n, int elem)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(elem==vetor[i])
        {
            return i;
        }
        else
        {
            if(elem<vetor[i])
            {
                return -1;
            }
        }
    }
    return -1;
}
