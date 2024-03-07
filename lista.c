#include "lista.h"

/**
 * @brief Funcao que insere o novo valor em uma posição específica da lista.
 * 
 * @param tipo_lista *lst - Estrutura da Lista 
 * @param int valor - Valor a ser inserido
 * @param int pos - Posição para inserir o valor
 * @return int - verdadeiro se insercao com sucesso, falso caso contrario
 */
int insere_pos_lista(tipo_lista *lst, int valor, int pos){
    int i;
    if(lst->contador < N){
        i = lst -> contador;
        while (i > pos){
            lst->lista[i] = lst->lista[i-1];
            i--;
        }
        lst -> lista[pos] = valor;
        lst->contador++;
        return 1;
    } else {
        return 0;
    }
}

/**
 * @brief Funcao que insere no inicio da lista.
 * 
 * @param tipo_lista *lista - Estrutura da lista
 * @param int valor - valor a ser inserido na lista
 * 
 * @return int - verdadeiro se insercao com sucesso, falso caso contrário
 */
int insere_inicio_lista(tipo_lista *lst, int valor) {
    return insere_pos_lista (lst, valor, 0);
}

/**
 * @brief Funcao que insere o novo valor no fim da lista.
 * 
 * @param tipo_lista *lst - Estrutura da Lista 
 * @param int valor - Valor a ser inserido
 * @return int - verdadeiro se insercao com sucesso, falso caso contrario
 */
int insere_fim_lista(tipo_lista *lst, int valor) {
    return insere_pos_lista (lst, valor, lst->contador);
}

/**
 * @brief Função que remove o valor no início da lista.
 * 
 * @param tipo_lista *lst - Estrutura da Lista 
 * @return int - verdadeiro se remoção com sucesso, falso caso contrario
 * @return int - valor retirado do início da lista
 */
int remove_inicio_lista(tipo_lista *lst){
    return remove_pos_lista(lst, 0);
}


/**
 * @brief Função que remove o valor do fim da lista
 * 
 * @param tipo_lista *lst - Estrutura da lista
 * @return int - retorna 0, caso não seja possível 
 * @return int - valor retirado do fim da lista
*/
int remove_fim_lista(tipo_lista *lst){
    return remove_pos_lista(lst, lst->contador-1);
}

/**
 * @brief Função que remove valor de uma posição específica da lista
 * 
 * @param tipo_lista *lst - Estrutura da lista
 * @param int pos - Posição para remover o valor
 * @return int - valor retirado da determinada posição na fila ou -1 no caso de erro
*/
int remove_pos_lista(tipo_lista *lst, int pos){
    int valor, i;
    if((pos >= 0) && (pos < lst->contador)){
        valor = lst->lista[pos];
        for(i=pos; i<lst->contador - 1; i++){
            lst->lista[i] = lst->lista[i+1];
        }
        lst->contador--;
        return valor;
    } else {
        return -1;
    }
}

/**
 * @brief Função que remove valor específico da lista
 * 
 * @param tipo_lista *lst - Estrutura da lista
 * @param int V - Valor para remover
 * @return int - retorna 0, caso não seja possível
 * @return int - retorna 1, caso contrário
*/
int remove_valor_lista(tipo_lista *lst, int valor){
    int pos;
    pos = busca_valor_lista(*lst, valor);
    if (pos != 1){
        return remove_pos_lista(lst, pos);
    }    
    return -1;
}

/**
 * @brief Função que busca pelo valor de uma posição específica da lista
 * 
 * @param tipo_lista lst - Estrutura da lista
 * @param int pos - posição para buscar valor da lista
 * @return int - retorna 0, caso não seja possível
 * @return int - retorna valor da posição  
*/
int busca_pos_lista(tipo_lista lst, int pos){
    if ((pos >= 0) && (pos < lst.contador)){
        return lst.lista[pos];
    } else {
        return -1;
    }
}

/**
 * @brief Função que busca pelo valor específico na lista
 * 
 * @param tipo_lista lst - Estrutura da lista
 * @param int V - valor para buscar na lista
 * @return int - retorna -1, caso não seja possível
 * @return int - retorna valor encontrado
*/
int busca_valor_lista(tipo_lista lst, int valor){
    int i;
    for (i = 0; i < lst.contador; i++){
        if (lst.lista[i] == valor){
            return i;
        }
    }
    return -1;
}

/***
 * @brief funcao que busca o maior valor na lista
 * 
 * @param tipo_lista *lista - estrutura da lista
 * 
 * @return int - maior valor da lista
*/
int busca_maior_lista (tipo_lista lst){
    int i, maior;
    if (lst.contador > 0){
        maior = lst.lista[0];
        for (i = 1; i < lst.contador; i++){
            if (lst.lista[i] > maior){
                maior = lst.lista[i];
            }
        }
        return maior;
    } else {
        return -1;
    }
}
/***
 * @brief funcao que busca o menor valor na lista
 * 
 * @param tipo_lista *lista - estrutura da lista
 * 
 * @return int - menor valor da lista
*/
int busca_menor_lista (tipo_lista lst){
    int i, menor;
    if (lst.contador > 0){
        menor = lst.lista[0];
        for (i = 1; i < lst.contador; i++){
            if (lst.lista[i] < menor){
                menor = lst.lista[i];
            }
        }
        return menor;
    } else {
        return -1;
    }
}

/**
 * @brief Procedimento que imprime a lista.
 * 
 * @param tipo_lista lst - Estrutura da lista.
 */
void imprime_lista(tipo_lista lst) {
    int i;
    printf("Quantidade de elementos da lista = %d\n", lst.contador);
    printf("Lista: [ ");
    for (i=0; i<lst.contador; i++)
        printf("%d ", lst.lista[i]);
    printf("]\n");
    printf ("Maior valor da lista = %d\n", busca_maior_lista(lst));
    printf ("Menor valor da lista = %d\n", busca_menor_lista(lst));
}