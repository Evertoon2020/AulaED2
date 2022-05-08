//Arquivo arvoreBinaria.c
#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

struct NO
{
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};
//Arquivo arvoreBinaria.c
arvAVL *cria_arvAVL()
{
    arvAVL *raiz = (arvAVL*) malloc(sizeof(arvAVL));
    if(raiz != NULL)
    {
        *raiz = NULL;
    }
    return raiz;
}
//Arquivo arvoreBinaria.c
void liberar_arvAVL(arvAVL *raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    libera_NO(*raiz);
    free(raiz);
}

//Arquivo arvoreBinaria.c
void libera_NO(struct NO *no)
{
    if(no == NULL)
    {
        return;
    }
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

//Arquivo arvoreBinaria.c
int vazia_arvAVL(arvAVL *raiz)
{
    if(raiz == NULL)
    {
        return 1;
    }
    if(*raiz == NULL)
    {
        return 1;
    }
    return 0;
}

//Arquivo arvoreBinaria.c
int altura_arvAVL(arvAVL *raiz)
{
    if(raiz == NULL)
    {
        return 0;
    }
    if(*raiz == NULL)
    {
        return 0;
    }
    int alt_esq = altura_arvAVL(&((*raiz)->esq));
    int alt_dir = altura_arvAVL(&((*raiz)->dir));
    if(alt_esq > alt_dir)
    {
        return(alt_esq + 1);
    }
    else
    {
        return(alt_dir + 1);
    }
}

//Arquivo arvoreBinaria.c
int totalNO_arvAVL(arvAVL *raiz)
{
    if(raiz == NULL)
    {
        return 0;
    }
    if(*raiz == NULL)
    {
        return 0;
    }
    int alt_esq = totalNO_arvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_arvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

//Arquivo arvoreBinaria.c
void preOrdem_arvAVL(arvAVL *raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    if(*raiz != NULL)
    {
        printf("%d\n", (*raiz)->info);
        preOrdem_arvAVL(&((*raiz)->esq));
        preOrdem_arvAVL(&((*raiz)->dir));
    }
}

//Arquivo arvoreBinaria.c
void emOrdem_arvAVL(arvAVL *raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    if(*raiz != NULL)
    {
        emOrdem_arvAVL(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_arvAVL(&((*raiz)->dir));
    }
}

//Arquivo arvoreBinaria.c
void posOrdem_arvAVL(arvAVL *raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    if(*raiz != NULL)
    {
        posOrdem_arvAVL(&((*raiz)->esq));
        posOrdem_arvAVL(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

//Arquivo arvoreBinaria.c
int insere_arvAVL(arvAVL *raiz, int valor)
{
    if(raiz == NULL)
    {
        return 0;
    }
    struct NO *novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
    {
        return 0;
    }
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;
    if(*raiz == NULL)
    {
        *raiz = novo;
    }
    else
    {
        struct NO *atual = *raiz;
        struct NO *ant = NULL;
        while(atual != NULL)
        {
            ant = atual;
            if(valor == atual->info)
            {
                free(novo);//elemento já existe!
                return 0;
            }
            if(valor > atual->info)
            {
                atual = atual->dir;
            }
            else
            {
                atual = atual->esq;
            }
        }
        if(valor > ant->info)
        {
            ant->dir = novo;
        }
        else
        {
            ant->esq = novo;
        }
    }
    return 1;
}


//Arquivo arvoreBinaria.c
//função auxiliar para remoção o nó especifico
struct NO *remove_atual(struct NO *atual)
{
    struct NO *no1, *no2;
    if(atual->esq == NULL)
    {
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL)
    {
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual)
    {
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

//Arquivo arvoreBinaria.c
int consulta_arvAVL(arvAVL *raiz, int valor)
{
    if(raiz == NULL)
    {
        return 0;
    }
    struct NO *atual = *raiz;
    while(atual != NULL)
    {
        if(valor == atual->info)
        {
            return 1;
        }
        if(valor > atual->info)
        {
            atual = atual->dir;
        }
        else
        {
            atual = atual->esq;
        }
    }
    return 0;
}

//Calcula a altura de um nó
int alt_no(struct NO *no)
{
    if(no == NULL)
    {
        return -1;
    }
    else
    {
        return no->alt;
    }
}

//Calcula o Fator de Balanceamento de um nó
int fatorBalanceamento_NO(struct NO *no)
{
    return labs(alt_no(no->esq) - alt_no(no->dir));
}

/*A função labs(), arredonda valores em módulo*/

//Calcula maior valor
int maior (int x, int y)
{
    if(x > y)
    {
        return(x);
    }
    else
    {
        return(y);
    }
}

//Rotação da LL
void rotacaoLL(arvAVL *raiz)
{
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->esq), (*raiz)->alt + 1);
    *raiz = no;
}
//Rotação da RR
void rotacaoRR(arvAVL *raiz)
{
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    no->alt = maior(alt_no(no->dir), (*raiz)->alt + 1);
    *raiz = no;
}

//Rotação LR
void rotacaoLR (arvAVL *raiz)
{
    rotacaoRR(&(*raiz)->esq);
    rotacaoLL(raiz);
}

//Rotação RL
void rotacaoRL (arvAVL *raiz)
{
    rotacaoLL(&(*raiz)->dir);
    rotacaoRR(raiz);
}

int insere_arvAVL(arvAVL *raiz, int valor)
{
    int res;
    if(*raiz == NULL)
    {
        struct NO *novo;
        novo = (struct NO*) malloc (sizeof(struct NO));
        if(novo == NULL)
        {
            return 0;
        }
        novo->info = valor;
        novo->alt = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(valor < atual->info)
    {
        if((res = insere_arvAVL(&(atual->esq), valor)) == 1)
        {
            if(fatorBalanceamento_NO(atual)>=2)
            {
                if(valor < (*raiz)->esq->info)
                {
                    rotacaoLL(raiz);
                }
                else
                {
                    rotacaoLR(raiz);
                }
            }
        }
    }
    else
    {
        if(valor > atual->info)
        {
            if((res = insere_arvAVL(&(atual->dir), valor)) ==1)
            {
                if(fatorBalanceamento_NO(atual)>=2)
                {
                    if((*raiz)->dir->info < valor)
                    {
                        rotacaoRR(raiz);
                    }
                    else
                    {
                        rotacaoRL(raiz);
                    }
                }

            }
        }
        else
        {
            printf("Valor duplicado!\n");
            return 0;
        }
    }
    atual->alt = maior(alt_no(atual->esq), alt_no(atual->dir)) +1;
    return res;
}


int remove_arvAVL(arvAVL *raiz, int valor){
    if(*raiz == NULL) {
        return 0 ;
    }
    int res;
    if(valor < (*raiz)->info){
            if((res = remove_arvAVL(&(*raiz)->esq, valor)) == 1){
                if(fatorBalanceamento_NO(*raiz) >= 2){
                    if(alt_no((*raiz)->dir->esq) <= alt_no((*raiz)->dir->dir)){
                        rotacaoRR(raiz);
                    }else{
                        rotacaoRL(raiz);
                    }
                }
            }
    }
    if((*raiz)->info < valor){
        if((res = remove_arvAVL(&(*raiz)->dir, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
    }
    if((*raiz)->info == valor){
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){
            struct NO *no_velho = (*raiz);
            if((*raiz)->esq != NULL){
                *raiz = (*raiz)->esq;
            }else{
                *raiz = (*raiz)->dir;
            }
            free(no_velho);
        }else{
            struct NO *temp = procuramenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_arvAVL((*raiz)->dir,(*raiz)->info);
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(alt_no((*raiz)->esq->dir) <= alt_no((*raiz)->esq->esq)){
                    rotacaoLL(raiz);
                }else{
                    rotacaoLR(raiz);
                }
            }
        }
        if(*raiz != NULL){
            (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
        }
        return 1;
    }
    if(*raiz != NULL){
        (*raiz)->alt = maior(alt_no((*raiz)->esq), alt_no((*raiz)->dir)) + 1;
    }
    return res;
}

struct NO *procuramenor(struct NO *atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

