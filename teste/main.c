#include <stdio.h>
#include <stdlib.h> // Para system("cls") ou system("clear")
#include <unistd.h> // Para sleep() (Windows: use <windows.h>)

void efeitoTransicao() {
    printf("Carregando");
    for (int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout); // Atualiza a saída
        sleep(1); // Espera 1 segundo
    }
    system("cls"); // Windows -> "cls", Linux -> "clear"
}

int main() {
    int opcao;
    
    while (1) {
        printf("1. Opção A\n");
        printf("2. Opção B\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        efeitoTransicao();
        
        switch (opcao) {
            case 1:
                printf("Você escolheu a Opção A\n");
                break;
            case 2:
                printf("Você escolheu a Opção B\n");
                break;
            case 3:
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opção inválida\n");
        }
        
        sleep(2); // Dá tempo para ver o resultado antes de limpar
        system("cls");
    }
    
    return 0;
}