#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int num;
    struct elemento *prox;
}El;

El *criaLista(){
    El *no = (El*)malloc (sizeof(El));
    no->prox = NULL;
    return no;
}

El *criaElemento(int num){
    El *no = (El*)malloc (sizeof(El));
    no->num = num;
    no->prox = NULL;
    return no;
}

void insereElementoInicio(El *no, El *inicio){
    no->prox = inicio->prox;
    inicio->prox = no;
}
void insereElementoFinal(El *no, El *inicio){
	El *aux = inicio;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	no->prox = aux->prox;
   aux->prox = no;
}

El *buscaElemento(int num, El *inicio){
	if(inicio == NULL){
		return NULL;
	}
	if(inicio->num == num){
		return inicio;
	}
	return buscaElemento(num, inicio->prox);
}

void imprimeLista(El *inicio){
    El *aux;
    aux = inicio->prox;
    while(aux!=NULL){
        printf("%i ", aux->num);
        aux = aux->prox;
    }
}


int removeDaLista(El *inicio, int num){
    if(inicio == NULL){
        return 0;
    }
    El *antecessor, *atual;
    antecessor = inicio;
    atual = inicio->prox;
    
    while(atual != NULL && atual->num != num){
        antecessor = atual;
        atual = atual->prox;
    }
    if(atual != NULL){
        antecessor->prox = atual->prox;
        free(atual);
    }
    if(atual == NULL) {
        return 0;
    }
}


int main(void) {
    
   printf("Compilou");

   return 0;
}