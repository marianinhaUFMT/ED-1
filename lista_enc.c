/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discentes: Mariana Sanchez Pedroni
 * 
 * Meu PROGRAMA - Implementacao da estrutura de LISTA ENCADEADA
 */

#include <stdio.h>
#include <stdlib.h>

// implementacao do cabecalho LISTA_ENC.H
#include "lista_enc.h"

// Funcao que aloca memoria para um TIPO_NO
tipo_no_lst *aloca_no(int vl) {
    tipo_no_lst *novo_no;
    novo_no = (tipo_no_lst*) malloc (sizeof(tipo_no_lst));
    novo_no -> valor = vl;
    novo_no -> prox = NULL;
    return novo_no;
}

// Funcao que insere no inicio da lista
void insereInicio(tipo_no_lst **lst, int valor) {
    tipo_no_lst *novo_no;
    novo_no = aloca_no(valor);
    // o ponteiro prox que acabei de alocar vai apontar para o mesmo endereco que a lista
    novo_no -> prox = (*lst);
    (*lst) = novo_no; // a lista agora aponta para o novo noh
}

// Funcao que insere no fim da lista
void insereFim(tipo_no_lst **lst, int valor) {
    tipo_no_lst *novo_no;
    novo_no = aloca_no(valor);

    if ( (*lst) == NULL ) {
        (*lst) = novo_no;
    } else {
        tipo_no_lst *aux; // auxiliar para percorrer a lista e nao perder o ponteiro
        aux = (*lst); // auxiliar recebe o endereco da lista
        while (aux -> prox != NULL) { // enquanto o proximo noh nao for nulo
            aux = aux -> prox; // auxiliar recebe o endereco do proximo noh
        }
        aux -> prox = novo_no; // o proximo noh do auxiliar recebe o novo noh
    }

}

// Funcao que remove o primeiro noh da lista
int removeInicio(tipo_no_lst **lst) {
    tipo_no_lst *aux;
    int vl;

    if ( (*lst) != NULL ) {
        aux = (*lst); // auxiliar recebe o endereco da lista (primeiro noh)
        vl = (*lst) -> valor; // valor a ser removido
        (*lst) = (*lst) -> prox; // lista recebe o endereco do proximo noh 
        free(aux); // libera a memoria do noh removido
        return vl; // retorna o valor removido
    } else {
        return -1; // lista vazia
    }
}

// Funcao que remove o ultimo noh da lista
int removeFim(tipo_no_lst ** lst) {
    // aqui usamos um segundo auxiliar para guardar o valor anterior ao ultimo noh e nao perder o ponteiro por causa da liberacao de memoria
    tipo_no_lst *aux, *aux2; 
    int vl;

    if ( (*lst) != NULL ) {
        aux = (*lst);
        while (aux -> prox != NULL) { // enquanto o proximo noh nao for nulo
            aux2 = aux;
            aux = aux -> prox; // auxiliar 1 recebe o endereco do proximo noh
        }
        vl = aux -> valor; // valor a ser removido
        free(aux);
        // depois da liberacao de memoria o auxiliar 2 (sentinela) se torna o ultimo no
        aux2 -> prox = NULL; // o proximo noh do auxiliar 2 (sentinela) recebe nulo
        return vl;
    } else {
        return -1;
    }
}

// Funcao que insere posicao na lista
void inserePosicao(tipo_no_lst **lst, int vl, int pos) {
    tipo_no_lst *novo_no, *aux, *aux2;
    int contador;
    if (pos == 0) {
        insereInicio(lst, vl);
    } else {
        aux = (*lst);
        contador = 0;
        while( (aux != NULL) && (contador < pos)) {
            aux2 = aux; // sentinela
            aux = aux -> prox; // auxiliar 1 recebe o endereco do proximo noh
            contador++; // incrementa o contador para percorrer a lista ate a posicao desejada
        }
        if ((aux != NULL) && (contador == pos)) { // se a posicao for valida
            novo_no = aloca_no(vl);
            novo_no -> prox = aux;
            aux2 -> prox = novo_no;
        } else if ( (aux == NULL) && (contador == pos)) { // se a posicao for a ultima
            novo_no = aloca_no(vl);
            aux2 -> prox = novo_no;
        } else {
            printf("[ERRO] Posicao invalida para insercao de valor na lista.\n");
        }
    }
}

int removePosicao(tipo_no_lst **lst, int pos) {
    tipo_no_lst *aux, *aux2;
    int contador, vl;

    if ((*lst) != NULL) {
        if (pos == 0) {
            return removeInicio(lst);
        } else {
            aux = (*lst);
            contador = 0;
            while ( (aux != NULL) && (contador < pos) ) { // enquanto o proximo noh nao for nulo e o contador for menor que a posicao
                aux2 = aux; // sentinela recebe o endereco do noh anterior
                aux = aux -> prox; // auxiliar 1 recebe o endereco do proximo noh
                contador++;
            }
            if (aux != NULL) {
                vl = aux -> valor; // valor a ser removido
                aux2 -> prox = aux -> prox; // o proximo noh do auxiliar 2 (sentinela) recebe o proximo noh do auxiliar 1
                free(aux); // libera a memoria do noh removido
                return vl; // retorna o valor removido
            } else {
                printf("[ERRO] posicao eh invalida para remocao!\n");
            }
        }
    } else {
        printf("[ERRO] Lista vazia!\n");
        return -1;
    }

}

// Funcao para imprimir a lista
void imprimeLista(tipo_no_lst *lst) {
    printf("LISTA: [ ");
    while (lst != NULL) {
        printf("%d ", lst -> valor);
        lst = lst -> prox;
    }
    printf("]\n");
}