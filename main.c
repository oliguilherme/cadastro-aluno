#include <stdio.h>
#include <stdlib.h>
#define MAX_ALUNOS 4


typedef struct {
    int id;
    char matricula[6];
    float nota;
    char nome[101];
} Aluno;

void imprimirInterface();
void processarOpcao(Aluno alunos[], int opcao, int *qnt);

void cadastrarAluno(Aluno alunos[], int *qnt);

int main() {
    system("cls");
    
    Aluno alunos[MAX_ALUNOS];
    int qnt = 0, id, opcao;
    float nota;

    do {   
        system("cls"); 

        imprimirInterface();
        scanf("%d", &opcao);
        getchar();
        processarOpcao(alunos, opcao, &qnt);

         printf("\nPressione ENTER para continuar...");
         getchar();
    } while (opcao != 5);

    return 0;
}

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
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("\nOpção inválida! Tente novamente.\n");
            break;
    }
}

void cadastrarAluno(Aluno alunos[], int *qnt) {

    if (*qnt >= MAX_ALUNOS) {
        printf("Capacidade máxima de alunos atingida. Não é possível cadastrar mais alunos.\n");
        return;
    }

    Aluno novoAluno;

    printf("Nome do aluno: ");
    fgets(novoAluno.nome, 101, stdin);
    //novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';
    
    getchar();
    printf("ID de %s: ", novoAluno.nome);
    scanf("%d", &novoAluno.id);

    getchar();
    printf("Matricula de %s: ", novoAluno.nome);
    fgets(novoAluno.matricula, 6, stdin);
    //novoAluno.matricula[strcspn(novoAluno.matricula, "\n")] = '\0';

    
    do {
        printf("Nota de %s: ", novoAluno.nome);
        scanf("%f", &novoAluno.nota);
    } while(novoAluno.nota < 0.0 || novoAluno.nota > 10.0);
    

    //Adiciona o novo aluno ao vetor alunos[]
    alunos[*qnt] = novoAluno;
    (*qnt)++;

    printf("\nAluno cadastrado com sucesso!\n");
}