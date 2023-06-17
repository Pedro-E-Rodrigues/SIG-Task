typedef struct tarefa Tarefa;
struct tarefa {
    char nome[71];
    char id[6];
    char data_entrega[11];
    int status;
};

///Assinaturas tarefas

void modulotarefas(void);
char telatarefas(void);
void visualizartarefa(void);
void adicionartarefa(void);
void editartarefa(void);
void excluirtarefa(void);