/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discente: Mariana Sanchez Pedroni
 * 
 * Meu PROGRAMA - Implementacao de uma estrutura HEAP MAXIMO
*/

#include "heap_max.h"

/**
 * @brief Funcao que inicializa o heap
 * 
 * @param hp Referencia para o heap
*/
void inicializaHeap (tipo_heap *hp){
    hp->qtd = 0;
}
/**
 * @brief Funcao que calcula o indice do filho esquerdo
 * 
 * @param pos Posicao do pai
 * @return int Indice do filho esquerdo
*/
int filhoEsqHeap (int pos){
    return 2*pos + 1;
}

/**
 * @brief Funcao que calcula o indice do filho direito
 * 
 * @param pos Posicao do pai
 * @return int Indice do filho direito
*/
int filhoDirHeap (int pos){
    return 2*pos + 2;
}

/**
 * @brief Funcao que calcula o indice do pai
 * 
 * @param pos Posicao do filho
 * @return int Indice do pai
*/
int paiHeap (int pos){
    return (int) (pos-1)/2;
}
/**
 * @brief Funcao que sobe com o dado, a partir de sua posicao, ate a raiz do heap
 * 
 * @param hp Referencia para o heap
 * @param pos Posicao a ser verificado
*/
void sobeHeap(tipo_heap *hp, int pos){
    tipo_dado_heap aux;
    if (pos > 0){ //verifica senao eh raiz
    //verifica se a prioridade do pai eh menor
        if (hp->heap[pos].prioridade > hp->heap[paiHeap(pos)].prioridade){
            //faz a troca
            aux = hp->heap[pos];
            hp->heap[pos] = hp->heap[paiHeap(pos)];
            hp->heap[paiHeap(pos)] = aux;
            //faz chamada recursiva entregando nova posicao do noh
            sobeHeap(hp, paiHeap(pos));
        }

    }
}
/**
 * @brief Funcao que desce com o dado, por meio da sua chave/prioridade ate a posicao adequada no Heap
 * 
 * @param hp Referencia para o heap
 * @param pos Posicao a ser verificado
*/
void desceHeap(tipo_heap *hp, int pos){
    int pos_filho;
    tipo_dado_heap aux;
    //verifica se ha ao menos um dos filhos na respeciva pos
    if ((filhoEsqHeap(pos) < hp-> qtd) || (filhoDirHeap(pos) < hp-> qtd )){
        //verifica se tem dois filhos
        if (filhoDirHeap(pos) < hp -> qtd){
            //identifica a maior prioridade entre os filhos
            //se o esquerdo eh maior
            if (hp -> heap[filhoEsqHeap(pos)].prioridade > hp -> heap[filhoDirHeap(pos)].prioridade){
                pos_filho = filhoEsqHeap(pos);
            } else {
                pos_filho = filhoDirHeap(pos);
            }
        //verifica se tem apenas filho esquerdo
        } else if (filhoEsqHeap(pos) < hp -> qtd){
            pos_filho = filhoEsqHeap(pos);
        }    
        //verifica se o noh atual tem prioridade mais baixa que o maior filho
        if (hp -> heap[pos].prioridade < hp -> heap[pos_filho].prioridade){
            aux = hp -> heap[pos];
            hp -> heap[pos] = hp -> heap[pos_filho];
            hp -> heap[pos_filho] = aux;
            desceHeap(hp, pos_filho);
        }
    }
}

/**
 * @brief Funcao que insere um dado no heap
 * 
 * @param hp Referencia para o heap
 * @param prioridade Prioridade do dado
 * @param dado Dado a ser inserido
 * 
*/
void insereHeap (tipo_heap *hp, int prioridade, char dado){
    if (hp->qtd < TAM_HEAP){
        hp->heap[hp->qtd].prioridade = prioridade;
        hp->heap[hp->qtd].dado = dado;
        hp->qtd++;
        sobeHeap(hp, hp->qtd-1);
    }
}
/**
 * @brief Funcao que remove o valor da raiz do Heap
 * 
 * @param hp Referencia para o heap
 * @return tipo_dado_heap Dado removido
*/
tipo_dado_heap removeHeap (tipo_heap *hp){
    tipo_dado_heap aux;
    if (hp->qtd > 0){
        aux = hp->heap[0];
        hp -> heap[0] = hp->heap[--hp->qtd]; //copia o ultimo dado para a raiz
        desceHeap(hp, 0);
    }
    return aux;
}
// eu implementei essa funcao de heapsort
/**
 * @brief Função que realiza o HeapSort
 * 
 * @param hp Referência para o heap
 * @param qtdElementos Quantidade de elementos no heap
*/
void heapSort (tipo_heap *hp, int qtdElementos) {
    tipo_heap heapOrdenado;
    inicializaHeap(&heapOrdenado);

    // Passo 1: Construir o heap máximo
    for (int i = 0; i < qtdElementos; i++) {
        insereHeap(&heapOrdenado, hp->heap[i].prioridade, hp->heap[i].dado);
    }
    
    // Passo 2: Ordenar o array
    for (int i = 0; i < qtdElementos; i++) {
        tipo_dado_heap max = removeHeap(&heapOrdenado);
        hp->heap[i] = max;
    }
}

/**
 * @brief Funcao que imprime o heap
 * 
 * @param hp Referencia para o heap
*/
void imprimeHeap (tipo_heap *hp){
    int i;
    printf ("HEAP:\nQTD Dados = %d\nHEAP-> [", hp->qtd);

    for (i=0; i<hp->qtd; i++){
        printf("(%d | %c)", hp->heap[i].prioridade, hp->heap[i].dado);
    }
    printf("]\n");
}