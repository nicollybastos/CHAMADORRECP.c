// REDE HOSPITALAR - CHAMADOR DE RECEPÇÃO

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct {
    char nome[50];
    char cpf[15];
    char exame[50];
} Paciente;

typedef struct {
    Paciente itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

void inicializarFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

int filaCheia(Fila *f) {
    return f->total == MAX;
}

int filaVazia(Fila *f) {
    return f->total == 0;
}

void adicionarPaciente(Fila *f, Paciente p) {
    if (filaCheia(f)) {
        printf("\nFila cheia! Não é possível adicionar mais pacientes.\n");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;

    printf("\nPaciente adicionado com sucesso!\n");
}

void chamarPaciente(Fila *f) {
    if (filaVazia(f)) {
        printf("\nFila vazia! Nenhum paciente para chamar.\n");
        return;
    }

    Paciente p = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->total--;

    printf("\nChamando paciente:\n");
    printf("Nome: %s\n", p.nome);
    printf("CPF: %s\n", p.cpf);
    printf("Exame: %s\n", p.exame);
}

void verTotal(Fila *f) {
    printf("\nTotal de pacientes na fila: %d\n", f->total);
}

int main() {
    Fila fila;
    inicializarFila(&fila);

    int opcao;

    do {
        printf("\n===== REDE HOSPITALAR - CHAMADOR DE RECEPÇÃO =====\n");
        printf("1 - Adicionar paciente\n");
        printf("2 - Chamar paciente\n");
        printf("3 - Ver total da fila\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch(opcao) {
            case 1: {
                Paciente p;

                printf("\nDigite o nome: ");
                fgets(p.nome, sizeof(p.nome), stdin);
                p.nome[strcspn(p.nome, "\n")] = 0;

                printf("Digite o CPF: ");
                fgets(p.cpf, sizeof(p.cpf), stdin);
                p.cpf[strcspn(p.cpf, "\n")] = 0;

                printf("Digite o exame: ");
                fgets(p.exame, sizeof(p.exame), stdin);
                p.exame[strcspn(p.exame, "\n")] = 0;

                adicionarPaciente(&fila, p);
                break;
            }

            case 2:
                chamarPaciente(&fila);
                break;

            case 3:
                verTotal(&fila);
                break;

            case 0:
                printf("\nEncerrando sistema...\n");
                break;

            default:
                printf("\nOpção inválida!\n");
        }

    } while(opcao != 0);

    return 0;
}
