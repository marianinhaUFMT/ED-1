/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discentes: Mariana Sanchez Pedroni
 * 
 * Meu PROGRAMA - Implementacao da estrutura de FILA ENCADEADA
*/

#include "fila_enc.h"

/***
 * @brief Funcao que aloca um novo no na memoria, iniciliaza os dados e retorna o endereco de memoria alocado
 * 
 * @param vl valor a ser inserido na fila
 * 
 * @return tipo_no* - endereco do no inserido
 */
tipo_no *aloca_no(int vl){
    tipo_no *novo_no;
    novo_no = (tipo_no *) malloc(sizeof(tipo_no));
    if (novo_no != NULL){
        novo_no -> valor = vl;
        novo_no -> prox = NULL;
    }
    return novo_no;
}
/**
 * @brief Funcao que insere um novo elemento na fila
 * 
 * @param fila - ponteiro para o primeiro no da fila
 * 
 * @param vl - valor a ser inserido na fila
 * 
*/
void insereFilaEnc (tipo_no **fila, int vl){
    //verifica se a fila esta vazia
    if ((*fila) == NULL){
        (*fila) = aloca_no(vl); //aloca novo no e atualiza o ponteiro da fila
    } else {
        tipo_no *novo_no, *aux;
        novo_no = aloca_no(vl);
        if (novo_no != NULL){
            aux = (*fila);
            while (aux -> prox != NULL){
                aux = aux -> prox;
            }
            aux -> prox = novo_no;
        }
    }
}
/**
 * @brief Funcao que remove o primeiro elemento da fila
 * 
 * @param fila - ponteiro para o primeiro no da fila
 * 
 * @return int - valor removido da estrutura
*/
int removeFilaEnc (tipo_no **fila){
    int valor;
    tipo_no *aux;

    if ((*fila) != NULL){
        valor = (*fila) -> valor;
        aux = (*fila);
        (*fila) = (*fila) -> prox;
        free(aux);
        return valor;
    }
    return -1; // em caso de erro
}

/**
 * @brief Funcao que imprime os valores da fila encadeada
 * 
 * @param fila - ponteiro para o primeiro no da fila
*/
void imprimeFilaEnc (tipo_no *fila){
    printf ("FILA:\n\t|\n\t->");
    while (fila != NULL){
        printf ("[%d]->", fila -> valor);
        fila = fila -> prox;
    }
    printf ("[NULL]\n");
}

int qtdValores (tipo_no *fila){
    int qtd = 0;
    while (fila != NULL){
        qtd++;
        fila = fila -> prox;
    }
    return qtd;
}