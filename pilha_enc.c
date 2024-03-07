/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discentes: Mariana Sanchez Pedroni
 * 
 * Meu PROGRAMA - Implementacao da estrutura de PILHA ENCADEADA
*/

#include "pilha_enc.h"

/**
 * @brief Funcao que empilha novo valor, considerando o topo na esquerda do encadeamento
 * 
 * @param pl - ponteiro para o topo da pilha
 * @param valor - valor a ser inserido na pilha
 * 
*/
void empilha(tipo_no **pl, int valor){
    tipo_no *novo_no;
    novo_no = aloca_no(valor);

    if (novo_no != NULL){ // se alocou memoria
        novo_no -> prox = (*pl); // o proximo do novo noh aponta para o topo
        (*pl) = novo_no; // a pilha aponta para o novo noh
    }
}

/**
 * @brief Funcao auxiliar que aloca um novo no na memoria, iniciliaza os dados e retorna o endereco de memoria alocado
 * 
 * @param valor - valor a ser inserido na pilha
 * @return tipo_no* - endereco do no inserido
*/
tipo_no *aloca_no(int valor){
    tipo_no *novo_no;
    novo_no = (tipo_no *) malloc(sizeof(tipo_no));
    if (novo_no != NULL){ // se alocou memoria
        novo_no -> valor = valor; // inicializa o valor do noh
        novo_no -> prox = NULL; // inicializa o proximo do noh
        return novo_no; // retorna o endereco do noh alocado
    }
    return NULL;
}

/**
 * @brief Funcao que desempilha o valor do topo da pilha
 * 
 * @param pl - ponteiro para o topo da pilha
 * @return int - valor desempilhado ou -1 no caso da falha
*/
int desempilha (tipo_no** pl){
    int valor;
    tipo_no *aux;
    if ((*pl) == NULL){
        printf ("[ERRO] Pilha vazia.\n");
        return -1;
    } else {
        valor = (*pl) -> valor; // guarda o valor do topo
        aux = (*pl); // guarda o endereco do topo
        (*pl) = (*pl) -> prox; // topo recebe o endereco do proximo noh
        free(aux); // libera a memoria do noh removido
        return valor; // retorna o valor removido do topo
    }
}

/**
 * @brief Funcao que imprime pilha encadeada (para debug)
 * 
 * @param pl - ponteiro para o topo da pilha
*/
void imprime_pilha (tipo_no *pl){
    printf("PILHA:\n\tTOPO->");
    while (pl != NULL){
        printf("[%d]->", pl -> valor);
        pl = pl -> prox;
    }
    printf("NULL\n");
}