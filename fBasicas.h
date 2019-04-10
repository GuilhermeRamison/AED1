
struct pessoas {
    char nome[20];
    int idade;
    int tel;
};

void *addPessoa(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p);
void *rmvPessoa(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p);
void buscarPessoa(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p);
void listarAgenda(void *pBuffer, int *menu, int *c, int *tp, struct pessoas *p);
