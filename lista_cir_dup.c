/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * Meu PROGRAMA - Implementacao da estrutura de LISTA CIRCULAR ENCADEADA
 * 
***/

#include "lista_cir_dup.h"

/**
 * @brief Funcao que aloca um novo no na memoria, iniciliaza os dados e retorna o endereco de memoria alocado
 * 
 * @param vl valor a ser inserido na lista
 * 
 * @return tipo_noh* - endereco do no inserido
 */
// Funcao que aloca memoria para um TIPO_NO
tipo_no_circ_dup *aloca_no_cir_dup(int valor) {
    tipo_no_circ_dup *novo_no;
    novo_no = (tipo_no_circ_dup *) malloc(sizeof(tipo_no_circ_dup));
    novo_no -> valor = valor;
    novo_no -> prox = NULL;
    return novo_no;
}

/**
 * @brief Funcao que insere um novo noh no inicio da lista
 * 
 * @param lst endereco do ponteiro para o inicio da lista
 * @param valor valor a ser inserido
*/
void insereInicioLstCirDup(tipo_no_circ_dup **lst, int valor) {
    tipo_no_circ_dup *novo_no;
    novo_no = aloca_no_cir_dup(valor);

    if (novo_no != NULL) {
        if ((*lst) == NULL) {
            novo_no -> prox = novo_no;
            novo_no -> ant = novo_no;
            (*lst) = novo_no;
        } else {
            novo_no -> prox = (*lst);
            novo_no -> ant = (*lst) -> ant;
            (*lst) -> ant -> prox = novo_no;
            (*lst) -> ant = novo_no;
            (*lst) = novo_no;
        }
    }
}

/**
 * @brief Funcao que insere um novo noh no fim da lista
 * 
 * @param lst endereco do ponteiro para o inicio da lista
 * @param valor valor a ser inserido
*/
void insereFimLstCirDup(tipo_no_circ_dup **lst, int valor) {
    tipo_no_circ_dup *novo_no;
    novo_no = aloca_no_cir_dup(valor);

    if (novo_no != NULL) {
        if ((*lst) == NULL) {
            novo_no -> prox = novo_no;
            novo_no -> ant = novo_no;
            (*lst) = novo_no;
        } else {
            novo_no -> prox = (*lst);
            novo_no -> ant = (*lst) -> ant;
            (*lst) -> ant -> prox = novo_no;
            (*lst) -> ant = novo_no;
        }
    }
}
/**
 * @brief Funcao que remove o noh do inicio da lista
 * 
 * @param lst endereco do ponteiro para o inicio da lista
 * 
 * @return int - valor removido
*/
int removeInicioLstCirDup(tipo_no_circ_dup **lst) {
    tipo_no_circ_dup *aux;
    int valor;

    if ((*lst) != NULL) {
        if ((*lst) -> prox == (*lst)) {
            valor = (*lst) -> valor;
            free(*lst);
            (*lst) = NULL;
            return valor;
        } else {
            aux = (*lst);
            valor = aux -> valor;
            (*lst) = (*lst) -> prox;
            (*lst) -> ant = aux -> ant;
            aux -> ant -> prox = (*lst);
            free(aux);
            return valor;
        }
    }
}
/**
 * @brief Funcao que remove o noh do fim da lista
 * 
 * @param lst endereco do ponteiro para o inicio da lista
 * 
 * @return int - valor removido
*/
int removeFimLstCirDup(tipo_no_circ_dup **lst){
        tipo_no_circ_dup *aux;
    int valor;

    if ((*lst) != NULL) {
        if ((*lst) -> prox == (*lst)) {
            valor = (*lst) -> valor;
            free(*lst);
            (*lst) = NULL;
            return valor;
        } else {
            aux = (*lst) -> ant;
            valor = aux -> valor;
            aux -> ant -> prox = (*lst);
            (*lst) -> ant = aux -> ant;
            free (aux);
            return valor;
        }
    }
    return -1;
}
/**
 * @brief Funcao que imprime a lista
 * 
 * @param lst endereco do ponteiro para o inicio da lista
*/
void imprimeLstCirDup (tipo_no_circ_dup *lst) {
    tipo_no_circ_dup *aux;
    printf ("Lista CIRCULAR DUPLAMENTE ENCADEADA:\nLista -->");
    aux = lst;
    //trata o caso especial de possuir um unico noh
    if (aux -> prox == aux) {
        printf ("(lista)<-[%d]->(lista)\n", aux -> valor);
    } else {
        //imprime o primeiro noh separado
        printf ("<-[%d]->", aux -> valor);
        aux = aux -> prox;
        //imprime os demais nohs
        while (aux != lst) {
            printf ("<-[%d]->", aux -> valor);
            aux = aux -> prox;
        }
        printf ("\n");
    }
}
