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
        receita->final = no;
        no->anterior = NULL;
        no->proximo = NULL;
        receita->quantidadeIngredientes++;
    }

    else {
        receita->final->proximo = no;
        no->proximo = NULL;
        no->anterior = receita->final;
        receita->final = no;
        receita->quantidadeIngredientes++;
    }
    
    no->ingrediente.codigo = receita->quantidadeIngredientes;

    return 0;
}

int removeIngrediente(int id, Receita receita){
    if(!receita){
        return -1;
    }

    if(receita->quantidadeIngredientes == 0){
        return -2;
    }

    if(id > receita->quantidadeIngredientes){
        return -3;
    }

    NoIngrediente temp = receita->inicio;

    // percorre até achar o ingrediente
    while(temp != NULL && temp->ingrediente.codigo != id){
        temp = temp->proximo;
    }
    
    //se não encontrou
    if(temp == NULL){
        return -4;
    }
    
    //se não é o primeiro
    if(temp->anterior){
        temp->anterior->proximo = temp->proximo;
    }

    //se é o primeiro
    else{
        receita->inicio = temp->proximo;
    }

    //se não é o ultimo
    if(temp->proximo){
        temp->proximo->anterior = temp->anterior;
    }

    //se é o ultimo
    else{
        receita->final = temp->anterior;
    }


    //arruma os próximos códigos 
    while(temp != NULL){
        temp->ingrediente.codigo--;
        temp = temp->proximo;
    }

    free(temp);
    receita->quantidadeIngredientes--;
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

    printf("\n\nIngredientes:\n");

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

    printf("\n\n==================================\n");
}