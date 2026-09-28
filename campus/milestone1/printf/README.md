*Este proyecto ha sido creado como parte del currículo de 42 por rtapiado.*

# ft_printf

## Descripción

El proyecto **ft_printf** consiste en reimplementar la función `printf` de la biblioteca estándar de C (`libc`). El objetivo principal es profundizar en el funcionamiento interno de las funciones variádicas en lenguaje C, el paso de argumentos a bajo nivel a través de la pila, la manipulación de diferentes tipos de datos y la conversión de formatos numéricos hacia sus representaciones textuales.

El resultado final es una biblioteca estática (`libftprintf.a`) que imita el comportamiento de la función original, gestionando adecuadamente los siguientes especificadores de formato:

- `%c`: Imprime un único carácter.
- `%s`: Imprime una cadena de caracteres (gestionando cadenas nulas como `(null)`).
- `%p`: Imprime un puntero (`void *`) en formato hexadecimal con prefijo `0x` (o `(nil)` en caso de puntero nulo).
- `%d`: Imprime un número decimal con signo en base 10.
- `%i`: Imprime un entero en base 10.
- `%u`: Imprime un número decimal sin signo (`unsigned int`) en base 10.
- `%x`: Imprime un número hexadecimal en base 16 en minúsculas.
- `%X`: Imprime un número hexadecimal en base 16 en mayúsculas.
- `%%`: Imprime el símbolo del porcentaje literal.

Cada llamada devuelve el número total de caracteres impresos con éxito por la salida estándar, o un valor negativo (`-1`) en caso de error.

---

## Instrucciones

### Compilación

El proyecto se compila utilizando el `Makefile` incluido, el cual genera la biblioteca estática `libftprintf.a` cumpliendo las reglas de compilación estipuladas (`-Wall -Wextra -Werror`):

```bash
# Compilar la biblioteca
make

# Limpiar archivos objeto (.o)
make clean

# Limpiar archivos objeto y la biblioteca generada
make fclean

# Recompilar el proyecto completo desde cero
make re
```

### Uso y Enlace

Para utilizar `ft_printf` en cualquier programa en C:

1. Incluye el archivo de cabecera `ft_printf.h` en tu código fuente:
   ```c
   #include "ft_printf.h"

   int main(void)
   {
       ft_printf("Hola, %s! El numero es: %d\n", "42", 42);
       return (0);
   }
   ```

2. Compila enlazando la biblioteca `libftprintf.a`:
   ```bash
   cc -Wall -Wextra -Werror main.c libftprintf.a -o mi_programa
   ./mi_programa
   ```

---

## Recursos

### Referencias Clásicas
- **Manual de Linux (man pages):**
  - `man 3 printf`: Formato y especificaciones de conversión.
  - `man 3 stdarg`: Uso y ciclo de vida de `va_list`, `va_start`, `va_arg` y `va_end`.
  - `man 2 write`: Comportamiento y retorno de la llamada al sistema de escritura.
- **Estándar C99 (ISO/IEC 9899:1999):** Promoción de argumentos por defecto (*default argument promotions*) en funciones variádicas.

### Uso de Inteligencia Artificial (IA)
En conformidad con las directrices de la versión 12.0 del currículo de 42, el uso de herramientas de asistencia basada en IA durante el proyecto se ha realizado con fines puramente formativos y de revisión, estructurado de la siguiente forma:

- **Tareas en las que se utilizó:**
  - Consulta conceptual sobre la promoción de tipos en funciones variádicas (`va_arg(args, int)` frente a tipos menores como `char`).
  - Planteamiento y ejecución de pruebas unitarias comparativas automatizadas frente al `printf` original de la biblioteca estándar de C.
- **Partes del proyecto en las que se empleó:**
  - En la verificación de robustez del analizador de formato para garantizar que secuencias inválidas o incompletas (como `%` huérfano al final de la cadena o paso de `NULL` como formato) retornen código de error `-1` en lugar de lecturas fuera de límites de memoria.

---

## Elección de Algoritmos y Estructura de Datos

### 1. Patrón Despachador (*Dispatcher*) y Simetría
En lugar de centralizar la lógica de impresión dentro del bucle de formato, se implementó un diseño modular dividido en dos capas:
- **`ft_printf.c`:** Actúa como controlador de flujo. Inicializa los argumentos variádicos con `va_start`, recorre linealmente la cadena de formato, imprime texto plano de forma inmediata y delega la interpretación de especificadores a una función despachadora (`ft_eval_format`).
- **`ft_printf_utils.c`:** Proporciona funciones atómicas especializadas por tipo (`ft_putchar`, `ft_putstr`, `ft_putnbr`, `ft_puthex`, `ft_putptr`). Cada función es la única responsable de calcular y retornar los bytes emitidos, garantizando la separación de responsabilidades y el cumplimiento estricto del límite de 25 líneas por función de la Norma.

### 2. Conversión Numérica Recursiva
Para las conversiones numéricas (`%d`, `%i`, `%u`, `%x`, `%X` y `%p`):
- Se descartó el uso de buffers estáticos invertidos y asignación dinámica de memoria (`malloc`), optando por **algoritmos recursivos**.
- **Ventajas:**
  - **Eficiencia en memoria:** Evita el consumo de memoria en el heap y el riesgo de fugas de memoria (*leaks*).
  - **Orden natural:** Al evaluar `n / base` en la llamada recursiva antes de escribir `n % base`, los dígitos se emiten directamente de izquierda a derecha.
  - **Conteo acumulativo:** El valor de retorno de cada llamada se suma de forma ascendente en el retorno de la pila de llamadas, garantizando un conteo exacto de bytes.

### 3. Prevención de Desbordamiento (*Overflow*) en `INT_MIN`
En arquitecturas de 32 bits en complemento a dos, el rango de un entero con signo va de `-2147483648` a `2147483647`. El valor absoluto de `INT_MIN` excede el rango de un `int`. Para evitar comportamientos indefinidos al negar el valor (`-n`), los cálculos matemáticos se promocionan a tipo `long` (64 bits), permitiendo operar de manera uniforme sin necesidad de casos especiales aislados.
