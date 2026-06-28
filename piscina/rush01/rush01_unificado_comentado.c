/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* rush01_comentado.c                                 :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: joquinta <joquinta@alumno.42malaga.co      +#+  +:+       +#+        */
/* Created: 2026/06/28                           #+#   #+#         #+#      */
/* Updated: 2026/06/28                          ###   ########.fr        */
/* */
/* ************************************************************************** */

#include <unistd.h>

// ============================================================================
// 1. ARCHIVO: ft_print_error.c
// ============================================================================

void    ft_print_error(void)
{
    write(1, "Error\n", 6);
    // Escribe en la salida estándar (1) la palabra "Error" con su salto de línea.
}

// ============================================================================
// 2. ARCHIVO: ft_errors.c
// ============================================================================

int ft_errors(char *str)
{
    int i;
    // Variable para indexar y recorrer el string de argumentos.
    int count;
    // Contador para asegurarnos de que vienen exactamente 16 números válidos.

    i = 0;
    // Inicializa el índice del string a 0.
    count = 0;
    // Inicializa el contador de números encontrados a 0.
    while (str[i] != '\0')
    // Bucle que se ejecuta hasta llegar al final del string (carácter nulo).
    {
        if (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4')
        // Comprueba si el carácter actual es un número válido entre 1 y 4.
        {
            if (str[i + 1] == ' ' || str[i + 1] == '\0')
            // Verifica que justo después del número haya un espacio o sea el final del string.
            {
                count++;
                // Si la estructura del número es correcta, aumenta el contador de pistas válidas.
                i = i + 2;
                // Salta 2 posiciones en el string (el número y el espacio) para evaluar el siguiente.
            }
            else
            // Si después del número válido no hay un espacio o un final de línea...
                return (0);
                // Retorna 0 indicando que el formato no es válido.
        }
        else
        // Si el carácter actual no es un dígito del 1 al 4...
            return (0);
            // Retorna 0 inmediatamente debido a un carácter inválido.
    }
    if (count == 16)
    // Tras procesar todo el string, valida si se contaron exactamente 16 pistas.
        return (0);
        // Retorna 0, lo cual significa para este diseño: "No hay errores".
    return (1);
    // Si no sumó exactamente 16, retorna 1 (Sí hay error).
}

// ============================================================================
// 3. ARCHIVO: ft_convert.c
// ============================================================================

void    ft_convert(char *str, int num[16])
{
    int i;
    // Variable contadora para iterar sobre las 16 posiciones que necesitamos rellenar.

    i = 0;
    // Inicializa el contador a 0.
    while (i < 16)
    // Se repite exactamente 16 veces para extraer cada una de las pistas.
    {
        num[i] = str[i * 2] - '0';
        // Multiplica i*2 para saltarse los espacios del string, resta '0' para convertir el char a int y lo guarda.
        i++;
        // Incrementa el índice para ir a la siguiente posición del array de enteros.
    }
}

// ============================================================================
// 4. ARCHIVO: ft_try.c
// ============================================================================

int ft_try(int b[4][4], int row, int col, int numtry)
{
    int i;
    // Variable para recorrer las filas o columnas de la matriz.

    i = 0;
    // Inicializa el índice a 0.
    while (i < 4)
    // Bucle para chequear la fila actual completa.
    {
        if (b[row][i] == numtry)
        // Comprueba si el número que queremos intentar colocar ya existe en alguna columna de esta fila.
            return (0);
            // Si ya existe, rompe y retorna 0 (movimiento inválido por duplicado horizontal).
        i++;
        // Pasa a la siguiente columna de la fila.
    }
    i = 0;
    // Reinicia el índice a 0 para la siguiente comprobación.
    while (i < 4)
    // Bucle para chequear la columna actual completa.
    {
        if (b[i][col] == numtry)
        // Comprueba si el número que queremos intentar colocar ya existe en alguna fila de esta columna.
            return (0);
            // Si ya existe, rompe y retorna 0 (movimiento inválido por duplicado vertical).
        i++;
        // Pasa a la siguiente fila de la columna.
    }
    return (1);
    // Si superó ambos bucles sin retornar 0, significa que el número no se repite en su cruz. Retorna 1 (Válido).
}

// ============================================================================
// 5. ARCHIVO: ft_check_views.c
// ============================================================================

int ft_visible(int line[4])
{
    int i;
    // Índice para recorrer los 4 elementos de la línea analizada.
    int max;
    // Guarda la altura del edificio más alto visto hasta el momento.
    int count;
    // Contador de cuántos edificios son visibles desde esa perspectiva.

    i = 0;
    // Inicializa el índice a 0.
    max = 0;
    // Inicializa la altura máxima a 0 (cualquier edificio del 1 al 4 será mayor al principio).
    count = 0;
    // Inicializa el contador de edificios divisados en 0.
    while (i < 4)
    // Recorre los 4 edificios de la línea de manera secuencial.
    {
        if (line[i] > max)
        // Si el edificio actual es más alto que el rascacielos más alto que hemos visto antes...
        {
            max = line[i];
            // Actualiza el nuevo valor máximo con la altura de este edificio.
            count++;
            // Incrementa en 1 el contador de rascacielos que el observador logra ver.
        }
        i++;
        // Avanza al siguiente edificio de la línea.
    }
    return (count);
    // Devuelve el número total de edificios que se ven desde ese extremo.
}

int ft_check_views_l_r(int b[4][4], int row, int col, int num[16])
{
    int line[4];
    // Array temporal de 4 elementos para aislar y analizar la fila actual.
    int i;
    // Índice auxiliar para copiar los elementos.

    if (col == 3)
    // Clave de optimización: Solo realiza la comprobación cuando la fila actual está completamente llena (columna 3).
    {
        i = 0;
        // Inicializa el índice a 0.
        while (i < 4)
        // Bucle para copiar la fila del tablero al array temporal 'line'.
        {
            line[i] = b[row][i];
            // Copia el valor de izquierda a derecha.
            i++;
            // Siguiente elemento.
        }
        if (ft_visible(line) != num[8 + row])
        // Compara los edificios visibles de izquierda a derecha con las pistas correspondientes (pistas 8 a 11).
            return (0);
            // Si no coincide con la condición visual de la pista izquierda, descarta la combinación retornando 0.
        i = 0;
        // Reinicia el índice a 0.
        while (i < 4)
        // Bucle para copiar la misma fila pero de forma invertida (para evaluar la derecha).
        {
            line[i] = b[row][3 - i];
            // Copia los valores en orden inverso (del índice 3 al 0).
            i++;
            // Siguiente elemento.
        }
        if (ft_visible(line) != num[12 + row])
        // Compara los edificios visibles de derecha a izquierda con sus pistas correspondientes (pistas 12 a 15).
            return (0);
            // Si no coincide con la pista del extremo derecho, retorna 0.
    }
    return (1);
    // Si la columna no era la última (aún no se puede juzgar), o si pasó con éxito los test visuales, retorna 1.
}

int ft_check_views_t_b(int b[4][4], int row, int col, int num[16])
{
    int line[4];
    // Array temporal de 4 elementos para aislar y analizar la columna actual.
    int i;
    // Índice auxiliar para realizar las copias.

    if (row == 3)
    // Clave de optimización: Solo realiza la comprobación cuando la columna actual está completamente llena (fila 3).
    {
        i = 0;
        // Inicializa el índice a 0.
        while (i < 4)
        // Bucle para copiar los elementos verticales (la columna) al array 'line'.
        {
            line[i] = b[i][col];
            // Extrae los elementos fijando la columna e iterando sobre las filas de arriba a abajo.
            i++;
            // Siguiente fila.
        }
        if (ft_visible(line) != num[col])
        // Compara los edificios visibles desde arriba con las pistas de la fila superior (pistas 0 a 3).
            return (0);
            // Si la vista desde arriba no coincide con la pista, retorna 0.
        i = 0;
        // Reinicia el índice a 0.
        while (i < 4)
        // Bucle para copiar los elementos de la columna al revés (para evaluar la vista desde abajo).
        {
            line[i] = b[3 - i][col];
            // Extrae los elementos de abajo hacia arriba.
            i++;
            // Siguiente elemento.
        }
        if (ft_visible(line) != num[4 + col])
        // Compara los edificios visibles desde abajo con las pistas de la fila inferior (pistas 4 a 7).
            return (0);
            // Si la vista desde abajo no coincide con la pista, retorna 0.
    }
    return (1);
    // Si la fila no era la última o si las vistas cuadran perfectamente con las restricciones, retorna 1.
}

int ft_check_views(int b[4][4], int row, int col, int num[16])
{
    if (ft_check_views_l_r(b, row, col, num) == 0)
    // Ejecuta y comprueba si fallan las vistas horizontales (izquierda/derecha).
        return (0);
        // Si fallan, propaga el fallo devolviendo 0.
    if (ft_check_views_t_b(b, row, col, num) == 0)
    // Ejecuta y comprueba si fallan las vistas verticales (arriba/abajo).
        return (0);
        // Si fallan, propaga el fallo devolviendo 0.
    return (1);
    // Si ambas comprobaciones de visibilidad son válidas, da luz verde retornando 1.
}

// ============================================================================
// 6. ARCHIVO: ft_solve.c
// ============================================================================

int ft_solve(int b[4][4], int num[16], int row, int col)
{
    int numtry;
    // Variable para almacenar el número que vamos a testear en la celda actual (del 1 al 4).

    if (row == 4)
    // Condición de parada exitosa de la recursividad: Si hemos llegado a la fila 4 es porque rellenamos la 0, 1, 2 y 3 con éxito.
        return (1);
        // Retorna 1 indicando que el tablero completo está resuelto correctamente.
    if (col == 4)
    // Salto de línea: Si la columna llega a 4 significa que terminamos la fila actual.
        return (ft_solve(b, num, row + 1, 0));
        // Llama recursivamente a la función moviéndose al inicio de la siguiente fila (fila + 1, columna 0).
    numtry = 1;
    // Inicializa el número de prueba a 1.
    while (numtry <= 4)
    // Bucle para probar de forma secuencial los valores posibles del 1 al 4 en la celda.
    {
        if (ft_try(b, row, col, numtry) == 1)
        // Pregunta a ft_try si poner 'numtry' en esta posición no rompe las reglas de repetición básicas de la cruz.
        {
            b[row][col] = numtry;
            // Si es válido provisionalmente, asigna ese número a la celda del tablero.
            if (ft_check_views(b, row, col, num) == 1)
            // Pregunta si al colocar este número se siguen respetando los rascacielos que se deben ver desde fuera.
            {
                if (ft_solve(b, num, row, col + 1) == 1)
                // Llama recursivamente a ft_solve para intentar resolver la siguiente celda (misma fila, siguiente columna).
                    return (1);
                    // Si las llamadas del futuro encuentran la solución total del mapa, propaga el éxito devolviendo 1.
            }
            b[row][col] = 0;
            // BACKTRACKING: Si los pasos siguientes fallaron, borra el número puesto y lo vuelve a dejar a 0 para probar el siguiente 'numtry'.
        }
        numtry++;
        // Incrementa para intentar probar el siguiente número (ej. pasar de probar el 2 al 3).
    }
    return (0);
    // Si probó del 1 al 4 en esta celda y ninguno llevó a una solución válida, retorna 0 informando al paso anterior que debe cambiar su decisión.
}

// ============================================================================
// 7. ARCHIVO: ft_print_board.c
// ============================================================================

void    ft_print_board(int b[4][4])
{
    int     row;
    // Índice para recorrer las filas de la matriz.
    int     col;
    // Índice para recorrer las columnas de la matriz.
    char    c;
    // Variable char temporal para poder usar la función write.

    row = 0;
    // Comienza en la primera fila (0).
    while (row < 4)
    // Itera a través de las 4 filas del tablero.
    {
        col = 0;
        // Reinicia a la primera columna (0) para cada nueva fila.
        while (col < 4)
        // Itera a través de las 4 columnas de la fila.
        {
            c = b[row][col] + '0';
            // Convierte el número entero a su equivalente en carácter ASCII (ej: 3 + '0' = '3').
            write(1, &c, 1);
            // Escribe el carácter numérico en la pantalla.
            if (col < 3)
            // Condición para no poner un espacio en blanco después del último número de la fila.
                write(1, " ", 1);
                // Imprime un espacio separador entre los números de la misma fila.
            col++;
            // Avanza a la siguiente columna.
        }
        write(1, "\n", 1);
        // Al terminar de imprimir las 4 columnas de una fila, escribe un salto de línea en la pantalla.
        row++;
        // Pasa a procesar la siguiente fila del tablero.
    }
}

// ============================================================================
// 8. ARCHIVO: main.c
// ============================================================================

int main(int argc, char *argv[])
{
    if (argc != 2)
    // Valida que el número de argumentos del programa sea estrictamente 2 (el nombre del ejecutable `./rush-01` y el string de pistas).
    {
        ft_print_error();
        // Si no se pasaron los argumentos correctos (ej: no pusiste nada o pusiste dos strings), imprime "Error\n".
        return (0);
        // Termina la ejecución del programa de forma segura.
    }
    if (ft_errors(argv[1]) == 1)
    // Envía el string de entrada (pistas) a la función de validación de errores.
    {
        ft_print_error();
        // Si ft_errors retorna 1 (lo que indica que hay fallos de caracteres o formato), imprime "Error\n".
        return (0);
        // Finaliza el programa debido a parámetros de entrada incorrectos.
    }
    ft_logic(argv[1]);
    // Si la entrada superó todos los filtros, invoca a ft_logic pasándole el string validado para arrancar el juego.
    return (0);
    // Finalización exitosa estándar de la función main.
}

// ============================================================================
// 9. ARCHIVO: ft_logic.c
// ============================================================================

void    ft_logic(char *str)
{
    int b[4][4];
    // Declaración de la matriz bidimensional de 4x4 que actuará como nuestro tablero de juego.
    int num[16];
    // Declaración del array unidimensional de 16 posiciones para almacenar las pistas numéricas limpias.
    int row;
    // Variable índice para limpiar filas.
    int col;
    // Variable índice para limpiar columnas.

    row = 0;
    // Comienza en la fila 0.
    while (row < 4)
    // Bucle externo para recorrer las filas del tablero y ponerlas a cero.
    {
        col = 0;
        // Comienza en la columna 0.
        while (col < 4)
        // Bucle interno que pone a 0 cada una de las 4 celdas de la fila actual.
        {
            b[row][col] = 0;
            // Asigna 0 a la celda (vacía/sin resolver).
            col++;
            // Pasa a la siguiente celda.
        }
        row++;
        // Pasa a la siguiente fila.
    }
    ft_convert(str, num);
    // Llama a ft_convert para transformar el string de entrada en el array de enteros 'num'.
    if (ft_solve(b, num, 0, 0) == 1)
    // Arranca el resolvedor por backtracking desde la posición inicial del tablero (fila 0, columna 0).
        ft_print_board(b);
        // Si ft_solve devuelve 1, significa que encontró la solución y se procede a pintarla en la consola.
    else
    // Si devuelve 0, significa que el puzzle con esas pistas concretas es matemáticamente imposible de resolver.
        ft_print_error();
        // Imprime el mensaje "Error\n".
}