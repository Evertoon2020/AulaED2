//============================ MENU =====================================

int menu();
int submenu();

//===============   Gerando numeros aleatorios e alocando memoria, e limpado vetor  =======================

int* gerarVetorAletorio(int QTDE);
int* gerarVetorOrdenado(int QTDE);
int* gerarVetorDesordenado(int QTDE);
void limpaVetor(int *vetor);

//=====================    Calculando o Tempo      ===============================

void calculandoTempo10Tentativas(int opcao, int QTDE);
void calculandoTempoVetorOrdenado(int opcao, int QTDE);
void calculandoTempoVetorDesordenado(int opcao, int QTDE);

//======================          Megesort       ============================
void merge(int *vetor1, int *vetor2, int start, int mid, int end);
void sort(int *vetor1, int *vetor2, int start, int end);
void mergesort(int *vetor1, int tamanho);

//======================          Heapsort         ============================

int heapsortFunction(int *numero, int QTDE);
void heapfy(int *vet,int QTDE, int i);
void create_heap(int *vet, int QTDE);
void heapsort(int *vet, int QTDE);

//======================          Beadsort         ============================

void beadsort(int *vet, int QTDE);

//======================          CoutingSort         ============================

void countingsort(int *vet, int QTDE);
//void exibeVetor(int *vet, int QTDE);

//======================          Timsort         ============================

int min(int arg1, int arg2);
void insertionSort(int arr[], int l, int r);
void timsort(int vet[], unsigned int QTDE);

//======================          Radixsort         ============================

void radixsortFunction(int *vet, int QTDE);

//======================          Quicksort         ============================

void quicksort(int *vet, int QTDE);

//======================          Shellsort         ============================

void shellsort(int *vet, int QTDE);

//======================          Seletionsort         ============================

void seletionsort(int vet[], int QTDE);

//======================          Insertionsort         ============================

void insertionsort(int *vet, int QTDE);

//======================          Bubblesort         ============================

void bubblesort(int* vet, int QTDE);
