#include <stdio.h>
#include "aluno.h"

void imprimirInterface() {
    printf("=================================================================\n");
    printf("                 SISTEMA DE CADASTRO DE ALUNOS               \n");
    printf("=================================================================\n\n");
    printf("1 - Cadastrar\n2 - Exibir\n3 - Editar\n4 - Excluir\n5 - Sair\n\n");
    printf("=================================================================\n");
    printf("Escolha: ");
}

void processarOpcao(Aluno alunos[], int opcao, int *qnt) {
    switch (opcao) {
        case 1:
            cadastrarAluno(alunos, qnt);
            break;
        case 2:
            // Lógica para exibir alunos
            break;
        case 3:
            // Lógica para editar alunos
            break;
        case 4:
            // Lógica para excluir alunos
            break;
        case 5:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n");
            break;
    }
}