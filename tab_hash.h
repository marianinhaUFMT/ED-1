/**
 * @file tab_hash.h
 * @author Mariana Sanchez Pedroni
 * @brief Biblioteca que implementa a tabela hash
 * @version 0.1
 * @date 2024-02-20
 * 
 * @copyright Copyright (c) 2024
 * 
*/

#ifndef __TAB_HASH_H__
#define __TAB_HASH_H__

#include <stdio.h>
#include <stdlib.h>

#define TAM_HASH 10 //tamanho da tabela hash

//definicao da estrtura do noh
struct est_no_hash{
    int chave; //chave que identifica o conjunto dos dados
    int valor; // dado que sera armazenado, sendo nome, idade, etc
    struct est_no_hash *prox; //ponteiro para estabelecer um encadeamento
};
typedef struct est_no_hash tipo_no_hash;

struct est_tab_hash{
    tipo_no_hash *tabela_hash[TAM_HASH]; //ponteiro para a tabela hash
};
typedef struct est_tab_hash tipo_tab_hash;

//prototipo das funcoes
tipo_no_hash *alocaNoHash (int, char); //aloca um novo noh
void inicializaTabHash(tipo_tab_hash *);
int funcaoHash(int);
void insereTabHash(tipo_tab_hash *, int, char); //insere um novo valor 
//pode implementar uma funcao de insercao que recebe um noh direto
char removeTabHash(tipo_tab_hash *, int); //remove um valor da tabela hash
tipo_no_hash *buscaTabHash(tipo_tab_hash *, int); //busca um valor na tabela hash
void imprimeTabHash(tipo_tab_hash *); //imprime a tabela hash

#endif // __TAB_HASH_H__