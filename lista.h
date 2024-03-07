/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * Meu PROGRAMA XXV - Implementacao da estrutura de LISTA (modular)
 * Arquivo de cabeçalho LISTA.H
*/

#ifndef __LISTA_H__
#define __LISTA_H__

#include <stdio.h>
#include <stdlib.h>

#define N 10 //definicao de constante que determina a capacidade

//definicao do tipo abstrato de dado que representa a funcao FILA
struct est_lista {
    int lista[N];
    int contador;
};
typedef struct est_lista tipo_lista;

//definicao dos prototipos
int insere_inicio_lista (tipo_lista*, int);
int insere_fim_lista (tipo_lista*, int);
int insere_pos_lista (tipo_lista*, int, int);
int remove_inicio_lista (tipo_lista*);
int remove_fim_lista (tipo_lista*);
int remove_pos_lista (tipo_lista*, int);
int remove_valor_lista (tipo_lista*, int);
int busca_pos_lista (tipo_lista, int);
int busca_valor_lista (tipo_lista, int);
int busca_maior_lista (tipo_lista);
int busca_menor_lista (tipo_lista);
void imprime_lista (tipo_lista);



#endif //fim __LISTA_H__
