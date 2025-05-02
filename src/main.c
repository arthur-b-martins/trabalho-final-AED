#include "receita/receita.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
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
    Receita r = criaReceita(nome);

    int deuCerto = insereIngrediente(i,r);
    deuCerto = insereIngrediente(j,r);
    deuCerto = insereIngrediente(k,r);
    deuCerto = insereIngrediente(l,r);
    deuCerto = insereIngrediente(m,r);

    mostraReceita(r);
    mostraEssenciais(r);

    trocar(r,5,2);

    mostraReceita(r);
    mostraEssenciais(r);
    return 0;
}