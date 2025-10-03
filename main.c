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

// Busca por ID.
int busca(Biblioteca bib, int id){

    // Condição para verificar se já tem algum livro cadastrado com esse ID,
    // caso já exista ele retorna o ID.
    for (int i = 0; i < bib.qtdLivros; i ++) if (bib.livros[i].id == id)return i;   

    // Se não achar ele retorna nada.
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
        // Id do Livro
        printf("Digite o Id: ");

        // Verifica se o Id que foi digitado é um número.
        if (scanf("%d", &newBook.id)){

            // Condição para verificar se ele digitou o ID menor que 0. 
            while (newBook.id < 1)
            {
                // Verifica se ele não digitou mais ou menos do que 10 exemplares.
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

    // Condição para verificar se o que o cara digitou é um número.
    do
    {
        // Quantidade Disponível.
        printf("Digite a Quantidade de Exemplares: ");

        // Verifica se o que foi digitado é um número.
        if (scanf("%d", &newBook.qtdDisponivel)){

            // Condição para verificar se ele digitou a quantidade certa de exemplares. 
            while (newBook.qtdDisponivel < 0 || newBook.qtdDisponivel > 10)
            {
                // Verifica se ele não digitou mais ou menos do que 10 exemplares.
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
        
}


// Lista todos livros.
void listaTodos(Biblioteca bib){

    // Lista Todos Livros da Biblioteca.
    for (int i = 0; i <  bib.qtdLivros; i++){
        printf("Livro %d\n", i + 1);
        printf("ID: %d\n", bib.livros[i].id);
        printf("Nome do Livro: %s\n", bib.livros[i].titulo);
        printf("Autor Livro: %s\n", bib.livros[i].autor);
        printf("Data de Publicacao (yyyy/mm/dd): %s\n", bib.livros[i].dataPubli);
        printf("Quantidade de Exemplares: %d\n", bib.livros[i].qtdDisponivel);
        printf("Quantidade de Livros Emprestados: %d\n\n", bib.livros[i].qtdPessoas);

    }
}


// Lista livros por ID.
void listaId(Biblioteca bib){

    int validoId = 0, buscaId;

    // Condição para verificar se o que o cara digitou é um número.
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

    int findId = busca(bib, buscaId);
    // Verifica se possui o livro que ele quer pelo ID.
    if (findId == -1)
    {
        printf("LIVRO NAO ENCONTRADO\n\n");
        return;
    }

    // Lista Todos Livros da Biblioteca.
    printf("Livro %d\n",findId);
    printf("ID: %d\n", bib.livros[findId].id);
    printf("Nome do Livro: %s\n", bib.livros[findId].titulo);
    printf("Autor Livro: %s\n", bib.livros[findId].autor);
    printf("Data de Publicacao (yyyy/mm/dd): %s\n", bib.livros[findId].dataPubli);
    printf("Quantidade de Exemplares: %d\n", bib.livros[findId].qtdDisponivel);
    printf("Quantidade de Livros Emprestados: %d\n\n", bib.livros[findId].qtdPessoas);
    printf("\n\n");  
}


// Função para consultar os livros.
void consulta(Biblioteca bib){

    int tipo = 0, valido = 0;

    // Verifica se possui algum livro registrado.
    if (bib.qtdLivros == 0)
    {
        printf("\nNENHUM LIVRO REGISTADRO NA BIBLIOTECA\n\n");
        return;
    } 

    // Loop para rodar o menu.
    do
    {        
        // Condição para verificar se o que o cara digitou é um número.
        do
        {
            // Pede para usuario escolher a opção..
            printf("================================================================\n");
            printf("                     2 - Consulta de Livro.                   \n\n");
            printf("1  - Lista Todos os Livro.                                      \n");
            printf("2  - Buscar um Livro Especifico por ID.                         \n");
            printf("3  - Sair.                                                      \n");
            printf("================================================================\n");
            // Opção do Menu
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

        // Define o que fazer com a opcao escolhida.
        switch (tipo)
        {
            // Cadastro de livros.   
            case 1:
            {            
                printf("===============================================================\n");
                printf("                   1 - Lista Todos os Livro.                   \n");      
                printf("===============================================================\n");
                listaTodos(bib);    
                break;               

            }

            //   
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
            printf("5  - Retorna o tamanho da string.                               \n");
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

            //   
            case 2:
            {
                consulta(bib);
                break;
            }

            //    
            case 3:
            {
                printf("===============================================================\n");
                printf("                   3 - Emprestimo de Livros.                   \n");      
                printf("===============================================================\n");

                break;
            }

            //    
            case 4:
            {
                printf("===============================================================\n");
                printf("                 4 - Devolução de Livros.                      \n");      
                printf("===============================================================\n");

                break;
            }

            //
            case 5:
            {
                printf("===============================================================\n");
                printf("                     5 - Remoção de Livros.                    \n");      
                printf("===============================================================\n");

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
    Menu();
    return 0;
}
