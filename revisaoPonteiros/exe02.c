#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int num;
    struct elemento *prox;
}El;

El *criaElemento(int num){
   El *no = (El*)malloc (sizeof(El));
	if(no != NULL) {
		no->num = num;
    	no->prox = NULL;
	}
    return no;
}

El *criaLista(){
   El *no = (El*)malloc (sizeof(El));
	if(no != NULL){
		no->prox = NULL;
	}
    return no;
}

int insereElementoFinal(El *no, El *inicio){
	if(inicio == NULL){
		return 0;
	}
	El *aux = inicio;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	no->prox = aux->prox;
   aux->prox = no;
}

int imprimeLista(El *inicio){
    if(inicio == NULL){
		return 0;
	 }
	El *aux = inicio->prox;
    while(aux!=NULL){
        printf("%i ", aux->num);
        aux = aux->prox;
    }
}

int deTras(El *inicio){
   if(inicio == 0){
		return 0;
	}
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
    
   int i, num;
    El *inicio = criaLista();
	 El *segundoInicio = NULL; 
    for(i=0;i<3;i++){
		 scanf("%d", &num);
        El *no = criaElemento(num);
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