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
	 c = menu+1;
	 tp = c+1;
    p = (struct pessoas *) (tp+1);
    *tp = 0;

    while(*menu != 5) {
		printf("##########MENU##########\n");
		printf("\t1 - Adicionar pessoa\n\t2 - Remover pessoa\n\t3 - Buscar pessoa\n\t4 - Listar agenda\n\t5 - Sair\n");
		scanf("%d", menu);
        setbuf(stdin, NULL);
		switch(*menu) {
			case 1:
				pBuffer = addPessoa(pBuffer, menu, c, tp, p);
				menu = pBuffer;
            c = menu+1;
            tp = c+1;
            p = (struct pessoas *) (tp+1);
				break;
			case 2:
				pBuffer = rmvPessoa(pBuffer, menu, c, tp, p);
				menu = pBuffer;
            c = menu+1;
            tp = c+1;
            p = (struct pessoas *) (tp+1);
				break;
			case 3:
				buscarPessoa(pBuffer, menu, c, tp, p);
				break;
			case 4:
				listarAgenda(pBuffer, menu, c, tp, p);
				break;
			case 5:
			   printf("Finalizando o programa...\n");
				break;
			default:
				printf("Opção inválida!");
		}
	}
	free(pBuffer);
	return 0;
}
