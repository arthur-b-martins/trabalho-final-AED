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
    int essencial;
};

typedef struct ingrediente Ingrediente;

struct noIngrediente{
    Ingrediente ingrediente;
    struct noIngrediente *proximo;
    struct noIngrediente *anterior;
};

typedef struct noIngrediente* NoIngrediente;

// no descritor da receita
struct descritorReceita{
    char nomeReceita[50];
    NoIngrediente inicio;
    int quantidadeIngredientes; 
};

typedef struct descritorReceita* Receita;

Receita criaReceita(char nome[50]);
void inserirIngrediente(Ingrediente ingrediente, Receita receita);

#endif