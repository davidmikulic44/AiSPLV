#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VELICINA 10000

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;


    int *L = (int*)malloc(n1*sizeof(int));
    int *R = (int*)malloc(n2*sizeof(int));

    for (i = 0; i < n1; i++) {
         L[i] = arr[l + i];
    }
       
    for (j = 0; j < n2; j++) {
         R[j] = arr[m + 1 + j];
    }
       
    i = 0;
    j = 0; 
    k = l; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void zamjena(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void uhrpljavanje(int *arr, int n, int i){
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
        
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }
        
    if (largest != i) {
        zamjena(&arr[i], &arr[largest]);
        uhrpljavanje(arr, n, largest);
    }
}

void maxHrpa(int *V, int n){
    for(int i = n/2-1;i>=0;i--){
        uhrpljavanje(V, i, n);
    }
}


void heap_sort(int *V, int n){
    maxHrpa(V, n);
    for(int i = n-1; i >= 0; i--){
        zamjena(&V[0], &V[n-1]);
        n--;
        uhrpljavanje(V,i,0);
    }
}

void bubble_sort(int V[]){
    for(int i=0;i<VELICINA-1;i++){
        for(int j=0;j<VELICINA-i-1;j++){
            if(V[j+1]<V[j])
                zamjena(&V[j+1],&V[j]);
        }
    }
}

void ispis(int a[]){
    for(int i = 0;i < VELICINA;i++)
        printf("%d ",a[i]);
}

int main(){
    int *arr=(int*)malloc(VELICINA*sizeof(int));
    srand((unsigned)time(NULL));
    for(int i=0; i<VELICINA;i++){
        arr[i]=rand()%VELICINA;
    }

    time_t t1,t2;

    t1=clock();
    heap_sort(arr, VELICINA);
    t2=clock();

    printf("\nVrijeme heap_sort: %dms",t2-t1);

    t1=clock();
    merge_sort(arr, 0, VELICINA-1);
    t2=clock();
    printf("\nVrijeme merge_sort: %dms",t2-t1);

    t1=clock();
    bubble_sort(arr);
    t2=clock();
    printf("\nVrijeme bubble_sort: %dms",t2-t1);
    return 0;    
}
