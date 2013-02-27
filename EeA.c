/* 
 * File:   EeA.c
 * Author: s.ahmet.kiyak@gmail.com
 *
 * Created on 2. Februar 2013, 17:31
 */

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "EeA.h";

t_listHeader* initList(int a, int b)
{
    t_listHeader *listHead = (t_listHeader *) malloc(sizeof (t_listHeader));
    t_step *p = (t_step*) malloc(sizeof (t_step));
    listHead->first = p;
    listHead->last = p;
    // Zeile 0
    p->k = 0;
    p->x_k = 1;
    p->y_k = 0;
    p->r_k = a;
    p->prev = NULL;

    // Zeile 1
    p = (t_step *) malloc(sizeof (t_step));
    append(listHead, p);
    p->k = 1;
    p->x_k = 0;
    p->y_k = 1;
    p->r_k = b;

    return listHead;
}

t_listHeader* calculate(int a, int b)
{
    t_listHeader *list;
    t_step *p;
    t_step *q;
    list = initList(a, b);
    p = getByK(list, 1);
    
    while(p->r_k != 0)
    {
        append(list, ((t_step *) malloc(sizeof (t_step))));
        p = list->last;
        p->k = p->prev->k + 1;
        // rk = rk-2 % rk-1
        p->r_k = p->prev->prev->r_k % p->prev->r_k;
        // qk = (rk-2 - rk) / rk-1
        p->q_k = (p->prev->prev->r_k - p->r_k) / p->prev->r_k;
        // xk = xk-2 - qk * xk-1
        p->x_k = p->prev->prev->x_k - (p->q_k * p->prev->x_k);
        // yk = yk-2 - qk * yk-1
        p->y_k = p->prev->prev->y_k - (p->q_k * p->prev->y_k);
    }
    
    return list;
}

/**
 * Append a t_step element and set the pointer to the new element
 * @param t_step p
 */
void append(t_listHeader *listHead, t_step *p)
{
    listHead->last->next = p;
    p->prev = listHead->last;
    listHead->last = p;
    p->next = NULL;

    return;
}

t_step* getByK(t_listHeader *listHead, int k)
{
    t_step *p;
    p = listHead->first;

    while (p != NULL)
    {
        if (p->k == k)
        {
            return p;
        }
        p = p->next;
    }
}