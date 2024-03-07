/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * Cabeçalho da lista duplamente encadeada
*/

#ifndef __LISTADUPLA_ENC_H__
#define __LISTADUPLA_ENC_H__

#include <stdio.h>
#include <stdlib.h>

struct est_noh_dup {
    int valor;
    struct est_noh_dup *prox;
    struct est_noh_dup *ant;
};
typedef struct est_noh_dup tipo_noh_dup;

tipo_noh_dup *aloca_no(int);

void insereInicioLstDup(tipo_noh_dup **, int);
void insereFimLstDup(tipo_noh_dup **, int);
void inserePosLstDup(tipo_noh_dup **, int, int);
int removeInicioLstDup(tipo_noh_dup **);
int removeFimLstDup(tipo_noh_dup **);
int removePosLstDup(tipo_noh_dup **, int);
void imprimeLstDup(tipo_noh_dup *);

#endif // __LISTADUPLA_ENC_H__