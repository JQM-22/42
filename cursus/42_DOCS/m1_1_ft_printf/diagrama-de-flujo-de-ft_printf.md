# Diagrama de flujo de ft\_printf

#### Responsabilidad de cada archivo

1. `ft_printf.c` (Controlador Central):
   * Inicializa las funciones variádicas (`va_start`).
   * Recorre la cadena `format` con el bucle `while`.
   * Si ve un carácter normal, llama a `write`.
   * Si detecta un `%`, lee el siguiente carácter y llama a la función auxiliar adecuada pasándole `va_arg`.
   * Finaliza con `va_end` y devuelve el total de caracteres impresos.
2. Funciones Auxiliares (Procesadores de Datos):
   * `ft_print_char.c`: Imprime caracteres individuales (`%c`) o el símbolo `%%`.
   * `ft_print_str.c`: Recorre e imprime una cadena (`%s`), controlando el caso de que sea `NULL`.
   * `ft_print_nbr.c`: Imprime enteros con o sin signo (`%d`, `%i`, `%u`).
   * `ft_print_hex.c`: Convierte e imprime números en base 16 (`%x`, `%X`) y direcciones de memoria/punteros (`%p`).
3. `ft_printf.h` (Cabecera):
   * Contiene los prototipos de todas las funciones anteriores para que se puedan llamar entre sí sin advertencias del compilador.

```
                        ┌────────────────────────┐
                        │      ft_printf.h       │
                        │  (Declaraciones y .h)  │
                        └───────────┬────────────┘
                                    │
                                    ▼
                        ┌────────────────────────┐
                        │      ft_printf.c       │
                        │ (Controlador Principal)│
                        └───────────┬────────────┘
                                    │
                  ┌─────────────────┼─────────────────┐
                  │   ¿Carácter %   │   Carácter normal
                  │ + especificador?│   ───────────────► write(1, &c, 1)
                  └────────┬────────┘
                           │
      ┌────────────────────┼────────────────────┬────────────────────┐
      ▼                    ▼                    ▼                    ▼
┌───────────────┐    ┌───────────────┐    ┌───────────────┐    ┌───────────────┐
│ ft_print_char │    │ ft_print_str  │    │ ft_print_nbr  │    │ ft_print_hex  │
│  (%c, %%)     │    │     (%s)      │    │  (%d, %i, %u) │    │ (%x, %X, %p)  │
└───────────────┘    └───────────────┘    └───────────────┘    └───────────────┘
```

#### Resumen rápido para la lógica:

1. `ft_printf.c`: Lee el string `format`. Si encuentra texto normal, lo imprime con `write`. Si detecta `%`, analiza la siguiente letra y redirige el flujo.
2. `ft_print_char.c`: Procesa un único carácter o el escape `%%`.
3. `ft_print_str.c`: Imprime cadenas completas y gestiona casos especiales como punteros a `NULL`.
4. `ft_print_nbr.c`: Gestiona la conversión e impresión de números enteros enteros con y sin signo (`base 10`).
5. `ft_print_hex.c`: Maneja las conversiones a hexadecimal (`base 16`), incluyendo letras en mayúsculas/minúsculas y la impresión de direcciones de memoria con su prefijo `0x`.

Como `ft_printf.c` es el "director de orquesta", cuando detecta un `%` evalúa el carácter siguiente y llama a la función adecuada:

* 🔤 Si ve `%c` o `%%` $$ $\rightarrow$ $$ Llama a `ft_print_char`.
* 📝 Si ve `%s` $$ $\rightarrow$ $$ Llama a `ft_print_str`.
* 🔢 Si ve `%d`, `%i` o `%u` $$ $\rightarrow$ $$ Llama a `ft_print_nbr`.
* 🔣 Si ve `%x`, `%X` o `%p` $$ $\rightarrow$ $$ Llama a `ft_print_hex`.
