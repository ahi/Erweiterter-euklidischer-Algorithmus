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
        double k;
        double q_k;
        double r_k;
        
        double x_k;
        double y_k;
    } t_step;

    typedef struct t_list {
        t_step *data;
        struct t_list *next;
    } t_list;
    
    typedef struct t_listHeader {
        struct t_list *first;
        struct t_list *last
    } t_listHeader;
#ifdef	__cplusplus
}
#endif

#endif	/* EEA_H */

