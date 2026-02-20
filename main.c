#include <stdio.h>
#include "dados.h"

// Protótipos das funções (ou use um arquivo .h para elas)
void cadastrarProduto(Produto cardapio[], int *totalProdutos);
void listarCardapio(Produto cardapio[], int totalProdutos);
void registrarPedido(Pedido pedidos[], int *totalPedidos, Produto cardapio[], int totalProdutos);

int main() {
    Produto cardapio[50];
    Pedido pedidos[100];
    int totalProdutos = 0;
    int totalPedidos = 0;
    int opcao;

    do {
        printf("\n--- LANCHONETE SYSTEM ---\n");
        printf("1. Cadastrar Item no Cardápio\n");
        printf("2. Ver Cardápio\n");
        printf("3. Novo Pedido\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarProduto(cardapio, &totalProdutos);
                break;
            case 2:
                listarCardapio(cardapio, totalProdutos);
                break;
            case 3:
                if(totalProdutos == 0) {
                    printf("Cadastre um produto primeiro!\n");
                } else {
                    registrarPedido(pedidos, &totalPedidos, cardapio, totalProdutos);
                }
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}