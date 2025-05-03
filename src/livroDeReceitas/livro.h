#ifndef LIVRODERECEITAS_H
#define LIVRODERECEITAS_H

#include "../receita/receita.h"

struct descritorLivro{
    char nome[50];
    Receita inicio;
    int quantidadeReceitas;
};

typedef struct descritorLivro* Livro;

Livro criaLivro(char nome[50]);
int insereReceita(Livro livro, Receita receita);
int removeReceita(Livro livro, int posicao);
Receita recebeReceita(Livro livro, int posicao);
void mostraLivro(Livro livro);
void mostraFavoritas(Livro livro);

#endif