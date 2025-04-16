/*
Biblioteca feita para manipular uma lista duplamente encadeada 
de ingredientes, que juntos formam uma receita
*/
#ifndef RECEITA_H
#define RECEITA_H

//struct do no de cada ingrediente na lista
struct ingrediente{
    int codigo;
    char nomeIngrediente[50];
    int quantidade;
    char medida[50];
    bool essencial;
    struct ingrediente *proximo;
    struct ingrediente *anterior;
};

typedef struct ingrediente* Ingrediente;

// no descritor da receita
struct descritorReceita{
    char nomeReceita[50];
    Ingrediente inicio;
    Ingrediente final;
    int quantidadeIngredientes; 
};

typedef struct descritorReceita* Receita;

#endif