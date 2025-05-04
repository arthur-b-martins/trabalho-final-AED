#include "../receita/receita.h"
#include "../livroDeReceitas/livro.h"
#include <string.h>


Livro cadastrarDados(){
    Ingrediente i,j,k,l,m;

    strcpy(i.nomeIngrediente, "paprica");
    i.quantidade = 3;
    strcpy(i.medida, "pitadas");
    i.essencial = 0;


    strcpy(j.nomeIngrediente, "noz moscada");
    j.quantidade = 2;
    strcpy(j.medida, "nozes");
    j.essencial = 1;

    
    strcpy(k.nomeIngrediente, "arroz");
    k.quantidade = 2;
    strcpy(k.medida, "xícaras");
    k.essencial = 0;

    
    strcpy(l.nomeIngrediente, "salmão");
    l.quantidade = 350;
    strcpy(l.medida, "gramas");
    l.essencial = 0;

    
    strcpy(m.nomeIngrediente, "macarrão");
    m.quantidade = 1;
    strcpy(m.medida, "pacote");
    m.essencial = 1;
    
    char nome[50];
    strcpy(nome, "Macarrao ao molho branco");
    Receita r = criaReceita(nome, 1);

    strcpy(nome, "Carbonara");
    Receita r2 = criaReceita(nome, 0);

    strcpy(nome, "Lasanha de frango");
    Receita r3 = criaReceita(nome, 0);

    insereIngrediente(i,r);
    insereIngrediente(j,r);
    insereIngrediente(k,r);
    insereIngrediente(l,r2);
    insereIngrediente(m,r);

    strcpy(nome,"Livro da Paola Caçarola");
    Livro livro = criaLivro(nome);
    insereReceita(livro, r);
    insereReceita(livro, r2);
    insereReceita(livro, r3);

    return livro;
}