/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * IMPLEMENTACAO DA FILA ENCADEADA
 * Arquivo de cabeçalho fila_enc.h
*/
#ifndef __FILA_ENC__
#define __FILA_ENC__

#include <stdio.h>
#include <stdlib.h>

struct est_no {
    int valor;
    struct est_no *prox;
};
typedef struct est_no tipo_no;

tipo_no *aloca_no (int);
void insereFilaEnc (tipo_no **, int);
int removeFilaEnc (tipo_no **);
void imprimeFilaEnc (tipo_no *);

#endif