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