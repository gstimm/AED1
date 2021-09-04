# LISTA DE EXERCÍCIOS 02 - AED1

## CONTATO

_Gabriel Schultz Timm<br>
gstimm@inf.ufpel.edu.br_

## EXERCÍCIO 5

• Faça um programa que armazene a informação de várias
pessoas.

• O programa só deve sair quando o usuário disser que não
deseja mais entrar com os dados de outra pessoa.

• Antes de sair o programa deve apresentar, de forma
organizada, os dados de todas as pessoas.

typedef struct { <br>
char nome[30]; <br>
int idade; <br>
int altura; <br>
} Pessoa; <br>

## EXERCÍCIO 7

1.  O programa deve armazenar no máximo 10 pessoas
2.  Todas as variáveis que forem usadas no programa deve ser ponteiros. A única exceção é o
    item 1 que deve ser uma variável global
    Pessoa pessoas[10].
3.  Os ponteiros devem apontar para um buffer chamado
    pBuffer
    onde os dados devem
    ser armazenados. Por exemplo, um contador para um for deve ser um ponteiro para
    int
    e o
    int
    vai ficar armazenado dentro de
    pBuffer
    .
4.  Não pode usar
    struct
    dentro do
    pBuffer
5.  Como sempre, entregar o código e o vídeo explicando o código, mostrando casos de
    teste e o resultado do
    DrMemory

## EXECUÇÃO

### MANUAL

- Primeiramente clone o repositório na sua máquina com `git clone https://github.com/gstimm/AED1.git`

- Em seguida, abra a pasta onde os arquivos estão localizados.

- Compile o código com `gcc nomeDoArquivo.c -o nomeDoArquivo`

- Rode o executável com `.\nomeDoArquivo.exe`

### AUTOMÁTICA

As configuações usadas no meu compilador estão na pasta `.vscode`.

À princípio, dentro da pasta principal do projeto, basta estar com o arquivo .c aberto e selecionado, e pressionar **F5** que a compilação e execução são feitas automaticamente.
