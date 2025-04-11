#include <stdio.h>
#include <string.h>
#include "biblioteca_encadeada.h"

int main() {
    Biblioteca b;
    inicializarBiblioteca(&b);

    int opcao;
    char titulo[MAX_TITULO], autor[MAX_AUTOR], isbn[MAX_ISBN], usuario[MAX_USUARIO], data[MAX_DATA];
    int ano;

    do {
        printf("\n==== MENU BIBLIOTECA (Encadeada) ====\n");
        printf("1. Cadastrar livro\n");
        printf("2. Consultar livro por ISBN\n");
        printf("3. Emprestar livro\n");
        printf("4. Devolver livro\n");
        printf("5. Listar todos os livros\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        
        for (int i = 0; i < 500; i++)
        {
            sprintf(titulo, "Livro %d", i);
            sprintf(autor, "Autor %d", i);
            sprintf(isbn, "ISBN%07d", i);
            cadastrarLivro(&b, titulo, autor, 2000 + (i % 24), isbn);
        }

        switch(opcao) {
            case 1:
                printf("Titulo: ");
                fgets(titulo, MAX_TITULO, stdin);
                titulo[strcspn(titulo, "\n")] = 0;

                printf("Autor: ");
                fgets(autor, MAX_AUTOR, stdin);
                autor[strcspn(autor, "\n")] = 0;

                printf("Ano: ");
                scanf("%d", &ano);
                getchar();

                printf("ISBN: ");
                fgets(isbn, MAX_ISBN, stdin);
                isbn[strcspn(isbn, "\n")] = 0;

                if (cadastrarLivro(&b, titulo, autor, ano, isbn))
                    printf("Livro cadastrado com sucesso!\n");
                else
                    printf("Erro ao cadastrar livro.\n");
                break;

            case 2:
                printf("ISBN do livro: ");
                fgets(isbn, MAX_ISBN, stdin);
                isbn[strcspn(isbn, "\n")] = 0;

                NoLivro* no = consultarLivroPorISBN(&b, isbn);
                if (no)
                    printf("%s | %s | %d | %s | %s\n", 
                        no->livro.titulo,
                        no->livro.autor,
                        no->livro.ano,
                        no->livro.isbn,
                        no->livro.status == DISPONIVEL ? "Disponível" : "Emprestado");
                else
                    printf("Livro nao encontrado.\n");
                
                break;

            case 3:
                printf("ISBN do livro: ");
                fgets(isbn, MAX_ISBN, stdin);
                isbn[strcspn(isbn, "\n")] = 0;

                printf("Usuario: ");
                fgets(usuario, MAX_USUARIO, stdin);
                usuario[strcspn(usuario, "\n")] = 0;

                printf("Data (DD/MM/AAAA): ");
                fgets(data, MAX_DATA, stdin);
                data[strcspn(data, "\n")] = 0;

                if (emprestarLivro(&b, isbn, usuario, data))
                    printf("Livro emprestado com sucesso!\n");
                else
                    printf("Nao foi possivel emprestar o livro.\n");
                break;

            case 4:
                printf("ISBN do livro: ");
                fgets(isbn, MAX_ISBN, stdin);
                isbn[strcspn(isbn, "\n")] = 0;

                if (devolverLivro(&b, isbn))
                    printf("Livro devolvido com sucesso!\n");
                else
                    printf("Nao foi possivel devolver o livro.\n");
                break;

            case 5:
                listarTodosLivros(&b);
                break;

            case 0:
                printf("Encerrando o programa.\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while(opcao != 0);

    destruirBiblioteca(&b);
    return 0;
}
