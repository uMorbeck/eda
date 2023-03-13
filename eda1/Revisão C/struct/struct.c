#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char titulo[50];
    char autor[50];
    char assunto[100];
    int id;
} Livros;

int main(){

    Livros livro;

    printf("Informe o titulo do livro\n");
    fgets(livro.titulo, 50, stdin);

    printf("Informe o autor do livro\n");
    fgets(livro.autor, 50, stdin);

    printf("Informe o assunto do livro\n");
    fgets(livro.assunto, 100, stdin);

    livro.id = rand();

    printf("\n\n%s\n%s\n%s\n%d\n", livro.titulo, livro.autor, livro.assunto, livro.id);

    return 0;
}
