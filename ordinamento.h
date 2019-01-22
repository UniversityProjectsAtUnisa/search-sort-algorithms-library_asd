/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ordinamento.h
 * Author: marco
 *
 * Created on 22 gennaio 2019, 19.29
 */

#ifndef ORDINAMENTO_H
#define ORDINAMENTO_H

#include "tinfo.h"
int searchMin(TInfo a[], int n);
void selectionSort(TInfo a[], int n);
void insertInOrder(TInfo a[], int n, TInfo x);
void insertionSort(TInfo a[], int n);
void merge(TInfo a1[], int n1, TInfo a2[], int n2, TInfo b[]);
void mergeSort(TInfo a[], int n);
void mergeSortR(TInfo a[], int n, TInfo temp[]);
void mergeSort(TInfo a[], int n);
int partition(TInfo a[], int n);
void quickSort(TInfo a[], int n);
void bubbleSort (TInfo a[], int n);

#endif /* ORDINAMENTO_H */

