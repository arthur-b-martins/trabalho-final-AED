# Trabalho final de AED1

Repositório do trabalho final da matéria de algritmos e estruturas de dados,
foi escolhido o tema "Livro de Receitas", onde se deve manipular uma lista 
simplesmente encadeadas de receitas (livro de receitas), sendo cada receita
uma lista duplamente encadeada de ingredientes.

Alunos:
- Arthur Martins
- Gustavo Luis
- Estevão  

# Estrutura

##   Src
  
  A pasta contém os códigos fonte do programa, na seguinte organização: 
  
  arquivo principal *main.c*,
  
  bibliotecas subdivididas em pastas:
   
   - receita - para manipulação de uma receita (lista de ingredientes)
      *receita.h*
      *receita.c*
   - livroDeReceitas - para manipulação do livro (lista de receitas)
      *livro.h*
      *livro.c*
   - dados - para cadastrar dados (hardcoded) simulando persistência
      *dados.h*
      *dados.c*

## Build

  A pasta contém o arquivo executável *programa.exe*

## Doc

  A pasta contém o relatório em pdf

# Como compilar

Windows

1 - Clone o repositório
2 - Abra o Cmd
3 - Navegue até o diretório do projeto
4 - Dê o comando ``` mingw32-make ```

Dependencias 
 - mingw (gcc, makefile)

# Como rodar 

Windows

1 - Clone o repositório
2 - Abra o Cmd
3 - Navegue até o diretório do projeto
4 - Dê o comando ``` mingw32-make run ```

Antes de rodar o executável, o comando irá setar o terminal
para usar UTF-8 e não ter problemas com caracteres,
portanto é recomendável que se execute o comando a cima, 
ao invés de apenas abrir o programa diretamente.

Dependencias 
 - mingw (gcc, makefile)

      
  
