/*
*    Biblioteca Arvore AVL de Busca
*
*/
//Arquivo arvAVL.h
typedef struct NO *arvAVL;

//Arquivo arvAVL.h
arvAVL *cria_arvAVL();

//Arquivo arvAVL.h
void liberar_arvAVL(arvAVL *raiz);

//Arquivo arvAVL.h
int vazia_arvAVL(arvAVL *raiz);

//Arquivo arvAVL.h
int altura_arvAVL(arvAVL *raiz);

//Arquivo arvAVL.h
int totalNO_arvAVL(arvAVL *raiz);

//Arquivo arvAVL.h
void preOrdem_arvAVL(arvAVL *raiz);

//Arquivo arvAVL.h
void emOrdem_arvAVL(arvAVL *raiz);

//Arquivo arvAVL.h
void posOrdem_arvAVL(arvAVL *raiz);

//Arquivo arvAVL.h
int insere_arvAVL(arvAVL *raiz, int valor);

//Arquivo arvAVL.h
int remove_arvAVL(arvAVL *raiz, int valor);

//Arquivo arvAVL.h
int consulta_arvAVL(arvAVL *raiz, int valor);
