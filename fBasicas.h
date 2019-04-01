
struct pessoas {
    char nome[20];
    int idade;
    int tel;
};

void addPessoa(void *pBuffer, int *menu, int *c, int *tp);
void rmvPessoa(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p);
void buscarPessoa(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p);