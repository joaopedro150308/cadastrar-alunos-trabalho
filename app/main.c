#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_TAMANHO 64
#define INFOS_TAMANHO 20

// É a quantidade inicial mínima de alunos.
#define QUANT_INIT_ALUNOS 2

void flush_in()
{
    int ch = 0;
    do
    {
        ch = fgetc(stdin);
    } while(ch != EOF && ch != '\n');
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
    
    // Conta a quantidade de alunos. Será usado como index.
    int cont_al = 0;
    char buffer[NOME_TAMANHO];

    // Pequena leitura dos alunos
    do
    {
        printf("Digite o nome do aluno %d: ", cont_al);
        fgets(buffer, NOME_TAMANHO, stdin);
        buffer[strcspn(buffer, "\n")] = '\0'; 

        if(strcmp(buffer, "sair") == 0)
        {
            break;
        }
        strcpy(alunos[cont_al][0], buffer);

        printf("Digite as informações do aluno %d: ", cont_al);
        fgets(alunos[cont_al][1], INFOS_TAMANHO, stdin);
        alunos[cont_al][1][strcspn(alunos[cont_al][1], "\n")] = '\0';

        cont_al++;

        // Algoritmo de realocação para expandir lista de alunos
        if(cont_al == tamanho)
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
    
    for(int i = 0; i < cont_al; i++)
    {
        printf("Nome: %s\tInfos: %s\n", alunos[i][0], alunos[i][1]);
    }



    

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