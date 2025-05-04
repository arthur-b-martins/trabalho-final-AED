#include "../receita/receita.h"
#include "livro.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Livro criaLivro(char nome[50]){
    Livro livro = (struct descritorLivro *)malloc(sizeof(struct descritorLivro));

    strcpy(livro->nome, nome);
    livro->inicio = NULL;
    livro->quantidadeReceitas = 0;

    return livro;
}

int insereReceita(Livro livro, Receita receita){
    if(!livro){
        return -1;
    }

    if(!receita){
        return -2;
    }

    receita->proxima = livro->inicio;
    livro->inicio = receita;
    livro->quantidadeReceitas++;

    return 0;
}

int removeReceita(Livro livro, int posicao){
    if(!livro){
        return -1;
    }

    if(livro->quantidadeReceitas == 0){
        return -2;
    }

    if(posicao < 1 || posicao > livro->quantidadeReceitas){
        return -3;
    }

    if(posicao == 1){
        Receita temp = livro->inicio;
        livro->inicio = temp->proxima;
        desalocaReceita(temp);
        return 0;
    }

    Receita atual = livro->inicio;
    int contador = 1;
    while((contador + 1) != posicao && atual->proxima != NULL){
        atual = atual->proxima;
        contador++;
    }

    if(!atual->proxima){
        return -4;
    }

    Receita temp = atual->proxima;
    atual->proxima = temp->proxima;

    desalocaReceita(temp);
    return 0;
}

Receita recebeReceita(Livro livro, int posicao){
    if(!livro){
        return NULL;
    }

    if(livro->quantidadeReceitas == 0){
        return NULL;
    }

    if(posicao < 1 || posicao > livro->quantidadeReceitas){
        return NULL;
    }

    Receita atual = livro->inicio;
    int contador = 1;
    while(contador != posicao && atual != NULL){
        atual = atual->proxima;
        contador++;
    }

    if(atual == NULL){
        return NULL;
    }

    return atual;
}

void mostraLivro(Livro livro){
    if(!livro){
        printf("\nErro! Você precisa criar o livro de receitas primeiro.");
        return;
    }

    printf("\n==================================");
    printf("\n      %s", livro->nome);
    printf("\n==================================");

    printf("\n\nReceitas:\n");

    if(livro->quantidadeReceitas == 0){
        printf("\nNão há receitas cadastrados.");
    }

    else{
        Receita noAtual = livro->inicio;

        int contador = 1;
        while(noAtual != NULL){
            printf("\n%d - %s", 
                contador,
                noAtual->nomeReceita
            );
            contador++;

            if(noAtual->favorita == 1){
                printf(" *");
            }

            noAtual = noAtual->proxima;
        }
    }

    printf("\n\n==================================\n");
}

void mostraFavoritas(Livro livro){
    if(!livro){
        printf("\nErro! Você precisa criar o livro de receitas primeiro.");
        return;
    }

    printf("\n==================================");
    printf("\n      %s", livro->nome);
    printf("\n==================================");

    printf("\n\nReceitas Favoritas:\n");

    if(livro->quantidadeReceitas == 0){
        printf("\nNão há receitas cadastrados.");
    }

    else{
        Receita noAtual = livro->inicio;

        int contador = 1;
        int temFavorito = 0;
        while(noAtual != NULL){
            if(noAtual->favorita == 1){
                temFavorito++;
                printf("\n%d - %s", 
                    contador,
                    noAtual->nomeReceita
                );
                printf(" *");
                
            }
        
            contador++;
            noAtual = noAtual->proxima;
        }

        if(temFavorito == 0){
            printf("\nNão há receitas favoritadas.");
        }
    }

    printf("\n\n==================================\n");
}