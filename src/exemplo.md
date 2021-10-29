Algoritmo Counting Sort 
======

Ordenação por contagem
---------
Antes de começarmos o handout vamos responder a uma pergunta:

??? Checkpoint

O que algoritmos de ordenação como Selection Sort Bubble Sort e Insertion Sort tem em comum? 

::: Gabarito
Todos eles são algoritmos que usam comparação para ordenar valores em um vetor.
:::

???

Diferente disso o Counting Sort que é o algoritmo abordado neste handout não utiliza de comparação para ordenar os valores, este algoritmo serve para ordenar **apenas** valores inteiros e positivos de um vetor, assim ele pode ser implementado para criação de rankings ou para ordens de prioridades dea tendimento por exemplo.

Mas espera ai, como assim ele não utiliza de comparação ? Antes de prosseguirmos com a explicação do counting sort, vamos mostrar como pode ser feita a ordenação de um vetor sem utilizar comparação.

A ideia é lembrar que estamos ordenando numeros inteiros e que seus indices (no array) também são inteiros, dessa forma  podemos usar um vetor auxiliar e mapear o valor presente em uma sequência para uma posição de mesmo valor nesse vetor (array[i] = i).

Para entender melhor esse conceito vamos imaginar um mundo ideial onde temos:

* não existe repetição de elementos.

* Todos os elementos do array a ser ordenado são positivos.

* Conhecemos qual o maior valor desse array.

Assim se quisermos ordenar o vetor V = [6,1,4,2,3], basta criarmos um vetor auxiliar C de tamanho 6, pois é o maior elemento do vetor V e interar seguindo a instrução: C[V[i] - 1] = True, ou seja pega o valor do elemento do vetor V diminue 1 e coloca True no lugar desse indice.

Assim teremos: 

C = [True,True,True,True,False,True]

Agora temos que criar um vetor B do tamanho de V pois o output deve ser o mesmo vetor so que ordenado, e onde tiver True acrescenta 1 ao valor do indice, por exemplo :
    
Temos True na posição i = 0,1,2,3,5  assim basta somarmos 1 para cada valor do indice e adicionar no vetor B

B = [1,2,3,4,6]

Agora vamos fazer um exercicio para fixar a ideia na cabeça

??? Exercício

Ordene o vetor V = [8,3,10,1,7]. Não olhe o gabarito antes de tentar!

::: Gabarito
1. Primeiro criamos o vetor auxiliar

    C = [True,False,True,False,False,False,True,True,False,True]

2. Criando o vetor B do tamanho de V somando 1 onde tem True

    B = [1,3,7,8,10]

:::

???

Implementando o codigo do primeiro exemplo de ordenação 
---------

``` c
void f() {
    printf("hello world\n");
}
```
Voltando para o Counting Sort 
---------

Ta bom mas nosso primeiro exemplo era mais simples, pois não tinha repetição, mas e se tivessemos numeros repetidos num vetor a ser ordenado, o que seria feito? Agora sim vamos falar diretamente do counting sort.

A ideia desse algoritmo é parecida com a ideia que vimos anteriormente, porem tem algumas coisas diferentes, como por exemplo ele coloca a frequencia dos numeros no array auxiliar, ou seja no lugar do vetor C ser um vetor de booleanos ele será de inteiros.

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

Começando pegando o ultimo numero do vetor: V[5] ==> B[C[2 - 1] - 1] = V[5]  --> B[C[1] - 1] = V[5] ==> B[4 - 1] = V[5] ==> B[3] = 2
Apos isso teriamos que fazer a instrução C[V[i]-1] -= 1 para que se tiver um numero repetido ele va para uma posição anterior.

Logo, nosso vetor C ficaria C[2 - 1] -= 1 ==> C = [2,3,5,5,6] ( Perceba que onde era 4 na segunda posição do vetor agora é um 3)

Assim: preenchemos a posição 3 do vetor B, B = [Null,Null,Null,2,Null,Null] (deixei escrito Null apenas para mostrar que ainda não preenchemos essas partes.)

Continuando teriamos: B = [1,1,2,2,3,5]

:::

???


Complexidade do Counting Sort
-------------------------

Sabemos que o Counting Sort usa apenas loops de for simples sem cahamdas recurssivas nem outras coisas um poucos mais complicadas, assim analisar sua complexidade fica fácil, temos um loop 
e imagens. Lembre que todas as imagens devem estar em uma subpasta *img*.

![](logo.png)

Para tabelas, usa-se a [notação do
MultiMarkdown](https://fletcher.github.io/MultiMarkdown-6/syntax/tables.html),
que é muito flexível. Vale a pena abrir esse link para saber todas as
possibilidades.

| coluna a | coluna b |
|----------|----------|
| 1        | 2        |

Ao longo de um texto, você pode usar *itálico*, **negrito**, {red}(vermelho) e
[[tecla]]. Também pode usar uma equação LaTeX: $f(n) \leq g(n)$. Se for muito
grande, você pode isolá-la em um parágrafo.

$$\lim_{n \rightarrow \infty} \frac{f(n)}{g(n)} \leq 1$$

Para inserir uma animação, use `md ;` seguido do nome de uma pasta onde as
imagens estão. Essa pasta também deve estar em *img*.

;bubble

Você também pode inserir código, inclusive especificando a linguagem.

``` py
def f():
    print('hello world')
```

``` c
void f() {
    printf("hello world\n");
}
```

Se não especificar nenhuma, o código fica com colorização de terminal.

```
hello world
```


!!! Aviso
Este é um exemplo de aviso, entre `md !!!`.
!!!


??? Exercício

Este é um exemplo de exercício, entre `md ???`.

::: Gabarito
Este é um exemplo de gabarito, entre `md :::`.
:::

???
