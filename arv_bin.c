/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * Meu PROGRAMA - Implementacao de uma estrutura de ARVORE BINARIA
*/

#include "arv_bin.h"


/**
 * @brief Funcao que aloca um no da arvore
 * 
 * @param valor valor a ser inserido
 * @return tipo_no_arvore* 
 */
tipo_no_arvore *alocaNoArv(int valor) {
    tipo_no_arvore *novo_no;
    novo_no = (tipo_no_arvore *) malloc(sizeof(tipo_no_arvore));
    novo_no->dado = valor;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    return novo_no;
}
/**
 * @brief Funcao que insere um no na arvore
 * 
 * @param arv_bin referencia para arvore
 * @param valor valor a ser inserido
 */
void insereArvBin(tipo_no_arvore **arv_bin, int valor) {
    if ((*arv_bin) != NULL) { // criterio de parada, encontrou posicao para inserir
        if (valor < (*arv_bin)-> dado){
            insereArvBin (&(*arv_bin)-> esq, valor); // recursao para a esquerda
        } else {
            insereArvBin (&(*arv_bin)-> dir, valor); // recursao para a direita
        }
    } else { // arvore vazia
        (*arv_bin) = alocaNoArv (valor);
    }
}

/**
 * @brief Funcao que remove um no da arvore
 * 
 * @param arv_bin referencia para arvore
 * @param valor valor a ser removido
*/
void removeArvBin(tipo_no_arvore **arv_bin, int valor) {
    tipo_no_arvore *aux;
    //encontra o noh a ser removido
    if (*arv_bin != NULL){
        if ((*arv_bin)-> dado != valor){ // se diferente, continua a busca
            if (valor < (*arv_bin)-> dado){ // se valor eh menor, desce pela esquerda
                removeArvBin(&(*arv_bin)-> esq, valor);
            } else { // se valor eh maior, desce pela direita
                removeArvBin(&(*arv_bin)-> dir, valor);
            }
        } else { // valor eh igual, foi encontrado
            //verifica caso 1: noh eh folha
            if ((*arv_bin) -> esq == NULL && (*arv_bin) -> dir == NULL){
                //desaloca noh da memoria
                free(*arv_bin);
                //atualiza ponteiro do pai para ele com nulo
                (*arv_bin) = NULL;
            //verifica caso 2: noh tem um filho unico
            //TODO: fazer uma funcao que realiza esta verificacao
            } else if ((*arv_bin) -> esq == NULL && (*arv_bin) -> dir != NULL || (*arv_bin) -> esq != NULL && (*arv_bin) -> dir == NULL){
                aux = (*arv_bin);
                //verifica qual eh o filho existente
                if ((*arv_bin) -> esq != NULL){
                    (*arv_bin) = aux -> esq; // atualiza o ponteiro do pai para o filho unico
                } else if ((*arv_bin) -> dir != NULL){
                    (*arv_bin) = aux -> dir; // atualiza o ponteiro do pai para o filho unico
                }
                //desaloca noh da memoria
                free(aux);
            //verifica caso 3: noh tem dois filhos
            } else if ( ((*arv_bin) -> esq != NULL) && ((*arv_bin) -> dir != NULL) ){
                int novo_valor;
                //encontra o maior valor da subarvore esquerda
                novo_valor = maiorValorArvBin((*arv_bin) -> esq);
                //substitui o valor do noh que sera removido pelo maior valor da subarvore esquerda
                (*arv_bin) -> dado = novo_valor;
                //faz a chamada recursiva de remocao no ramo esquerdo com o valor identificado
                removeArvBin(&(*arv_bin) -> esq, novo_valor);
            }
        }    
    }
}

/**
 * @brief Funcao que imprime a arvore usando o percurso em Pre Ordem
 * 
 * @param arv_bin referencia para arvore
 * 
*/
void percursoPreOrdem(tipo_no_arvore *arv_bin) {
    if (arv_bin != NULL) {
        printf("%d ", arv_bin->dado);
        percursoPreOrdem(arv_bin->esq);
        percursoPreOrdem(arv_bin->dir);
    }   
}

/**
 * @brief Funcao que imprime a arvore usando o percurso em Ordem
 * 
 * @param arv_bin referencia para arvore
 * 
*/
void percursoOrdem(tipo_no_arvore *arv_bin) {
    if (arv_bin != NULL) {
        percursoOrdem(arv_bin->esq);
        printf("%d ", arv_bin->dado);
        percursoOrdem(arv_bin->dir);
    }
}

/**
 * @brief Funcao que imprime a arvore usando o percurso em Pos Ordem
 * 
 * @param arv_bin referencia para arvore
*/
void percursoPosOrdem (tipo_no_arvore *arv_bin){
    if (arv_bin != NULL) {
        percursoPosOrdem(arv_bin->esq);
        percursoPosOrdem(arv_bin->dir);
        printf("%d ", arv_bin->dado);
    }
}

/**
 * @brief Funcao que busca por um valor na arvore binaria e retorna verdadeiro/falso
 * 
 * @param arv_bin referencia para arvore
 * @param valor valor a ser buscado
 * 
 * @return int Verdadeiro (1): encontrado ou Falso (0): nao encontrado
*/
int buscaArvBin(tipo_no_arvore *arv_bin, int valor) {
    if (arv_bin != NULL) {
        if (valor == arv_bin -> dado){
            return 1; //valor encontrado
        }
        if (valor < arv_bin -> dado){
            return buscaArvBin(arv_bin -> esq, valor);
        }
    }
    return 0;
}
/**
 * @brief Funcao que contabiliza a quantidade de nos da arvore
 * 
 * @param arv_bin referencia para arvore
 * 
 * @return int quantidade de nos
*/
int alturaArvBin (tipo_no_arvore *arv_bin) {
    int alt_esq, alt_dir;

    //verifica se o ramo esquerdo tem filho
    if (arv_bin -> esq == NULL){
        alt_esq = 0;
    } else {
        alt_esq = alturaArvBin(arv_bin -> esq) + 1;
    }
    //verfica se o ramo direito tem filho
    if (arv_bin -> dir == NULL){
        alt_dir = 0;
    } else {
        alt_dir = alturaArvBin(arv_bin -> dir) + 1;
    }
    //verifica qual ramo eh maior
    if (alt_esq > alt_dir){
        return alt_esq;
    } else {
        return alt_dir;
    }
}
/**
 * @brief Funcao que imprime a arvore
 * 
 * @param arv_bin
 */
void imprimeNivelArvBin(tipo_no_arvore *arv_bin, int nivel) {
    if (arv_bin != NULL){
        if (nivel == 0){
            printf ("\tNoh: %d\n", arv_bin -> dado);
        } else {
            imprimeNivelArvBin(arv_bin -> esq, nivel - 1);
            imprimeNivelArvBin(arv_bin -> dir, nivel - 1);
        }
    }
}
/**
 * @brief Funcao que identifica o maior valor da arvore
 * 
 * @param arv_bin referencia para arvore
 * @return int maior valor encontrado
*/
int maiorValorArvBin (tipo_no_arvore *arv_bin){
    if (arv_bin != NULL){
        if (arv_bin -> dir == NULL){
            return arv_bin -> dado;
        } else {
            return maiorValorArvBin(arv_bin -> dir);
        }
    }
    return -1;
}
/**
 * @brief Funcao que identifica o menor valor da arvore
 * 
 * @param arv_bin referencia para arvore
 * @return int menor valor encontrado
*/
int menorValorArvBin (tipo_no_arvore *arv_bin){
    if (arv_bin != NULL){
        if (arv_bin -> esq == NULL){
            return arv_bin -> dado;
        } else {
            return menorValorArvBin(arv_bin -> esq);
        }
    }
    return -1;
}

/**
 * @brief Funcao que contabiliza a quantidade de nos da arvore
 * 
 * @param arv_bin referencia para arvore
 * @return int quantidade de nos
*/
int contabilizaNosArvBin(tipo_no_arvore *arv_bin) {
    if (arv_bin != NULL){
        return contabilizaNosArvBin(arv_bin -> esq) + contabilizaNosArvBin(arv_bin -> dir) + 1;
    }
    return 0;
}