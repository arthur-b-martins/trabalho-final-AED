/*
TRABALHO FINAL DE AED1

ALUNOS: 

 - Arthur Borges Martins (12411BCC063)
 - Gustavo Luís de Siqueira Nascimento (12411BCC017)
 - Estevão Polom Gomes (12411BCC031)


Foi escolhido o tema "Livro de receitas"

*/



#include "receita/receita.h"
#include "livroDeReceitas/livro.h"
#include "dados/dados.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// funcao para que o segundo menu ficasse separado de uma maneira mais organiazda
void menu2(Receita receita){
    int opcao2;
    do{
        mostraReceita(receita);

        printf("\n\n====== MENU DE INGREDIENTES ======\n\n");
        printf("1. Adicionar Ingrediente\n");
        printf("2. Remover Ingrediente\n");
        printf("3. Trocar ingredientes\n");
        printf("4. Exibir ingredientes essênciais\n");
        printf("5. Substituir ingredientes\n");
        printf("6. Sair\n");
        printf("==================================\n");
        printf("\nDigite a opção desejada: ");
        setbuf(stdin, NULL);
        scanf("%d", &opcao2);

        switch (opcao2){
            case 1: {
                Ingrediente ing;
                char nming[50];
                char medida[50];
                int qtd, essencial;
                printf("\nDigite o nome do ingrediente que deseja adicionar:");
                setbuf(stdin, NULL);
                fgets(nming, 50, stdin);
                nming[strcspn(nming, "\n")] = '\0';

                printf("\nQual é a quantidade necessaria do ingrediente? ");
                scanf("%d", &qtd);

                printf("\nQual é a medida da quantidade? ");
                setbuf(stdin, NULL);
                fgets(medida, 50, stdin);
                medida[strcspn(medida, "\n")] = '\0';

                printf("\nO ingrediente é essencial?\n");
                printf("0. Não\n");
                printf("1. Sim\n");
                printf("Digite a opção desejada: ");
                scanf("%d", &essencial);

                strcpy(ing.nomeIngrediente, nming);
                ing.quantidade = qtd;
                strcpy(ing.medida,  medida);
                ing.essencial = essencial;

                int deuCerto = insereIngrediente(ing, receita);
                if(deuCerto == -2){
                    printf("\nErro na alocação de memória! Encerrando o programa...");
                    exit(1);
                }

                break;
            }
            case 2: {
                int cod;
                printf("\nDigite o Código do ingrediente que deseja remover: ");
                scanf("%d", &cod);

                int deuCerto = removeIngrediente(cod, receita);
                
                switch (deuCerto){
                    case -2:
                        printf("\nVocê não pode remover ingredientes de uma receita vazia.");
                        break;

                    case -3:
                        printf("\nVocê digitou um valor de código inválido.");
                        break;

                    case -4:
                        printf("\nCódigo não encontrado.");
                        break;

                    default:
                        break;
                }

                break;
            }
            case 3:{
                int cod1, cod2;
                printf("\nDigite o Código do primeiro ingrediente: ");
                scanf("%d", &cod1);
                printf("\nDigite o Código do segundo ingrediente: ");
                scanf("%d", &cod2);

                int deuCerto = trocar(receita, cod1, cod2);

                switch (deuCerto)
                {
                case -2:
                    printf("\nA receita não tem ingredientes suficientes.");
                    break;
                
                case -3:
                    printf("\nVocê digitou um valor inválido.");
                    break;

                case -4:
                    printf("\nUm ou ambos os códigos não foram encontrados.");
                    break;
                
                default:
                    break;
                }

                break;
            }
            
            case 4:{
                mostraEssenciais(receita);
                break;
            }

            case 5:{
                Ingrediente sub;
                char nmsub[50];
                char medidasub[50];
                int qtdsub, essencialsub, idsub;
                printf("\nDigite o Código do ingrediente que deseja substituir: ");
                scanf("%d", &idsub);

                printf("\nDigite o novo nome do ingrediente: ");
                setbuf(stdin, NULL);
                fgets(nmsub, 50, stdin);
                nmsub[strcspn(nmsub, "\n")] = '\0';

                printf("\nQual é a nova quantidade necessaria do ingrediente? ");
                scanf("%d", &qtdsub);

                printf("\nQual é a nova medida da quantidade? ");
                setbuf(stdin, NULL);
                fgets(medidasub, 50, stdin);
                medidasub[strcspn(medidasub, "\n")] = '\0';

                printf("\nO ingrediente é essencial?\n");
                printf("0. Não\n");
                printf("1. Sim\n");
                printf("\nDigite sua opção: ");
                scanf("%d", &essencialsub);

                strcpy(sub.nomeIngrediente, nmsub);
                sub.quantidade = qtdsub;
                strcpy(sub.medida,  medidasub);
                sub.essencial = essencialsub;

                int resultado = substituir(receita, idsub, sub);

                switch (resultado){
                case -2:
                    printf("\nA receita não tem ingredientes.");
                    break;
                
                case -3:
                    printf("\nCódigo não encontrado.");
                    break;

                default:
                    break;
                }

                break;
            }

            case 6:{
                printf("\nSaindo do Menu De Ingredientes...");
                break;
            }

            default:
                printf("\nOpção inválida! Tente novamente.");
        }

    } while (opcao2 != 6);
}

int main(){
    Livro livro = cadastrarDados(); // funcao para adicionar dados de teste 

    int opcao;
    
    do{
        mostraLivro(livro);
        printf("\n\n============== MENU ==============\n");
        printf("1. Adicionar receita\n");
        printf("2. Remover receita\n");
        printf("3. Ver receita\n");
        printf("4. Exibir receitas favoritas\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        setbuf(stdin, NULL);
        scanf("%d", &opcao);

        switch (opcao){
            case 1:{
                printf("\nDigite o nome da receita que deseja adicionar: ");
                char nomeReceita[50];
                setbuf(stdin, NULL);
                fgets(nomeReceita, 50, stdin);
                // tira o \n para nao bugar quando printar
                nomeReceita[strcspn(nomeReceita, "\n")] = '\0';
                setbuf(stdin, NULL);
                
                int fav;
                printf("Deseja favoritar essa receita?\n");
                printf("0. Não\n");
                printf("1. Sim\n");
                printf("Digite sua opção: ");
                scanf("%d", &fav);
                Receita t = criaReceita(nomeReceita, fav);
                
                if(!t){
                    printf("Erro na alocação de memória! Encerrando o programa...");
                    exit(1);
                }

                menu2(t);
                insereReceita(livro, t);
                break;
            }

            case 2:{
                printf("\nDigite o número da receita que deseja remover: ");
                int remv;
                scanf("%d", &remv);
                int deuCerto = removeReceita(livro, remv);

                switch (deuCerto)
                {
                case -2:
                    printf("\nO livro precisa de pelo menos uma receita para ser removida.");
                    break;
                
                case -3:
                    printf("\nVocê digitou um valor inválido.");
                    break;
                
                case -4: 
                    printf("\nNúmero não encontrado.");
                    break;

                default:
                    break;
                }

                break;
            }

            case 3:{
                printf("\nDigite o número da receita que deseja ver: ");
                int ver;
                scanf("%d", &ver);
                Receita temp = recebeReceita(livro,ver);
                
                if(!temp){
                    printf("\nErro! Verifique se foi inserido um valor válido.");
                    break;
                }

                menu2(temp);
                break;
            }
            case 4:{
                mostraFavoritas(livro);
                break;
            }
            case 5:{
                printf("\nSaindo do programa...\n");
                break;
            }
            default:
                printf("Opção inválida! Tente novamente.\n");
        }        
    } while (opcao != 5);

    
    
    return 0;
}