#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> // Para usar o tipo bool

#define MAX_ITENS 10

// Criterio de ordenaçao para melhorar a legibilidade
typedef enum { NOME = 1, TIPO, PRIORIDADE } Criterio;

typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
    int prioridade; //Prioridade de 1 a 5
} Item;

Item mochila[MAX_ITENS];
int totalItens = 0;
bool estaOrdenadoPorNome = false; // Controle para Busca 

// Funçoes
void adicionarItem();
void listarItens();
void ordenarMochila();
void buscaBinaria();
void limparBuffer();

int main() {
    int opcao;
    do {
        printf("\n--- DESAFIO CODIGO DA ILHA (MESTRE) ---\n");
        printf("1. Adicionar Item\n");
        printf("2. Listar Inventario\n");
        printf("3. Ordenar Mochila\n");
        printf("4. Busca Binaria (por nome)\n");
        printf("0. Sair\n");
        printf("Escolha sua acao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1: adicionarItem(); break;
            case 2: listarItens(); break;
            case 3: ordenarMochila(); break;
            case 4: buscaBinaria(); break;
            case 0: printf("Saindo da ilha...\n"); break;
            default: printf("Comando invalido!\n");
        }
    } while(opcao != 0);
    return 0;
}

void adicionarItem() {
    if (totalItens < MAX_ITENS) {
        printf("Nome: "); fgets(mochila[totalItens].nome, 30, stdin);
        mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = 0;
        printf("Tipo: "); fgets(mochila[totalItens].tipo, 20, stdin);
        mochila[totalItens].tipo[strcspn(mochila[totalItens].tipo, "\n")] = 0;
        printf("Quantidade: "); scanf("%d", &mochila[totalItens].quantidade);
        printf("Prioridade (1-5): "); scanf("%d", &mochila[totalItens].prioridade);
        totalItens++;
        estaOrdenadoPorNome = false; // Se adicionou novo, a ordem pode ter quebrado
        printf(">> Item adicionado!\n");
    } else {
        printf(">> Mochila cheia!\n");
    }
}

// Insertion Sort 
void ordenarMochila() {
    int criterio, comparacoes = 0;
    printf("\nOrdenar por: 1.Nome | 2.Tipo | 3.Prioridade: ");
    scanf("%d", &criterio);

    for (int i = 1; i < totalItens; i++) {
        Item chave = mochila[i];
        int j = i - 1;

        // Lógica de comparação baseada no critério
        while (j >= 0) {
            comparacoes++;
            int condicao = 0;
            if (criterio == NOME) condicao = strcmp(mochila[j].nome, chave.nome) > 0;
            else if (criterio == TIPO) condicao = strcmp(mochila[j].tipo, chave.tipo) > 0;
            else if (criterio == PRIORIDADE) condicao = mochila[j].prioridade > chave.prioridade;

            if (condicao) {
                mochila[j + 1] = mochila[j];
                j--;
            } else break;
        }
        mochila[j + 1] = chave;
    }
    
    if (criterio == NOME) estaOrdenadoPorNome = true;
    printf(">> Mochila ordenada! Comparacoes realizadas: %d\n", comparacoes);
    listarItens();
}

// Busca Binária
void buscaBinaria() {
    if (!estaOrdenadoPorNome) {
        printf("\n[ ERRO ] A mochila precisa estar ordenada por NOME para busca binaria!\n");
        return;
    }

    char alvo[30];
    printf("Buscar (Nome): ");
    fgets(alvo, 30, stdin);
    alvo[strcspn(alvo, "\n")] = 0;

    int inicio = 0, fim = totalItens - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        int res = strcmp(mochila[meio].nome, alvo);

        if (res == 0) {
            printf("\nItem ENCONTRADO! Tipo: %s | Qtd: %d | Prioridade: %d\n", 
                   mochila[meio].tipo, mochila[meio].quantidade, mochila[meio].prioridade);
            return;
        } else if (res < 0) inicio = meio + 1;
        else fim = meio - 1;
    }
    printf("\nItem nao encontrado.\n");
}

void listarItens() {
    printf("\n%-20s | %-15s | %-5s | %-5s\n", "NOME", "TIPO", "QTD", "PRIO");
    for (int i = 0; i < totalItens; i++) {
        printf("%-20s | %-15s | %-5d | %-5d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade, mochila[i].prioridade);
    }
}

void limparBuffer() {
    int c; while ((c = getchar()) != '\n' && c != EOF);
}