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
                break;
    
            case 2: // Remover
                break;
    
            case 3: // Mostrar
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