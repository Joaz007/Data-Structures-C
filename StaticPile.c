/* #include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct {
    int dados[10];
    int topo;
}PilhaEstatica;

void IniciaPilha(PilhaEstatica *p, int *topo){
    for (int i = 0; i < 10; i++){
        p->dados[i] = 0;
    }
    
    topo = 0;

    return;
}

int main(){
    PilhaEstatica Pilha;

    IniciaPilha(&Pilha, &Pilha.topo);


    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct{
    int k;
    char nome[20];
} Objeto;

typedef struct{
    Objeto vetor[MAX_SIZE];
    int topo;
} pilha_estatica;

// adiciona elemento ao topo da pilha
void push(Objeto x, pilha_estatica *p){

    // escreve objeto
    p->vetor[p->topo] = x;
    // atualiza o topo
    p->topo = p->topo+1;
}

// remove elemento do topo
void pop(Objeto *x, pilha_estatica *p){

    // atualizar a posição do topo 
    p->topo = p->topo - 1;
    // ler posição do topo (copia para o elemento)
    *x = p->vetor[p->topo];
}

// imprime elementos da pilha
void mostra_pilha(pilha_estatica *p){
    
    printf("\n conteudo da pilha: \n");
    for (int pos = p->topo-1; pos>-1; pos--){
        printf("%d %s\n", p->vetor[pos].k, p->vetor[pos].nome);
    }
}

int main(){

    // cria e inicializa a pilha
    pilha_estatica dados;
    dados.topo = 0;

    // insere primeiro objeto    
    Objeto d;
    d.k = 4;
    strcpy(d.nome, "kuka belludo");
    push(d, &dados);

    // insere segundo e terceiro objetos    
    d.k = 1;
    strcpy(d.nome, "Jalin Habbey");
    push(d, &dados);

    d.k = 3;
    strcpy(d.nome, "Kadu Kando");
    push(d, &dados);

    // remove um objeto
    pop(&d, &dados);
    printf("removido: %d %s\n", d.k, d.nome);

    // insere mais um
    d.k = 8;
    strcpy(d.nome, "Fujiro Nakombi");
    push(d, &dados);

    // remove um obj
    pop(&d, &dados);
    printf("removido: %d %s\n", d.k, d.nome);

    // no final mostra a pilha
    mostra_pilha(&dados);
}
