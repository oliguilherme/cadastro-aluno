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
void exibirAluno(Aluno alunos[], int *qnt);
void editarAluno(Aluno alunos[], int qnt, int id);


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
        getchar(); getchar();
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
    int id;
    switch (opcao) {
        case 1:
            cadastrarAluno(alunos, qnt);
            break;
        case 2:
            exibirAluno(alunos, qnt);
            break;
        case 3:
            printf("Informe o ID: ");
            scanf("%d", &id);
            editarAluno(alunos, qnt, id);
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
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = '\0';
    
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

void exibirAluno(Aluno alunos[],int *qnt){
    int i = 0;  

    if (*qnt == 0) {
        printf("Nenhum aluno cadastrado no sistema.\n");
    } else {
        do {
            printf("\nNome: %s", alunos[i].nome);
            printf("\nID: %d", alunos[i].id);
            printf("\nNota: %.2f", alunos[i].nota);
            printf("\nMatricula: %s", alunos[i].matricula);
            i++;        
        } while (i < *qnt); 
    }

    printf("Quantidade de alunos: %d", *qnt);//mostra quantidade de alunos
    
}

void editarAluno(Aluno alunos[], int qnt, int id) {
    int opcao;

    if (qnt == 0) {
        printf("Nenhum aluno cadastrado no sistema.\n");
    } else {
        for (int i = 0; i < qnt; i++) {
            if (id == alunos[i].id) {
                printf("Qual campo deseja alterar?\n");
                printf("1 - Nome\n2 - Matricula\n3 - Nota\n");
                scanf("%d", &opcao);
    
                switch (opcao) {
                    case 1:
                        printf("Nome atual: %s", alunos[i].nome);
                        printf("\nNovo nome: ");
                        fgets(alunos[i].nome, 101, stdin);
                        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = '\0';
                        break;
                    case 2:
                        printf("Matricula atual: %s", alunos[i].matricula);
                        printf("\nNova matricula: ");
                        fgets(alunos[i].matricula, 6, stdin);
                        getchar();
                        break;
                    
                    case 3:
                    getchar();
                        printf("Nota atual: %f", alunos[i].nota);
                        
                        do {
                            printf("\nNova nota: ");
                            scanf("%f", &alunos[i].nota);
                        } while(alunos[i].nota > 10.0 || alunos[i].nota < 0.0);
                        break;
                    
                    default:
                        break;
                }
            }
        } 
    }
}