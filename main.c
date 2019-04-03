#include <stdio.h>
#include <stdlib.h>
#include "fBasicas.h"

int main() {
    //menu: opção de menu, c: contador, tp: total de pessoas, pBuffer: buffer, p: aponta para o início das structs pessoas
    int *menu, *c, *tp;
	void *pBuffer;
    struct pessoas *p;
	pBuffer = (void *) malloc(sizeof(*menu)+sizeof(*c)+sizeof(*tp));
	menu = pBuffer;
	c = ++menu;
	tp = ++c;
    p = (struct pessoas *) tp;
    *tp = 0;

    while(*menu != 5) {
		printf("##########MENU##########\n");
		printf("\t1 - Adicionar pessoa\n\t2 - Remover pessoa\n\t3 - Buscar pessoa\n\t4 - Sair\n");
		scanf("%d", menu);
        setbuf(stdin, NULL);
		switch(*menu) {
			case 1:
				addPessoa(pBuffer, menu, c, tp);
				break;
			case 2:
				rmvPessoa(pBuffer, menu, c, tp, p);
				break;
			case 3:
				buscarPessoa(pBuffer, menu, c, tp, p);
				break;
			case 4:
				//listarAgenda(pBuffer, menu, c, tp, p);
				break;
			case 6:
				free(pBuffer);
				break;
			default:
				printf("Opção inválida!");
		}
	}
	return 0;
}
