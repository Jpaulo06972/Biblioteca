#include <stdio.h>
#include <string.h>

/********************************************
 *                Estruturas.   
 ********************************************/
// Estrutura Pessoas.
typedef struct {
    char nome[50];
    int cpf;
} Pessoa;

// Estrutura Livros.
typedef struct {
    char titulo[50];
    char autor[50];
    char dataPubli[50];
    int id;
    int qtdDisponivel;
    int qtdPessoas;

    // Struct de Pessoas.
    Pessoa pf[10]; 
    
} Livro;

// Estrutura Biblioteca.
typedef struct {

    // Struct de Livros.
    Livro livros[100];    
    int qtdLivros;
    
} Biblioteca;


/********************************************
 *                 Funções.    
 ********************************************/

// Busca por ID do Livro.
int busca(Biblioteca bib, int id){

    // Condição para verificar se já tem algum livro cadastrado com esse ID,
    // caso já exista ele retorna o ID.
    for (int i = 0; i < bib.qtdLivros; i ++) if (bib.livros[i].id == id)return i;   

    // Se não achar ele retorna -1.
    return -1;
}

// Cadastrar Livros.
void cadastro(Biblioteca *bib){
    
    // Pega a struct livros para utilizar localmente
    // nesse bloco de função.
    Livro newBook;
    
    int validoId = 0, validoDisp = 0;

    // Condição para verificar se o que o cara digitou é um número.
    do
    {
        // Id do Livro.
        printf("Digite o Id: ");

        // Verifica se o Id que foi digitado é um número.
        if (scanf("%d", &newBook.id)){

            // Condição para verificar se ele digitou o ID menor que 0. 
            while (newBook.id < 1)
            {
                printf("\nVALOR INVALIDO - Digite Numeros Maior que 0!\n");  
                printf("Digite Novamente o ID: ");
                scanf("%d", &newBook.id);
                printf("\n");
            }
            // Se for um número sai fora do loop.
            validoId = 1;
        } else {
            while (getchar() != '\n'); // Limpa o buffer - Função indicada pelo chatGPT, pois quando fiz sem esse cara ele ficou no
                                       // loop infinito.
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n");            
        }

    } while (validoId == 0);
    
    // Chama função para verificar se aquele id já possui.
    if(busca(*bib, newBook.id) != -1)
    {
        printf("\nID INVALIDO\n");
        printf("ELE JA EXISTE\n\n");
        return;
    }

    // Título do Livro.
    printf("Digite o Titulo do Livro: ");
    scanf(" %[^\n]", newBook.titulo);

    // Autor do Livro.
    printf("Digite o Nome do Autor: ");
    scanf(" %[^\n]", newBook.autor);

    // Data de Publicação do Livro.
    printf("Digite a Data de Publicacao (yyyy/mm/dd): ");
    scanf(" %[^\n]", newBook.dataPubli);    

    // Condição para verificar se a quantidade de exemplares é um número.
    do
    {
        // Quantidade Disponível.
        printf("Digite a Quantidade de Exemplares: ");

        // Verifica se o que foi digitado é um número.
        if (scanf("%d", &newBook.qtdDisponivel)){

            // Condição para verificar se ele digitou a quantidade certa de exemplares. 
            while (newBook.qtdDisponivel < 1 || newBook.qtdDisponivel > 10)
            {
                // Verifica se ele não digitou mais 10 exemplares ou menos de um 1 exemplare.
                printf("\nVALOR INVALIDO - Digite no Maxima de 10 Exemplares!\n");  
                printf("Digite Novamente a Quantidade de Exemplares: ");
                scanf("%d", &newBook.qtdDisponivel);
                printf("\n");
            }
            // Se for um número sai fora do loop.
            validoDisp = 1;
        } else {
            while (getchar() != '\n'); // Limpa o buffer - Função indicada pelo chatGPT, pois quando fiz sem esse cara ele ficou no
                                       // loop infinito.
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n");            
        }
    } while (validoDisp == 0);  
    
    // Quando o livro é criado não tem nenhum emprestimo.
    newBook.qtdPessoas = 0;

    // Passa os cadastros do novo livro para 
    // a estrutura biblioteca.
    bib->livros[bib->qtdLivros] = newBook;

    // Altera o número de livros cadastrados.
    bib->qtdLivros++;
    
    printf("\nLivro Cadastrado com Sucesso!\n\n");

    return; 
}

// Lista todos os livros.
void listaTodos(Biblioteca bib){

    // Lista Todos os Livros da Biblioteca.
    for (int i = 0; i <  bib.qtdLivros; i++){
        printf("Livro %d\n", i + 1);
        printf("ID: %d\n", bib.livros[i].id);
        printf("Nome do Livro: %s\n", bib.livros[i].titulo);
        printf("Autor Livro: %s\n", bib.livros[i].autor);
        printf("Data de Publicacao (yyyy/mm/dd): %s\n", bib.livros[i].dataPubli);
        printf("Quantidade de Exemplares: %d\n", bib.livros[i].qtdDisponivel);
        printf("Quantidade de Livros Emprestados: %d\n\n", bib.livros[i].qtdPessoas);
    }
    return;
}

// Lista livros por ID.
void listaId(Biblioteca bib){

    int validoId = 0, buscaId;

    // Condição para verificar se o ID que ele digitou é um número.
    do
    {
        // Id do Livro
        printf("Digite o Id: ");

        // Verifica se o Id que foi digitado é um número.
        if (scanf("%d", &buscaId)){
            // Se for um número sai fora do loop.
            validoId = 1;
        } else {
            while (getchar() != '\n'); // Limpa o buffer - Função indicada pelo chatGPT, pois quando fiz sem esse cara ele ficou no
                                       // loop infinito.
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n");            
        }

    } while (validoId == 0);

    // Chama função para verificar se possui algum livro com esse ID.
    int findId = busca(bib, buscaId);

    // Verifica se ele retornou o ID do livro ou não acho nenhum livro.
    if (findId == -1)
    {
        printf("LIVRO NAO ENCONTRADO\n\n");
        return;
    }

    // Lista o Livro da Biblioteca que ele Deseja.
    printf("Livro %d\n",findId);
    printf("ID: %d\n", bib.livros[findId].id);
    printf("Nome do Livro: %s\n", bib.livros[findId].titulo);
    printf("Autor Livro: %s\n", bib.livros[findId].autor);
    printf("Data de Publicacao (yyyy/mm/dd): %s\n", bib.livros[findId].dataPubli);
    printf("Quantidade de Exemplares: %d\n", bib.livros[findId].qtdDisponivel);
    printf("Quantidade de Livros Emprestados: %d\n\n", bib.livros[findId].qtdPessoas);
    printf("\n\n");  

    return;
}

// Função para escolha da consulta dos livros.
void consulta(Biblioteca bib){

    int tipo = 0, valido = 0;

    // Verifica se possui algum livro registrado.
    if (bib.qtdLivros == 0)
    {
        printf("\nNENHUM LIVRO REGISTADRO NA BIBLIOTECA\n\n");
        return;
    } 

    // Loop para rodar o menu para consultar os livros.
    do
    {        
        // Condição para verificar se o que o cara digitou é um número.
        do
        {
            // Pede para usuario escolher a opção.
            printf("================================================================\n");
            printf("                     2 - Consulta de Livro.                   \n\n");
            printf("1  - Lista Todos os Livro.                                      \n");
            printf("2  - Buscar um Livro Especifico por ID.                         \n");
            printf("3  - Sair.                                                      \n");
            printf("================================================================\n");
            // Opção do Menu.
            printf("Digite sua opcao: ");

            // Verifica se a opcao que foi digitado é um número.
            if (scanf("%d", &tipo)){
                // Se for um número sai fora do loop.
                valido = 1;
            } else {
                while (getchar() != '\n'); // Limpa o buffer - Função indicada pelo chatGPT, pois quando fiz sem esse cara ele ficou no
                                        // loop infinito.
                printf("\nVALOR INVALIDO - Digite apenas numeros!\n");            
            }

        } while (valido == 0);

        printf("\n"); 

        // Condição para executar a escolha dele.
        switch (tipo)
        {
            // Lista todos os Livros.   
            case 1:
            {            
                printf("===============================================================\n");
                printf("                   1 - Lista Todos os Livro.                   \n");      
                printf("===============================================================\n");
                listaTodos(bib);    
                break;               

            }

            // Lista Apenas o Livro que ele Escolheu  
            case 2:
            {
                printf("===============================================================\n");
                printf("                   2 - Consulta de Livro.                      \n");      
                printf("===============================================================\n");
                listaId(bib);
                break;
            }

            // Sai do programa.
            case 3:
                printf("Voltando...\n\n");
                return;

            // Aviso para valor invalido.    
            default:
                printf("Valor Invalido Digite a Nova Opcao\n");
                printf("\n");
                break;
        }

    // Loop da Busca por Livros.    
    } while (tipo != 3);  
    
    return;
}

// Função de emprestimo. 
void emprestimo(Biblioteca *bib){

    // Pega a struct pessoas para utilizar localmente
    // nesse bloco de função.
    Pessoa newPeople;

    int validoId = 0, validoCpf = 0, buscaId;

    // Condição para verificar se o que o cara digitou é um número.
    do
    {
        // Id do Livro.
        printf("Digite o Id: ");

        // Verifica se o Id que foi digitado é um número.
        if (scanf("%d", &buscaId)){
            // Se for um número sai fora do loop.
            validoId = 1;
        } else {
            while (getchar() != '\n'); // Limpa o buffer - Função indicada pelo chatGPT, pois quando fiz sem esse cara ele ficou no
                                       // loop infinito.
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n");            
        }

    } while (validoId == 0);

    // Chama função para buscar livro.
    int findId = busca(*bib, buscaId);

    // Verifica se possui o livro que ele quer pelo ID.
    if (findId == -1)
    {
        printf("\nLIVRO NAO ENCONTRADO\n\n");
        return;
    }
    
    // Aviso caso todos os exemplares estejam emprestados.
    if ((bib->livros[findId].qtdDisponivel - bib->livros[findId].qtdPessoas) == 0){
        printf("\nNAO POSSUI LIVROS DISPONIVEIS\n");
        return;
    }

    // Condição para verificar se o que o cara digitou é um número.
    do
    {
        // CPF da Pessoa 
        printf("Digite seu CPF: ");

        // Verifica se o CPF que foi digitado é um número.
        if (scanf("%d", &newPeople.cpf)){
            // Se for um número sai fora do loop.
            validoCpf = 1;
        } else {
            while (getchar() != '\n'); // Limpa o buffer - Função indicada pelo chatGPT, pois quando fiz sem esse cara ele ficou no
                                       // loop infinito.
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n");            
        }

    } while (validoCpf == 0);

    // Loop para verificar se a pessoa já pegou emprestado algum exemplar deste livro.
    for (int i = 0; i < bib->livros[findId].qtdPessoas; i ++) {
        {
            // Condição para verificar se a pessoa já pegou emprestado este livro. 
            if (bib->livros[findId].pf[i].cpf == newPeople.cpf)
            {
                printf("\nCPF JA UTILIZADO - ESSA PESSOA JA PEGOU ESTE LIVRO EMPRESTADO\n\n");
                return;
            }
        } 
    }

    // VERIFICAÇÃO DE LIMITE - ADICIONAR AQUI
    if (bib->livros[findId].qtdPessoas >= 10) {
        printf("\nLIMITE DE EMPRESTIMOS PARA ESTE LIVRO ATINGIDO (MAXIMO 10 PESSOAS)\n\n");
        return;
    }

    // Caso a pessoa não tenha pegado esse livro ainda, ela deve digitar seu nome.
    printf("Digite seu Nome: ");
    scanf(" %[^\n]", newPeople.nome);

    // Registra a pessoa que pegou o livro emprestado.
    bib->livros[findId].pf[bib->livros[findId].qtdPessoas] = newPeople;

    // Aumenta a quantidade de pessoas que emprestaram o livro.
    bib->livros[findId].qtdPessoas ++;

    printf("\nEmprestimo Realizado com Sucesso\n\n");

    return; 
}

// Função de devolução. 
void devolucao(Biblioteca *bib){

    // Pega a struct pessoas para utilizar localmente
    // nesse bloco de função.
    int removePeople;

    int validoId = 0, validoCpf = 0, indicePessoa = -1, buscaId;

    // Condição para verificar se o que o cara digitou é um número.
    do
    {
        // Id do Livro.
        printf("Digite o Id: ");

        // Verifica se o Id que foi digitado é um número.
        if (scanf("%d", &buscaId)){
            // Se for um número sai fora do loop.
            validoId = 1;
        } else {
            while (getchar() != '\n'); // Limpa o buffer - Função indicada pelo chatGPT, pois quando fiz sem esse cara ele ficou no
                                       // loop infinito.
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n");            
        }

    } while (validoId == 0);

    // Chama função para buscar livro.
    int findId = busca(*bib, buscaId);

    // Verifica se possui o livro que ele quer pelo ID.
    if (findId == -1)
    {
        printf("\nLIVRO NAO ENCONTRADO\n\n");
        return;
    }

    // Aviso caso nao tenha nenhum livro emprestado.
    if ((bib->livros[findId].qtdPessoas) == 0){
        printf("\nNAO E POSSIVEL REMOVER - EXISTEM %d EMPRESTIMOS ATIVOS PARA ESTE LIVRO\n\n", bib->livros[findId].qtdPessoas);
        return;
    }

    // Condição para verificar se o que o cara digitou é um número.
    do
    {
        // CPF da Pessoa 
        printf("Digite seu CPF: ");

        // Verifica se o CPF que foi digitado é um número.
        if (scanf("%d", &removePeople)){
            // Se for um número sai fora do loop.
            validoCpf = 1;
        } else {
            while (getchar() != '\n'); // Limpa o buffer - Função indicada pelo chatGPT, pois quando fiz sem esse cara ele ficou no
                                       // loop infinito.
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n");            
        }

    } while (validoCpf == 0);

    // Loop para verificar se a pessoa pegou este livro emprestado.
    for (int i = 0; i < bib->livros[findId].qtdPessoas; i ++) {
        {
            // Condição para verificar se a pessoa pegou o emprestado este livro. 
            if (bib->livros[findId].pf[i].cpf == removePeople)
            { 
                // Flag para indicar que ele achou a pessoa que pegou o livro emprestado.
                indicePessoa = i;
                break;
            }
        } 
    }

    // Retorna caso não tenha encontrado a pessoa.
    if (indicePessoa == -1){
        printf("\nCPF NAO FOI ACHADO\n\n");
        return;
    }

    // Altera o vetor, para remanejar a estrutura.
    for (int i = indicePessoa; i < bib->livros[findId].qtdPessoas - 1; i ++){
        bib->livros[findId].pf[i] = bib->livros[findId].pf[i + 1];
    }
  
    // Diminiu a quantidade de pessoas que emprestaram o livro.
    bib->livros[findId].qtdPessoas --;
    printf("\nDevolucao realizada com sucesso!\n\n"); 
    return; 
}

// Remoção dos Livros.
void remocao(Biblioteca *bib){
        
    int remocao;
    int validoId = 0;

    // Condição para verificar se o que o cara digitou é um número.
    do
    {
        // Id do Livro
        printf("Digite o Id: ");

        // Verifica se o Id que foi digitado é um número.
        if (scanf("%d", &remocao)){

            // Condição para verificar se ele digitou o ID menor que 0. 
            while (remocao < 1)
            {
                printf("\nVALOR INVALIDO - Digite Numeros Maior que 0!\n");  
                printf("Digite Novamente o ID: ");
                scanf("%d", &remocao);
                printf("\n");
            }
            // Se for um número sai fora do loop.
            validoId = 1;
        } else {
            while (getchar() != '\n'); // Limpa o buffer - Função indicada pelo chatGPT, pois quando fiz sem esse cara ele ficou no
                                       // loop infinito.
            printf("\nVALOR INVALIDO - Digite apenas numeros!\n");            
        }

    } while (validoId == 0);
    
    // Chama função para buscar livro.
    int findId = busca(*bib, remocao);

    // Verifica se possui o livro que ele quer pelo ID.
    if (findId == -1)
    {
        printf("\nLIVRO NAO ENCONTRADO\n\n");
        return;
    }
    
    if (bib->livros[findId].qtdPessoas > 0) {
        printf("\nNAO E POSSIVEL REMOVER - EXISTEM %d EMPRESTIMOS ATIVOS PARA ESTE LIVRO\n\n", bib->livros[findId].qtdPessoas);
        return;
    }

    // Altera o vetor, para remanejar a estrutura.
    for (int i = findId; i < bib->qtdLivros - 1; i ++){
        bib->livros[i] = bib->livros[i + 1];
    }

    // Altera o número de livros cadastrados.
    bib->qtdLivros --;
    
    printf("\nLivro Removido com Sucesso!\n\n");

    return;
}

// Programa principal.
void Menu()
{
    // Variavel para rodar loop do menu.
    int opcao = 0, valido = 0;

    // Declaração da estrutura biblioteca.
    Biblioteca bib = {0};
    
    // Loop para rodar o menu.
    do
    {        
        // Condição para verificar se o que o cara digitou é um número.
        do
        {
            // Pede para usuario escolher a opção..
            printf("================================================================\n");
            printf("                              MENU                              \n");
            printf("1  - Cadastro de Livro.                                         \n");
            printf("2  - Consulta de Livro.                                         \n");
            printf("3  - Emprestimo de Livros.                                      \n");
            printf("4  - Devolucao de Livros.                                       \n");
            printf("5  - Remocao de Livros.                                         \n");
            printf("6  - Sair.                                                      \n");
            printf("================================================================\n");
            // Opção do Menu
            printf("Digite sua opcao: ");

            // Verifica se a opcao que foi digitado é um número.
            if (scanf("%d", &opcao)){
                // Se for um número sai fora do loop.
                valido = 1;
            } else {
                while (getchar() != '\n'); // Limpa o buffer - Função indicada pelo chatGPT, pois quando fiz sem esse cara ele ficou no
                                        // loop infinito.
                printf("\nVALOR INVALIDO - Digite apenas numeros!\n");            
            }

        } while (valido == 0);

        printf("\n"); 

        // Define o que fazer com a opcao escolhida.
        switch (opcao)
        {
            // Cadastro de livros.   
            case 1:
            {   if (bib.qtdLivros < 100){             
                    printf("===============================================================\n");
                    printf("                    1 - Cadastro de Livro.                     \n");      
                    printf("===============================================================\n");
                    cadastro(&bib);
                    break;
                } else {
                    printf("\nNAO EH POSSIVEL CADASTRAR MAIS UM LIVRO\n");  
                    printf("       QUANTIDADE ULTRAPASSADA\n\n"); 
                    break;
                } 
            }

            // Consulta dos livros.
            case 2:
            {
                consulta(bib);
                break;
            }

            // Empestimo dos livros.   
            case 3:
            {
                printf("===============================================================\n");
                printf("                   3 - Emprestimo de Livros.                   \n");      
                printf("===============================================================\n");
                emprestimo(&bib);
                break;
            }

            // Devolução do livro
            case 4:
            {
                printf("===============================================================\n");
                printf("                 4 - Devolução de Livros.                      \n");      
                printf("===============================================================\n");
                devolucao(&bib);
                break;
            }

            // Remoção do livro
            case 5:
            {
                printf("===============================================================\n");
                printf("                     5 - Remoção de Livros.                    \n");      
                printf("===============================================================\n");
                remocao(&bib);
                break;
            }

            // Sai do programa.
            case 6:
                printf("Saindo...\n");
                break;

            // Aviso para valor invalido.    
            default:
                printf("Valor Invalido Digite a Nova Opcao\n");
                printf("\n");
                break;
        }

    // Loop do Menu.    
    } while (opcao != 6);
}


/********************************************
 *                   Main.   
 ********************************************/
// Programa Principal.
int main()
{
    // Chama função de menu
    Menu();
    return 0;
}
