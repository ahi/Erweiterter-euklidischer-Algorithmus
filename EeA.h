/* 
 * File:   EeA.h
 * Author: s.ahmet.kiyak@gmail.com
 *
 * Created on 2. Februar 2013, 17:31
 */

#ifndef EEA_H
#define	EEA_H

#ifdef	__cplusplus
extern "C" {
#endif

    typedef struct t_step {
        int k;
        int q_k;
        int r_k;

        int x_k;
        int y_k;
        struct t_step *prev;
        struct t_step *next;
    } t_step;

    typedef struct t_listHeader {
        struct t_step *first;
        struct t_step *last;
    } t_listHeader;

    t_listHeader* calculate(int a, int b);
    t_listHeader* initList(int a, int b);
    void append(t_listHeader *listHead, t_step *p);
    t_step* getByK(t_listHeader *listHead, int k);
#ifdef	__cplusplus
}
#endif

#endif	/* EEA_H */

