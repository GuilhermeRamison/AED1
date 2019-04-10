#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fBasicas.h"

void *addPessoa(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p) {
    *tp += 1;
    pBuffer = (void *) realloc(pBuffer, sizeof(*menu) + sizeof(*c) + sizeof(*tp) + (*tp) * sizeof(struct pessoas));
    menu = pBuffer;
	c = menu+1;
	tp = c+1;
    p = (int *) (tp+1);
    if(*tp > 1) p = (struct pessoas*) p+(*tp-1);

    printf("Digite o nome: ");
    scanf("%[^\n]s", p->nome);
    setbuf(stdin, NULL);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);
    setbuf(stdin, NULL);
    printf("Digite o telefone: ");
    scanf("%d", &p->tel);
    setbuf(stdin, NULL);
 
    return pBuffer;
}

void *rmvPessoa(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p) {
    struct pessoas *pBufferAUX, *auxP;

    pBuffer = (void *) realloc(pBuffer, sizeof(*menu) + sizeof(*c) + sizeof(*tp) + (2 * (*tp) * sizeof(struct pessoas) + sizeof(struct pessoas)));
    menu = pBuffer;
    c = menu+1;
	tp = c+1;
    p = tp+1;
    pBufferAUX = p+(*tp);
    memcpy(pBufferAUX, p, (*tp) * sizeof(struct pessoas));
    *menu = 0;
    auxP = pBufferAUX+(*tp);
    
    printf("Digite o nome da pessoa a ser removida: ");
    scanf("%[^\n]s", auxP->nome);
    setbuf(stdin, NULL);
    for(*c = 0;*c < *tp;pBufferAUX++) {
        if(strcmp(auxP->nome, pBufferAUX->nome) != 0) {
            memcpy(p, pBufferAUX, sizeof(struct pessoas));
            p++;
        } else {
            *menu += 1;
        }
        (*c)++;
    }

    *tp -= *menu;
    pBuffer = (void *) realloc(pBuffer, sizeof(*menu) + sizeof(*c) + sizeof(*tp) + (*tp) * sizeof(struct pessoas));
    menu = pBuffer;
    c = menu+1;
	tp = c+1;
    p = (struct pessoas *) (tp+1);

    return pBuffer;       
}

void buscarPessoa(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p) {
    struct pessoas *auxP;

    pBuffer = (void *) realloc(pBuffer, sizeof(*menu) + sizeof(*c) + sizeof(*tp) + (*tp + 1) * sizeof(struct pessoas));
    menu = pBuffer;
    c = menu+1;
	 tp = c+1;
    p = tp+1;
    auxP = p+(*tp);
    *menu = 0;
   
    printf("\t1 - Buscar por nome\n\t2 - Buscar por idade\n\t3 - Buscar por telefone\n");
    scanf("%d", menu);
    setbuf(stdin, NULL);

    switch (*menu) {
        case 1:
            printf("Digite o nome: ");
            scanf("%[^\n]s", auxP->nome);
            setbuf(stdin, NULL);
            for(*c = 0;*c < *tp; p++) {
                if(strcmp(auxP->nome, p->nome) == 0) {
                    printf("\tNome: %s\n\tIdade: %d\n\tTelefone: %d\n", p->nome, p->idade, p->tel);
                }
                (*c)++;
            }
            break;
        case 2:
            printf("Digite a idade: ");
            scanf("%d", &auxP->idade);
            setbuf(stdin, NULL);
            for(*c = 0;*c < *tp; p++) {
                if(auxP->idade == p->idade) {
                    printf("\tNome: %s\n\tIdade: %d\n\tTelefone: %d\n", p->nome, p->idade, p->tel);
                }
                (*c)++;
            }
            break;
        case 3:
            printf("Digite o telefone: ");
            scanf("%d", &auxP->tel);
            setbuf(stdin, NULL);
            for(*c = 0;*c < *tp; p++) {
                if(auxP->tel == p->tel) {
                    printf("\tNome: %s\n\tIdade: %d\n\tTelefone: %d\n", p->nome, p->idade, p->tel);
                }
                (*c)++;
            }
            break;
    }
    
    pBuffer = (void *) realloc(pBuffer, sizeof(*menu) + sizeof(*c) + sizeof(*tp) + (*tp) * sizeof(struct pessoas));
    menu = pBuffer;
    c = menu+1;
	tp = c+1;
    p = (struct pessoas *) (tp+1);
}

void listarAgenda(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p) {
    menu = pBuffer;
    c = menu+1;
	tp = c+1;
    p = (struct pessoas *) (tp+1);
	for(*c = 0;*c < *tp;(*c)++){
        printf("###Pessoa %d###\n", (*c+1));
        printf("Nome: %s\n", p->nome);
        printf("Idade: %d\n", p->idade);
        printf("Telefone: %d\n", p->tel);
        p++;
    }
}

