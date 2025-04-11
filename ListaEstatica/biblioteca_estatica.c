#include "biblioteca_estatica.h"
#include <stdio.h>
#include <string.h>

void inicializarBiblioteca(Biblioteca* b) {
    b->totalLivros = 0;
}

int cadastrarLivro(Biblioteca* b, char* titulo, char* autor, int ano, char* isbn) {
    if (b->totalLivros >= MAX_LIVROS) return 0;
    Livro* l = &b->livros[b->totalLivros++];
    strcpy(l->titulo, titulo);
    strcpy(l->autor, autor);
    l->ano = ano;
    strcpy(l->isbn, isbn);
    l->status = DISPONIVEL;
    l->usuario[0] = '\0';
    l->dataEmprestimo[0] = '\0';
    return 1;
}

void listarTodosLivros(Biblioteca* b) {
    for (int i = 0; i < b->totalLivros; i++) {
        Livro* l = &b->livros[i];
        printf("%s | %s | %d | %s | %s\n", l->titulo, l->autor, l->ano, l->isbn,
        l->status == DISPONIVEL ? "Disponível" : "Emprestado");
    }
}

int emprestarLivro(Biblioteca* b, char* isbn, char* usuario, char* data) {
    for (int i = 0; i < b->totalLivros; i++) {
        Livro* l = &b->livros[i];
        if (strcmp(l->isbn, isbn) == 0 && l->status == DISPONIVEL) {
            l->status = EMPRESTADO;
            strcpy(l->usuario, usuario);
            strcpy(l->dataEmprestimo, data);
            return 1;
        }
    }
    return 0;
}

int devolverLivro(Biblioteca* b, char* isbn) {
    for (int i = 0; i < b->totalLivros; i++) {
        Livro* l = &b->livros[i];
        if (strcmp(l->isbn, isbn) == 0 && l->status == EMPRESTADO) {
            l->status = DISPONIVEL;
            l->usuario[0] = '\0';
            l->dataEmprestimo[0] = '\0';
            return 1;
        }
    }
    return 0;
}

Livro* consultarLivroPorISBN(Biblioteca* b, char* isbn) {
    for (int i = 0; i < b->totalLivros; i++) {
        if (strcmp(b->livros[i].isbn, isbn) == 0)
            return &b->livros[i];
    }
    return NULL;
}
#ifndef BIBLIOTECA_ESTATICA_H
#define BIBLIOTECA_ESTATICA_H

#define MAX_LIVROS 100
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
    Livro livros[MAX_LIVROS];
    int totalLivros;
} Biblioteca;

void inicializarBiblioteca(Biblioteca* b);
int cadastrarLivro(Biblioteca* b, char* titulo, char* autor, int ano, char* isbn);
void listarTodosLivros(Biblioteca* b);
int emprestarLivro(Biblioteca* b, char* isbn, char* usuario, char* data);
int devolverLivro(Biblioteca* b, char* isbn);
Livro* consultarLivroPorISBN(Biblioteca* b, char* isbn);

#endif
