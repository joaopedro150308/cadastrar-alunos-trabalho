#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOME_TAMANHO 64
#define INFOS_TAMANHO 20
#define MATRICULAS_TAMANHO 6

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
    int capacidade = QUANT_INIT_ALUNOS;
    int cap_antiga = capacidade;
    char ***alunos = NULL;
    
    int Cont_Matricula = 1;

    // Alocando memória para a estrutura
    
    alunos = malloc(sizeof(char**) * capacidade);
    if(alunos == NULL) 
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }
    // Fim alocação
    
    // Menu de seleção de funções
    // Conta a quantidade de alunos. Será usado como index.
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
                
                char buffer[NOME_TAMANHO];
                
                int Idade;
                char Turma, Matricula[6];

                // Pequena leitura dos alunos
                do
                {
                    limpar();
                    // alocando novo aluno
                    char **novo_aluno = malloc(sizeof(char*) * 2);
                    if(novo_aluno == NULL)
                    {
                        printf("Erro ao alocar aluno\n");
                        return 1;
                    }
                    novo_aluno[0] = malloc(NOME_TAMANHO);
                    novo_aluno[1] = malloc(INFOS_TAMANHO);
                    if(novo_aluno[0] == NULL || novo_aluno[1] == NULL)
                    {
                        free(novo_aluno[0]);
                        free(novo_aluno[1]);
                        free(novo_aluno);
                        printf("Erro ao alocar aluno\n");
                        return 1;
                    }
                    // Fim alocação

                    printf("\nDigite o nome do aluno %d (0 para sair): ", quant_alunos + 1);
                    fgets(buffer, NOME_TAMANHO, stdin);
                    buffer[strcspn(buffer, "\n")] = '\0'; 

                    // Verificando flag para sair
                    if(strcmp(buffer, "0") == 0)
                    {
                        free(novo_aluno[0]);
                        free(novo_aluno[1]);
                        free(novo_aluno);
                        break;
                    }

                    // Validando possível nome
                        // Se for vazio
                    if(strlen(buffer) == 0)
                    {
                        printf("\nNome inválido. Nada foi digitado.\n");
                        printf("Pressione ENTER para tentar novamente.\n");
                        getchar();

                        free(novo_aluno[0]);
                        free(novo_aluno[1]);
                        free(novo_aluno);
                        continue;
                    }

                    // Atribuindo nome ao aluno
                    strcpy(novo_aluno[0], buffer);

                    // Lendo idade do aluno
                    printf("Digite a idade do aluno %d: ", quant_alunos + 1);
                    scanf("%d", &Idade);
                    flush_in();
                    
                    // Validando idade
                    if(Idade < 3 || Idade > 18){
                        printf("\nIdade fora do intervalo aceito [3, 18]. Cadastro do aluno %d será reiniciado!\n", quant_alunos + 1);
                        printf("Pressione ENTER para tentar novamente.\n");
                        getchar();

                        free(novo_aluno[0]);
                        free(novo_aluno[1]);
                        free(novo_aluno);
                        continue;
                    }
                    
                    // Atribuindo turma com base na idade
                    if(Idade >= 3 && Idade < 6){
                    Turma = 'A';
                    }
                    
                    if(Idade > 5 && Idade < 16){
                    Turma = 'B';
                    }
                    
                    if(Idade > 15 && Idade < 19){
                    Turma = 'C';
                    }
                    
                    sprintf(Matricula, "%05d", Cont_Matricula);
                    
                    Cont_Matricula ++;
                    
                    sprintf(novo_aluno[1], "%s %d %c", Matricula, Idade, Turma);
                    
                    novo_aluno[1][strcspn(novo_aluno[1], "\n")] = '\0';

                    alunos[quant_alunos] = novo_aluno;
                    novo_aluno = NULL;

                    quant_alunos++;

                    // Algoritmo de realocação para expandir lista de alunos
                    if(quant_alunos == capacidade)
                    {
                        char ***nova_lista = NULL;
                        cap_antiga = capacidade;
                        capacidade *= 2; // Aumenta em cinco a quantidade de alunos

                        // Tentando Realocar e expandir alunos
                        nova_lista = realloc(alunos, sizeof(char**) * capacidade);
                        if(nova_lista == NULL)
                        {
                            printf("Erro ao realocar nova_lista.\n");
                            return 1;
                        }

                        alunos = nova_lista;
                    }

                    // Fim Realocação
                } while(1);
                // Fim cadastro
                break;
    
            case 2: // Remover
            
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

                    int id = 0;
                    // Algoritmo de remoção de alunos
                    id = quant_alunos + 1; // Um ID sempre inválido, para resetar o loop caso não seja lido
                    
                    // Algoritmo de exibição dos alunos
                    printf("%-4s | %-20s | %s\n\n", "ID", "INFOS", "NOME");
                    for(int i = 0; i < quant_alunos; i++)
                    {
                        printf("%-4d | %-20s | %s\n", i, alunos[i][1], alunos[i][0]);
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

                    printf("\nAluno removido: %s\n", temp[0]);
                    printf("Pressione ENTER para continuar.");
                    getchar();

                    // Libera o aluno que removido
                    free(temp[0]);
                    free(temp[1]);
                    free(temp);

                    quant_alunos--;
                    // Fim remoção

                } while(1);
                    
                break;
    
            case 3: 
            {

                // Mostrar
                limpar();

                if(quant_alunos <= 0)
                {
                    printf("Não é possível mostrar alunos. Não há nenhum aluno registrado.\n");
                    printf("Pressione ENTER para voltar ao menu.\n");
                    getchar();
                    break;
                }

                // Estruturas que guradarão as informações dos alunos
                char nomes[quant_alunos][NOME_TAMANHO];
                char matriculas[quant_alunos][MATRICULAS_TAMANHO];
                int idades[quant_alunos];
                char turmas[quant_alunos];

                char infosBuff[INFOS_TAMANHO];

                char *infoPtr = NULL;
                int info_i = 0; // index da informação

                // Separando cada informação usando strtok
                for(int i = 0; i < quant_alunos; i++)
                {
                    // Nomes
                    strcpy(nomes[i], alunos[i][0]);

                    // Separando infos
                    strcpy(infosBuff, alunos[i][1]);
                    info_i = 0;
                    infoPtr = strtok(infosBuff, " ");
                    while(infoPtr != NULL)
                    {
                        switch(info_i)
                        {
                            case 0:
                                sscanf(infoPtr, "%s", matriculas[i]);
                                break;

                            case 1:
                                sscanf(infoPtr, "%d", &idades[i]);
                                break;

                            case 2:
                                sscanf(infoPtr, "%c", &turmas[i]);
                                break;
                            }

                        infoPtr = strtok(NULL, " ");
                        info_i++;
                    }
                }
                infoPtr = NULL;

                // Algoritmo de exibição dos alunos
                printf("%-9s | %-5s | %5s | %s\n\n", "MATRICULA", "IDADE", "TURMA", "NOME");
                for(int i = 0; i < quant_alunos; i++)
                {
                    printf("%-9s | %-5d | %-5c | %s\n", matriculas[i], idades[i], turmas[i], nomes[i]);
                }
                printf("\nPressione ENTER para voltar ao menu.\n");
                getchar();
                // Fim exibição

                break;
            }

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
    for(int i = 0; i < quant_alunos; i++)
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