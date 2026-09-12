#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //pra usar booleanos
#include <string.h> // pra usar comandos de string

int main() {

    // coloca as variáveis aqui
    int menu, quant, qarch;

    bool run = false;

    char opt;
    char test;
    char item[150];
    char search[150];
    
    FILE *inv = fopen("inventory.txt", "r+");

    // coloca o código dentro do while, é pra fazer o loop
    while (1) {

        printf("================================\n");
        printf("      Controle de Estoque\n");
        printf("================================\n");
        printf("Selecione uma opção:\n");
        printf("1. Adicionar Item\n");
        printf("2. Remover Item\n");
        printf("3. Listar Estoque\n");
        printf("4. Sair\n");
        printf("Opção: ");

        do {

            scanf("%d", &menu);
            while(getchar() != '\n');

            switch (menu) {

                case 1:

                    printf("Digite o nome do item: ");
                    scanf("%s", item);
                    fprintf(inv, "%s\n", item);

                    printf("Digite a quantidade: ");
                    scanf("%d", &quant);
                    fprintf(inv, "%d\n", quant);

                    printf("Item adicionado com sucesso!\n");
                    break;

                case 2:

                    printf("Digite o nome do item: ");
                    scanf("%s",item);
                    
                    while(fscanf(inv, "%s",search) == 1){
                        if(strcmp(search, item) == 0){
                            fscanf(inv, "%d", &qarch);
                            printf("Digite a quantidade a ser removida: ");
                            scanf("%d",&quant);
                            if(qarch > quant){
                                 qarch -= quant;
                                 printf("Quantidade atualizada com sucesso!\n");
                            }else if(qarch == quant){
                                qarch = 0;
                                printf("Item removido do estoque!");
                            }else{
                                printf("Estoque insuficiente. Quantidade disponível: %d", qarch);
                            }

                            run = true;
                            break;
                        }
                    }
                    if(run == true) break;
                    else printf("Item não encontrado.\n");
                    
                    break;

                case 3:
                test = fgetc(inv);
                if(test == EOF){
                    printf("O estoque está vazio.");
                    break;
                }
                    ungetc(test, inv);
                    printf("=============================\n");
                    printf("        Estoque Atual\n");
                    printf("=============================\n");
                    while(fscanf(inv, "%s \n %d", item, &quant) == 2){
                        printf("Nome: %s\n",item);
                        printf("Quantidade: %d\n\n",quant);
                    }

                    break;

                case 4:
                    printf("Obrigado por usar o Controle de Estoques! Até a próxima.\n");
                    return 0;

                default:
                    printf("Opção inválida! Tente novamente.\n");
                    while (getchar() != '\n');
                    break;
            }

        } while (menu != 1 && menu != 2 && menu != 3 && menu != 4);

        while(getchar() != '\n');

        printf("Deseja realizar outra operação? (s/n): ");
        scanf("%c",&opt);

        if(opt == 'N' || opt == 'n'){
            printf("Obrigado por usar o Controle de Estoques! Até a próxima.");
            return 0;
        }else if(opt == 'S' || opt == 's') continue;

    }
    return 0;
}