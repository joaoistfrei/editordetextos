#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editortextos.h"
typedef struct No {
    char palavra[MAX];
    struct No *prox;
    struct No *ant;
} no;

typedef struct Lista {
    no *comeco;
    no *cursor;
} lista;

lista *criar_lista() {
    lista *p = (lista*) calloc(1, sizeof(lista));
    p->comeco = NULL;
    p->cursor = NULL;

    return p;
}

no *criar_no(char *pal) {
    no *novo = (no*) calloc(1, sizeof(no));
    strcpy(novo->palavra, pal);
    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

void insere_inicio(lista *l, char *pal) {
    no *novo = criar_no(pal);
    if(l->comeco != NULL) {
        l->comeco->ant = novo;
        novo->prox = l->comeco;
    }
    l->comeco = novo;
    l->cursor = novo;

    return;
}

void insere_final(lista *l, char *pal) {
    if(l->comeco == NULL) {
        l->comeco = criar_no(pal);
        l->cursor = l->comeco;
    }
    else {
        while(l->cursor->prox != NULL) {
            l->cursor = l->cursor->prox;
        }
        no *novo = criar_no(pal);
        novo->ant = l->cursor;
        l->cursor->prox = novo;
        l->cursor = novo;
        }
}

void insere_antes_cursor(lista *l, char *pal) {
    no *novo = criar_no(pal);
    if (l == NULL) {
        return;
    }
    if (l->comeco == NULL) {
        l->comeco = novo;
        l->cursor = novo;
    } else if (l->cursor == l->comeco) {
        novo->prox = l->comeco;
        l->comeco->ant = novo;
        l->comeco = novo;
        l->cursor = novo;
    } else {
        novo->ant = l->cursor->ant;
        novo->prox = l->cursor;
        l->cursor->ant->prox = novo;
        l->cursor->ant = novo;
        l->cursor = novo;
    }
}


void insere_depois_cursor(lista *l, char *pal) {
    no *novo = criar_no(pal);
    if(l->comeco == NULL) {
        l->comeco = novo;
        l->cursor = novo;
        return;
    }
    if(l->cursor->prox != NULL) {
        novo->prox = l->cursor->prox;
        novo->prox->ant = novo;
    }
    novo->ant = l->cursor;
    l->cursor->prox = novo;
    l->cursor = novo;
    return;
}

void procura_pal(lista *l, char *pal) {
    if (l == NULL || l->comeco == NULL) {
        return;
    }

    no *busca = l->cursor;

    while (busca != NULL) {
        if (strcmp(pal, busca->palavra) == 0) {
            l->cursor = busca;
            return;
        }
        busca = busca->prox;
    }
}


void remove_pal(lista *l) {
    if(l->cursor == NULL) {
        return;
    }
    if(l->cursor->ant != NULL) {
        if(l->cursor->prox != NULL) {
            no *ref = l->cursor->prox;
            l->cursor = l->cursor->ant;
            ref->ant = l->cursor;
            free(l->cursor->prox);
            l->cursor->prox = ref;
            return;
        }
        if(l->cursor->prox == NULL) {
            l->cursor = l->cursor->ant;
            free(l->cursor->prox);
            l->cursor->prox = NULL;
            return;
        }
    }   
    if(l->cursor->ant == NULL) {
        if(l->cursor->prox != NULL) {
            l->cursor = l->cursor->prox;
            l->comeco = l->cursor;
            free(l->cursor->ant);
            l->cursor->ant = NULL;
            return;
        }
        if(l->cursor->prox == NULL) {
            l->cursor = NULL;
            l->comeco = NULL;
            return;
        }
    }
}

void cursor_inicio(lista *l) {
    if(l->comeco == NULL) {
        return;
    }
    l->cursor = l->comeco;
    return;
}

void cursor_fim(lista *l) {
    if(l->comeco == NULL) {
        return;
    }
    while(l->cursor->prox != NULL) {
        l->cursor = l->cursor->prox;
    }
    return;
}

void cursor_prox(lista *l) {
    if(l->comeco == NULL) {
        return;
    }
    if(l->cursor->prox != NULL) {
        l->cursor = l->cursor->prox;
    }
    return;
}

void cursor_ant(lista *l) {
    if(l->comeco == NULL || l->cursor->ant == NULL) {
        return;
    }
    if(l->cursor->ant != NULL) {
        l->cursor = l->cursor->ant;
        return;
    }
    return;
}

void imprimir_lista (lista *l) {
    if(l->comeco == NULL) {
        return;
    }
    no *ref = l->comeco;
    int contador = 1;
    while(ref->prox != NULL) {
        printf("%s ", ref->palavra);
        contador++;
        ref = ref->prox;
    }
    printf("%s", ref->palavra);
    printf("\n");
    return;
}

void imprimir_palavra (lista *l) {
    if(l->cursor == NULL) {
        return;
    }
    printf("%s", l->cursor->palavra);
    printf("\n");
    return;
}



