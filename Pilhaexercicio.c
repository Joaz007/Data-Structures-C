#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
}No;


typedef struct {
    No *topo;
    int tamanho;
}Pilha;

void InicializaPilha(Pilha *pilha){
    pilha->topo = NULL;
    pilha->tamanho = 0;
}

void Empilhar(int valor, Pilha *pilha){
    No *novoNo = malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = pilha->topo;
    pilha->topo = novoNo;
    pilha->tamanho++;
}

void Pop(Pilha *pilha) {
  printf("Limpando Pilha\n");
  No *temporario;
  temporario = pilha->topo;
  pilha->topo = pilha->topo->proximo;
  pilha->tamanho--;
  free(temporario);
}

void exibir(Pilha *pilha) {
  No *temporario;
  int i = pilha->tamanho;
  printf("Valores da pilha:\n");

  for (temporario = pilha->topo; temporario != NULL; temporario = temporario->proximo){
    printf("Posição[%d]: %d\n ", i, temporario->valor);
    i--;
  }
  
}

int main(){
    Pilha pilha;
    int opcao;
    int novoitem; 
    InicializaPilha(&pilha);

  while (opcao != 5) {
        printf("Escolha uma Opção\n");
        printf("1) Exibir Pilha\n");
        printf("2) Empilhar Item na Pilha\n");
        printf("3) Desempilhar Item da Pilha\n");
        printf("4) Esvaziar Pilha\n");
        printf("5) Sair do Programa\n");
        scanf("%i", &opcao);

        if (opcao == 1) exibir(&pilha);
        if (opcao == 2) {
        printf("Digite um Número Inteiro: \n");
        scanf("%i", &novoitem);
        Empilhar(novoitem, &pilha);
        }
        if (opcao == 3){
          Pop(&pilha);
        }
        
    }//while

    Pop(&pilha);
    printf("Programa Finalizado"); 
    return 0;
} //main