#include "receita.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Receita criaReceita(char nome[50]){
    Receita receita = malloc(sizeof(descritorReceita));
    if(!receita){
        pritnf("Erro na alocação de memória");
        exit;
    }

    strcpy(receita->nomeReceita, nome);
    receita->inicio = NULL;
    receita->final = NULL;
    receita->quantidadeIngredientes = 0;

    return receita;
}