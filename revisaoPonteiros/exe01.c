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

El *iniciaLista(){
    El *no = (El*)malloc (sizeof(El));
	if(no != NULL){
		no->prox = NULL;
	}
    return no;
}

int insereElemento(El *no, El *inicio){
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

El *criaLista(){
    El *inicio = iniciaLista();
    int num;
    scanf("%d", &num);
    while(num != 0){
        El *no = criaElemento(num);
        insereElemento(no, inicio);
        scanf("%d", &num);
    }
    
    return inicio;
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


int imprimeLista(El *inicio){
    if(inicio == NULL){
        return 0;
    }
    El *aux;
    aux = inicio->prox;
    while(aux!=NULL){
        printf("%i ", aux->num);
        aux = aux->prox;
    }
}

El *insercaoListaUniao(El *inicioLista, El *uniao){
    if(inicioLista == NULL || uniao == NULL){
        return NULL;
    }
	int achou;
	El* aux = inicioLista;
    
    while(aux != NULL){
		achou = buscaElemento(aux->num,uniao);
		if(achou == 1){
			aux = aux->prox;
		} 
		if(achou == 0){
		    El *no = criaElemento(aux->num);
			insereElemento(no, uniao);
			aux = aux->prox;
		}
	}
	return uniao;
}


El *insercaoListaIntersecao(El *inicioLista1, El *inicioLista2, El *intersecao){
	if(inicioLista1 == NULL || inicioLista2 == NULL || intersecao == NULL){
	    return NULL;
	}
	int achou;
	El* aux = inicioLista1;
    
    while(aux != NULL){
		achou = buscaElemento(aux->num,inicioLista2);
		if(achou == 0 || aux->num == 0){
            aux = aux->prox;
		}
		else {
            achou = buscaElemento(aux->num,intersecao);
		    if(achou == 0){
      		    El *no = criaElemento(aux->num);
			    insereElemento(no, intersecao);
			    aux = aux->prox;  
		    }
		    else {
		        aux = aux->prox;
		    }
		} 
	}
	
	aux = inicioLista2;
	while(aux != NULL){
		achou = buscaElemento(aux->num,inicioLista1);
    	if(achou == 0 || aux->num == 0){
            aux = aux->prox;
		}
		else {
		    achou = buscaElemento(aux->num,intersecao);
		    if(achou == 0){
      		    El *no = criaElemento(aux->num);
			    insereElemento(no, intersecao);
			    aux = aux->prox;  
		    }
		    else {
		        aux = aux->prox;
		    }
		} 
	}
	
	return intersecao;
}

El *intersecaoListas(El *inicioLista1, El *inicioLista2){
	if(inicioLista1 == NULL || inicioLista2 == NULL){
	    return NULL;
	}
    El *intersecao = iniciaLista();
    
    intersecao = insercaoListaIntersecao(inicioLista1, inicioLista2, intersecao);

	return intersecao;
}


El *uniaoListas(El *inicioLista1, El *inicioLista2){
	if(inicioLista1 == NULL || inicioLista2 == NULL){
	    return NULL;
	}
    El *uniao = iniciaLista();
    
    uniao = insercaoListaUniao(inicioLista1, uniao);
    uniao = insercaoListaUniao(inicioLista2, uniao);

	return uniao;
}

int main(void) {
	int i;
	El *inicio1 = criaLista();
	El *inicio2 = criaLista();
	El *uniao, *intersecao;
	
 	uniao = uniaoListas(inicio1,inicio2);
 	intersecao = intersecaoListas(inicio1,inicio2);
	
	printf("Lista 1: ");
	imprimeLista(inicio1);
	printf("\n");
	printf("Lista 2: ");
	imprimeLista(inicio2);
	printf("\n");
	printf("Uniao: ");
	imprimeLista(uniao);
	printf("\n");
	printf("Intersecao: ");
	imprimeLista(intersecao);
	printf("\n");
	
	