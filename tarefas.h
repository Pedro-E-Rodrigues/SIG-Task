typedef struct tarefa Tarefa;
struct tarefa {
    char nome[71];
    char id[6];
    char data_entrega[11];
    int status;
};

///Assinaturas tarefas
void visualizar_tarefa(void);
void adicionar_tarefa(void);

void modulotarefas(void);
char telatarefas(void);
char* tela_visualizar_tarefa(void);
Tarefa* tela_adicionar_tarefa(void);
void tela_editar_tarefa(void);
void tela_excluir_tarefa(void);

void salvar_tarefa(Tarefa*);
Tarefa* buscar_Tarefa(char*);
void exibirTarefa(Tarefa*);
void regravarTarefa(Tarefa*);