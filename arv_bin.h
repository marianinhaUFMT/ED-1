/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * IMPLEMENTACAO DA ARVORE BINARIA
 * Arquivo de cabeçalho arv_bin.h
*/

#ifndef __ARV_BIN_H__
#define __ARV_BIN_H__

#include <stdio.h>
#include <stdlib.h>

struct est_no_arvore {
    int dado;
    struct est_no_arvore *esq;
    struct est_no_arvore *dir;
};
typedef struct est_no_arvore tipo_no_arvore;

// Prototipos das funcoes
tipo_no_arvore *alocaNoArv(int);
void insereArvBin(tipo_no_arvore **, int);
void removeArvBin(tipo_no_arvore **, int);
void percursoPreOrdem(tipo_no_arvore *);
void percursoOrdem(tipo_no_arvore *);
void percursoPosOrdem(tipo_no_arvore *);
int buscaArvBin(tipo_no_arvore *, int);
int alturaArvBin(tipo_no_arvore *);
int contabilizaNosArvBin(tipo_no_arvore *);
void imprimeNivelArvBin(tipo_no_arvore *, int);
int menorValorArvBin(tipo_no_arvore *);
int maiorValorArvBin(tipo_no_arvore *);

#endif // __ARV_BIN_H__
