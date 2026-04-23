#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.

#define TAM_MAX 10

typedef struct {
    char nome[30];
    char tipo[30];
    int quantidade;
} itemModel;

typedef struct {
    itemModel dados[TAM_MAX];
    int quantidade;
} inventario;

void iniciarInventario(inventario *lista) {
    lista->quantidade = 0;
}

void inserirItem(inventario *lista, itemModel item) {
    if(lista->quantidade == TAM_MAX){
        printf("Erro: Lista cheia! Nao e possivel inserir.\n");
        return;
    }

    lista->dados[lista->quantidade] = item;
    lista->quantidade++;
    
    printf("Item '%s' adicionado com sucesso!\n", item.nome);
    
}

void removerItem(inventario *lista, const char* nome) {
    int i, pos = -1;
    for(i = 0; i < lista->quantidade; i++){
        if(strcmp(lista->dados[i].nome, nome) == 0){
            pos = i;
            break;
        }
    }
    if (pos == -1) {
        printf("Erro: Item \"%s\" nao encontrado na lista.\n", nome);
        return;
    }

    for(i = pos; i < lista->quantidade - 1; i++) {
        lista->dados[i] = lista->dados[i + 1];
    }
    lista->quantidade--;
    printf("Item \"%s\" removido com sucesso.\n", nome);


}

void listarInventario(inventario *lista) {
    if(lista->quantidade == 0){
        printf("O inventário está vazio.");
        return;
    }
    printf("* Itens do inventário *\n");
    printf("|  Nome  |  tipo  |  quantidade  |\n");
    for(int i = 0; i < lista->quantidade; i++) {
        printf("  %s  |  %s  |  %d  |\n", lista->dados[i].nome, lista->dados[i].tipo, lista->dados[i].quantidade);
}
    
}


void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    inventario inv; 
    iniciarInventario(&inv);
     
    int opcao;
    itemModel novoItem;

    do {
        printf("-- MENU DE INVENTARIO --\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Inventario\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                printf("Nome do item: ");
                fgets(novoItem.nome, 30, stdin);
                novoItem.nome[strcspn(novoItem.nome, "\n")] = 0;

                printf("Tipo do item: ");
                fgets(novoItem.tipo, 30, stdin);
                novoItem.tipo[strcspn(novoItem.tipo, "\n")] = 0;

                printf("Quantidade: ");
                scanf("%d", &novoItem.quantidade);
                limparBuffer();

                inserirItem(&inv, novoItem);
                break;

            case 2:
                printf("Nome do item a ser removido: ");
                fgets(novoItem.nome, 30, stdin);
                novoItem.nome[strcspn(novoItem.nome, "\n")] = 0;

                removerItem(&inv, novoItem.nome);
                break;
            case 3:
                listarInventario(&inv);
                break;
            case 0:
                printf("Saindo do sistema...\n");
                break;

            default:
                printf("Opcao Invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}


// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.




// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
