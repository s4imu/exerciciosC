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

void insereElemento(El *no, El *inicio){
	El *aux = inicio;
	while(aux->prox != NULL){
		aux = aux->prox;
	}
	no->prox = aux->prox;
    aux->prox = no;
}

int buscaElemento(int num, El *inicio){
	if(inicio == NULL){
		return 0;
	}
	if(inicio->num == num){
		return 1;
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

void imprimeListaComZer0(El *inicio){
    El *aux;
    aux = inicio->prox;
    while(aux->num!=0){
        printf("%i ", aux->num);
        aux = aux->prox;
    }
}

El *uniaoListas(El *inicioLista1, El *inicioLista2){
	int achou;
	El *uniao = criaLista();
// 	receber o inicio da primeiraLista
	El* aux = inicioLista1;
	
// 	laço para percorrrer a lista inteiro;
	while(aux->num != 0){
	    printf("Entrou\n");
	   // verifica se o numero ja nao esta inserido na lista de uniao
		achou = buscaElemento(aux->num,uniao);
		printf("%i", achou);
		if(achou == 1){
		    // caso ache passa para o prox
		    printf("Achou elemento %d na Lista Uniao", aux->num);
			aux = aux->prox;
		} else {
		    // insercao na lista de uniao
			insereElemento(aux, uniao);
			aux = aux->prox;
		}
	}
	
// 	a ideia é se repetir os mesmos passos para a lista 2
	aux = inicioLista2;
	
	while(aux->num != 0){
		printf("Entrou\n");
		achou = buscaElemento(aux->num,uniao);
		printf("%i", achou);
		if(achou == 1){
		    printf("Achou elemento %d na Lista Uniao", aux->num);
			aux = aux->prox;
		} else {
			insereElemento(aux, uniao);
			aux = aux->prox;
		}
	}
	
	return uniao;
}

int main(void) {
	int i;
	El *inicio1 = criaLista();
	El *inicio2 = criaLista();
	El *uniao;
	
	int array1[3] = {10, 2, 0};
	int array2[3] = {2, 1, 0};
	
	for(i=0;i<3;i++){
		El *no1 = criaElemento(array1[i]);
		El *no2 = criaElemento(array2[i]);
		insereElemento(no1,inicio1);
		insereElemento(no2,inicio2);
	}
	
	uniao = uniaoListas(inicio1,inicio2);
	
	printf("Lista 1: ");
	imprimeListaComZer0(inicio1);
	printf("\n");
	printf("Lista 2: ");
	imprimeListaComZer0(inicio2);
	printf("\n");
	printf("Uniao: ");
	imprimeLista(uniao);
	printf("\n");
	
	 return 0;
}