*Este proyecto ha sido creado como parte del currículo de 42 por rtapiado.*

# get_next_line

## Descripción

El proyecto **get_next_line** consiste en programar una función en lenguaje C que devuelva una línea leída desde un descriptor de archivo (*file descriptor*, `fd`). Llamadas sucesivas a la función permiten leer el contenido completo de un archivo de texto o de la entrada estándar (`stdin`), línea a línea, hasta alcanzar el final del archivo (*EOF*).

El objetivo pedagógico principal del proyecto es dominar el concepto de **variables estáticas** en C, profundizar en el funcionamiento de las llamadas al sistema para entrada/salida a bajo nivel (`read`) y perfeccionar el control estricto de la memoria dinámica en el *heap* (`malloc` y `free`), evitando cualquier tipo de fuga de memoria (*memory leak*).

Cada llamada exitosa a `get_next_line` devuelve un puntero a una cadena de caracteres terminada en `\n` (salvo si el archivo finaliza sin salto de línea). Cuando no quedan más líneas por leer o se produce un error, la función devuelve `NULL`.

---

## Instrucciones

### Archivos del Proyecto

El proyecto está compuesto por los siguientes archivos de cabecera y código fuente:

- `get_next_line.h`: Cabecera con el prototipo de la función principal, dependencias y definición por defecto de `BUFFER_SIZE`.
- `get_next_line.c`: Lógica principal del lector (`read_and_stash`, `extract_line`, `update_stash` y `get_next_line`).
- `get_next_line_utils.c`: Funciones auxiliares de manipulación de cadenas y memoria (`ft_strlen`, `ft_strchr`, `ft_strjoin`, `ft_substr`, `ft_strdup`).

### Compilación y Uso

La función se compila junto con el código fuente del programa consumidor mediante el compilador `cc` con los flags habituales y la definición del tamaño de buffer `-D BUFFER_SIZE=n`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o mi_programa
```

Si no se define la bandera `-D BUFFER_SIZE`, el archivo de cabecera aplicará un valor por defecto (42).

### Ejemplo de Uso en C

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("ejemplo.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

También es posible leer directamente de la entrada estándar pasando `0` como descriptor de archivo:

```c
line = get_next_line(0);
```

---

## Recursos

### Referencias Clásicas
- **Manual de Linux (man pages):**
  - `man 2 read`: Mecanismo de lectura de descriptores de archivo, retornos y detección de *EOF* (0) o errores (-1).
  - `man 2 open` / `man 2 close`: Gestión del ciclo de vida de los descriptores de archivo.
  - `man 3 malloc` / `man 3 free`: Asignación y liberación adecuada de memoria en el *heap*.
- **Estándar C99 (ISO/IEC 9899:1999):** Especificación sobre almacenamiento estático y ámbito (*scope*) de variables con especificador `static`.

### Uso de Inteligencia Artificial (IA)
En cumplimiento con las directrices de la versión 14.0 del currículo de 42 relativas a la transparencia en el uso de herramientas de IA:

- **Tareas en las que se utilizó:**
  - Consulta conceptual y orientación socrática para estructurar la separación de responsabilidades en tres funciones auxiliares.
  - Asistencia en la depuración guiada de casos borde en la gestión de índices de corte de cadenas y detección de dependencias en variables locales sin inicializar.
  - Creación de entornos de prueba automatizados con interceptación (*wrapping*) de llamadas a `malloc` y `free` para auditar la ausencia de fugas de memoria (*leaks*) bajo diferentes valores de `BUFFER_SIZE`.
- **Partes del proyecto en las que se empleó:**
  - En la condición del bucle de acumulación dentro de `read_and_stash`, asegurando la verificación sobre el acumulador estático y gestionando adecuadamente el corte limpio por fin de archivo (`bytes_read == 0`).
  - En el refinamiento de la función `update_stash`, para garantizar la liberación inmediata de memoria estática cuando el salto de línea coincide exactamente con el final de la lectura, eliminando la persistencia de cadenas vacías residuales en llamadas prematuras o cierres de archivo.

---

## Algoritmo y Decisiones Técnicas

### 1. Descomposición en Tres Fases Modulares

Para mantener cada función por debajo del límite estricto de 25 líneas de la Norma de 42 y asegurar una arquitectura limpia, la lógica se dividió en tres fases independientes:

1. **`read_and_stash` (Lectura y Acumulación):**
   - Utiliza un buffer temporal asignado dinámicamente de tamaño `BUFFER_SIZE + 1`.
   - Realiza llamadas sucesivas a `read` mientras el acumulador estático no contenga un salto de línea (`\n`) y queden bytes por leer (`bytes_read > 0`).
   - Cada bloque leído se añade al acumulador `stash` mediante una versión optimizada de `ft_strjoin` que libera automáticamente el puntero anterior, evitando la necesidad de variables temporales adicionales y fugas intermedias.
   - Si `read` devuelve error (`-1`), se libera inmediatamente tanto el buffer de lectura como el `stash` existente, retornando `NULL`.

2. **`extract_line` (Extracción de la Línea Actual):**
   - Recorre linealmente `stash` para localizar el primer `\n` o el terminador nulo `\0`.
   - Reserva memoria únicamente para los caracteres que forman la línea actual e incluye el salto de línea `\n` conforme a las especificaciones del *subject*.
   - Devuelve la línea lista para el consumidor.

3. **`update_stash` (Conservación del Remanente):**
   - Determina si existen caracteres posteriores al salto de línea.
   - Si no hay salto de línea o el `\n` era el último carácter disponible (`!stash[n] || !stash[n + 1]`), libera `stash` y retorna `NULL`, dejando la variable estática limpia sin reservas innecesarias.
   - Si quedan datos remanentes, extrae el fragmento sobrante mediante `ft_substr`, libera el bloque antiguo de `stash` y retorna la nueva cadena podada para la siguiente llamada.

### 2. Justificación del Buffer Dinámico en el Heap frente al Stack

El parámetro `BUFFER_SIZE` puede ser redefinido en compilación con valores extremos (desde `1` hasta `10000000`).
- Si se asignase el buffer en la pila de llamadas (*stack*) como array local (por ejemplo `char buf[BUFFER_SIZE]`), valores elevados provocarían inevitablemente un desbordamiento de pila (*stack overflow* / *segmentation fault*).
- Además, el uso de VLAs (*Variable Length Arrays*) está prohibido por la Norma.
- Por tanto, reservar `buf` dinámicamente mediante `malloc(BUFFER_SIZE + 1)` en cada invocación garantiza estabilidad absoluta con independencia del tamaño de buffer configurado.

### 3. Prevención de Fugas de Memoria y Residuos Estáticos

Un fallo frecuente en este proyecto ocurre cuando un archivo se lee parcialmente o cuando la última línea termina exactamente en `\n`. En este diseño:
- Se evita la creación de cadenas vacías `""` en el *heap*.
- Si un descriptor devuelve fin de archivo o error, el puntero estático siempre retorna a `NULL` tras liberar su contenido.
- `update_stash` devuelve un nuevo puntero asignado, garantizando que el paso por valor de C reasigne correctamente la variable estática en el ámbito de `get_next_line`.
