*Este proyecto ha sido creado como parte del currículo de 42 por rtapiado.*

## Descripción

Este repositorio contiene los proyectos realizados durante el campus de 42, con foco principal en `libft`, la biblioteca base de funciones reutilizables en lenguaje C. El proyecto `libft` consiste en recrear funciones estándar de la biblioteca C (`libc`) y otras utilidades auxiliares para comprender mejor manejo de memoria, cadenas, caracteres y listas enlazadas. El objetivo es construir una biblioteca estática `libft.a` que pueda reutilizarse en futuros proyectos del campus.

## Instrucciones

### Proyecto `libft`

1. Entra en el directorio del proyecto:
   ```bash
   cd campus/milestone0/libft
   ```
2. Compila la biblioteca:
   ```bash
   make
   ```
3. Usa la biblioteca en tus programas incluyendo la cabecera y enlazando con `-lft`:
   ```c
   #include "libft.h"
   ```
   ```bash
   cc -Wall -Wextra -Werror -I. main.c -L. -lft
   ```
4. Limpia los archivos objeto y la biblioteca:
   ```bash
   make clean
   make fclean
   ```
5. Vuelve a compilar todo desde cero:
   ```bash
   make re
   ```

### Requisitos de compilación

- Compilador: `cc`
- Flags: `-Wall -Wextra -Werror`
- No se permiten funciones prohibidas por el subject de 42
- No se usan variables globales

## Recursos

- Documentación de la biblioteca estándar de C (`man 3`)
- Normas y subject de 42 para el proyecto `libft`
- Tutoriales sobre punteros y manejo de memoria en C

### Uso de IA

No se ha utilizado inteligencia artificial para implementar el código de este proyecto. El desarrollo, depuración y documentación se han realizado manualmente.

## Detalle de la librería

`libft` es una biblioteca estática que incluye implementaciones propias de funciones de la libc y utilidades adicionales. Está diseñada para:

- Manipular cadenas de caracteres
- Gestionar memoria dinámica
- Procesar caracteres y condiciones de comprobación
- Trabajar con listas enlazadas simples
- Proveer funciones de salida hacia descriptor de archivo

### Funcionalidades incluidas

- Funciones de carácter: `ft_isalpha`, `ft_isalnum`, `ft_isdigit`, `ft_isprint`, `ft_isascii`, `ft_toupper`, `ft_tolower`
- Funciones de cadena: `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_strmapi`, `ft_striteri`
- Funciones de memoria: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- Conversión y salida: `ft_atoi`, `ft_itoa`, `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- Listas enlazadas: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Estructura del repositorio

- `campus/milestone0/libft/`: proyecto `libft` con su `Makefile`, `libft.h` y archivos fuente
- `piscine/`: proyectos previos del campus 42

## Autor

- `rtapiado` — `rtapiado@student.42madrid.com`
