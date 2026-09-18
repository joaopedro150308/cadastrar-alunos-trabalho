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
    char ***alunos = NULL;

    // Alocando memória para as estruturas
    alunos = malloc(sizeof(char**) * QUANT_INIT_ALUNOS);
    if(alunos == NULL) 
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for(int i = 0; i < QUANT_INIT_ALUNOS; i++)
    {
        alunos[i] = malloc(sizeof(char*) * 2); // Aloca espaço para o ponteiro matrz do aluno
        if(alunos[i] == NULL)
        {
            return 1;
        }
        alunos[i][0] = malloc(NOME_TAMANHO); // Alocando espaço para o nome
        alunos[i][1] = malloc(INFOS_TAMANHO); // Alocando espaço para as infos

        // Algorítimo de liberação de memória caso haja erro
        if(alunos[i][0] == NULL || alunos[i][1] == NULL)
        {
            for(int j = 0; j != i; j++)
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

    // Pequena escrita dos alunos lidos (DEMO)
    for(int i = 0; i < QUANT_INIT_ALUNOS; i++)
    {
        fgets(alunos[i][0], NOME_TAMANHO, stdin);
        alunos[i][0][strcspn(alunos[i][0], "\n")] = '\0';
    
        fgets(alunos[i][1], INFOS_TAMANHO, stdin);
        alunos[i][1][strcspn(alunos[i][1], "\n")] = '\0';
    }

    for(int i = 0; i < QUANT_INIT_ALUNOS; i++)
    {
        printf("Nome: %s\tInfos: %s\n", alunos[i][0], alunos[i][1]);
    }



    return 0;
}