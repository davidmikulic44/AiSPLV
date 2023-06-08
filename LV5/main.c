#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define VELICINA 10

void zamjena(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int lijevi(int i){
    return (2 * i) + 1;
}

int desni(int i){
    return (2 * i) + 2;
}

void uhrpljavanje(int V[], int i, int n){
    int l = lijevi(i);
    int najveci;
    int r = desni(i);

    if( (V[l] > V[i]) && (l < n) )
        najveci = l;
    else
        najveci = i;

    if( (V[r] > V[najveci]) && (r < n) )
        najveci = r;

    if(najveci != i){
        zamjena(&V[i], &V[najveci]);
        uhrpljavanje(V, najveci, n);
    }
}

void maxHrpa(int V[], int n){
    for(int i = (n-1)/2;i>=0;i--){
        uhrpljavanje(V, i, n);
    }
}


void heap_sort(int V[], int n){
    maxHrpa(V, n);
    for(int i = n; i > 0; i--){
        zamjena(&V[0], &V[n-1]);
        n--;
        uhrpljavanje(V,0,n);
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
    int arr[VELICINA];
    srand((unsigned)time(NULL));
    for(int i=0; i<VELICINA;i++){
        arr[i]=rand()%(VELICINA*10);
    }

    time_t t1,t2;

    t1=clock();
    heap_sort(arr, VELICINA);
    t2=clock();

    printf("\nVrijeme heap-sort: %dms",t2-t1);

    t1=clock();
    bubble_sort(arr);
    t2=clock();
    printf("\nVrijeme bubble-sort: %dms",t2-t1);
    return 0;    
}
