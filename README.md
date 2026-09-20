# Cadastrar Aluno

É um programa semi CRUD, que permite a realização de cadastro de alunos, assim como remover estes e mostrá-los.

O programa não conta com persistência de dados. É um software de cadastro meramente ilustrativo onde, ao final do programa, você tem uma estrutura "alunos" preenchida mas que não é salva.

O programa possui uma interface de tela de comando, com um menu de seleção para as funções.

## Sobre o projeto

Para o desenvolvimento desse programa, havia a seguinte condição inicial: usar ao menos cinco funções presentes na biblioteca <string.h>.

O projeto utilizá funções dessa biblioteca para tentar solucionar o seguinte problema: uma escola precisa fazer um cadastro de um número desconhecido de alunos. Cada aluno deve ter um conjunto de informações: nome, matrícula, idade e turma. Alunos diferentes podem ter o mesmo nome, mas nunca a mesma matrícula.

O nome e a idade dos alunos são lidos do usuário, enquanto a matrícula e a turma são definidas pelo programa. A primeira é um código numérico de 5 dígitos. Já a última é representada por uma letra maiúscula A, B ou C, definida com base na idade dos alunos.

Para determinar a turma, toma-se com base os seguintes interva-los:

- Turma A: (2, 6) anos
- Turma B: (5, 16) anos
- Turma C: (15, 19) anos

## Funcionalidades

- [1] Cadastrar alunos
- [2] Remover alunos
- [3] Mostrar alunos
- [4] Sair

## Tecnologias utilizadas

- C
- GCC
- Git
- Windows api
- Makefile

## Como compilar

Tendo a tecnologia **make** e estando na pasta geral do projeto **cadastrar-alunos-trabalho**, basta rodar no terminal:

    make app

O programa será compilado e seu executável, juntamente com os arquivos binários .o, estarão na pasta **build**.

## Como rodar

Uma vez tendo compilado com **make file**, basta rodar no terminal:

    build\app (no windows)

## Observações

- Pouca portabilidade
    O programa foi inicialmente desenvolvido no windows e, para que o app.exe rode com acentuação correta no cmd, foi necessário usar as tecnologias em <windows.h>. Portanto, sua portabilidade fica limitada

- Falta de persistência das informações
    Como dito anteriormente, o programa não salva nenhum tipo de informação.