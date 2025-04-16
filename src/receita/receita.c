#include "receita.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Receita criaReceita(char nome[50]){
    Receita receita = malloc(sizeof(struct descritorReceita));
    if(!receita){
        pritnf("Erro na alocação de memória");
        exit;
    }

    strcpy(receita->nomeReceita, nome);
    receita->inicio = NULL;
    receita->quantidadeIngredientes = 0;

    return receita;
}

int insereIngrediente(Ingrediente ingredienteRecebido, Receita receita){
    if(!receita){
        return -1;        
    }

    NoIngrediente no = malloc(sizeof(struct noIngrediente));
    no->ingrediente = ingredienteRecebido;

    if(receita->quantidadeIngredientes = 0){
        receita->inicio = no;
        no->anterior = NULL;
        no->proximo = NULL;
        receita->quantidadeIngredientes++;
    }

    else {
        receita->inicio->anterior = no;
        no->proximo = receita->inicio;
        receita->inicio = no;
        receita->quantidadeIngredientes++;
    }
    
}