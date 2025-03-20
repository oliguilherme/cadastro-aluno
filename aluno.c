#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "aluno.h"

void cadastrarAluno(Aluno alunos[], int *qnt) {
    //Verifica se é possível cadastrar mais alunos
    if (*qnt >= MAX_ALUNOS) {
        printf("Capacidade máxima de alunos atingida. Não é possível cadastrar mais alunos.\n");
        return;
    }

    Aluno novoAluno;

    //Cadastro de alunos
    printf("Nome do aluno: ");
    fgets(novoAluno.nome, 101, stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';
    
    printf("ID de %s: ", novoAluno.nome);
    scanf("%d", &novoAluno.id);
    getchar();

    printf("Matricula de %s: ", novoAluno.nome);
    scanf("%d", &novoAluno.matricula);
    getchar();

    printf("Nota de %s: ", novoAluno.nome);
    scanf("%f", &novoAluno.nota);
    getchar();

    //Adiciona o novo aluno ao vetor alunos[]
    alunos[*qnt] = novoAluno;
    (*qnt)++;

    printf("\nAluno cadastrado com sucesso!\n");

}