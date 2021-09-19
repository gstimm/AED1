# TRABALHO 1 - AGENDA - AED1

## CONTATO

_Gabriel Schultz Timm<br>
gstimm@inf.ufpel.edu.br_

## DESCRIÇÃO

Continuar a sua implementação da agenda (exercício 3) semana 1 dentro dos mesmo parâmetros, mas incluir o seguinte.

1. Nenhuma variável pode ser declarada em todo o programa, somente ponteiros. Todos os dados do programa devem ser guardados dentro do pBuffer.

2. Nem mesmo como parâmetro de função. Só ponteiros que apontam para dentro do pBuffer.

3. Exemplo do que não pode: int c; char a; int v[10]; void Funcao(int parametro)

4. Não pode usar struct em todo o programa.

5. Usar fila ordenada (heap) para armazenar as pessoas em ordem alfabética sempre que o usuário incluir uma nova pessoa.

6. Implementar a base de dados da agenda usando lista duplamente ligada

7. Somente essa base de dados pode ficar fora do buffer principal, ou seja, pode usar um malloc para cada nodo.

Seguir as orientações elaborados pelo monitor para código!

Entregar um vídeo explicando o código e mostrando alguns testes e ao final o resultado do DrMemory.

## EXECUÇÃO

### MANUAL

- Primeiramente clone o repositório na sua máquina com `git clone https://github.com/gstimm/AED1.git`

- Em seguida, abra a pasta onde os arquivos estão localizados.

- Compile o código com `gcc nomeDoArquivo.c -o nomeDoArquivo`

- Rode o executável com `.\nomeDoArquivo.exe`

### AUTOMÁTICA

As configuações usadas no meu compilador estão na pasta `.vscode`.

À princípio, dentro da pasta principal do projeto, basta estar com o arquivo .c aberto e selecionado, e pressionar **F5** que a compilação e execução são feitas automaticamente.
