#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define MIN 1
#define MAX 1000000
#define RUN 2

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

//============================ MAIN =====================================
int main(){

    int opcao, QTDE;
    opcao = menu();
    QTDE = submenu();
    calculandoTempo10Tentativas(opcao, QTDE);
    calculandoTempoVetorOrdenado(opcao, QTDE);
    calculandoTempoVetorDesordenado(opcao, QTDE);
    return 0;
}

//============================ MENU =====================================

int menu(){
    srand(time(NULL));
    int opcao;
    printf("----------------------------------------------------------------------------------------------");
    printf("\n\n                                        BEM VINDO\n\n");
    printf("----------------------------------------------------------------------------------------------\n\n");

    printf("Lista de programas:\n\n");
    printf("   1 - BubbleSort\n");
    printf("   2 - InsertionSort\n");
    printf("   3 - SeletionSort\n");
    printf("   4 - ShellSort\n");
    printf("   5 - MergeSort\n");
    printf("   6 - QuickSort\n");
    printf("   7 - HeapSort\n");
    printf("   8 - RadixSort\n");
    printf("   9 - TimSort\n");
    printf("   10 - BeadSort\n");
    printf("   11 - CountingSort\n\n");
    printf("Escolha o programa de ordenacao que deseja usar: ");
    scanf("%d", &opcao);
    system("cls");
    switch(opcao){
    case 1:
        printf("\n\nTipo: BubbleSort");
    break;
    case 2:
        printf("\n\nTipo: InsertionSort");
    break;
    case 3:
        printf("\n\nTipo: SeletionSort");
    break;
    case 4:
        printf("\n\nTipo: ShellSort");
    break;
    case 5:
        printf("\n\nTipo: MergeSort");
    break;
    case 6:
        printf("\n\nTipo: QuickSort");
    break;
    case 7:
        printf("\n\nTipo: HeapSort");
    break;
    case 8:
        printf("\n\nTipo: RadixSort");
    break;
    case 9:
        printf("\n\nTipo: TimSort");
    break;
    case 10:
        printf("\n\nTipo: BeadSort");
    break;
    case 11:
        printf("\n\nTipo: CountingSort");
    break;
    default:
        system("cls");
        printf("\n\nOpcao Invalida!!! Encerrando programa...\n\n");
        exit(0);
    break;
    }

    return opcao;
}

int submenu(){
    int opcao,QTDE;

    printf("\n\nQuantidade de elementos:\n\n");
    printf("   1 - 1.000\n");
    printf("   2 - 5.000\n");
    printf("   3 - 10.000\n");
    printf("   4 - 20.000\n");
    printf("   5 - 50.000\n");
    printf("   6 - 100.000\n");
    printf("\n\nEscolha a quantidade de elementos a serem ordenados: ");
    scanf("%d", &opcao);

    switch(opcao){
    case 1:
        QTDE = 1000;
    break;
    case 2:
        QTDE = 5000;
    break;
    case 3:
        QTDE = 10000;
    break;
    case 4:
        QTDE = 20000;
    break;
    case 5:
        QTDE = 50000;
    break;
    case 6:
        QTDE = 100000;
    break;
    default:
        system("cls");
         printf("\n\n  Opcao Invalida!!! Encerrando programa...\n\n");
        exit(0);
    break;
    }
    system("cls");
    printf("==========================================================================================================\n");
    printf("                                    QUANTIDADE ESCOLHIDA: %d", QTDE);
    return QTDE;
}

//===============   Gerando numeros aleatorios e alocando memoria, e limpado vetor  =======================

int* gerarVetorAleatorio(int QTDE){
    int j;

    int *numeros = (int*) malloc(QTDE * sizeof(int));

    if(!numeros){
        printf("Erro de alocacao!!");
        exit(EXIT_FAILURE); //é igual a -> exit(1)
    }
    for(int i = 0; i<QTDE; i++){
        j = rand()% MAX;
        numeros[i]=j;
    }
    return numeros;
}

int* gerarVetorOrdenado(int QTDE){

    int *numeros = (int*) malloc(QTDE * sizeof(int));

    if(!numeros){
        printf("Erro de alocacao!!");
        exit(EXIT_FAILURE); //é igual a -> exit(1)
    }
    for(int i = 0; i<QTDE; i++){
        numeros[i] = i;
    }
    return numeros;
}

int* gerarVetorDesordenado(int QTDE){

    int *numeros = (int*) malloc(QTDE * sizeof(int));

    if(!numeros){
        printf("Erro de alocacao!!");
        exit(EXIT_FAILURE); //é igual a -> exit(1)
    }
    for(int i = 0; i<QTDE; i++){
        numeros[i] = QTDE - i;
    }
    return numeros;
}


void limpaVetor(int *vetor){
    free(vetor);
}


//=====================    Calculando o Tempo      ===============================

void calculandoTempo10Tentativas(int opcao, int QTDE){

    int i, *vetor;
    struct timeval Tempo_inicial, Tempo_final;
    double deltaT, soma, media;

    for(i = 0; i < 10; i++){
        vetor = gerarVetorAleatorio(QTDE);

        switch(opcao){
            case 1:
                if(i == 0){
                    printf("\n==========================================================================================================\n");
                    printf("\n                                         BUBBLESORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
                bubblesort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 2:
                if(i == 0){
                    printf("\n==========================================================================================================\n");
                    printf("\n                                        INSERTONSORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
                insertionsort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 3:
                if(i == 0){
                    printf("\n==========================================================================================================\n");
                    printf("\n                                         SELETIONSORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
                seletionsort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 4:
                if(i == 0){
                    printf("\n==========================================================================================================\n");
                    printf("\n                                         SHELLSORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
                shellsort( vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 5:
                if(i == 0){
                    printf("\n==========================================================================================================\n");
                    printf("\n                                         MERGESORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
                mergesort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 6:
                if(i == 0){
                    printf("\n==========================================================================================================\n");
                    printf("\n                                         QUICKSORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
                quicksort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 7:
                if(i == 0){
                    printf("\n\n==========================================================================================================");
                    printf("\n                                         HEAPSORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
                heapsort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);

            break;
            case 8:
                if(i == 0){
                    printf("\n==========================================================================================================\n");
                    printf("\n                                         RADIXSORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
                radixsortFunction(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 9:
                if(i == 0){
                    printf("\n==========================================================================================================\n");
                    printf("\n                                         TIMSORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
               timsort(vetor, QTDE);
               gettimeofday(&Tempo_final, NULL);
            break;
            case 10:
                if(i == 0){
                    printf("\n==========================================================================================================\n");
                    printf("\n                                         BEADSORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
               beadsort(vetor, QTDE);
               gettimeofday(&Tempo_final, NULL);
            break;
            case 11:
                if(i == 0){
                    printf("\n==========================================================================================================\n");
                    printf("\n                                         COUNTINGSORT                                              \n");
                    printf("\n==========================================================================================================\n");
                }
                gettimeofday(&Tempo_inicial, NULL);
               countingsort(vetor, QTDE);
               gettimeofday(&Tempo_final, NULL);
            break;
        }

        //gettimeofday(&Tempo_final, NULL);

        deltaT = (Tempo_final.tv_sec + Tempo_final.tv_usec/1000000.0)-(Tempo_inicial.tv_sec + Tempo_inicial.tv_usec/1000000.0);

        printf("\n   Tempo da %d%c tentativa: %.20f segundos\n", i+1,167, deltaT);

        soma = soma + deltaT;
        //limpar funçao aqui
        limpaVetor(vetor);
    }
    printf("\n   Aperte enter para ver a media...\n\n", media);
    system("pause");
    system("cls");
    media = (soma/10);
    printf("\n\n----------------------------------------------------------------------------------------------------------\n");
    printf("                                                  MEDIA       \n");
    printf("----------------------------------------------------------------------------------------------------------\n\n");
    printf("    Media das tentativas: %.20f segundos\n", media);
    printf("\n\n==========================================================================================================\n");
}

void calculandoTempoVetorOrdenado(int opcao, int QTDE){

    int i, *vetor;
    struct timeval Tempo_inicial, Tempo_final;
    double deltaT;

    vetor = gerarVetorOrdenado(QTDE);

    switch(opcao){
        case 1:
                gettimeofday(&Tempo_inicial, NULL);
                bubblesort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 2:
                gettimeofday(&Tempo_inicial, NULL);
                insertionsort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 3:
                gettimeofday(&Tempo_inicial, NULL);
                seletionsort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 4:
                gettimeofday(&Tempo_inicial, NULL);
                shellsort( vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 5:
                gettimeofday(&Tempo_inicial, NULL);
                mergesort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 6:
                gettimeofday(&Tempo_inicial, NULL);
                quicksort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 7:
                gettimeofday(&Tempo_inicial, NULL);
                heapsort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 8:
                gettimeofday(&Tempo_inicial, NULL);
                radixsortFunction(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 9:
                gettimeofday(&Tempo_inicial, NULL);
                timsort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 10:
                gettimeofday(&Tempo_inicial, NULL);
               beadsort(vetor, QTDE);
               gettimeofday(&Tempo_final, NULL);
            break;
            case 11:
                gettimeofday(&Tempo_inicial, NULL);
               countingsort(vetor, QTDE);
               gettimeofday(&Tempo_final, NULL);
            break;
        }

        //gettimeofday(&Tempo_final, NULL);

        deltaT = (Tempo_final.tv_sec + Tempo_final.tv_usec/1000000.0)-(Tempo_inicial.tv_sec + Tempo_inicial.tv_usec/1000000.0);

        //limpar funçao aqui
        limpaVetor(vetor);

    printf("\n\n----------------------------------------------------------------------------------------------------------\n");
    printf("                                                  TEMPO VETOR ORDENADO       \n");
    printf("----------------------------------------------------------------------------------------------------------\n\n");
    printf("    Tempo de organizacao do vetor ordenado: %.20f segundos\n", deltaT);
    printf("\n\n==========================================================================================================\n");
}

void calculandoTempoVetorDesordenado(int opcao, int QTDE){

    int i, *vetor;
    struct timeval Tempo_inicial, Tempo_final;
    double deltaT;

    vetor = gerarVetorDesordenado(QTDE);

    switch(opcao){
        case 1:
                gettimeofday(&Tempo_inicial, NULL);
                bubblesort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 2:
                gettimeofday(&Tempo_inicial, NULL);
                insertionsort(vetor, QTDE);
            break;
            case 3:
                gettimeofday(&Tempo_inicial, NULL);
                seletionsort(vetor, QTDE);
            break;
            case 4:
                gettimeofday(&Tempo_inicial, NULL);
                shellsort( vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 5:
                gettimeofday(&Tempo_inicial, NULL);
                mergesort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);
            break;
            case 6:
                gettimeofday(&Tempo_inicial, NULL);
                quicksort(vetor, QTDE);
            break;
            case 7:
                gettimeofday(&Tempo_inicial, NULL);
                heapsort(vetor, QTDE);
                gettimeofday(&Tempo_final, NULL);

            break;
            case 8:
                gettimeofday(&Tempo_inicial, NULL);
                printf("RadixSort");
                radixsortFunction(vetor, QTDE);
            break;
            case 9:
                gettimeofday(&Tempo_inicial, NULL);
                printf("TimSort");
               timsort(vetor, QTDE);
            break;
            case 10:
                gettimeofday(&Tempo_inicial, NULL);
                printf("BeadSort");
               beadsort(vetor, QTDE);
            break;
            case 11:
                gettimeofday(&Tempo_inicial, NULL);
               countingsort(vetor, QTDE);
            break;
        }

        //gettimeofday(&Tempo_final, NULL);

        deltaT = (Tempo_final.tv_sec + Tempo_final.tv_usec/1000000.0)-(Tempo_inicial.tv_sec + Tempo_inicial.tv_usec/1000000.0);

        //limpar funçao aqui
        limpaVetor(vetor);

    printf("\n\n----------------------------------------------------------------------------------------------------------\n");
    printf("                                                  TEMPO VETOR DESORDENADO       \n");
    printf("----------------------------------------------------------------------------------------------------------\n\n");
    printf("    Tempo de organizacao do vetor desordenado: %.20f segundos\n", deltaT);
    printf("\n\n==========================================================================================================\n");
}

//======================          Megesort       ============================

void merge(int *vetor1, int *vetor2, int start, int mid, int end) {

	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) {
		if(vetor1[i] <= vetor1[j]) {
			vetor2[k] = vetor1[i];
			k += 1; i += 1;
		}
		else {
			vetor2[k] = vetor1[j];
			k += 1; j += 1;
		}
	}

	while(i <= mid) {
		vetor2[k] = vetor1[i];
		k += 1; i += 1;
	}

	while(j <= end) {
		vetor2[k] = vetor1[j];
		k += 1; j += 1;
	}

	for(i = start; i <= end; i += 1) {
		vetor1[i] = vetor2[i - start];
	}
}

void sort(int *vetor1, int *vetor2, int start, int end) {

	if(start < end) {
		int mid = (start + end) / 2;
		sort(vetor1, vetor2, start, mid);
		sort(vetor1, vetor2, mid + 1, end);
		merge(vetor1, vetor2, start, mid, end);
	}
}

void mergesort(int *vetor1, int tamanho) {
    int *vetor2 = malloc(sizeof(int) * tamanho);
    sort(vetor1, vetor2, 0, tamanho - 1);
    free(vetor2);
}

//======================          Heapsort         ============================

void heapfy(int *vet,int QTDE, int i){
    int esq =2*i+1;
    int dir =2*i+2;
    int maior,aux, n = QTDE;

    //escolhe maior valor entre os filhos (esq e dir)
    maior = i;
    if((esq < n) && (vet[esq] > vet[maior]))
        maior = esq;
    if((dir < n) && (vet[dir] > vet[maior]))
        maior = dir;

    //se um dos filhos for maior que o pai, troca.
    if(maior != i)
    {
        aux = vet[i];
        vet[i] = vet[maior];
        vet[maior]=aux;

        //continua descida até o local adequado, o elemento trocado
        //é comparado com seus filhos, para o maior elemento ser o pai
        //isso é feito para que o pai sempre seja maior que os filhos.
        heapfy(vet, n, maior);
    }
}

void create_heap(int *vet, int QTDE){
    int i, n = QTDE;
    //For que irá olhar só para os nós pais
    for(i=n/2-1; i>=0; i--)
    {
        //organiza o heap maior
        heapfy(vet,n,i);
    }
}

void heapsort(int *vet, int QTDE){
    int aux, i, n = QTDE;
    //O create_heap faz a primeira organização para uma heap maior
    create_heap(vet,n);
    for(i= n-1; i>0; i--){
        //Troca maior (primeiro elemento do vetor) com o ultimo
        aux=vet[0];
        vet[0]=vet[i];
        vet[i]=aux;
        n--; //diminuindo o tamanho do vetor, pois o ultimo elemento do vetor já é o maior
        //Chama o heapfy para organizar a heap
        heapfy(vet,n,0);
    }
}

//======================          Beadsort         ============================

void beadsort(int *vet, int QTDE)
{
	int i, j, max, sum;
	unsigned char *beads;
       #define BEAD(i, j) beads[i * max + j]

	for (i = 1, max = vet[0]; i < QTDE; i++)
		if (vet[i] > max) max = vet[i];

	beads = calloc(1, max * QTDE);

	/* mark the beads */
	for (i = 0; i < QTDE; i++)
		for (j = 0; j < vet[i]; j++)
			BEAD(i, j) = 1;

	for (j = 0; j < max; j++) {
		/* count how many beads are on each post */
		for (sum = i = 0; i < QTDE; i++) {
			sum += BEAD(i, j);
			BEAD(i, j) = 0;
		}
		/* mark bottom sum beads */
		for (i = QTDE - sum; i < QTDE; i++) BEAD(i, j) = 1;
	}

	for (i = 0; i < QTDE; i++) {
		for (j = 0; j < max && BEAD(i, j); j++);
		vet[i] = j;
	}
	free(beads);
}

//======================          CoutingSort         ============================

void countingsort(int *vet, int QTDE)
{
	int i;

	// Encontrando o maior elemento do vet

	int max=vet[0];
	for(i = 0; i<QTDE; i++){
		if(vet[i]>max)
		max=vet[i];
	}
	int VetorIndexA[max+1];

	// Inicializando o contador do vet com todos os valores sendo zeros

	for(i=0;i<=max;i++)	{
		VetorIndexA[i]=0;
	}

	// Acumular a quantidade de vezes que cada número se repete no vet

	for(i=0;i<QTDE;i++){
		VetorIndexA[vet[i]]++;
	}

	// Atualizar o contador do vet

	for(i=1; i<=max;i++){
		VetorIndexA[i] = VetorIndexA[i]+VetorIndexA[i-1];
	}

	// Encontrando o indice de cada elemento

    int VetorIndexB[QTDE];
	for(i=QTDE-1; i>=0; i--){
		VetorIndexB[--VetorIndexA[vet[i]]]=vet[i];
	}

	// copiar os elementos do vet original para o vet b

	for(i=0;i<QTDE;i++){
		vet[i]=VetorIndexB[i];
	}
}

/*
void exibeVetor(int *vetor, int tamanho ){
    int seq;
    for(seq = 0; seq < tamanho; seq++){
        printf(" %i",vetor[seq]);
        if(seq < tamanho - 1) printf(", ");
        else printf("\n");
    }
}
*/

//======================          Timsort         ============================

    void timsort(int vet[], unsigned int QTDE){
        if (vet == NULL || QTDE <= 1) return;
        int i;

// Sort individual subarrays of QTDE RUN

        for (i=0; i < QTDE; i+=RUN){
            insertionSort(vet, i, min(i+RUN-1, QTDE-1));
        }
        int* temp = (int*)malloc(sizeof(int)*QTDE);

        int l, m, r, n;
        for (n=RUN; n < QTDE; n*=2){
            for (l=0; l < QTDE; l+=2*n){
                m = l+n-1;
                r = min(l+2*n-1, QTDE-1);
                if (m<r){
                    merge(vet, temp, l, m, r);
                }
            }
        }

        free(temp);
    }

    void insertionSort(int arr[], int l, int r) {
    if (arr == NULL || l>=r) return;
    int key;
    int i, j;
    for (i=l+1; i<=r; i++) {
        key = arr[i];
        j = i-1;
        while (j>=l && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

    int min(int arg1, int arg2){
        if (arg1 <= arg2){
        return arg1;
    } else {
        return arg2;
        }
    }


//======================          Radixsort         ============================

void radixsortFunction(int *vet, int QTDE) {
	int i, exp = 1, m = 0, bucket[QTDE], temp[QTDE];

	for(i = 0; i < QTDE; i++) {
		if(vet[i] > m) {
			m = vet[i];
		}
	}

	while((m/exp) > 0) {
		for (i = 0; i < QTDE; i++) {
			bucket[i] = 0;
		}
		for(i = 0; i < QTDE; i++) {
			bucket[(vet[i] / exp) % 10]++;
		}
		for(i = 1; i < QTDE; i++) {
			bucket[i] += bucket[i-1];
		}
		for(i = (QTDE - 1); i >= 0; i--) {
			temp[--bucket[(vet[i] / exp) % 10]] = vet[i];
		}
		for(i = 0; i < QTDE; i++) {
			vet[i] = temp[i];
		}
		exp *= 10;
	}
}

//======================          Quicksort         ============================

void quicksort(int *vet, int QTDE) {
	int a = 1, b = (QTDE - 1), temp, x = vet[0];

	if (QTDE <= 1) {
		return;
	}

	while (1) {
		while ((a < QTDE) && (vet[a] <= x)) {
			a++;
		}

		while (vet[b] > x) {
			b--;
		}

		if (a < b) {
			temp = vet[a];
			vet[a] = vet[b];
			vet[b] = temp;
			a++;
			b--;
		}

		if (a >= b) {
			break;
		}
	}

	vet[0] = vet[b];
	vet[b] = x;

	quicksort(vet,b);
	quicksort(&vet[a],(QTDE - a));
}

//======================          Shellsort         ============================

void shellsort(int *vet, int QTDE) {
    int i, j, value;
    int h = 1;

    while(h < QTDE) {
        h = 3*h+1;
    }

    while (h > 0) {
        for(i = h; i < QTDE; i++) {
            value = vet[i];
            j = i;
                while (j > h-1 && value <= vet[j - h]) {
                    vet[j] = vet[j - h];
                    j = j - h;
                }
                vet[j] = value;
        }
        h = h/3;
    }
};

//======================          Seletionsort         ============================

void seletionsort(int vet[], int QTDE){
    int i,j,indice_menor,tmp;

    for (i = 0; i <QTDE-1; i++) {
    indice_menor = i;
    for (j = (i+1); j < QTDE; j++) {
      if(vet[j] < vet[indice_menor]) {
        indice_menor = j;
      }
    }
    if (i != indice_menor) {
       tmp = vet[i];
      vet[i] = vet[indice_menor];
      vet[indice_menor] = tmp;
    }
  }
}

//======================          Insertionsort         ============================

void insertionsort(int *vet, int QTDE) {
	int i, j, x;
	for (i = 1; i < QTDE; i++) {
		x = vet[i];
		for (j = i-1; j >= 0 && vet[j] > x; j--) {
			vet[j+1] =  vet[j];
		}
		vet[j+1] = x;
	}
}

//======================          Bubblesort         ============================

void bubblesort(int* vet, int QTDE) {
	int i, j, tmp;
	for (i = QTDE-1; i >= 1; i--) {
		for (j = 0; j < i; j++) {
			if (vet[j] > vet[j+1]) {
				tmp = vet[j];
				vet[j] = vet[j+1];
				vet[j+1] = tmp;
			}
		}
	}
}
