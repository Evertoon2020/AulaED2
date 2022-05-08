#include <stdio.h>


void shellsort(int arr[], int num);

void shellsort(int *vet, int size) {
    int i, j, value;
    int h = 1;

    while(h < size) {
        h = 3*h+1;
    }

    while (h > 0) {
        for(i = h; i < size; i++) {
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

int main(){
    int arr[30];
    int k, num;
    printf("Enter total no. of elements : ");
    scanf("%d", &num);
    printf("\nEnter %d numbers: ", num);
    for (k = 0 ; k < num; k++){
        scanf("%d", &arr[k]);
    }
    shellsort(arr, num);
    printf("\n Sorted array is: ");
    for (k = 0; k < num; k++)
        printf("%d ", arr[k]);
return 0;
}
