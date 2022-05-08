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
    int vetor2[9]= {1,2,3,4,5,6,7,8,9};
    int vetor3[9]= {1,2,3,4,5,6,7,8,9};
    int quant = 9;
    int i, num;

    printf("\nDigite o número para busca: ");
    scanf("%d",&num);

    if(buscaLinear(vetor1, quant, num) != -1)
    {
        printf("\nValor %d, foi encontrado \nBusca Linear\nVetores:",num);
        for(i=0;i<quant;i++){
            printf("%d ",vetor1[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nValor %d, NÃO foi encontrado na Busca Linear!\n", num);
    }

    if(buscaOrdenada(vetor2, quant, num) != -1)
    {
        printf("\nValor %d, foi encontrado \nBusca Ordenada\nVetores:",num);
        for(i=0;i<quant;i++){
            printf("%d ",vetor2[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nValor %d, NÃO foi encontrado na Busca Ordenada!\n", num);
    }

    if(buscaBinaria(vetor2, quant, num) != -1)
    {
        printf("\nValor %d, foi encontrado \nBusca Binaria\nVetores:",num);
        for(i=0;i<quant;i++){
            printf("%d ",vetor2[i]);
        }
        printf("\n");
    }
    else
    {
        printf("\nValor %d, NÃO foi encontrado na Busca Binaria!\n", num);
    }

    printf("\n\n");
    system("pause");
}

int buscaLinear(int *vetor, int n, int elem)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(elem==vetor[i])
        {
            return i;
        }
    }
    return -1;
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

int buscaBinaria(int *vetor, int n, int elem)
{
    int i, inicio, meio, fim;
    inicio = 0;
    fim = n-1;

    while(inicio<=fim)
    {
        meio=(inicio+fim)/2;
        if(elem<vetor[meio])
        {
            fim = meio-1;
        }
        else
        {
            if(elem>vetor[meio])
            {
                inicio=meio+1;
            }
            else
            {
                return meio;
            }
        }
    }
    return -1;
}
