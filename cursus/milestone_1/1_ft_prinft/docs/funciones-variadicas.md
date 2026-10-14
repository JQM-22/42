# Funciones variádicas

#### ¿Qué es una función variádica?

Normalmente, una función en C sabe exactamente cuántos parámetros recibe (por ejemplo, `int sumar(int a, int b)` siempre recibe dos enteros).

Una función variádica es una función que puede recibir un número indeterminado de argumentos. Cuando llamas a `printf("Hola %s %d", "Mundo", 42)`, le estás pasando 3 argumentos.

Para poder leer esos argumentos "extra" que no están definidos en el prototipo, la librería `<stdarg.h>` nos proporciona un tipo de dato y tres herramientas (macros) clave:

#### 🛠️ Las 4 piezas clave de `<stdarg.h>`

1.  `va_list` _(El contenedor)_:

    Es el tipo de dato que guardará la lista de argumentos. Puedes imaginarlo como un puntero o una cinta transportadora que apunta al primer argumento variable.

    C

    ```
    va_list args;
    ```
2.  `va_start` _(El encendido)_:

    Inicializa la lista `args`. Necesita saber cuál es el último parámetro fijo de la función para saber dónde empiezan los argumentos variables.

    C

    ```
    va_start(args, format); // 'format' es la cadena const char *
    ```
3.  `va_arg` _(La extracción)_:

    Extrae el siguiente argumento de la lista. Necesitas decirle de qué tipo es ese dato (`int`, `char *`, etc.). Cada vez que ejecutas `va_arg`, la cinta avanza automáticamente al siguiente elemento.

    C

    ```
    int num = va_arg(args, int);        // Lee el siguiente argumento como entero
    char *str = va_arg(args, char *);   // Lee el siguiente argumento como string
    ```
4.  `va_end` _(La limpieza)_: Libera la memoria o limpia el estado de la lista cuando terminamos de leer todos los argumentos.

    C

    ```
    va_end(args);
    ```

#### 💡 Ejemplo visual del flujo dentro de tu `ft_printf`

C

```
int ft_printf(char const *format, ...)
{
    va_list args;
    int     count;

    count = 0;
    va_start(args, format); // 1. Inicializamos la lista

    // 2. Aquí haremos un bucle recorriendo 'format'
    // Si encontramos '%', usaremos va_arg(args, tipo) para obtener el valor.

    va_end(args);           // 3. Limpiamos la lista
    return (count);
}
```
