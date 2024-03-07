/***
 * UFMT - Universidade Federal de Mato Grosso
 * Campus Universitario do Araguaia
 * Bacharelado em Ciencia da Computacao
 * 
 * Disciplina de ED I
 * Prof. Ivairton
 * Discentes: Mariana Sanchez Pedroni
 * 
 * Meu PROGRAMA - Tipos de ordenacao
*/

#include "lista.h"
#include "ordenacao.h"

/**
 * @brief Funcao que ordena a lst pelo metodo bubble sort (complexidade 0(n^2))
 * 
 * @param lst ponteiro para a lst
 */

void bubbleSort (tipo_lista *lst){
    int flag_troca, i, aux;
    do {
        flag_troca = 0;
        for (i = 0; i < lst -> contador - 1; i++){
            if (lst -> lista[i] > lst -> lista[i+1]){
                aux = lst -> lista[i];
                lst -> lista[i] = lst -> lista[i+1];
                lst -> lista[i+1] = aux;
                flag_troca ++;
            }
        }
    } while (flag_troca != 0);
}

/**
 * @brief Funcao que ordena a lst pelo metodo shell sort (complexidade 0(n^2))
 * 
 * @param lst ponteiro para a estrutura de lst
 */

void shellSort (tipo_lista *lst){
    int salto, i, flag_troca, aux;
    salto = (int) lst -> contador / 2;

    while (salto > 1){
        for (i = 0; (i+salto) < lst -> contador; i++){
            if (lst -> lista[i] > lst -> lista[i+salto]){
                aux = lst -> lista[i];
                lst -> lista[i] = lst -> lista[i+salto];
                lst -> lista[i+salto] = aux;
            }
        }
        salto = (int) salto / 2;
    }
    do {
        flag_troca = 0;
        for (i = 0; i < lst -> contador - 1; i++){
            if (lst -> lista[i] > lst -> lista[i+salto]){
                aux = lst -> lista[i];
                lst -> lista[i] = lst -> lista[i+salto];
                lst -> lista[i+salto] = aux;
                flag_troca ++;
            }
        }
    } while (flag_troca);
}


/**
 * @brief Funcao que ordena a lst pelo metodo insert sort (complexidade 0(n^2))
 * 
 * @param lst ponteiro para a estrutura de lst
 */

void insertSort (tipo_lista *lst){
    int i, pos;
    tipo_lista lst_ordenada;
    lst_ordenada.contador = 0;

    for (i = 0; i < lst -> contador; i++){
        pos = lst_ordenada.contador;
        if (pos == 0){
            insere_fim_lista(&lst_ordenada, lst -> lista[i]);
        } else {
            while ((pos > 0) && (lst_ordenada.lista[pos-1] > lst -> lista[i]))
                pos --;
            insere_pos_lista(&lst_ordenada, lst -> lista[i], pos);
        }
    }
    for (i = 0; i < lst -> contador; i++){
        lst -> lista[i] = lst_ordenada.lista[i];
    }
}

/**
 * @brief Funcao que ordena a lst pelo metodo insert sort versao 2 (complexidade 0(n^2))
 * 
 * @param lst ponteiro para a estrutura de lst
 */

void insertSort_ver2(tipo_lista *lst){
    int i, aux, corte;
    corte = 1;
    while (corte < lst -> contador){
        i = corte;
        while ((i > 0) && (lst -> lista[i] < lst -> lista[i-1])){
            aux = lst -> lista[i];
            lst -> lista[i] = lst -> lista[i-1];
            lst -> lista[i-1] = aux;
            i --;
        }
        corte ++;
    }
}
/**
 * @brief Funcao que ordena a lista pelo metodo merge sort (complexidade 0(n log n))
 * 
 * @param lst ponteiro para a estrutura de lista
 * @param tamanho da lista
 */
//Função de merge
void merge (int vet[], int tamanho){
    int *vet_aux, meio, i , j, idx_aux;

    vet_aux = (int*) malloc(sizeof(int)*tamanho);

    meio = tamanho/2;

    i = 0;
    j = meio;
    idx_aux =0;
    while ((i < meio) && (j < tamanho))
    {
        if (vet[i] < vet[j]){
            vet_aux[idx_aux++]= vet [i++];

        }else{ 
            vet_aux[idx_aux ++]= vet [j++];

        }
    }
    while (i < meio)
    {
        vet_aux[idx_aux++] = vet [i++];
    }
    while (j < tamanho)
    {
        vet_aux[idx_aux++] =vet [j++];
    }

    for (i = 0; i < tamanho; i++){
        vet [i] =  vet_aux[i];
    }
    
    free(vet_aux);
}

void mergeSort(tipo_lista *lst){
    merge_div(lst -> lista, lst -> contador);
}
/**
 * @brief Funcao que ordena a lista pelo metodo merge sort (complexidade 0(n log n))
 * 
 * @param lst ponteiro para a estrutura de lista
 * @param tamanho tamanho da lista
 */
//Usa estratégia recursiva
void merge_div(int vet[], int tamanho) {
    if (tamanho > 1) {
        int meio = tamanho / 2;
        merge_div(vet, meio);
        merge_div(&vet[meio], (tamanho - meio));
        merge(vet, tamanho);
    }
}

/**
 * @brief Funcao que ordena a lst pelo metodo quick sort (complexidade 0(n log n))
 * 
 * @param lst ponteiro para a estrutura de lst
 * @param inicio posicao inicial da lst
 * @param fim posicao final da lst
 * 
*/
void quickSort(tipo_lista *lst, int inicio, int fim){
    int pivo, aux, i, j, meio;
    meio = ( (fim - inicio) / 2 ) + inicio;
    pivo = lst -> lista[meio];
    i = inicio;
    j = fim;
    //Faz as trocas entre os valores menores e maiores posicionados em lados errados (em relação ao pivo)
    while ( i < j ){
        while ( lst -> lista[i] < pivo ){
            i++;
        }
		while ( lst -> lista[j] > pivo ){
			j--;
        }
		//Verifica se os dois não se encontraram para fazer troca
		if ( i < j ){
			aux = lst -> lista[i];
			lst -> lista[i] = lst -> lista[j];
			lst -> lista[j] = aux;
		}
	}
	//Verifica e faz a chamada recursiva
	if (( j > inicio ) && ( (j-inicio) > 1 )){
		quickSort(lst, inicio, j);
	}
	if (( i < fim ) && ( (fim-i) > 1 )){
		quickSort(lst, i, fim);
    }
}