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

void insereElemento(El *no, El *inicio){
    no->prox = inicio->prox;
    inicio->prox = no;
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

int deTras(El *inicio){
    El *aux, *ante;
    aux = inicio->prox;
    if(aux->prox != NULL){
        ante = aux;
        deTras(aux);
        printf(" %i", ante->num);
    }
    else{
        printf("%i", aux->num);
        return 0;
    }
}

void removeDaLista(El *inicio, int num){
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
}


int main(void) {
    
    int i, num;
    El *no;
    El *inicio = criaLista();
    
    for(i=0;i<5;i++){
        scanf("%i", &num);
        El *no = criaElemento(num);
        insereElemento(no, inicio);
    }
    

    deTras(inicio);
    printf("\n");
    imprimeLista(inicio);

   return 0;
}