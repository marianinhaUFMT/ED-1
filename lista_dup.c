/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * IMPLEMENTACAO DA LISTA_DUP.H
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista_dup.h"

/**
 * @brief Funcao que aloca memoria para um TIPO_NO
 * 
 * @param vl valor a ser inserido
 * @return tipo_noh_dup* 
 */
tipo_noh_dup *aloca_no(int vl) {
    tipo_noh_dup *novo_no;
    novo_no = (tipo_noh_dup*) malloc (sizeof(tipo_noh_dup));
    if (novo_no != NULL){
        novo_no -> prox = NULL;
        novo_no -> ant = NULL;
        novo_no -> valor = vl;
    } else {
        return NULL;
    }
}
/**
 * @brief Funcao que insere no inicio da lista duplamente encadeada
 * 
 * @param lst ponteiro para lista
 * @param vl valor a ser inserido
 */
void insereInicioLstDup(tipo_noh_dup **lst, int vl) {
    tipo_noh_dup *novo_no;
    novo_no = aloca_no(vl);
    if (novo_no != NULL){ // Se o novo nó foi alocado
        novo_no -> prox = (*lst); // O proximo do novo nó aponta para o primeiro nó da lista (estava na linha 46 e foi passado para cá para evitar erro de segmentação)
        if ((*lst) != NULL){
            (*lst)->ant = novo_no; // O anterior do primeiro nó aponta para o novo nó
        }
        (*lst) = novo_no;
    } else {
        printf("[ERRO] Falha na insercao de valor no inicio.\n");
    }
}

/**
 * @brief Funcao que insere no fim da lista duplamente encadeada
 * 
 * @param lst ponteiro para lista
 * @param vl valor a ser inserido
 */
void insereFimLstDup(tipo_noh_dup **lst, int vl){
    tipo_noh_dup *novo_no, *aux;
    novo_no = aloca_no(vl);
    if (novo_no != NULL){
        if ((*lst) == NULL) {
            (*lst) = novo_no; // Se a lista estiver vazia, o novo nó é o primeiro
        } else {
            aux = (*lst); // Se a lista não estiver vazia, percorre a lista até o último nó
            while (aux->prox != NULL){
                aux = aux->prox; // Enquanto o próximo nó não for nulo, percorre a lista
            }
            novo_no->ant = aux; // O anterior do novo nó aponta para o último nó da lista
            aux->prox = novo_no; // O próximo do último nó aponta para o novo nó
        }
    } else {
        printf("[ERRO] Falha na insercao de valor no fim.\n");
    }
}
/**
 * @brief Funcao que insere um novo valor em posicao
 * 
 * @param lst ponteiro para lista
 * @param vl valor a ser inserido
 * @param pos posicao a ser inserido
 */
void inserePosLstDup(tipo_noh_dup **lst, int vl, int pos){
    tipo_noh_dup *novo_no, *aux;
    int contador;

    novo_no = (tipo_noh_dup*) malloc (sizeof(tipo_noh_dup));

    if (novo_no != NULL){
        contador = 0;
        aux = (*lst);
        while ((aux != NULL) && (contador < pos)){
            aux = aux -> prox;
            contador++;
        }
        if (aux != NULL){
            novo_no -> valor = vl; // Atribui o valor ao novo nó (nao estava sendo feito)
            novo_no -> prox = aux; // O próximo do novo nó aponta para o nó da posição
            novo_no -> ant = aux -> ant; // O anterior do novo nó aponta para o anterior do nó da posição
            if (aux->ant != NULL){ // Se o nó da posição não for o primeiro
                aux -> ant -> prox = novo_no;// O próximo do nó anterior ao nó da posição aponta para o novo nó
                }
            aux -> ant = novo_no; // O anterior do nó da posição aponta para o novo nó
            if (pos == 0){
                (*lst) = novo_no; // Se a posição for 0, o novo nó é o primeiro
            }
        } else {
            printf("[ERRO] Posicao invalida para insercao de valor na lista.\n");
            free(novo_no); //nao estava sendo feito
        }
    }
}
/**
 * @brief Funcao que remove um valor do inicio da lista
 * 
 * @param lst ponteiro para lista
 * @param pos posicao a ser removido
 * @return int 
 */
int removeInicioLstDup(tipo_noh_dup **lst) {
    tipo_noh_dup *aux;
    int vl;
    // se a lista nao estiver vazia
    if ( (*lst) != NULL ) {
        aux = (*lst);
        vl = (*lst) -> valor;
        // empurra o ponteiro da lista para frente
        (*lst) = (*lst) -> prox;
        (*lst) -> ant = NULL;
        free(aux);
        return vl;
    } else {
        printf("[ERRO] Lista vazia, impossivel remover no inicio!\n");
        return -1;
    }
}

/**
 * @brief Funcao que remove um valor do fim da lista
 * 
 * @param lst ponteiro para lista
 * @param pos posicao a ser removido
 * @return int 
 */
int removeFimLstDup(tipo_noh_dup ** lst) {
    tipo_noh_dup *aux;
    int vl;

    if ( (*lst) != NULL ) {
        aux = (*lst);
        // enquanto nao chegar no ultimo noh o aux percorre a lista
        while (aux -> prox != NULL) {
            aux = aux -> prox;
        }
        vl = aux -> valor;
        // verifica se NAO eh o ultimo noh
        if (aux -> ant != NULL) {
            // o ponteiro proximo do ex ultimo elemento passa a valer nulo
            aux -> ant -> prox = NULL;
        }
        // o elemento desejado eh liberado da memoria
        if ( ((*lst) -> ant == NULL) && ((*lst) -> prox == NULL) ) {
            (*lst) = NULL;
        }
        free(aux);
        return vl;
    } else {
        printf("[ERRO] Lista vazia, impossivel remover no fim!\n");
        return -1;
    }
}
/**
 * @brief Funcao que remove um valor de uma posicao
 * 
 * @param lst ponteiro para lista
 * @param pos posicao a ser removido
 * @return int 
*/
int removePosLstDup(tipo_noh_dup **lst, int pos) {
    tipo_noh_dup *aux;
    int vl, contador;

    if ( (*lst) != NULL ) {
        contador = 0;
        aux = (*lst);
        while ( (aux != NULL) && (contador < pos) ) {
            aux = aux -> prox;
            contador++;
        }
        if (aux != NULL) {
            vl = aux -> valor;
            if (aux -> ant != NULL) {
                aux -> ant -> prox = aux -> prox;
            } else {
                (*lst) = aux -> prox;
            }
            if (aux -> prox != NULL) {
                aux -> prox -> ant = aux -> ant;
            }
            free(aux);
            return vl;
        } else {
            printf("[ERRO] Posicao invalida para remocao de valor na lista.\n");
            return -1;
        }
    } else {
        printf("[ERRO] Lista vazia, impossivel remover no fim!\n");
        return -1;
    }
}

/**
 * @brief Funcao que imprime uma lista com encadeamento duplo
 * 
 * @param lst ponteiro para lista
 */
void imprimeLstDup (tipo_noh_dup *lst){
    if (lst != NULL){
        printf ("[NULL]");
        while (lst != NULL){
            printf ("->[%d]<-", lst -> valor);
            lst = lst -> prox;
        }
        printf("->[NULL]<-\n");
    }
}