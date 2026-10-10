*Este proyecto ha sido creado como parte del currículo de 42 por joquinta.*

---

# ft_printf

## Descripción

El proyecto **ft_printf** consiste en la reimplementación de la famosa función `printf()` de la librería estándar de C (`libc`). 

El objetivo principal es comprender y manejar las **funciones variádicas** en C (aquellas que aceptan un número indeterminado de argumentos utilizando la librería `<stdarg.h>`)[cite: 1, 3, 8], así como afianzar la gestión de formatos de conversión, punteros y bases numéricas (decimal y hexadecimal).

### Conversiones Soportadas:
- `%c`: Imprime un solo carácter.
- `%s`: Imprime una cadena de caracteres[cite: 10].
- `%p`: Imprime el puntero `void *` dado como argumento en formato hexadecimal[cite: 10].
- `%d` / `%i`: Imprime un número entero con signo en base 10[cite: 10].
- `%u`: Imprime un número decimal sin signo en base 10[cite: 10].
- `%x`: Imprime un número hexadecimal en base 16 en minúsculas[cite: 10].
- `%X`: Imprime un número hexadecimal en base 16 en mayúsculas[cite: 10].
- `%%`: Imprime un símbolo de porcentaje[cite: 10].

### Arquitectura del proyecto

La estructura de ft_printf cuenta con los siguientes archivos principales:
- ft_printf.h: El archivo de cabecera con los prototipos de las funciones, las librerías necesarias (<stdarg.h>, <unistd.h>) y la inclusión de libft (si se utiliza).   
- ft_printf.c: La función principal que recorre la cadena format y gestiona las funciones variádicas (va_start, va_arg, va_end).  
- ft_check_format.c: La función distribuidora, se encarga de reconocer cada caracter especificador y llamar a las funciones "print" correspondientes. 
- Módulos de impresión auxiliaries: Funciones encargadas de procesar cada tipo de conversión especifico (%c, %s, %p, %d/%i, %u, %x/%X).
    - ft_print_char.c: Procesa un único carácter o el escape %%.
    - ft_print_str.c: Imprime cadenas completas y gestiona casos especiales como punteros a NULL.
    - ft_print_nbr.c: Gestiona la conversión e impresión de números enteros enteros con y sin signo (base 10).
    - ft_print_hex.c: Maneja las conversiones a hexadecimal (base 16), incluyendo letras en mayúsculas/minúsculas y la impresión de direcciones de memoria con su prefijo 0x.
- Makefile: Encargado de compilar tu librería libftprintf.a. 


```mermaid
graph TD
    A[ft_printf.h] --> B[ft_printf.c]
    B --> C{ft_check_format}
    C --> D[ft_print_char <br> %c, %%]
    C --> E[ft_print_str <br> %s]
    C --> F[ft_print_nbr <br> %d, %i, %u]
    C --> G[ft_print_hex <br> %x, %X, %p]
```

---

##  Instrucciones

### Requisitos Previos e Instalación

Para compilar y probar este proyecto necesitarás un entorno Unix con `gcc` o `clang` y `make`.

### Compilación

Clona el repositorio e ingresa a la carpeta del proyecto:

git clone <url-del-repositorio>
cd ft_printf

Para generar la librería estática libftprintf.a, ejecuta:

make

Reglas Disponibles del Makefilemake 
- make all: Compila el proyecto y genera la librería libftprintf.a.
- make clean: Elimina los archivos objeto (.o).   
- make fclean: Elimina los archivos objeto y la librería libftprintf.a.   
- make re: Ejecuta fclean y vuelve a compilar todo (all).   

Compila enlazando con la librería creada:

En Terminal:

gcc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf

## Recursos
Referencias y Documentación
Manual de C para printf: man 3 printf

Documentación oficial de <stdarg.h> y funciones variádicas en C (va_start, va_arg, va_copy, va_end).

### Uso de Inteligencia Artificial
En cumplimiento de las normas de integridad del proyecto y de la sección Recursos del Readme:   
Tareas donde se usó IA: Explicación conceptual sobre cómo funcionan las funciones variádicas (stdarg.h), sugerencias para estructurar la arquitectura de archivos del proyecto y revisión inicial de la plantilla del archivo README.md.   
Partes del proyecto donde se utilizó: Fase teórica previa y maquetación de la documentación. Todo el código C y la lógica de parseo/impresión han sido analizados, comprendidos e implementados directamente por el estudiante para garantizar un aprendizaje real y preparar la evaluación entre pares y exámenes.

## Elección de Algoritmo y Estructura de Datos

### Estructura de Datos

No se utilizaron estructuras de datos complejas (como listas enlazadas o árboles) ni buffers dinámicos dinámicamente asignados, conforme a las restricciones del subject que prohíben la gestión de buffer del printf original.   
Se utiliza un enfoque iterativo directo apoyado en un contador acumulativo (int count) que rastrea la cantidad exacta de bytes/caracteres escritos mediante la llamada al sistema 

### Algoritmo de Procesamiento

1. Recorrido del formato: 
    Se itera caracter por caracter sobre el string format recibido.   

2. Detección de especificador:
    - Si se encuentra un caracter común, se escribe directamente en    STDOUT (write(1, ...)) e incrementa el contador.
    - Si se detecta un %, se consulta el siguiente carácter para identificar la conversión solicitada (c, s, p, d, i, u, x, X, %)[cite: 10].
3. Despacho y Conversión: Se extrae el siguiente argumento utilizando va_arg y se deriva a la función auxiliar correspondiente:   
    - Bases numéricas / Hexadecimal (%x, %X, %p): Se aplica un algoritmo recursivo de división e impresión mediante módulo (base 10 y base 16).
    - Manejo de Casos Nulos: Se comprueban punteros NULL (imprimiendo (null) para %s o (nil)/0x0 para %p según el estándar de la libc)[cite: 10].Retorno: Retorna el valor acumulado del número total de caracteres impresos en pantalla.