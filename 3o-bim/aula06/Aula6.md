# Alocação dinâmica

## O que e alocação de memória
**Estática:** o tamanho da variável é definido antes da execução.
```c
int vet[10];
```

**Alocação dinâmica:** define o tamanho da viável dinamicamente, de acordo com
as necessidades de armazenamento. __Em tempo de execução__.
```c
malloc();
calloc();
realloc();
free();
sizeof();
```

## Funções para alocação dinâmica
**free()**: libera a memória alocada. Usada ao final do algoritmo.
> Se não usar isso, só tira da memória quando reiniciar o computador.

**sizeof()**: mostra o tamanho dos dados. Ele ajuda o programador a alocar uma
determinada quantidade de memória, de acordo com o tipo de dado.
> Evita que o programador tenha que decorar a quantidade de bytes.
- char: 1 byte
- int: 4 bytes
- float: 4 bytes
- double: 8 bytes
- long double: 16 bytes

```c
// Mostra a quantidade de memória ocupada por um int
printf("%d", sizeof(int));
```

## Malloc
```c
// Pega um valor do tipo inteiro (sem sinal) e retorna um endereço (ponteiros)
// defindo como void*
void* malloc(int valor);
```
É o comando para alocar um novo endereço de memória RAM.

- Caso não consiga alocar, retorna _NULL_.
- Se conseguir, retorna o endereço da 1a posição.

```c
// Aloca 100 bytes e divide em tipo inteiro, logo, resulta em 25 posições
int *p = (int *)malloc(100);
// Não recomendado por conta das implementaçÕes
```


```c
// Malloca um array de 25 posições para inteiro
int *p = (int *)malloc(25 * sizeof(int));
```


**Exemplo:**

```c
int main() {
    int x, *p;
    p = (int *)malloc(10 * sizeof(int));
    // Aloca 10 posições do tamanho e tipo inteiro

    for (x = 0; x < 10; x++) {
        scanf("%d", &p[x]);
    }

    free(p); // Libera a memória
```


```c
int main() {
    int x, *p;
    p = (int *)malloc(10 * sizeof(int));
    // Aloca 10 posições do tamanho e tipo inteiro

    for (x = 0; x < 10; x++) {
        scanf("%d", *p);
        p++;
    }

    // Volta o p para a posição 0
    p = &p[0];

    // Printa os valores
    for (x = 0; x < 10; x++) {
        scanf("%d", *p);
        p++;
    }

    free(p); // Libera a memória
```


## Calloc
Pega um valor do tipo inteiro e inicializa com o valor 0.
- Retorna um ponteiro sem tipo definido
- Se não conseguir, manda null

```c
// Aloca 25 posições
int p = (int *) calloc(25, 4)
```


```c
// Aloca 25 posições do tipo int e inicializa com zeros (0)
int *p = (int *)malloc(25, sizeof(int));
```

```c
int main() {
    int x, *p;
    p = (int *)calloc(10, sizeof(int));

    for (0; x < 10; x++) {
        
    }
}
```

## Calloc VS Malloc
**Malloc**: mais rápido, pois não inicializa.
**Calloc**: mais lento, mas evita erros, pois inicializa.

## Realloc
Faz a adição de novas posições a uma alocação já estabelecida.
O processo consiste nas seguintes etapas:
1. Busca um novo espaço na memória com a quantidade do realloc()
2. Copia o conteúdo da memória do espaço anterior para o novo espaço
3. Roda um free() na alocação inicial
> O realloc dá um free nas partes que já existiam

## Outras liberações
```c
// Realoca com null - Equivalente a free()
int realloc(NULL, p, 25 * sizeof(int));
```

