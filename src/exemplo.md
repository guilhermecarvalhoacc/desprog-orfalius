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

A ideia é lembrar que estamos ordenando numeros inteiros e que seus indices (no array) também são inteiros, assim podemos usar um vetor auxiliar e mapear o valor presente em uma sequência para uma posição de mesmo valor (array[i] = i).

Para entender melhor esse conceito vamos imaginar um mundo ideial onde temos:

* Todos os 


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
