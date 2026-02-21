#include <stdio.h>
#include <string.h>
#include "dados.h"

void cadastrarProduto(Produto cardapio[], int *totalProdutos) {
    cardapio[*totalProdutos].id = *totalProdutos + 1;
    printf("Nome do Item: ");
    scanf(" %[^\n]", cardapio[*totalProdutos].nome);
    printf("Preço: ");
    scanf("%f", &cardapio[*totalProdutos].preco);
    
    (*totalProdutos)++;
    printf("Item adicionado ao cardápio com sucesso!\n");
}

void listarCardapio(Produto cardapio[], int totalProdutos) {
    printf("\n--- CARDÁPIO ---\n");
    for(int i = 0; i < totalProdutos; i++) {
        printf("ID: %d | %s - R$ %.2f\n", cardapio[i].id, cardapio[i].nome, cardapio[i].preco);
    }
}

void registrarPedido(Pedido pedidos[], int *totalPedidos, Produto cardapio[], int totalProdutos) {
    listarCardapio(cardapio, totalProdutos);
    
    pedidos[*totalPedidos].idPedido = *totalPedidos + 1;
    printf("\nDigite o ID do produto para o pedido: ");
    scanf("%d", &pedidos[*totalPedidos].idProduto);
    printf("Quantidade: ");
    scanf("%d", &pedidos[*totalPedidos].quantidade);
    strcpy(pedidos[*totalPedidos].status, "Pendente");
    
    (*totalPedidos)++;
    printf("Pedido registrado com sucesso!\n");

}

void calcularValorPedido(Pedido pedidos[], int totalPedidos, Produto cardapio[], int totalProdutos) {
    float valorTotal = 0.0;
    
    for(int i = 0; i < totalPedidos; i++) {
        for(int j = 0; j < totalProdutos; j++) {
            if(pedidos[i].idProduto == cardapio[j].id) {
                valorTotal += cardapio[j].preco * pedidos[i].quantidade;
            }
        }
    }
    
    printf("\n--- VALOR TOTAL DO PEDIDO ---\n");
    printf("Valor Total: R$ %.2f\n", valorTotal);
}

