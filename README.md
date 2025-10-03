# 📌 Biblioteca – Sistema de Gerenciamento
## 📚 Descrição do Projeto
- O sistema é uma aplicação console desenvolvida em linguagem C, que     simula as operações básicas de gerenciamento de uma      biblioteca. O programa permite o cadastro, consulta, empréstimo, devolução e remoção de livros, além de controlar os usuários que realizam empréstimos.

## 🧱 Estrutura de Dados
- O sistema utiliza as seguintes estruturas (structs) para organizar os dados:

    ### Pessoa
        - Nome: Nome da pessoa
        - CPF: Cadastro de Pessoa Física (identificador único)

    ### Livro
        - Título: Título do livro
        - Autor: Nome do autor
        - Ano de publicação: Ano em que o livro foi publicado
        - Código único (ID): Identificador único do livro
        - Quantidade disponível: Número de exemplares disponíveis (máximo: 10)
        - Vetor de pessoas: Lista de pessoas que realizaram empréstimos do livro
        - Contador de pessoas: Número de pessoas que emprestaram o livro

    ### Biblioteca
        - Vetor de livros: Lista de até 100 livros cadastrados
        - Contador de livros: Número total de livros cadastrados

## ⚙️ Funcionalidades
- O sistema oferece um menu interativo com as seguintes opções:
    - Cadastro de Livros
    - Cadastra novos livros (até 100)
    - Inicializa a quantidade disponível com o número de exemplares
    - Impede cadastro de livros com ID duplicado
    - Consulta de Livros
    - Lista todos os livros cadastrados
    - Busca um livro específico por ID
    - Empréstimo de Livros
    - Realiza empréstimo de exemplares
    - Atualiza a quantidade disponível
    - Registra a pessoa que realizou o empréstimo
    - Impede empréstimo se não houver exemplares disponíveis
    - Impede que a mesma pessoa empreste dois exemplares do mesmo livro
    - Devolução de Livros
    - Processa a devolução de exemplares
    - Atualiza a quantidade disponível
    - Remove a pessoa do vetor de empréstimos
    - Remoção de Livros
    - Remove um livro cadastrado do sistema
    - Encerrar o Programa
    - Finaliza a execução do sistema

## 🚀 Como Compilar e Executar
- Para compilar o programa, utilize um compilador C (como GCC):

## 👨‍💻 Desenvolvimento
- Este é um projeto individual que aplica os conceitos estudados em sala de aula:
    - Variáveis
    - Condicionais
    - Loops
    - Vetores
    - Funções
    - Structs
