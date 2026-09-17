### CONTEXTUALIZAÇÃO DO PROBLEMA ###

A escola Alecrim Douorado é uma instituição sem fins lucrativos que destina seus esforços a fornecer educação básica a crianças, adolescentes e jovens adultos em situações de necessidades.

Essa instituição, porém, não é capaz de atender todo o público de sua comunidade. Nesse sentido, tornou-se necessário uma forma de cadastrar os alunos para ter um melhor controle da situação.

Sendo assim, a escola contará com a sua ajuda para desenvolver esse sitema de cadastro. Um analista de sistemas da sua equipe entrou em contato com a instituição, afim de compreender o seu problema e elicitar alguns requisitos. O artefato que contém a descrição do sistema está logo adiante. Leia-o e desenvolva o software.

### Descrição do software ###

O sistema deve contar com uma interface de tela de comando.

O sistema deve ser capaz de cadastrar alunos, mostrar alunos cadastrados até o momento e de remover alunos cadastrados enquanto o usuário desejar. O programa deverá encerrar apenas quando o usuário escolher a opção "sair".

Ao cadastrar, é necessário obter as seguintes informações de cada aluno: nome completo, número de matrícula e idade. Alunos diferentes podem ter nomes e idades iguais, mas nunca matrícula. Esta deve ser um código numérico de 5 digitos, por exemplo: 12345, 54321, 10001, 00002 e assim por diante. O sistema deve começar a contar os códigos de matrícula a partir de 00001.

Além disso, o sistema deve ser capaz de separar os alunos em turmas, representadas por uma letra e determinadas pela idade de cada. Para crianças maiores que 2 anos e menores que 6 anos, atribui-se a turma A; para maiores que 5 anos e menores que 16, a turma B; e, para maiores de 15 anos e menores que 19, a turma C. A turma é uma outra informação que deve contar no cadastro de cada aluno.

A quantidade de alunos que será cadastrada em um dia é desconhecida.