#ifndef BIBLIOTECA_DINAMICA_H
#define BIBLIOTECA_DINAMICA_H

#define MAX_TITULO 100
#define MAX_AUTOR 100
#define MAX_ISBN 14
#define MAX_USUARIO 100
#define MAX_DATA 11

typedef enum {
    DISPONIVEL,
    EMPRESTADO
} StatusLivro;

typedef struct {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int ano;
    char isbn[MAX_ISBN];
    StatusLivro status;
    char usuario[MAX_USUARIO];
    char dataEmprestimo[MAX_DATA];
} Livro;

typedef struct {
    Livro* livros;
    int capacidade;
    int totalLivros;
} Biblioteca;

void inicializarBiblioteca(Biblioteca* b);
void destruirBiblioteca(Biblioteca* b);
int cadastrarLivro(Biblioteca* b, char* titulo, char* autor, int ano, char* isbn);
void listarTodosLivros(Biblioteca* b);
int emprestarLivro(Biblioteca* b, char* isbn, char* usuario, char* data);
int devolverLivro(Biblioteca* b, char* isbn);
Livro* consultarLivroPorISBN(Biblioteca* b, char* isbn);

#endif
