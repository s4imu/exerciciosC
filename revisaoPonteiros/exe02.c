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
    if(inicio == NULL){
		 printf(" ");
	 }
	El *aux = inicio->prox;
    while(aux!=NULL){
        printf("%i ", aux->num);
        aux = aux->prox;
    }
}

void deTras(El *inicio){
    El *aux, *ante;
    aux = inicio->prox;
    if(aux->prox != NULL){
        ante = aux;
        deTras(aux);
        printf(" %i", ante->num);
    }
    else{
        printf("%i", aux->num);
    }
}

int main(void) {
    
    int i;
	int array[6] = {1, 5, 7, 9, 3, 6};
    El *inicio = criaLista();
    El *segundoInicio = NULL;
    for(i=0;i<6;i++){
        El *no = criaElemento(array[i]);
        insereElementoFinal(no, inicio);
    }
    
	printf("Lista Original: ");
	imprimeLista(inicio);
	printf("\n");
	printf("Lista Invertida: ");
   deTras(inicio);
   printf("\n");
	printf("Lista Original: ");
	imprimeLista(segundoInicio);
	printf("\n");
	printf("Lista Invertida: ");
   deTras(segundoInicio);
   printf("\n");
    

   return 0;
}