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

Plaintext

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
                  ┌─────────────────┴─────────────────┐
                  │   ¿Carácter %   │   Carácter normal
                  │ + especificador?│   ───────────────► write(1, &c, 1)[cite: 8]
                  └────────┬────────┘
                           │
                           ▼
                        ┌────────────────────────┐
                        │    ft_check_format     │
                        │(Distribuidor / Parseo) │
                        └───────────┬────────────┘
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



Para conectar este archivo principal con las funciones auxiliares de forma limpia y sin llenar `ft_printf.c` de muchos `if` (lo que violaría la Norma de 42 📏), la mejor estrategia es usar una función distribuidora / parseadora (por ejemplo, `ft_check_format`).

#### 🛠️ Estrategia de derivación

En lugar de poner los `if` de cada letra (`'c'`, `'s'`, `'d'`, etc.) dentro de `ft_printf`, creamos una función auxiliar que reciba el carácter especificador (`format[i]`) y la lista de argumentos `args`.

**1. La función distribuidora (`ft_check_format`)**

Usamos una estructura `switch` (o varios `if`) dentro de esta función auxiliar para derivar cada caso:

C

```
int	ft_check_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_print_char(va_arg(args, int));
	else if (specifier == 's')
		count += ft_print_str(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_print_nbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count += ft_print_hex(va_arg(args, unsigned int), specifier);
	else if (specifier == 'p')
		count += ft_print_ptr(va_arg(args, void *));
	else if (specifier == '%')
		count += ft_print_char('%');
	return (count);
}
```
