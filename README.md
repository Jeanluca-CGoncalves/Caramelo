# Distribuição de Sacolas

Este projeto consiste em um programa em C desenvolvido para dividir um conjunto de valores numéricos (representando o peso ou quantidade em "sacolas") em duas partes com somas exatamente iguais, distribuídas entre duas entidades (Alice e Bob).

## ⚙️ Lógica e Funcionamento

O algoritmo resolve o problema utilizando uma abordagem **gulosa (greedy)**:

1. **Validação de Paridade:** Inicialmente, o programa calcula a soma total de todos os elementos. Se a soma for ímpar, é matematicamente impossível dividi-la em duas partes inteiras iguais, e o programa retorna `-1`.
2. **Ordenação:** O vetor de sacolas é ordenado utilizando um algoritmo de ordenação de complexidade $O(n^2)$.
3. **Distribuição Gulosa:** O sistema percorre o vetor ordenado de trás para frente (priorizando os maiores valores). O valor atual é sempre entregue àquele que possuir a menor soma acumulada no momento (Alice ou Bob).
4. **Verificação Final:** Após distribuir todos os itens, o código verifica se as somas de Alice e Bob são idênticas. Se forem, os itens são impressos de forma intercalada; caso contrário, imprime `-1`.
5. **Monitoramento de Tempo:** A função `clock()` da biblioteca `<time.h>` é utilizada para medir e exibir o tempo de execução do bloco principal em milissegundos.

## 🚀 Como Executar

**Pré-requisitos:** É necessário ter um compilador C (como o GCC) instalado.

1. Salve o código em um arquivo chamado `main.c`.
2. Abra o terminal e compile o arquivo:
   ```bash
   gcc main.c -o distribuicao
3. Execute o programa gerado
   distribuicao.exe
4.Siga as instruções no console:

Digite o número total de elementos.

Digite os valores de cada elemento separados por espaço ou tecla Enter.
