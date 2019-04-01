#include <stdio.h>
#include <stdlib.h>
#include "fBasicas.h"

void addPessoa(void *pBuffer, int *menu, int *c, int *tp) {
    struct pessoas *p;
    if(*tp == 0){
        pBuffer = (void *) realloc(pBuffer, sizeof(*menu) + sizeof(*c) + sizeof(*tp) + sizeof(struct pessoas));
        menu = pBuffer;
	    c = ++menu;
	    tp = ++c;
        p = (struct pessoas *) ++tp;
    } else {
        pBuffer = (void *) realloc(pBuffer, sizeof(*menu) + sizeof(*c) + sizeof(*tp) + (*tp + 1) * sizeof(struct pessoas));
        menu = pBuffer;
	    c = ++menu;
	    tp = ++c;
        p = (struct pessoas *) ++tp + (*tp * sizeof(struct pessoas));
    }
    printf("Digite o nome:");
    scanf("%[^\n]s", p->nome);
    setbuf(stdin, NULL);
    printf("Digite a idade:");
    scanf("%d", p->idade);
    setbuf(stdin, NULL);
    printf("Digite o telefone:");
    scanf("%d", p->tel);
    setbuf(stdin, NULL);

    p = (struct pessoas *) ++tp;
    *tp +=1;
}

void rmvPessoa(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p) {

}

void buscarPessoa(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p) {
    struct pessoas *auxP;
    pBuffer = (void *) realloc(pBuffer, sizeof(*menu) + sizeof(*c) + sizeof(*tp) + (*tp + 1) * sizeof(struct pessoas));
    menu = pBuffer;
    c = ++menu;
	tp = ++c;
    p = (struct pessoas *) ++tp;
    auxP = p + (*tp * sizeof(struct pessoas));

    printf("\t1 - Buscar por nome\n\t2 - Buscar por idade\n\t3 - Buscar por telefone\n");
    scanf("%d", menu);

    switch (*menu) {
        case 1:
            printf("Digite o nome:");
            scanf("%[^\n]s", auxP->nome);
            setbuf(stdin, NULL);
            for(*c = 0;*c < *tp; p++) {
                if(auxP->nome == p->nome) {
                    printf("\tNome: %s\n\tIdade: %d\n\tTelefone: %d\n", p->nome, p->idade, p->tel);
                }
            }
            break;
        case 2:
            printf("Digite a idade:");
            scanf("%d", auxP->idade);
            setbuf(stdin, NULL);
            for(*c = 0;*c < *tp; p++) {
                if(auxP->idade == p->idade) {
                    printf("\tNome: %s\n\tIdade: %d\n\tTelefone: %d\n", p->nome, p->idade, p->tel);
                }
            }
            break;
        case 3:
            printf("Digite o telefone:");
            scanf("%d", auxP->tel);
            setbuf(stdin, NULL);
            for(*c = 0;*c < *tp; p++) {
                if(auxP->tel == p->tel) {
                    printf("\tNome: %s\n\tIdade: %d\n\tTelefone: %d\n", p->nome, p->idade, p->tel);
                }
            }
            break;
    }
    
    pBuffer = (void *) realloc(pBuffer, sizeof(*menu) + sizeof(*c) + sizeof(*tp) + (*tp) * sizeof(struct pessoas));
    menu = pBuffer;
    c = ++menu;
	tp = ++c;
    p = (struct pessoas *) ++tp;
}