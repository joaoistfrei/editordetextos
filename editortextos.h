#define MAX 10
#ifndef EDITORTEXTOS_H
#define EDITORTEXTOS_H

typedef struct No no;
typedef struct Lista lista;

lista *criar_lista();
no *criar_no(char *palavra);

void insere_inicio(lista *, char *);
void insere_final(lista *, char *);
void insere_antes_cursor(lista *, char *);
void insere_depois_cursor(lista *, char *);
void procura_pal(lista *, char *);
void remove_pal(lista *);
void cursor_inicio(lista *);
void cursor_fim(lista *);
void cursor_prox(lista *);
void cursor_ant(lista *);
void imprimir_lista(lista *);
void imprimir_palavra(lista *);
void terminar(lista *);

#endif
