#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef  struct cliente {
    char *nome;
    int id;
} Cliente;

typedef struct Item {
    Cliente valor;
    struct Item* proximo;
} Item;

Item* criarItem(Cliente valor) {
    Item* novoItem = malloc(sizeof(Item));
    novoItem->valor = valor;
    novoItem->proximo = NULL;

    return novoItem;
}

void adicionarItem(Item** primeiro, Cliente valor){
    Item* novoItem = criarItem(valor);

    if (*primeiro == NULL) {
        *primeiro = novoItem;
    } else {
        Item* atual = *primeiro;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novoItem;
    }
}

void exibirLista(Item** inicio) {
    Item* item = *inicio;
    while (item != NULL) {
        Cliente cliente = item->valor;
        printf("Id: %d \n", cliente.id);
        printf("Nome: %s \n", cliente.nome);

        item = item->proximo;
    }
}

Cliente criarCliente() {
    Cliente cliente;
    cliente.nome = malloc(50);

    printf("Informe o nome do cliente: ");
    scanf(" %[^\n]", cliente.nome);

    printf("Informe o id do cliente: ");
    scanf("%d", &cliente.id);

    return cliente;
}

int main () {
    char continuar = 'N';
    Item* inicio = NULL;

    do {
        Cliente cliente = criarCliente();
        adicionarItem(&inicio, cliente);

        printf("Deseja continuar? (S/N) ");
        scanf(" %c", &continuar);
    } while (toupper(continuar) == 'S');

    exibirLista(&inicio);

    return 0;
}