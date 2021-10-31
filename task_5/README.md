# LISTA DE EXERCÍCIOS 5 - AED1

## CONTATO

_Gabriel Schultz Timm<br>
gstimm@inf.ufpel.edu.br_

## DESCRIÇÃO

1 - Implementar os algoritmos de ordenação Insertion Sort, Selection Sort, Quick Sort e Merge Sort.

2 - O programa deve solicitar o tamanho do vetor de números (n) que será ordenado

3 - O programa deve preencher um vetor de tamanho n com números aleatórios. Usar srand(time(NULL)); no inicio do programa.

4 - Faça um código que verifica se o resultado dado por cada algoritmo de ordenação está correto.

5 - Use a melhor lib (defina a melhor no item 7) para calcular quanto tempo cada algoritmo de ordenação levou para terminar: https://levelup.gitconnected.com/8-ways-to-measure-execution-time-in-c-c-48634458d0f9

6 - No 1:1 vou perguntar sobre questões de desempenho relacionadas a esse exercício, então pense sobre desempenho, otimizações, avaliação de tempo, complexidade, hardware, etc

7 - Faça teste de leaks de memória.

8 - Faça um vídeo explicando todos os pontos. Por favor, não faça o vídeo mais longo do que o necessário e não esqueça das regras de envio de material.

## EXECUÇÃO

### MANUAL

- Primeiramente clone o repositório na sua máquina com `git clone https://github.com/gstimm/AED1.git`

- Em seguida, abra a pasta onde os arquivos estão localizados.

- Compile o código com `gcc nomeDoArquivo.c -o nomeDoArquivo`

- Rode o executável com `./nomeDoArquivo`

### AUTOMÁTICA

As configuações usadas no meu compilador estão na pasta `.vscode`.

À princípio, dentro da pasta principal do projeto, basta estar com o arquivo .c aberto e selecionado, e pressionar **F5** que a compilação e execução são feitas automaticamente.

### TESTES AUTOMATIZADOS

Para executar o programa com um teste, por exemplo o que esta disponível junto ao programa, basta após a compilação, executar o comando:

`./nomeDoArquivo < ../work/test.txt`

É necessário ir até a pasta work para rodar o teste pois é o modo como o compilador está configurado na pasta .vscode.
