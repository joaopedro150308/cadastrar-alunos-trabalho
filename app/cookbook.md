Esse arquivo guardará alguns algorítimos importantes do projeto

# Alocar alunos

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

# Dealocação dos alunos 

// Inicio dealocação
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

# Realocação

// Inicio realocação
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

# Leitura de alunos

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
