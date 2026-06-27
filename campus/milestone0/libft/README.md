# Libft

## Descripción
Libft es una biblioteca personal creada para recrear y comprender funciones básicas de la libc de C. El objetivo del proyecto es implementar funciones de manejo de cadenas, memoria, caracteres y listas enlazadas, respetando las normas de compilación y estilo del campus 42.

## Compilación
- `make` : compila todos los archivos `.c` y construye la biblioteca `libft.a`
- `make clean` : borra los archivos objeto `.o`
- `make fclean` : borra `libft.a` y los archivos objeto
- `make re` : ejecuta `fclean` y luego `all`

## Uso
1. Incluir la cabecera en el proyecto:
   ```c
   #include "libft.h"
   ```
2. Compilar usando la biblioteca:
   ```bash
   cc -I. main.c -L. -lft
   ```
3. Asegurarse de que `libft.a` esté en el directorio del proyecto o en el `LD_LIBRARY_PATH`.

## Requisitos del proyecto
- Compilación con `cc -Wall -Wextra -Werror`
- No usar funciones prohibidas por el subject
- No usar variables globales
- Manejar correctamente `NULL` y casos límite
- Implementar la biblioteca como un archivo estático `libft.a`

## Funciones implementadas
### Parte obligatoria
- `ft_isalpha`
- `ft_isalnum`
- `ft_isdigit`
- `ft_isprint`
- `ft_isascii`
- `ft_strlen`
- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_toupper`
- `ft_tolower`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_memchr`
- `ft_memcmp`
- `ft_strnstr`
- `ft_atoi`
- `ft_calloc`
- `ft_strdup`
- `ft_substr`
- `ft_strjoin`
- `ft_strtrim`
- `ft_split`
- `ft_itoa`
- `ft_strmapi`
- `ft_striteri`
- `ft_putchar_fd`
- `ft_putstr_fd`
- `ft_putendl_fd`
- `ft_putnbr_fd`

### Listas enlazadas
- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## Estructura de archivos
- `libft.h` : prototipos de funciones y definición de `t_list`
- `Makefile` : reglas de compilación para generar `libft.a`
- Archivos `.c` : implementación de cada función

## Notas
- Esta librería es la base para futuros proyectos de 42 como `get_next_line`, `libftprintf`, `pipex`, `minishell`, entre otros.
- El proyecto muestra la comprensión de punteros, manejo dinámico de memoria, manipulación de cadenas y estructuras enlazadas.

## Autor
- `rtapiado` — `rtapiado@student.42madrid.com`
