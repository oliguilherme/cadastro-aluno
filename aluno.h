#ifndef ALUNO_H
#define ALUNO_H
#define MAX_ALUNOS 5

typedef struct {
    int id;
    int matricula;
    float nota;
    char nome[101];
} Aluno;

void cadastrarAluno(Aluno alunos[], int *qnt);

#endif