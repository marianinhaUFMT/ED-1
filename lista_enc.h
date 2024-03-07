/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * IMPLEMENTACAO DA LISTA ENCADEADA
 * Arquivo de cabeçalho "lista_enc.h"
*/

#ifndef __LISTA_ENC__
#define __LISTA_ENC__

#include <stdio.h>
#include <stdlib.h>

// cria uma estrutura que contem o valor a ser inserido e o um ponteiro p/ o proximo noh
struct est_no {
    int valor;
    struct est_no *prox;
};
typedef struct est_no tipo_no_lst;

// TODO
// prototipo das funcoes
tipo_no_lst *aloca_no(int);
void insereInicio(tipo_no_lst **lst, int valor);
void insereFim(tipo_no_lst **lst, int valor);
void inserePosicao(tipo_no_lst **lst, int valor, int pos);
int removeInicio(tipo_no_lst **lst);
int removeFim(tipo_no_lst **lst);
int removePosicao(tipo_no_lst **lst, int valor);
void imprimeLista(tipo_no_lst *lst);

#endif