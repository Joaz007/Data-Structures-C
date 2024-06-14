#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NoLista{
    int valor;
    struct NoLista *proximo;
}NoLista;

typedef struct{
   NoLista *inicio;
   int quantidade_Elementos;
}ListaOrdenada;

void Inicializar(ListaOrdenada *lista){
    lista->inicio = NULL;
    lista->quantidade_Elementos = 0;
}

bool EstaVaziaListaOrdenada(ListaOrdenada *lista){
    return(lista->inicio == NULL);
}

int tamanhoListaOrdenada(ListaOrdenada *lista){
    return (lista->quantidade_Elementos);
}

void InserirListaOrdenada(ListaOrdenada *lista, int x){
    NoLista *novo = (NoLista*)malloc(sizeof(NoLista));
    novo->valor = x;


    if (EstaVaziaListaOrdenada(lista) || x < lista->inicio->valor){
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    } else {
        NoLista *aux = (NoLista*)malloc(sizeof(NoLista));
        aux = lista->inicio;
        while (aux->proximo != NULL && x > aux->proximo->valor){
            aux = aux->proximo;
        }
        novo->proximo = aux->proximo;
        aux->proximo = novo;
    }
    lista->quantidade_Elementos++;
}

void ExibeLista(ListaOrdenada *lista){
    NoLista *inicio = lista->inicio;
    if(inicio!=NULL){
        while(inicio!=NULL){
            printf("%d ",inicio->valor);
            inicio = inicio->proximo;
        }
    }else{
        printf("Lista vazia");
    } 
}

int main(){

    ListaOrdenada lista;
    Inicializar(&lista);
    InserirListaOrdenada(&lista, 10);
    InserirListaOrdenada(&lista, 20);
    InserirListaOrdenada(&lista, 5);
    ExibeLista(&lista);

    return 0;
}