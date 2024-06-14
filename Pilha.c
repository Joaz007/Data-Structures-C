#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore binária
typedef struct No {
    char nome[100];    // Nome do aluno
    int ra;            // RA do aluno
    struct No* esquerda;  // Ponteiro para o nó filho à esquerda
    struct No* direita;   // Ponteiro para o nó filho à direita
} No;

// Função para criar um novo nó com os dados do aluno
No* criarNo(char* nome, int ra) {
    No* novoNo = (No*)malloc(sizeof(No));  // Aloca memória para o novo nó
    strcpy(novoNo->nome, nome);            // Copia o nome para o nó
    novoNo->ra = ra;                       // Atribui o RA ao nó
    novoNo->esquerda = NULL;               // Inicializa o ponteiro da esquerda como NULL
    novoNo->direita = NULL;                // Inicializa o ponteiro da direita como NULL
    return novoNo;                         // Retorna o ponteiro para o novo nó
}

// Função para inserir um nó na árvore ordenada por nome
No* inserirPorNome(No* raiz, char* nome, int ra) {
    if (raiz == NULL) {
        return criarNo(nome, ra);  // Cria um novo nó se a raiz for NULL
    }
    if (strcmp(nome, raiz->nome) < 0) {
        raiz->esquerda = inserirPorNome(raiz->esquerda, nome, ra);  // Insere à esquerda se o nome for menor
    } else {
        raiz->direita = inserirPorNome(raiz->direita, nome, ra);  // Insere à direita se o nome for maior ou igual
    }
    return raiz;
}

// Função para inserir um nó na árvore ordenada por RA
No* inserirPorRA(No* raiz, int ra, char* nome) {
    if (raiz == NULL) {
        return criarNo(nome, ra);  // Cria um novo nó se a raiz for NULL
    }
    if (ra < raiz->ra) {
        raiz->esquerda = inserirPorRA(raiz->esquerda, ra, nome);  // Insere à esquerda se o RA for menor
    } else {
        raiz->direita = inserirPorRA(raiz->direita, ra, nome);  // Insere à direita se o RA for maior ou igual
    }
    return raiz;
}

// Função para imprimir a árvore em ordem crescente
void imprimirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);  // Imprime a subárvore esquerda
        printf("RA: %d, Nome: %s\n", raiz->ra, raiz->nome);  // Imprime o nó atual
        imprimirEmOrdem(raiz->direita);  // Imprime a subárvore direita
    }
}

// Função para imprimir a árvore em ordem decrescente
void imprimirEmOrdemReversa(No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdemReversa(raiz->direita);  // Imprime a subárvore direita
        printf("RA: %d, Nome: %s\n", raiz->ra, raiz->nome);  // Imprime o nó atual
        imprimirEmOrdemReversa(raiz->esquerda);  // Imprime a subárvore esquerda
    }
}

// Função para buscar um nó na árvore pelo nome
No* buscarPorNome(No* raiz, char* nome) {
    if (raiz == NULL || strcmp(raiz->nome, nome) == 0) {
        return raiz;  // Retorna o nó se encontrado ou NULL se não encontrado
    }
    if (strcmp(nome, raiz->nome) < 0) {
        return buscarPorNome(raiz->esquerda, nome);  // Busca na subárvore esquerda se o nome for menor
    }
    return buscarPorNome(raiz->direita, nome);  // Busca na subárvore direita se o nome for maior
}

// Função para buscar um nó na árvore pelo RA
No* buscarPorRA(No* raiz, int ra) {
    if (raiz == NULL || raiz->ra == ra) {
        return raiz;  // Retorna o nó se encontrado ou NULL se não encontrado
    }
    if (ra < raiz->ra) {
        return buscarPorRA(raiz->esquerda, ra);  // Busca na subárvore esquerda se o RA for menor
    }
    return buscarPorRA(raiz->direita, ra);  // Busca na subárvore direita se o RA for maior
}

// Função para carregar a árvore a partir de um arquivo CSV
No* carregarArvore(char* nomeArquivo, int ordenarPor) {
    FILE* arquivo = fopen(nomeArquivo, "r");  // Abre o arquivo para leitura
    if (!arquivo) {
        printf("Não foi possível abrir o arquivo %s\n", nomeArquivo);
        return NULL;  // Retorna NULL se não for possível abrir o arquivo
    }

    No* raiz = NULL;  // Inicializa a raiz da árvore como NULL
    char linha[256];
    fgets(linha, sizeof(linha), arquivo); // Ignora a primeira linha (cabeçalho)
    while (fgets(linha, sizeof(linha), arquivo)) {
        char nome[100];
        int ra;
        sscanf(linha, "%d, %[^\n]", &ra, nome); // Lê o RA e o nome do aluno
        if (ordenarPor == 1) { // Ordenar por nome
            raiz = inserirPorNome(raiz, nome, ra);  // Insere na árvore ordenada por nome
        } else { // Ordenar por RA
            raiz = inserirPorRA(raiz, ra, nome);  // Insere na árvore ordenada por RA
        }
    }

    fclose(arquivo);  // Fecha o arquivo
    return raiz;  // Retorna a raiz da árvore
}

int main() {
    int ordenarPor;
    // Solicita ao usuário para escolher o critério de ordenamento da árvore
    printf("Escolha o critério de ordenamento da árvore:\n");
    printf("1. Alfabética por nome\n");
    printf("2. Crescente por RA\n");
    printf("Digite 1 ou 2: ");
    scanf("%d", &ordenarPor);

    // Carrega a árvore a partir do arquivo CSV com o critério selecionado
    No* raiz = carregarArvore("nome_RA.csv", ordenarPor);
    if (raiz == NULL) {
        return 1;  // Sai do programa se não foi possível carregar a árvore
    }

    int opcao;
    do {
        // Menu de opções para o usuário
        printf("\nMenu:\n");
        printf("1. Imprimir em ordem\n");
        printf("2. Imprimir em ordem reversa\n");
        printf("3. Buscar pelo critério\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            imprimirEmOrdem(raiz);  // Imprime a árvore em ordem crescente
        } else if (opcao == 2) {
            imprimirEmOrdemReversa(raiz);  // Imprime a árvore em ordem decrescente
        } else if (opcao == 3) {
            if (ordenarPor == 1) {
                char nome[100];
                printf("Digite o nome a buscar: ");
                scanf(" %[^\n]", nome);  // Lê o nome do usuário
                No* resultado = buscarPorNome(raiz, nome);  // Busca pelo nome
                if (resultado) {
                    printf("Encontrado: RA: %d, Nome: %s\n", resultado->ra, resultado->nome);
                } else {
                    printf("Não encontrado.\n");
                }
            } else {
                int ra;
                printf("Digite o RA a buscar: ");
                scanf("%d", &ra);  // Lê o RA do usuário
                No* resultado = buscarPorRA(raiz, ra);  // Busca pelo RA
                if (resultado) {
                    printf("Encontrado: RA: %d, Nome: %s\n", resultado->ra, resultado->nome);
                } else {
                    printf("Não encontrado.\n");
                }
            }
        }
    } while (opcao != 4);  // Repete o menu até que o usuário escolha sair (opção 4)

    return 0;
}
