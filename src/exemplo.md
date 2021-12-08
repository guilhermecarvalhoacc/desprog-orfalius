Algoritmo Counting Sort 
======

Ordenação por contagem
---------

Até o momento, os algoritmos que foram vistos se baseam em comparação, ou seja, em algum ponto do algoritmo é feito
comparações entre os valores do vetor para ver quem é maior que o outro, para trocar suas posições.

Diferente de outros algoritmos de ordenação o Counting Sort que é o algoritmo abordado neste handout não utiliza de comparação para ordenar os valores, este algoritmo serve para ordenar **apenas** valores inteiros e positivos de um vetor, assim ele pode ser implementado para criação de rankings ou para ordens de prioridades de atendimento, por exemplo.

Mas espera aí, como assim ele não utiliza de comparação ? Antes de prosseguirmos com a explicação do counting sort, vamos mostrar como pode ser feita a ordenação de um vetor sem utilizar comparação.

A ideia é lembrar que estamos ordenando números inteiros e que seus índices (no array) também são inteiros, dessa forma  podemos usar um vetor auxiliar e mapear o valor presente em uma sequência para uma posição de mesmo valor nesse vetor (array[i] = i).

Para entender melhor esse conceito vamos imaginar um mundo ideal onde temos:

* Não existe repetição de elementos.

* Todos os elementos do array a ser ordenado são positivos.

* Conhecemos qual o maior valor desse array.

Assim se quisermos ordenar o vetor V = [9,1,4,2,3], basta criarmos um vetor auxiliar C de tamanho 10, pois é o maior elemento do vetor V e iterar seguindo a instrução: C[V[i]] = True, ou seja pega o valor do elemento do vetor V e coloca True no lugar desse índice.

Assim teremos: 

??? Checkpoint

Observe a instrução e tente criar o vetor C 

::: Gabarito

C = [False,True,True,True,True,False,False,False,False,True]

:::

???

Agora temos que criar um vetor B do tamanho de V pois o output deve ser o mesmo vetor só que ordenado, e pegaremos o índice do elemento que tiver como True, por exemplo :

??? Checkpoint

Crie o vetor B

::: Gabarito
Temos True na posições i = 1,2,3,4,9  assim basta pegarmos cada valor do índice e adicionar no vetor B

B = [1,2,3,4,9]

:::

???



Agora vamos fazer um exercício para fixar a ideia na cabeça

??? Exercício

Ordene o vetor V = [8,3,10,1,7], com base na ideia que acabamos de apresentar. Não olhe o gabarito antes de tentar!

::: Gabarito
1. Primeiro criamos o vetor auxiliar

    C = [False,True,False,True,False,False,False,True,True,False,True]

2. Criando o vetor B do tamanho de V e pegando os índices onde o valor é True

    B = [1,3,7,8,10]

:::

???

Implementando o código do primeiro exemplo de ordenação 
---------


``` c
#include <stdio.h>
#include <stdbool.h>

void sort(int *V, int len_v, int *b, int k) {
    int vetor_c[k]
    int idx_posicao = 0;

    para cada i de 0 até i < len_v {
        C[V[i]] = 1;
    }

    para cada i de 0 até i <= k {
        se (vetor_c[i] é true) {
            b[idx_posicao] = i;
            idx_posicao += 1;
        }
    }
    return;
}

int main() {

    int v[]   = {2,9,15,26,4,3};
    int len_v = tamanho(v)
    int k     = maior_numero(v);

    int b[len_v];

    sort(v, len_v, b, k);

    para cada i até len_v {
        print(b[i]);
    }

    printf("\n");

    return 0;
}
```


??? Exercicio

Calcule a complexidade desse algoritmo que acabamos de ver.

::: Gabarito

Sabemos que esse algoritmo usa apenas loops de for simples sem chamadas recurssivas nem outras coisas um poucos mais complicadas, assim analisar sua complexidade fica fácil, temos 1 loop que percorrem o vetor auxiliar c e de tamanho K (valor maximo do vetor V).


sendo k (o maior valor do vetor V) + 1, temos assim k interações nesse loop.
Assim ja temos complexidade  O(k)

Analisando os outros loops vemos que a complexidade é apenas O(n), assim o algoritmo inteiro possui compexidade O(n+K).

:::

???



Usando vetor de contagem de forma simples
---------
Antes de finalmente vermos o Counting Sort, vamos entender como seria utilizando um vetor auxiliar de contagem e não um binário como vimos mais acima.

Imagine agora a mesma situação descrita acima, mas agora temos numero repetidos no vetor que queremos ordenar

Imaginemos o seguinte vetor V = [1,10,1,1,3,3,4,5]

realizando o mesmo passo de criar o vetor auxiliar C, mas agora ele terá a frequencia com que o numero aparece, ou seja C[V[i]] += 1 , no lugar de colocar True, adicionamos 1 para mostrar que aquele numero apareceu mais uma vez.

??? Checkpoint

Crie o vetor C com base na explicação acima

::: Gabarito

Usando a mesma lógica só que agora contando quantas vezes aparece tal numero teríamos:

C = [0,3,0,2,1,1,0,0,0,0,1]

Perceba que o vetor tem tamanho 11, pois é o maior valor do vetor V + 1 (pois começa do índice 0), e onde tem 0 significa que não tem aparição do número correspondente no vetor V.

:::

???

Agora seguindo a mesma lógica já estudada, vamos construir o vetor B. Primeiro observa-se as posições que não tem 0 e soma-se 1,então repita esse valor com base no número que estiver nessa posição, por exemplo, no vetor C o número 0 está na posição 0, e o 3 está na posição 1, então no vetor B será: B = [?,?,?,?,?,?,?,?].

??? Checkpoint

Complete o vetor B com base no que foi explicado acima

::: Gabarito

Seguindo a mesma lógica, temos o valor 2 na posição 3, e posições 4,5 e 10 aparecem os valores 1.

Assim, temos que o vetor B será:

B = [1,1,1,3,3,4,5,10]

:::

???



Voltando para o Counting Sort 
---------

Ta bom, mas nossos  exemplos eram simples, e é importante lembrar que as versões anteriormente vistas nesse handout se baseiam em escrever a versao ordenada do vetor e não copiar os elementos do vetor original, no entenato essa estrategia nao vai funcionar para versoes mais complexas como por exemplo ordenação de alunos por numero de matricula, não da pra escrever os numeros de matricula, teria que copiar.

A ideia desse algoritmo é parecida com a ideia que vimos anteriormente, porem tem algumas coisas diferentes, como por exemplo ele coloca a frequencia dos numeros no array auxiliar, ou seja no lugar do vetor C ser um vetor de booleanos ele será de inteiros.

Continuando com a ideia de contar o numero de vezes que algum elemento apareceu. Assim vamos imaginar que temos 3 zeros, não podemos simplesmentes escrever eles, temos que conseguir uma estrategia, uma estrategia boa seria encontrar a posição do ultimo zero., ou seja o contador está entregando a posição do ultimo. 

??? Checkpoint
Agora imaginemos que temos mais dois numeros 1. Poderiamos também encontrar a posição do ultimo 1.

O segundo 1 seria colocado la posição 2 do vetor final ?

::: Gabarito

Não! Você ja percebeu que deveriamos ter primeiro os 3 zeros e depois os dois 1's. Logo percebe-se que não devemos ocnsiderar os contadores originais e sim a versão cumulativa dos contadores.

:::

???


Agora que ja temos uma noção melhor sobre o counting sort, vamos para uma sequência mais trabalhada dele.

Para se ordenar com counting sort pode-se seguir os seguintes passos 

1. Registrar a frequencia dos elementos do vetor V no vetor auxiliar C ( o qual o tamanho vai ser o do maior elemento de V) seguindo a instrução C [V[i] - 1] += 1.

2. Fazer a soma cumulativa do vetor anterior com o proximo e alocar neste próximo, ou seja C[i] = C[i] + C[i-1].

3. Interar sobre V registrando no vetor B com a instrução B[C[V[i] - 1] - 1] = V[i] apos isso fazer C[V[i]-1] -= 1, pois se ouver outro valor repetido ele irá para uma posição anterior deixando ordenado.

Assim, ordenando o vetor V = [1,3,1,5,2,2]  seguindo os passos anteriores como fariamos? 

??? Checkpoint

Passo 1:

Registrando a frequencia teriamos: 

::: Gabarito
C = [2,2,1,0,1] 

perceba que temos um vetor de tamanho 5, pois é o maior valor do vetor inicial V (parecido com o que vimos na primeira ideia desse handout)
:::

???

??? Checkpoint

Passo 2:

Fazendo a soma acumulativa:

::: Gabarito
C = [2,2,1,0,1] => C = [2,4,5,5,6]  

Perceba que somamos 2 + 2 dando 4 e alocando na segunda posição, somamdos 4 + 1 dando 5 e alocando na posição 3, e assim por diante.
:::

???

??? Checkpoint

Passo 3:

Interando usando a instrução B[C[V[i] - 1] - 1] = V[i]:

::: Gabarito
C = [2,2,1,0,1] => C = [2,4,5,5,6]  

temos V = [1,3,1,5,2,2] 
      C = [2,4,5,5,6]
Fazendo o B por partes temos: 

Começando pegando o ultimo numero do vetor: V[5] ==> B[C[2 - 1] - 1] = V[5]  ==> B[C[1] - 1] = V[5] ==> B[4 - 1] = V[5] ==> B[3] = 2
Apos isso teriamos que fazer a instrução C[V[i]-1] -= 1 para que se tiver um numero repetido ele va para uma posição anterior.

Logo, nosso vetor C ficaria C[2 - 1] -= 1 ==> C = [2,3,5,5,6] ( Perceba que onde era 4 na segunda posição do vetor agora é um 3)

Assim: preenchemos a posição 3 do vetor B, B = [Null,Null,Null,2,Null,Null] (deixei escrito Null apenas para mostrar que ainda não preenchemos essas partes.)

Continuando teriamos: B = [1,1,2,2,3,5]

:::

???

Um exemplo de Counting sort implementado em C
-------
``` c
#include<stdio.h>  

void count_sort(int v[], int n) {  
  int output[n+1];  
  int max = get_max(v, n);  
  int c[max+1]; //create count array with size [max+1]  
  
  // Inicializa o array de contagem com zeros
  for (int i = 0; i <= max; ++i)   {  
    c[i] = 0; 
  }  
    
  //frequencia
  for (int i = 0; i < n; i++){ 
    c[v[i]]++;  
  }  

  //cumulativa
  for(int i = 1; i<=max; i++)   
    c[i] += c[i-1]; 
  
  /* Loop para encontrar o indice de cada elemento do array original dentro do array de contagem,
  e alocar no array output */

  for (int i = n - 1; i >= 0; i--) {  
    output[c[a[i]] - 1] = v[i];  
    c[v[i]]--; // decrease count for same numbers  
   }  

  // Sobrescrever o array de entrada com o array ordenado
  for(int i = 0; i<n; i++) {  
     v[i] = output[i];
  }  
}  
  
void printarr(int a[], int n) {  
    int i;  
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);  
    }
}  
  
```


Complexidade do Counting Sort
-------------------------


??? Exercicio

Calcule a complexidade do counting sort

::: Gabarito

Sabemos que o Counting Sort usa apenas loops de for simples sem cahamdas recurssivas nem outras coisas um poucos mais complicadas, assim analisar sua complexidade fica fácil, temos 2 loops que percorrem o vetor auxiliar c e de tamanho K (valor maximo do vetor V).

``` c
  for (int i = 0; i <= max; ++i)   {  
    c[i] = 0; 
  }  

// sendo k o maior valor do vetor V, temos assim k + 1 interações nesse loop, analisando o outro loop com k vemos que este tem k interações.
```
Assim ja temos complexidade  O(k)

Analisando os outros loops vemos que a complexidade é apenas O(n), assim o algoritmo inteiro possui compexidade O(n+K).

:::

???




Simulação do Counting Sor
-------

Simulando a ordenação para um vetor A = [1,2,7,2,5,4,6]

;bubble







Exercicios de desafio
------

Vimos implementações para versões de elementos inteiros não negativos, será que podemos adaptar para resolver problemas com elementos negativos ou até decimais ?

??? Desafio

Ordene o vetor V = [-15,-8,5,1,5,0] 

(Uma dica: transforme os vetores em inteiros positivos para usar o counting sort)

::: Gabarito
Primeiro some 15 a todos os elementos, pois é o numero mais negativo, assim todos ficarão positivos.

V = [0,7,20,16,20,15]

Agora pode ordenar usando o counting sort

V = [0,7,15,16,20,20]

Agora subtraia 15 de cada elemento para voltar a serem os elementos do vetor inicial

V = [-15,-8,0,1,5,5]
:::

???


??? Desafio

Ordene o vetor V = [-10.5, -12.6, -3.2, 30.9, -10.7, 2.8]


::: Gabarito
Primeiro some 12.6 a todos os elementos, pois é o numero mais negativo, assim todos ficarão positivos.

V = [2.1,0,9.4,43.5,1.9,15.4]

Agora multiplique todos os numeros por 10 

V = [21,0,94,435,19,154]

Agora ordene usando o counting sort

V = [0,19,21,94,154,435]

Agora desfaça todas as operações feitas ( multiplicação por 10 e a soma por 12.6)

Assim temos 

V = [-12.6,-10.7,-10.5,-3.2,2.8,30.9]

:::

???








Referências:
------

Teoria e alguns exemplos:   <https://joaoarthurbm.github.io/eda/posts/ordenacao-linear/>

Comandos:<https://docs.pipz.com/central-de-ajuda/learning-center/guia-basico-de-markdown#open>

Alguns exercicios: <https://docplayer.com.br/140797087-Topico-5-algoritmos-de-ordenacao-parte-ii-metodos-de-ordenacao-counting-sort-radix-sort-e-bucket-sort.html>


