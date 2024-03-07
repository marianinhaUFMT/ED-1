/**
 * @file heap.h
 * @author Mariana Sanchez Pedroni
 * @brief Biblioteca eu implementa um heap maximo
 * @version 0.1
 * @date 2024-02-22
 * 
 * @copyright Copyright (C) 2024
 * 
*/

#ifndef __HEAP_MAX_H__
#define __HEAP_MAX_H__

#include <stdio.h>
#include <stdlib.h>

#define TAM_HEAP 20 // capacidade do heap

//define a estrutura que armazena a PRIORIDADE e o valor/dado
struct est_dado_heap {
    int prioridade;
    char dado;
};
typedef struct est_dado_heap tipo_dado_heap;

//define estrutura que representa toda a tabela HEAP
struct est_heap{
    int qtd;
    tipo_dado_heap heap[TAM_HEAP];
};
typedef struct est_heap tipo_heap;

//prototipos das funcoes
void inicializaHeap (tipo_heap *);
int filhoEsqHeap (int);
int filhoDirHeap (int);
int paiHeap (int);
void sobeHeap (tipo_heap *, int);
void desceHeap (tipo_heap *, int);
void insereHeap (tipo_heap *, int, char);
tipo_dado_heap removeHeap (tipo_heap *);
void imprimeHeap (tipo_heap *);
void heapSort (tipo_heap *, int);

#endif // __HEAP_MAX_H__