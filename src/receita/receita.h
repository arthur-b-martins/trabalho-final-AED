/*
Biblioteca feita para manipular uma lista duplamente encadeada 
de ingredientes, que juntos formam uma receita
*/

#ifndef RECEITA_H
#define RECEITA_H

//struct dos valores dos ingredientes
struct ingrediente{
    int codigo;
    char nomeIngrediente[50];
    int quantidade;
    char medida[50];
    int essencial;
};

typedef struct ingrediente Ingrediente;

// struct do No da lista
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
    NoIngrediente final;
    struct descritorReceita* proxima;
    int favorita; 
    int quantidadeIngredientes; 
};

typedef struct descritorReceita* Receita;

Receita criaReceita(char nome[50], int favorita);
int insereIngrediente(Ingrediente ingredienteRecebido, Receita receita);
void mostraReceita(Receita receita);
int removeIngrediente(int id, Receita receita);
int trocar(Receita receita, int cod1, int cod2);
void mostraEssenciais(Receita receita);
int substituir(Receita receita, int cod, Ingrediente ingrediente);
void desalocaReceita(Receita receita);

#endif