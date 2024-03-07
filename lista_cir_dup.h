/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * IMPLEMENTACAO DA LISTA CIRCULAR DUPLAMENTE ENCADEADA
 * Arquivo de cabeçalho "lista_cir_dup.h"
***/

#ifndef __LISTA_CIR_DUP_H__
#define __LISTA_CIR_DUP_H__

#include <stdio.h>
#include <stdlib.h>

struct est_no_circ_dup {
    int valor;
    struct est_no_circ_dup *prox, *ant;
};
typedef struct est_no_circ_dup tipo_no_circ_dup;

tipo_no_circ_dup *aloca_no_circ_dup();

void insereInicioLstCirDup(tipo_no_circ_dup **, int);
void insereFimLstCirDup(tipo_no_circ_dup **, int);
void inserePosLstCirDup(tipo_no_circ_dup **, int, int);
int removeInicioLstCirDup(tipo_no_circ_dup **);
int removeFimLstCirDup(tipo_no_circ_dup **);
int removePosLstCirDup(tipo_no_circ_dup **, int);
void imprimeLstCirDup(tipo_no_circ_dup *);

#endif // __LISTA_CIR_DUP_H__
