# Libft - Guía de estudio

Esta guía resume la librería libft para estudiarla de forma práctica y rápida.

## 1. Qué es la libft
La libft es una librería personalizada en C que recrea funciones básicas de libc.
Su objetivo es aprender:
- cómo funcionan las funciones de C a bajo nivel,
- manejo de memoria,
- punteros,
- strings,
- listas enlazadas,
- archivos y descriptores.

## 2. Estructura del proyecto
Archivos importantes:
- libft.h: prototipos de todas las funciones y definición de t_list
- Makefile: compila y arma la librería libft.a
- *.c: cada archivo implementa una función

## 3. Funciones de caracteres
Estas funciones trabajan con caracteres o enteros que representan caracteres.

### Funciones
- ft_isalpha: devuelve 1 si el carácter es una letra.
- ft_isdigit: devuelve 1 si es un dígito.
- ft_isalnum: devuelve 1 si es letra o número.
- ft_isascii: comprueba si está en el rango ASCII.
- ft_isprint: comprueba si es imprimible.
- ft_toupper: convierte a mayúscula si aplica.
- ft_tolower: convierte a minúscula si aplica.

### Idea clave
Se suelen comprobar rangos ASCII:
- 'A'..'Z'
- 'a'..'z'
- '0'..'9'

## 4. Funciones de strings
Trabajan con cadenas de caracteres terminadas en '\0'.

### Funciones
- ft_strlen: cuenta caracteres hasta el '\0'.
- ft_strchr: busca la primera aparición de un carácter.
- ft_strrchr: busca la última aparición de un carácter.
- ft_strncmp: compara dos strings hasta n caracteres.
- ft_strnstr: busca una subcadena dentro de los primeros n bytes.
- ft_strdup: duplica una cadena en memoria nueva.
- ft_substr: extrae una subcadena.
- ft_strjoin: une dos strings en uno nuevo.
- ft_strtrim: elimina caracteres del inicio y el final.
- ft_split: separa una cadena por un delimitador.
- ft_strmapi: aplica una función a cada carácter y crea otra cadena.
- ft_striteri: igual que strmapi, pero modifica la cadena original.
- ft_strlcpy: copia una cadena con límite de tamaño.
- ft_strlcat: concatena con límite de tamaño.

### Idea clave
Siempre hay que tener en cuenta:
- el carácter nulo '\0',
- el tamaño del buffer,
- la reserva de memoria con malloc.

## 5. Funciones de memoria
Estas funciones manipulan bloques de bytes.

### Funciones
- ft_memset: rellena un bloque con un byte.
- ft_bzero: rellena con ceros.
- ft_memcpy: copia bytes de origen a destino.
- ft_memmove: copia bytes, incluso si hay solapamiento.
- ft_memchr: busca un byte dentro de un bloque.
- ft_memcmp: compara dos bloques de memoria.
- ft_calloc: reserva memoria y la inicializa a cero.

### Idea clave
No trabajan con strings, sino con bytes. Son muy útiles para arrays, buffers y estructuras.

## 6. Conversión de números
- ft_atoi: convierte una cadena numérica en entero.
- ft_itoa: convierte un entero en una cadena nueva.

### Idea clave
- atoi debe ignorar espacios y signos.
- itoa necesita manejar el signo y reservar memoria suficiente.

## 7. Funciones de salida
- ft_putchar_fd: escribe un carácter en un descriptor.
- ft_putstr_fd: escribe una cadena.
- ft_putendl_fd: escribe una cadena y un salto de línea.
- ft_putnbr_fd: escribe un entero.

### Idea clave
Se usan con `write()` y un `fd` (file descriptor).

## 8. Listas enlazadas
La libft incluye funciones para manejar listas simples con `t_list`.

### Estructura
```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

### Funciones
- ft_lstnew: crea un nuevo nodo.
- ft_lstadd_front: añade un nodo al inicio.
- ft_lstsize: cuenta nodos.
- ft_lstlast: devuelve el último nodo.
- ft_lstadd_back: añade un nodo al final.
- ft_lstdelone: elimina un nodo y su contenido.
- ft_lstclear: elimina toda la lista.
- ft_lstiter: aplica una función a cada nodo.
- ft_lstmap: crea una nueva lista transformada.

### Idea clave
Cada nodo tiene:
- `content`: el dato guardado,
- `next`: puntero al siguiente nodo.

## 9. Qué debes saber para defenderla
Puedes explicar la libft así:

1. Es una librería personalizada que reimplementa funciones básicas.
2. Está dividida por bloques: caracteres, strings, memoria, conversiones, salida y listas.
3. Cada función debe ser segura, simple y manejar casos límite.
4. El Makefile compila todos los archivos `.c` y arma `libft.a`.
5. La librería se usa luego en otros proyectos para reutilizar código.

## 10. Preguntas típicas de examen
- ¿Qué diferencia hay entre `strcpy` y `strlcpy`?
- ¿Qué hace `malloc` y por qué se usa?
- ¿Qué pasa si `malloc` falla?
- ¿Qué diferencia hay entre `memcpy` y `memmove`?
- ¿Por qué `ft_split` necesita reservar memoria para cada palabra?
- ¿Cómo funciona una lista enlazada?

## 11. Recomendación de estudio
Estudia así:
- primero las funciones de caracteres,
- luego strings,
- luego memoria,
- luego conversiones,
- luego listas,
- finalmente el Makefile.

Si puedes, intenta reescribir cada función sin mirar el código.
Eso te hará entenderla mucho mejor.
