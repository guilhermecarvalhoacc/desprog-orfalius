Algoritmo Counting Sort 
======

Ordenação por contagem
---------
Antes de começarmos o handout vamos responder a uma pergunta:

??? Exercício

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

Você também pode criar

1. listas;

2. ordenadas,

assim como

* listas;

* não-ordenadas

* testando entao

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
