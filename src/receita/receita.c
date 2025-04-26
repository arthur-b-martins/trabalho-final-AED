#include "receita.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Receita criaReceita(char nome[50]){
    Receita receita = malloc(sizeof(struct descritorReceita));
    if(!receita){
        printf("\nErro na alocação de memória");
        exit(1);
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
    if(!no){
        printf("\nErro na alocação de memória");
        exit(1);
    }

    no->ingrediente = ingredienteRecebido;

    if(receita->quantidadeIngredientes == 0){
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
    
    return 0;
}

void mostraReceita(Receita receita){
    if(!receita){
        printf("\nErro! Você precisa criar a receita primeiro.");
        return;
    }

    printf("\n==================================");
    printf("\n      %s", receita->nomeReceita);
    printf("\n==================================");

    printf("\n\nIngredientes: ");

    if(receita->quantidadeIngredientes == 0){
        printf("\nNão há ingredientes cadastrados.");
    }

    else{
        NoIngrediente noAtual = receita->inicio;

        while(noAtual != NULL){
            printf("\n%d - %s - %d %s ", 
                noAtual->ingrediente.codigo,
                noAtual->ingrediente.nomeIngrediente,
                noAtual->ingrediente.quantidade,
                noAtual->ingrediente.medida
            );

            if(noAtual->ingrediente.essencial == 1){
                printf("*");
            }

            noAtual = noAtual->proximo;
        }
    }

    printf("\n=================\n");
}