#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ITENS 10

typedef struct {
   char nome[30];
   char tipo[20];
   int quantidade;
} Item;

Item mochila[MAX_ITENS];
int totalItens = 0;

// Funçoes
void adicionarItem();
void removerItem();
void listarItem();
void buscarItem();
void limparBuffer();

int main() {
    int opcao;

    do {
        printf("\n--- DESAFIO CODIGO DA ILHA (AVENTUREIRO) ---\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Inventario\n");
        printf("4. Buscar Item por Nome\n"); 
        printf("0. Sair\n");
        printf("Escolha sua acao: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
        case 1:
            adicionarItem();
            break;
        case 2:
            removerItem();
            break;
        case 3:
            listarItem();
            break;
        case 4: 
            buscarItem();
            break;
        case 0: 
            printf("Saindo da ilha...\n");
            break;                    
        default:
        printf("Comando Invalido!\n");
            break;
        }
    } while (opcao != 0)
    
    return 0;
    
}

// Funçao de buscar em sequencia 
void buscarItem() {
    char termoBusca[30];
    int encontrado = 0; // FLAG sinalizadora

    if (totalItens ==0) {
        printf("\nMochila vazia! Nao ha o que buscar.\n");
        return;
    }

    printf("\nDigite o nome do item que deseja encotar: ");
    fgets(termoBusca,30, stdin);
    termoBusca[strcspn(termoBusca, "\n")] = 0;
    
    printf("\nIniciando busca...\n");
    for (int i = 0; i < totalItens; i++) {
        // strcmp foi usado apra retornar 0 quando as strings sao identicas
        if(strcmp(mochila[i].nome, termoBusca) == 0) {
            printf("\n[ ITEM ENCONTRADO NA POSICAO %d ]\n", i + 1);
            printf("Nome: %s\n", mochila[i].nome);
            printf("Tipo: %s\n", mochila[i].tipo);
            printf("Quantidade: %d\n", mochila[i].quantidade);
            encontrado = 1; // Ativa a flag
            break; // parar o laço
        }
    }

    if (!encontrado) {
        printf("\n[ERRO] O item '%s'nao esta na sua mochila.\n", termoBusca);        
    }
}

// Estas funços sao as mesmas do nivel novato...
void adicionarItem() {
    if (toltalItens < MAX_INTENS){
        printf("\nNome do item (ex: M4A1): ");
        fgets(mochila[totalItens].nome, 30, stdin);
        mochila[totalItens].nome[strcspn(mochila[totalItens].nome, "\n")] = 0;

        printf("Tipo (ex: Arma, Cura, Muniçao): ");
        fgets(mochila[totalItens].tipo, 20 stdin);
        mochila[totalItens].nome[strcspn(mochila[totalItens].tipo, "\n")] = 0;

        printf("Quantidade: ")
        scanf("%d", &mochila[totalItens].quantidade);

        totalItens++;
        printf(">> Item adicionado com sucesso!\n");
    } else {
        printf(">> Erro: Mochila cheia (limite de 10 itens)\n");
    }
}

void listarItens() {
    if (totalItens == 0) {
        printf("\nA mochila esta vazia.\n");
        return;
    }

    printf("\n--- INVETARIO ATUAL ---\n");   
    for (int i = 0; i < totalItens; i++) {
        printf("%d. %s (%s) - QTD: %d\n", i+1, mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

void removerItem() {
    char alvo[30];
    int encontrado = -1;

    printf("\nDigite o nome do item para remover: ");
    fgets(alvo, 30, stdin);
    alvo[strcspn(alvo, "\n")] = 0;

    for (int i = o, i < totalItens, i++) {
        if (strcmp(mochila[i].nome, alvo) == 0) {
            encontrado = i
            break;
        }
    }

    if (encontrado != -1) {
        for (int i = encontrado; i < totalItens - 1; i++) {
            mochila[i] = mochila[i+1];
        }
        totalItens--;
        peintf(">> Item '%s' removido!\n", alvo); 
    } else {
        printf(">> Erro: Item nao encontrado.\n");
    }
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)      
}