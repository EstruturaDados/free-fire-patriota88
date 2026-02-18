#include <stido.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INTENS 10

// Itens da mochila
typedef struct {
   char nome[30];
   char tipo[20];
   int quantidade;
} Item;

// Variaveis para gerenciar o estado da mochila
Item mochila[MAX_INTENS];
int totalItens = 0;

// Funçoes
void adicionarItem();
void removerItem();
void listarItens();
void limparBuffer();

int main() {
    int opcao;
    do {
        printf("\n--- DESAFIO ILHA FREE FIRE (NOVATO) ---\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Inventario\n");
        printf("0. Sair\n");
        printf("Escolha a açao: ");
        printf(%d, &opcao);
        limparBuffer(); // Limpar o rastro deixado pelo Enter do teclado

        switch (opcao)
        {
        case 1:
            adicionarItem();
            break;
        case 2:
            removerItem();
            break;
        case 3:
            listarItens();
            break;
        case 0:
            printf("Saindo da ilha...\n");
            break;
        default:
            printf("Comando Invalido!\n");
        
        } 
              
    } while (opcao != 0);

    return 0;
}

// Cadastrar Itens
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

// Listar os itens em fomra de tabela
void listarItens() {
    if (totalItens == 0) {
        printf("\nA mochila esta vazia.\n");
        return;
    }

    printf("\n--- INVETARIO ATUAL ---\n");
    printf("%20s | %-15 | %s\n", "NOME", "TIPO", "QUANTIDADE");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < totalItens; i++) {
        printf("%20s | %-15 | %s\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
}

// Remover o item pelo nome
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

// Limpar o buffer
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF)      
}