#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_TAMANHO 64
#define INFOS_TAMANHO 20

// É a quantidade inicial mínima de alunos.
#define QUANT_INIT_ALUNOS 5

void flush_in()
{
    int ch = 0;
    do
    {
        ch = fgetc(stdin);
    } while(ch != EOF && ch != '\n');
}

void limpar()
{
    printf("\033c");
}

int main()
{
    // Definindo a estrutura dos alunos
    int tamanho = QUANT_INIT_ALUNOS;
    int tamanho_antigo = tamanho;
    char ***alunos = NULL;

    // Alocando memória para a estrutura
    
    alunos = malloc(sizeof(char**) * QUANT_INIT_ALUNOS);
    if(alunos == NULL) 
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for(int i = 0; i < QUANT_INIT_ALUNOS; i++)
    {
        alunos[i] = malloc(sizeof(char*) * 2); // Aloca espaço para o ponteiro matrz do aluno
        alunos[i][0] = malloc(NOME_TAMANHO); // Alocando espaço para o nome
        alunos[i][1] = malloc(INFOS_TAMANHO); // Alocando espaço para as infos

        // Algorítimo de liberação de memória, caso haja erro de alocação
        if(alunos[i] == NULL || alunos[i][0] == NULL || alunos[i][1] == NULL)
        {
            for(int j = 0; j <= i; j++)
            {
                free(alunos[j][0]);
                free(alunos[j][1]);
                free(alunos[j]);
            }
            free(alunos);

            printf("Erro ao alocar memória.\n");
            return 1;
        }
    }
    // Fim alocação
    
    // Menu de seleção de funções
    int quant_alunos = 0;
    int opcao = -1;
    do
    {
        opcao = -1;
        limpar();
        printf("1 - Cadastrar alunos\n2 - remover alunos\n3 - Mostrar alunos\n4 - Sair\n");
        printf("Sua opção: ");
        scanf("%d", &opcao);
        flush_in();
    
        switch(opcao)
        {
            case 1: // Cadastrar
                // Conta a quantidade de alunos. Será usado como index.
                char buffer[NOME_TAMANHO];

                // Pequena leitura dos alunos
                do
                {
                    printf("Digite o nome do aluno %d: ", quant_alunos + 1);
                    fgets(buffer, NOME_TAMANHO, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0'; 

                    if(strcmp(buffer, "sair") == 0)
                    {
                        break;
                    }
                    strcpy(alunos[quant_alunos][0], buffer);

                    printf("Digite as informações do aluno %d: ", quant_alunos + 1);
                    fgets(alunos[quant_alunos][1], INFOS_TAMANHO, stdin);
                    alunos[quant_alunos][1][strcspn(alunos[quant_alunos][1], "\n")] = '\0';

                    quant_alunos++;

                    // Algoritmo de realocação para expandir lista de alunos
                    if(quant_alunos == tamanho)
                    {
                        char ***nova_lista = NULL;
                        tamanho_antigo = tamanho;
                        tamanho += 5; // Aumenta em cinco a quantidade de alunos

                        // Tentando Realocar e expandir alunos
                        nova_lista = realloc(alunos, sizeof(char**) * tamanho);
                        if(nova_lista == NULL)
                        {
                            return 1;
                        }

                        // Alocando para cada novo aluno
                        for(int i = tamanho_antigo; i < tamanho; i++)
                        {
                            nova_lista[i] = malloc(sizeof(char*) * 2); // Aloca espaço para o ponteiro matriz do aluno
                            nova_lista[i][0] = malloc(NOME_TAMANHO); // Alocando espaço para o nome
                            nova_lista[i][1] = malloc(INFOS_TAMANHO); // Alocando espaço para as infos

                            // Algorítimo de liberação de memória, caso haja erro de alocação
                            if(nova_lista[i] == NULL || nova_lista[i][0] == NULL || nova_lista[i][1] == NULL)
                            {
                                for(int j = 0; j <= i; j++)
                                {
                                    free(nova_lista[j][0]);
                                    free(nova_lista[j][1]);
                                    free(nova_lista[j]);
                                }
                                free(nova_lista);

                                printf("Erro ao alocar memória.\n");
                                return 1;
                            }
                        }

                        alunos = nova_lista;
                    }
                    // Fim Realocação
                } while(1);
                // Fim cadastro
                break;
    
            case 2: // Remover
                int id = 0;

                do // Remove alunos enquanto o usuário desejar
                {
                    limpar();

                    if(quant_alunos <= 0)
                    {
                        printf("Não é possível remover alunos. Não há nenhum aluno registrado.\n");
                        printf("Pressione ENTER para voltar ao menu.\n");
                        getchar();
                        break;
                    }

                    // Algoritmo de remoção de alunos
                    id = quant_alunos + 1; // Um ID sempre inválido, para resetar o loop caso não seja lido
                        // Algoritmo de exibição dos alunos
                    printf("%-4s | %-50s | %s\n\n", "ID", "NOME", "INFOS");
                    for(int i = 0; i < quant_alunos; i++)
                    {
                        printf("%-4d | %-50s | %s\n", i, alunos[i][0], alunos[i][1]);
                    }
                    printf("\n");
    
                        // Seleção de id
                    printf("Digite o ID do aluno que deseja remover (-1 para sair): ");
                    scanf("%d", &id);
                    flush_in();

                    if(id == -1)
                    {
                        break;
                    }

                        // Validando ID
                    if(id < 0 || id > quant_alunos-1)
                    {
                        printf("Id inválido. Digite um número entre 0 e %d.\n", quant_alunos-1);
                        printf("Pressione ENTER para continuar.");
                        getchar();
                        continue;
                    }

                        // Removendo da lista
                    char **temp = alunos[id];

                    for(int i = id; i < quant_alunos - 1; i++)
                    {
                        alunos[i] = alunos[i+1]; // Substitui o aluno no id dado e desloca os demais para a esquerda
                    }
                    free(temp[0]);
                    free(temp[1]);
                    free(temp);
                    tamanho--;

                    quant_alunos--;
                    printf("\nAluno removido.\n");
                    printf("Pressione ENTER para continuar.");
                    getchar();
                    // Fim remoção

                } while(1);
                
                break;
    
            case 3: // Mostrar
                limpar();

                if(quant_alunos <= 0)
                {
                    printf("Não é possível mostrar alunos. Não há nenhum aluno registrado.\n");
                    printf("Pressione ENTER para voltar ao menu.\n");
                    getchar();
                    break;
                }

                // Algoritmo de exibição dos alunos
                printf("%-4s | %-50s | %s\n\n", "ID", "NOME", "INFOS");
                for(int i = 0; i < quant_alunos; i++)
                {
                    printf("%-4d | %-50s | %s\n", i, alunos[i][0], alunos[i][1]);
                }
                printf("\nPressione ENTER para voltar ao menu.\n");
                getchar();
                // Fim exibição

                break;

            case 4: // Sair
                break;
            
            default: // Opção inválida
                printf("\nOpção inválida. Digite um número entre 1 e 4.\n");
                printf("Pressione ENTER para tentar novamente.");
                getchar();
        }

    } while(opcao != 4);
    // Fim menu



    // Alogrítimo de liberação de memória dos alunos
    for(int i = 0; i < QUANT_INIT_ALUNOS; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            free(alunos[i][j]);
        }
        free(alunos[i]);
    }
    free(alunos);
    alunos = NULL;
    // Fim dealocação

    return 0;
}