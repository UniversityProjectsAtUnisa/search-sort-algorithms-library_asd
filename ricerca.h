/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ricerca.h
 * Author: marco
 *
 * Created on 22 gennaio 2019, 19.30
 */

#ifndef RICERCA_H
#define RICERCA_H

#include "tinfo.h"
int linearSearch(TInfo a[], int n, TInfo x);
int linearSearchO(TInfo a[], int n, TInfo x);
int binarySearch(TInfo a[], int n, TInfo x);
int binarySearchR(TInfo a[], int n, TInfo x);

#endif /* RICERCA_H */

