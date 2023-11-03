#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "editortextos.h"

int main() {

    lista *l = criar_lista();
    char opc = 'P';
    char adc[10], pal[30];

    while(opc != 'X' && strcmp(pal, "editor") != 0) {
        scanf(" %c %s", &opc, pal);
        switch(opc) {
            case 'I':
                insere_inicio(l, pal);
                break;
            case 'F':
                insere_final(l, pal);
                break;
            case 'A':
                insere_antes_cursor(l, pal);
                break;
            case 'D':
                insere_depois_cursor(l, pal);
                break;
            case'P':
                procura_pal(l, pal);
                break;
            case 'R':
                if(strcmp(pal, "atual") == 0) {
                    remove_pal(l);
                }
                break;
            case 'G':
                {
                    if (strcmp(pal, "inicio") == 0)
                        cursor_inicio(l);
                    else if (strcmp(pal, "fim") == 0)
                        cursor_fim(l);
                    else if (strcmp(pal, "prox") == 0)
                        cursor_prox(l);
                    else if (strcmp(pal, "ant") == 0)
                        cursor_ant(l);
                }
                break;
            case 'L':
                {
                    if (strcmp(pal, "texto") == 0) {
                        imprimir_lista(l);
                    }
                    else if (strcmp(pal, "palavra") == 0) {
                        imprimir_palavra(l);
                    }
                }
                break;
            default:
                continue;
        }
    }

    return 0;
}
