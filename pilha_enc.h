/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discentes: Mariana Sanchez Pedroni
 * 
 * IMPLEMENTACAO DE PILHA ENCADEADA
 * Arquivo de cabecalho pilha_enc.h
 */

#ifndef __PILHA_ENC_H__
#define __PILHA_ENC_H__

#include <stdio.h>
#include <stdlib.h>

// Estrutura de um noh da pilha
struct est_noh {
    int valor;
    struct est_noh *prox;
};
typedef struct est_noh tipo_no;

// protoipos das funcoes
tipo_no *aloca_no (int);
void empilha (tipo_no **, int);
int desempilha (tipo_no **);
void imprime_pilha (tipo_no *);

#endif // __PILHA_ENC_H__