/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * IMPLEMENTACAO DA LISTA CIRCULAR ENCADEADA
 * Arquivo de cabeçalho "lista_circ.h"
***/

#ifndef __LISTA_CIRC_H__
#define __LISTA_CIRC_H__

#include <stdio.h>
#include <stdlib.h>

// Estrutura do nó
struct est_noh_cir {
    int valor;
    struct est_noh_cir *prox;
};
typedef struct est_noh_cir tipo_noh_cir;

tipo_noh_cir *aloca_noh_cir(int);

void insereInicioCir(tipo_noh_cir **, int);
void insereFimCir(tipo_noh_cir **, int);
void inserePosCir(tipo_noh_cir **, int, int);
int removeInicioCir(tipo_noh_cir **);
int removeFimCir(tipo_noh_cir **);
int removePosCir(tipo_noh_cir **, int);
void imprimeCir(tipo_noh_cir *);

#endif // __LISTA_CIRC_H__