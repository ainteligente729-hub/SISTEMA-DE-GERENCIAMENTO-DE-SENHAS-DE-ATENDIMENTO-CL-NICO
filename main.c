#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int idade;
    char genero;
    char gestante;
    char lactante;
    char especial;
    char obeso;
    char senha[10];
    char categoria[20];
    int atendido;
} Paciente;

void cadastrarPaciente(Paciente pacientes[], int *total, int *n, int *p, int *u);
void classificarPaciente(Paciente *paciente);
void gerarSenha(Paciente *paciente, int *n, int *p, int *u);
int proximaSenha(Paciente pacientes[], int total);
void consultarProxima(Paciente pacientes[], int total);
void chamarPaciente(Paciente pacientes[], int total);
void finalizarAtendimento(Paciente pacientes[], int total);
void mostrarPainel(Paciente pacientes[], int total);
void menu(void);

int main() {
    Paciente pacientes[MAX];

    int total = 0;
    int n = 0;
    int p = 0;
    int u = 0;
    int opcao;

    do {
        menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarPaciente(pacientes, &total, &n, &p, &u);
                break;

            case 2:
                consultarProxima(pacientes, total);
                break;

            case 3:
                chamarPaciente(pacientes, total);
                break;

            case 4:
                finalizarAtendimento(pacientes, total);
                break;

            case 5:
                mostrarPainel(pacientes, total);
                break;

            case 6:
                printf("\nPrograma encerrado.\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 6);

    return 0;
}

void menu(void) {
    printf("\n==============================\n");
    printf("   SISTEMA DE SENHAS CLINICA\n");
    printf("==============================\n");
    printf("1 - Cadastrar paciente\n");
    printf("2 - Consultar proxima senha\n");
    printf("3 - Chamar paciente\n");
    printf("4 - Finalizar atendimento\n");
    printf("5 - Mostrar painel\n");
    printf("6 - Sair\n");
    printf("==============================\n");
}

void cadastrarPaciente(Paciente pacientes[], int *total, int *n, int *p, int *u) {
    if (*total >= MAX) {
        printf("\nLimite de pacientes atingido.\n");
        return;
    }

    printf("\n===== CADASTRO =====\n");

    printf("Genero (F/M): ");
    scanf(" %c", &pacientes[*total].genero);

    printf("Idade: ");
    scanf("%d", &pacientes[*total].idade);

    pacientes[*total].gestante = 'N';

    if (pacientes[*total].genero == 'F' ||
        pacientes[*total].genero == 'f') {
        printf("E gestante? (S/N): ");
        scanf(" %c", &pacientes[*total].gestante);
    }

    printf("E lactante? (S/N): ");
    scanf(" %c", &pacientes[*total].lactante);

    printf("Possui necessidade especial? (S/N): ");
    scanf(" %c", &pacientes[*total].especial);

    printf("Possui condicao de obesidade? (S/N): ");
    scanf(" %c", &pacientes[*total].obeso);

    classificarPaciente(&pacientes[*total]);
    gerarSenha(&pacientes[*total], n, p, u);

    pacientes[*total].atendido = 0;

    printf("\nPaciente cadastrado!\n");
    printf("Categoria: %s\n", pacientes[*total].categoria);
    printf("Senha: %s\n", pacientes[*total].senha);

    (*total)++;
}

void classificarPaciente(Paciente *paciente) {
    if (paciente->idade > 80) {
        strcpy(paciente->categoria, "Urgente");
    }
    else if (
        paciente->gestante == 'S' || paciente->gestante == 's' ||
        paciente->lactante == 'S' || paciente->lactante == 's' ||
        paciente->especial == 'S' || paciente->especial == 's' ||
        paciente->obeso == 'S' || paciente->obeso == 's' ||
        (paciente->genero == 'F' || paciente->genero == 'f') &&
        paciente->idade >= 60 ||
        (paciente->genero == 'M' || paciente->genero == 'm') &&
        paciente->idade >= 65
    ) {
        strcpy(paciente->categoria, "Preferencial");
    }
    else {
        strcpy(paciente->categoria, "Normal");
    }
}

void gerarSenha(Paciente *paciente, int *n, int *p, int *u) {
    if (strcmp(paciente->categoria, "Urgente") == 0) {
        (*u)++;
        sprintf(paciente->senha, "U%03d", *u);
    }
    else if (strcmp(paciente->categoria, "Preferencial") == 0) {
        (*p)++;
        sprintf(paciente->senha, "P%03d", *p);
    }
    else {
        (*n)++;
        sprintf(paciente->senha, "N%03d", *n);
    }
}

int proximaSenha(Paciente pacientes[], int total) {
    int i;

    for (i = 0; i < total; i++) {
        if (pacientes[i].atendido == 0 &&
            strcmp(pacientes[i].categoria, "Urgente") == 0) {
            return i;
        }
    }

    for (i = 0; i < total; i++) {
        if (pacientes[i].atendido == 0 &&
            strcmp(pacientes[i].categoria, "Preferencial") == 0) {
            return i;
        }
    }

    for (i = 0; i < total; i++) {
        if (pacientes[i].atendido == 0 &&
            strcmp(pacientes[i].categoria, "Normal") == 0) {
            return i;
        }
    }

    return -1;
}

void consultarProxima(Paciente pacientes[], int total) {
    int posicao = proximaSenha(pacientes, total);

    if (posicao == -1) {
        printf("\nNao existem pacientes aguardando.\n");
    }
    else {
        printf("\nProxima senha: %s\n", pacientes[posicao].senha);
        printf("Categoria: %s\n", pacientes[posicao].categoria);
    }
}

void chamarPaciente(Paciente pacientes[], int total) {
    int posicao = proximaSenha(pacientes, total);
    int i;
    int existeAtendimento = 0;

    for (i = 0; i < total; i++) {
        if (pacientes[i].atendido == 1) {
            existeAtendimento = 1;
        }
    }

    if (existeAtendimento == 1) {
        printf("\nJa existe um paciente em atendimento.\n");
        return;
    }

    if (posicao == -1) {
        printf("\nNao existem pacientes aguardando.\n");
        return;
    }

    pacientes[posicao].atendido = 1;

    printf("\nSenha chamada: %s\n", pacientes[posicao].senha);
    printf("Categoria: %s\n", pacientes[posicao].categoria);
}

void finalizarAtendimento(Paciente pacientes[], int total) {
    int i;

    for (i = 0; i < total; i++) {
        if (pacientes[i].atendido == 1) {
            pacientes[i].atendido = 2;
            printf("\nAtendimento da senha %s finalizado.\n",
                   pacientes[i].senha);
            return;
        }
    }

    printf("\nNao existe paciente em atendimento.\n");
}

void mostrarPainel(Paciente pacientes[], int total) {
    int i;
    int urgentes = 0;
    int preferenciais = 0;
    int normais = 0;
    int emAtendimento = 0;

    printf("\n========== PAINEL ==========\n");

    for (i = 0; i < total; i++) {
        if (pacientes[i].atendido == 1) {
            printf("Em atendimento: %s\n", pacientes[i].senha);
            emAtendimento = 1;
        }
    }

    if (emAtendimento == 0) {
        printf("Em atendimento: nenhum\n");
    }

    printf("\nSenhas aguardando:\n");

    for (i = 0; i < total; i++) {
        if (pacientes[i].atendido == 0) {
            printf("%s ", pacientes[i].senha);

            if (strcmp(pacientes[i].categoria, "Urgente") == 0) {
                urgentes++;
            }
            else if (strcmp(pacientes[i].categoria, "Preferencial") == 0) {
                preferenciais++;
            }
            else {
                normais++;
            }
        }
    }

    printf("\n\nQuantidade em espera:\n");
    printf("Urgentes: %d\n", urgentes);
    printf("Preferenciais: %d\n", preferenciais);
    printf("Normais: %d\n", normais);

    printf("============================\n");
}
