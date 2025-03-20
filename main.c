#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "menu.h"
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