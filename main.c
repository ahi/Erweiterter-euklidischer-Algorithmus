/* 
 * File:   main.cpp
 * Author: s.ahmet.kiyak@gmail.com
 *
 * Created on 2. Februar 2013, 17:25
 */

#include <stdlib.h>
#include <stdio.h>
#include "EeA.h"

/*
 * 
 */
int main(int argc, char** argv) {
    t_listHeader *l = calculate(6930, 1098);
    printf("Eingabe: a=6930, b=1098\n");
    printf("Ergebnis: x=%i, y=%i", l->last->prev->x_k, l->last->prev->y_k);
    return 0;
}

