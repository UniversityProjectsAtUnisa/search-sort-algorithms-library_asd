/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "tinfo.h"

bool info_equal (TInfo x, TInfo y) {
    return x == y;
}

bool info_less (TInfo x, TInfo y) {
    return x < y;
}

bool info_greater (TInfo x, TInfo y) {
    return x > y;
}

void info_swap(TInfo* x, TInfo* y) {
    TInfo z = *x;
    *x = *y;
    *y = z;
}

/*
 * Funzioni di utilità
 */

void info_arrayPrint(TInfo a[], int n) {
    for (int i = 0; i < n; i++)
        printf ("%d ", a[i]);
    printf ("\n");
}

void info_arrayCopy(TInfo a[], TInfo b[], int n) {
    for (int i = 0; i < n; i++)
        b[i]=a[i];
}
