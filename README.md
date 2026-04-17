# Sistema de Gerenciamento de Lanchonete 
Aqui dentro contém um sistema de Gerenciamento de Lanchonete feito na linguagem C. 

Composição do código 
Abaixo estão os scripts sobre como foi feito o sistema de Gerenciamento de Lanchonete

<summary><b> Composição do Código </b></summary>

<details style="margin-left: 20px;">
<summary> dados.h </summary>

```r
#Essa parte contém todos aqueles dados que serão utiulizados antes da main acontecer ou seja desde de varivaeis globla, constantes e structs
#ifndef DADOS_H
#define DADOS_H

typedef struct {
    int id;
    char nome[50];
    float preco;
} Produto;

typedef struct {
    int idPedido;
    int idProduto;
    int quantidade;
    char status[20]; // "Pendente", "Preparando", "Entregue"
} Pedido;
#endif
```

</details> 
<details> 
<summary> gerenciamento.c </summary>

```r

#essa parte contém os protótipos e funções que usaremos na main
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
```

</details>
<details>
<summary> main.c </summary>

```r

#a própria main
#include <stdio.h>
#include "dados.h"
#include <locale.h>
#include <windows.h>

// Protótipos das funções (ou use um arquivo .h para elas)
void cadastrarProduto(Produto cardapio[], int *totalProdutos);
void listarCardapio(Produto cardapio[], int totalProdutos);
void registrarPedido(Pedido pedidos[], int *totalPedidos, Produto cardapio[], int totalProdutos);
void calcularValorPedido(Pedido pedidos[], int totalPedidos, Produto cardapio[], int totalProdutos);

int main() {

SetConsoleOutputCP(CP_UTF8);    

    Produto cardapio[50];
    Pedido pedidos[100];
    int totalProdutos = 0;
    int totalPedidos = 0;
    int opcao;

    do {
        printf("\n--- SISTEMA DA LANCHONETE ---\n");
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
                    calcularValorPedido(pedidos, totalPedidos, cardapio, totalProdutos);
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
```
