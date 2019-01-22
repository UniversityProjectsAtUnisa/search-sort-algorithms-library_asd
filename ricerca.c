#include <stdio.h>
#include <stdlib.h>
#include "ricerca.h"


/* Ricerca lineare
 * restituisce l'indice del primo elemento di a uguale a x, -1 se x non è
 * presente in a.
 * 
 * Complessità: theta(n)
 */

int linearSearch(TInfo a[], int n, TInfo x) {
    int i = 0;
    while (i < n && !info_equal (a[i], x))
        i++;
    if (i == n) // non trovato
        return -1;
    else
        return i;
}

/* Ricerca lineare (per array ordinati)
 * restituisce l'indice del primo elemento di a uguale a x, -1 se x non è
 * presente in a.
 * 
 * Complessità: theta(n)
 */

int linearSearchO(TInfo a[], int n, TInfo x) {
    int i = 0;
    while (i < n && info_lesser (a[i], x))
        i++;
    if (i == n || info_greater (a[i],x)) // non trovato
        return -1;
    else
        return i;
}

/* Ricerca binaria (solo per array ordinati)
 * restituisce l'indice del primo elemento di a uguale a x, -1 se x non è
 * presente in a.
 * 
 * Complessità: theta(log n)
 */

int binarySearch(TInfo a[], int n, TInfo x) {
    int first = 0, last = n-1, i;
    while (first <= last) {
        i = (first+last)/2;
        if (info_equal(a[i], x))  // trovato
            return i;
        if (info_lesser(a[i], x)) 
            first = i+1;
        else
            last = i-1;
    }
    return -1; // non trovato
}

/* Ricerca binaria (algoritmo ricorsivo)
 * restituisce l'indice del primo elemento di a uguale a x, -1 se x non è
 * presente in a.
 * 
 * Complessità: theta(log n)
 */

int binarySearchR(TInfo a[], int n, TInfo x) {
    if (n <= 0)
        return -1; // non trovato
    int i = (n-1)/2;
    if (info_equal(a[i], x))  // trovato
        return i;
    if (info_lesser(x, a[i])) 
        return binarySearch(a, i, x);
    int j = binarySearch(a+i+1, n-i-1, x);
    if (j == -1)
        return -1;
    return j+i+1;
}
