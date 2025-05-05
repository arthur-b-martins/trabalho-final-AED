
# 📘 Trabalho Final de AED1 – Livro de Receitas

Repositório do trabalho final da disciplina **Algoritmos e Estruturas de Dados I (AED1)**.

O tema escolhido foi **\"Livro de Receitas\"**, onde foi desenvolvida uma estrutura composta por:

- Uma **lista simplesmente encadeada** representando o *livro de receitas*.
- Cada receita no livro é, por sua vez, uma **lista duplamente encadeada de ingredientes**.

---

## 👨‍🏫 Alunos

- Arthur Martins  
- Gustavo Luis  
- Estevão  

---

## 📁 Estrutura do Projeto

### \src – Códigos-fonte  
Contém os códigos-fonte do programa, organizados da seguinte forma:

- \main.c – Arquivo principal.  
- **Pastas de bibliotecas**:
  - \receita – Manipulação de uma receita (lista de ingredientes)  
    - \receita.h  
    - \receita.c
  - \livroDeReceitas – Manipulação do livro (lista de receitas)  
    - \livro.h  
    - \livro.c
  - \dados – Dados fixos (*hardcoded*) simulando persistência  
    - \dados.h  
    - \dados.c

---

### \build – Executável

Contém o arquivo **\programa.exe** , gerado após a compilação.

---

### \doc – Relatório

Contém o relatório final do projeto em formato PDF.

---

## ⚙️ Como compilar (Windows)

> Pré-requisitos:  
> - Ter o **MinGW** instalado (com **gcc** e **make** disponíveis no terminal).

1. Clone este repositório  
2. Abra o Prompt de Comando (CMD)  
3. Navegue até o diretório raiz do projeto  
4. Execute o comando:

``` 
mingw32-make
```

---

## ▶️ Como rodar o programa (Windows)

> Pré-requisitos:  
> - Ter o **MinGW** instalado (com **gcc** e **make** disponíveis no terminal).

Importante: Recomendado pois comando abaixo ajusta o terminal para utilizar **UTF-8**, evitando problemas com acentuação e caracteres especiais.

1. Clone este repositório  
2. Abra o Prompt de Comando (CMD)  
3. Navegue até o diretório raiz do projeto  
4. Execute o comando:

```
mingw32-make run
```

---

## 🛠️ Dependências

- [MinGW](http://www.mingw.org/) (GCC + Make)

---
