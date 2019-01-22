/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   tinfo.h
 * Author: marco
 *
 * Created on 22 gennaio 2019, 19.29
 */

#ifndef TINFO_H
#define TINFO_H

#include <stdbool.h>
typedef int TInfo;

bool info_equal (TInfo x, TInfo y);
bool info_lesser (TInfo x, TInfo y);
bool info_greater (TInfo x, TInfo y);
void info_swap(TInfo* x, TInfo* y);
void info_arrayPrint(TInfo a[], int n);
void info_arrayCopy(TInfo a[], TInfo b[], int n);


#endif /* TINFO_H */

