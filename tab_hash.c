/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * Meu PROGRAMA - Implementacao de uma tabela HASH
*/

//implementa tabela hash
#include "tab_hash.h"

/**
 * @brief Função que inicializa a tabela HASH
 * 
 * @param tbh referencia para a tabela
 */
void inicializaTabHash(tipo_tab_hash *tbh){
    int i;
    for (i = 0; i < TAM_HASH; i++){
        tbh->tabela_hash[i] = NULL;
    }
}
/**
 * @brief Funcao hash, gera um indice a partir de uma chave
 * 
 * @param chave chave identificadore do dado
 * @return int indice dado na tabela HASH
*/
int funcaoHash(int chave){
    return chave%TAM_HASH;
}
/**
 * @brief Funcao que insere um novo valor na tabela HASH
 * 
 * @param tbh referencia para a tabela
 * @param chave chave identificadora do dado
 * @param valor dado a ser armazenado
*/
void insereTabHash(tipo_tab_hash *tbh, int chave, char valor){
    int pos;
    tipo_no_hash *novo_no;

    //verifica se nao existe a chave na tabela
    if (buscaTabHash(tbh, chave) == NULL){
        pos = funcaoHash(chave);
        novo_no = alocaNoHash(chave, valor);

        if (tbh -> tabela_hash[pos] == NULL){
            tbh -> tabela_hash[pos] = novo_no;
        } else { // insere no inicio da lista
            novo_no -> prox = tbh -> tabela_hash[pos];
            tbh -> tabela_hash[pos] = novo_no;
        }
    }
}
/**
 * @brief Funcao que remove um valor da tabela HASH
 * 
 * @param tbh referencia para a tabela
 * @param chave chave identificadora do dado
 * @return char retorna o dado removido
*/
char removeTabHash (tipo_tab_hash *tbh, int chave){
    tipo_no_hash *aux, *ant;
    int pos;
    char dado;

    //verifica se o dado esta na tabela hash
    aux = buscaTabHash(tbh, chave);
    if (aux != NULL){
        pos = funcaoHash(chave);
        // verifica se ha apenas 1 noh
        if (tbh->tabela_hash[pos] == aux){
            tbh->tabela_hash[pos] = aux->prox;
        } else {
            ant = tbh->tabela_hash[pos];
            while (ant->prox != aux){
                ant = ant->prox;
            }
            ant->prox = aux->prox; // ant->prox = ant -> prox -> prox;
        }
        dado = aux->valor;
        free (aux);
        return dado;
    }
    return '\0'; // em caso de nao existir a chave procurada
}
/**
 * @brief Funcao que aloca um novo noh da tabela Hash
 * 
 * @param chave chave identificadora do dado
 * @param dado dado a ser armazenado
 * @return tipo_no_hash* referencia para o novo noh
 */
tipo_no_hash *alocaNoHash (int chave, char dado){
    tipo_no_hash *novo_no;
    novo_no = (tipo_no_hash *) malloc(sizeof(tipo_no_hash));
    novo_no->chave = chave;
    novo_no->valor = dado;
    novo_no->prox = NULL;
    return novo_no;
}
/**
 * @brief funcao que busca por uma chave/dado na tabela HASH
 * 
 * @param tbh referencia para a tabela
 * @param chave chave identificadora do dado
 * @return tipo_no_hash referencia para o noh encontrado
*/
tipo_no_hash *buscaTabHash(tipo_tab_hash *tbh, int chave){
    int pos;
    tipo_no_hash *aux;
    pos = funcaoHash(chave);
    aux = tbh->tabela_hash[pos];

    if (tbh->tabela_hash[pos] == NULL){
        return NULL;
    } else {
        aux = tbh->tabela_hash[pos];
        while (aux != NULL){
            if (aux->chave == chave){
                return aux;
            } else {
                aux = aux->prox;
            }
        }
    }
}

/**
 * @brief funcao que imprime a tabela HASH
 * 
 * @param tbh referencia para a tabela
 */
void imprimeTabHash(tipo_tab_hash *tbh){
    int i;
    tipo_no_hash *aux;

    printf("Tabela Hash:\n");
    for (i=0; i<TAM_HASH; i++){
        printf("[%d] -> ", i);
        if (tbh->tabela_hash[i] == NULL){
            printf("NULL\n");
        } else {
            aux = tbh->tabela_hash[i];
            while (aux != NULL){
                printf ("[%d | %c] -> ", aux->chave, aux->valor);
                aux = aux->prox;
            }
            printf("NULL\n");
        }
    }
}
