#include <stdio.h>
#include <stdlib.h>
#include "ordinamento.h"


/* 
 * Ricerca l'indice del minimo di un array
 */

int searchMin(TInfo a[], int n) {
    TInfo min = 0;
    for (int i = 1; i < n; i++)
        if (info_lesser(a[i], a[min]))
            min = i;
    return min;
}

/* 
 * Selection Sort 
 *   Theta(n^2)
 */

void selectionSort(TInfo a[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i + searchMin(a+i, n-i);
        if (min != i)
            info_swap (&a[i], &a[min]);
    }
}

/* 
 * Inserimento in order di x in a (a può contenere n+1 elementi)
 */

void insertInOrder(TInfo a[], int n, TInfo x) {
    int pos; // posizione di inserimento
    for (pos = n; pos > 0 && info_greater (a[pos-1], x); pos--)
        a[pos] = a[pos-1];
    a[pos]=x;
}

/* 
 * Insertion Sort
 *  best:Theta(n)
 *  else:Theta(n^2)
 */

void insertionSort(TInfo a[], int n) {
    for (int i = 1; i < n; i++) 
        insertInOrder(a, i, a[i]);
}

/* 
 * Fusione di due array ordinati a1 e a2 in un nuovo array ordinato b
 */

void merge(TInfo a1[], int n1, TInfo a2[], int n2, TInfo b[]) {
    int i1 = 0, i2 = 0, j = 0;
    
    while (i1 < n1 && i2 < n2) {
        if (info_lesser(a1[i1], a2[i2]))
            b[j++] = a1[i1++];
        else
            b[j++] = a2[i2++];
    }
    while (i1 < n1)
        b[j++] = a1[i1++];
    while (i2 < n2)
        b[j++] = a2[i2++];
}

/* 
 * Merge Sort
 * Theta(n*log n)
 */

void mergeSort(TInfo a[], int n) {
    if (n <= 1)
        return;
    
    int m = n/2;
    mergeSort(a, m);
    mergeSort(a+m, n-m);

    TInfo temp[n];
    merge(a, m, a+m, n-m, temp);
    for (int i = 0; i<n; ++i)
        a[i] = temp[i];
}



void mergeSortR(TInfo a[], int n, TInfo temp[]) {
    if (n <= 1)
        return;
    
    int m = n/2;
    mergeSortR(a, m, temp);
    mergeSortR(a+m, n-m, temp);

    merge(a, m, a+m, n-m, temp);
    for (int i = 0; i<n; ++i)
        a[i] = temp[i];
}

void mergeSort(TInfo a[], int n) {
    TInfo temp[n];
    mergeSortR(a,n,temp);
}

/* 
 * Partizionamento di un array rispetto ad un elemento pivot, restituisce 
 * l'indice aggiornato del pivot
 */

int partition(TInfo a[], int n) {
    int k = 1; // primo elemento della seconda partizione
    for (int i = 1; i<n; i++)
        if (info_lesser(a[i], a[0]))
            info_swap (&a[i], &a[k++]);
    info_swap(&a[0], &a[k-1]); // posiziona il pivot
    return k-1;
}

/* 
 * Quick Sort
 * worst:Theta(n^2)
 * else :Theta(n*log n)
 */

void quickSort(TInfo a[], int n) {
    if (n <= 1)
        return;
    int k = partition(a, n);
    quickSort(a, k);
    quickSort(a+k+1, n-k-1);
}

/* 
 * Bubble Sort
 *  best:Theta(n)
 *  else:Theta(n^2)
 */

void bubbleSort (TInfo a[], int n)
{
    int mod=1;
    for (int k=0; k<n-1 && mod; k++) {
        mod = 0;
        for (int i=0; i<n-k-1; i++) 
            if (info_greater(a[i],a[i+1])) {
                info_swap(&a[i], &a[i+1]);
                mod=1;
            }
    }
}
