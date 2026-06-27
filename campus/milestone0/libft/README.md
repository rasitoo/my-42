*Este proyecto ha sido creado como parte del currículo de 42 por rtapiado.*

## Descripción

Este proyecto es una implementación específica del ejercicio `libft` del campus 42. Consiste en desarrollar una biblioteca en C que replica funciones básicas de la libc y añade utilidades propias para manejo de cadenas, memoria, caracteres y listas enlazadas. El objetivo es crear una biblioteca estática `libft.a` que cumpla las normas de 42 y sirva como base reutilizable para futuros proyectos.

## Instrucciones

### Compilación

1. Navega al directorio del proyecto:
   ```bash
   cd campus/milestone0/libft
   ```
2. Compila la biblioteca:
   ```bash
   make
   ```
3. Usa la biblioteca en tu código:
   ```c
   #include "libft.h"
   ```
   ```bash
   cc -Wall -Wextra -Werror -I. main.c -L. -lft
   ```

### Limpieza

- `make clean` : elimina los archivos objeto `.o`
- `make fclean` : elimina `libft.a` y los archivos objeto
- `make re` : ejecuta `fclean` y luego `all`

### Requisitos del proyecto

- Compilación con `cc -Wall -Wextra -Werror`
- No se deben usar funciones prohibidas por el subject de 42
- No se usan variables globales
- La biblioteca se genera como un archivo estático `libft.a`

## Recursos

- Subject oficial del proyecto `libft` de 42
- Documentación de la biblioteca estándar de C (`man`)
- Recursos sobre manejo de memoria y cadenas en C
- Artículos y tutoriales sobre listas enlazadas simples en C (CS50x)

### Uso de IA

No se ha utilizado inteligencia artificial para desarrollar el código de esta biblioteca. La documentación y la solución se han elaborado manualmente.

## Detalle de la librería

La librería `libft` creada en este proyecto ofrece una colección de funciones fundamentales en C implementadas desde cero. Está diseñada para:

- manipular cadenas y subcadenas
- gestionar memoria dinámica de forma segura
- validar y convertir caracteres
- realizar operaciones de copia y comparación de memoria
- construir y gestionar listas enlazadas simples
- imprimir datos a descriptores de archivo

### Funciones implementadas

#### Caracteres
- `ft_isalpha`
- `ft_isalnum`
- `ft_isdigit`
- `ft_isprint`
- `ft_isascii`
- `ft_toupper`
- `ft_tolower`

#### Memoria
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_calloc`

#### Cadenas
- `ft_strlen`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_strnstr`
- `ft_strdup`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`

#### Entrada / salida
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

#### Listas enlazadas
- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## Autor

- `rtapiado` — `rtapiado@student.42madrid.com`
