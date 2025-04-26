#include "receita/receita.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){
    Ingrediente i,j;

    i.codigo = 1;
    strcpy(i.nomeIngrediente, "paprica");
    i.quantidade = 3;
    strcpy(i.medida, "pitadas");
    i.essencial = 0;


    j.codigo = 2;
    strcpy(j.nomeIngrediente, "noz moscada");
    j.quantidade = 2;
    strcpy(j.medida, "nozes");
    j.essencial = 1;
    
    char nome[50];
    strcpy(nome, "Macarrao ao molho branco");
    Receita r = criaReceita(nome);

    int deuCerto = insereIngrediente(i,r);
    if(deuCerto == -1){
        printf("erro");
    }

    
    deuCerto = insereIngrediente(j,r);
    if(deuCerto == -1){
        printf("erro");
    }

    mostraReceita(r);

    return 0;
}