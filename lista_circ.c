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
 */

#include "lista_circ.h"

/**
 * @brief Funcao que aloca um novo no na memoria, iniciliaza os dados e retorna o endereco de memoria alocado
 * 
 * @param vl valor a ser inserido na lista
 * 
 * @return tipo_noh* - endereco do no inserido
 */
tipo_noh_cir *aloca_noh_cir(int vl){
    tipo_noh_cir *novo_no;
    novo_no = (tipo_noh_cir *) malloc(sizeof(tipo_noh_cir));
    if (novo_no != NULL){
        novo_no -> valor = vl;
        novo_no -> prox = NULL;
        return novo_no;
    }
    return NULL;
}

/**
 * @brief Funcao que insere um novo elemento no fim da lista
 * 
 * @param lst - ponteiro para o primeiro no da lista
 * 
 * @param vl - valor a ser inserido na lista
 * 
 */
void insereFimCir(tipo_noh_cir **lst, int vl){
    if ((*lst) == NULL){ // caso a lista esteja vazia
        ((*lst) = aloca_noh_cir(vl));
        (*lst) -> prox = (*lst);
    } else {
        tipo_noh_cir *novo_no, *aux;
        novo_no = aloca_noh_cir(vl);
        aux = (*lst);
        while (aux -> prox != (*lst)){
            aux = aux -> prox;
        }
        aux -> prox = novo_no;
        novo_no -> prox = (*lst);
    }
}

/**
 * @brief Funcao que insere um novo elemento no inicio da lista
 * 
 * @param lst - ponteiro para o primeiro no da lista
 * 
 * @param vl - valor a ser inserido na lista
 * 
 */
void insereInicioCir(tipo_noh_cir **lst, int vl){
    tipo_noh_cir *novo_no, *aux;

    novo_no = aloca_noh_cir(vl);
    novo_no -> prox = (*lst);

    aux = (*lst);
    while (aux -> prox != (*lst)){
        aux = aux -> prox;
    }
    aux -> prox = novo_no;
    (*lst) = novo_no;
}
/**
 * @brief Funcao que remove do inicio da lsita circular
 * 
 * @param lst - ponteiro para o primeiro no da lista
 * 
 * @return int - valor removido
*/
int removeInicioCir(tipo_noh_cir **lst){
    int valor;
    tipo_noh_cir *aux;
    if ((*lst) != NULL){
        if ((*lst) -> prox == (*lst)){
            valor = (*lst) -> valor;
            free((*lst));
            (*lst) = NULL;
            return valor;
        } else {
            valor = (*lst) -> valor;
            aux = (*lst);
            while (aux -> prox != (*lst)){
                aux = aux -> prox;
            }
            aux -> prox = (*lst) -> prox; // ou: aux -> prox = aux -> prox -> prox;
            aux = (*lst);
            (*lst) = (*lst) -> prox;
            free(aux);
            return valor;
        }
    }
    return -1; // caso de erro (lista vazia)
}
/**
 * @brief Funcao que remove do fim da lsita circular
 * 
 * @param lst - ponteiro para o primeiro no da lista
 * 
 * @return int - valor removido
*/
int removeFimCir(tipo_noh_cir **lst){
    int valor;
    tipo_noh_cir *aux, *aux_ant;
    if ((*lst) != NULL){
        if ((*lst) -> prox == (*lst)){ // caso de um unico noh
            valor = (*lst) -> valor;
            free((*lst));
            (*lst) = NULL;
            return valor;
        } else { // caso de mais de um valor
            aux = (*lst);
            while (aux -> prox != (*lst)){
                aux_ant = aux;
                aux = aux -> prox;
            }
            valor = aux -> valor;
            aux_ant -> prox = aux -> prox;
            free(aux);
            return valor;
        }
    }
    return -1; // caso de erro (lista vazia)
}

/**
 * @brief Funcao que imprime os elementos da lista
 * 
 * @param lst - ponteiro para o primeiro no da lista
 * 
*/
void imprimeCir(tipo_noh_cir *lst){
    tipo_noh_cir *aux;
    printf ("Lista Circular:\n\t->");
    //imprime o primeiro noh
    if (lst != NULL){
        printf("[%d]->", lst -> valor);
        aux = lst -> prox;
    } else {
            printf ("[NULO]\n");
    }
    //imprime os demais nohs
    while (aux != lst){ 
        printf("[%d]->", aux -> valor);
        aux = aux -> prox;
    }
    printf ("... -> (lista)\n");
}