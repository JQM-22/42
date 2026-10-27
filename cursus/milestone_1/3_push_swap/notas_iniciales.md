
Nota sobre la marcha de lo que escucho:
- investigar, algoritmo turco, metodo simple de min max

github con explicaciones
kurro 

# pizarra 1

## 📌 Transcripción y Traducción de NotasPUSH-SWAP 
### (Pasos Generales)
1. Parseo (Parse): Llenar la pila a (stack a) con los valores de entrada.   
2. Push/Swap: Diferentes métodos para mover valores en las pilas a/b (sa, sb, ss, ...).   
    - Push: pa, pb   
    - Swap: sa, sb, ss   
    - Rotate: ra, rb, rr   
    - Reverse (Rotate): rra, rrb, rrr (en la pizarra indica la acción de invertir o rotar al revés).   
3. Algoritmos de ordenación (Sorting algos):
    - Simple, medio, complejo, personalizado (simple, medium, complex, custom).   
4. Desorden (Disorder): “¿Qué tan lejos está a de estar ordenada?”   

### Detalles de Parseo y Estructura de Datos
- Parseo (Parse):
     - Los valores no deben repetirse.   
     - Uso de ft_atoi(av[x]) $\rightarrow$ llenar la pila (fill stack).   
     - Banderas / pruebas de rendimiento (flags / bench).   
     - Estructura de la pila (stack structure):

```c
typedef struct s_stack
{
    int value;
    int index;
    int position;
} t_stack;
```

(Nota: También muestra conectar t_list->content = t_stack si usas listas enlazadas tipo t_list).   


## 🔍 Revisión Técnica 
- (¿Es correcto?)
- El esquema conceptual planteado en la pizarra es completamente correcto y acertado para afrontar el proyecto push_swap:
    - Parseo y validación: Es fundamental comprobar que no hay duplicados, que todos los argumentos son enteros dentro de los límites (INT_MAX / INT_MIN) y numéricos válidos.
    - Operaciones permitidas: Las listas de comandos descritas (pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr) corresponden exactamente a la especificación del sujeto de 42. (Nota: en la pizarra de la sección de rotate/reverse faltaba una ligera distinción gráfica en las letras, pero la lógica de las 4 familias de comandos es idéntica a la oficial).
    - Estructura de datos (t_stack): Guardar el value (valor original), el index (índice simplificado/rank) y la position (posición actual en la pila) es la mejor práctica común en 42 para implementar algoritmos como Turco (Turk algorithm), Radix o K-Sort de forma eficiente.



# pizarra 2

## 📌 Transcripción de la PizarraPUSH_SWAP. 

1. Plantea las estructuras necesarias

```c
t_stack: int size   
int *head   
    t_stack *next   (...)   
    t_context:t_stack a   
t_stack b   (...)
```

2. Parser:
- Chequea que:
    - No haya duplicados.   $\text{INT\_MIN} \le n \le \text{INT\_MAX}$.   
    - Entradas inválidas: "abc", "+-42" ❌.   
    - Argumentos vacíos: "" ❌.   
    - Consideraciones que no estén en el subject.   
- Guarda las flags:
    - --simple, --medium, --complex, --adaptive y --bench.   
    - (Devuelve ERROR si lees 2 flags de estrategia).   

3. Movimientos y algoritmospa, 
- pb, ra, rb, ...   
- RECOMENDADO:
    - Simple: Selection Sort   
    - Medio: Chunking Sort   
    - Complejo: Radix Sort   

4. MAIN:
    1. Parseo   
    2. Construir el stack A   
    3. Leer flags   
    4. Seleccionar algoritmo   
    5. Imprimir los movimientos   
    6. (Benchmark, si hay flag --bench)   
    7. Libera el stack   
    
## CONSEJO 
!!!Haz el código pensando en meter una posible nueva flag.   

## 🔍 Revisión Técnica 
- (¿Es correcto?)
- El planteamiento de la pizarra es muy acertado y completo, especialmente si estás implementando una versión extendida de Push Swap (o con bonus/flags de evaluación):
1. Estructuras de datos:
    - Separar el contexto general (t_context) de los nodos o pilas (t_stack) facilita enormemente la gestión del estado general del programa y el paso de parámetros entre funciones.
2. Parseo y casuísticas bordes:
    - Comprobar la ausencia de duplicados, el rango de enteros INT_MAX / INT_MIN y rechazar entradas con signos erróneos ("+-42") o strings vacíos ("") cubre todos los casos de error estándar exigidos por el subject oficial de 42.
3. Estrategia de algoritmos:
    - La división por complejidad (Simple/Medio/Complejo) es la habitual:
        - Selection Sort / Insertion Sort: Para pocos elementos ($\le 5$).
        - Chunking / Turk Algorithm / Radix Sort: Estrategias clave para batches grandes (100 y 500 números) para mantenerse dentro del límite máximo de movimientos permitido.
4. Gestión de memoria:
    - El paso 7 del main (Libera el stack) es imprescindible en 42 para evitar memory leaks (comprobado rigurosamente con Valgrind o la flag -fsanitize=address).



# 📌 Resumen Esquematizado del Subject. 

1. Estructura General y Trabajo en Equipo
    - Modalidad: Proyecto en grupo de 2 personas. Ambos deben entender y explicar el 100% del código.   
    - Entregables: Repositorio Git con Makefile, archivos .c y .h, además del README.md obligatorio con autorías detalladas.   
2. Reglas del Programa y Operaciones Permitidas
     Tienes dos pilas o stacks (a y b). El objetivo es ordenar los números en a de forma ascendente usando el mínimo de operaciones posibles.   
    - Swap (sa, sb, ss): Intercambia los 2 primeros elementos del stack.   
    - Push (pa, pb): Pasa el primer elemento de un stack al otro.   
    - Rotate (ra, rb, rr): Mueve el elemento superior al fondo del stack.   
    - Reverse Rotate (rra, rrb, rrr): Mueve el elemento del fondo a la parte superior.   

3. Requisitos del Parsing y Flags de Ejecución
    - Validación: Comprobar que no existan duplicados, cadenas vacías (""), valores que no sean enteros o números fuera del rango INT_MIN a INT_MAX. 
    Retornar Error\n por stderr si falla algo.   
    - Flags de Selección de Algoritmo:
        - --simple $\rightarrow$ Fuerza algoritmo $O(n^2)$.   
        - --medium $\rightarrow$ Fuerza algoritmo $O(n\sqrt{n})$.   
        - --complex $\rightarrow$ Fuerza algoritmo $O(n \log n)$.   
        - --adaptive $\rightarrow$ Comportamiento por defecto (calcula el Índice de Desorden).   
    - Flag de Modo Benchmark (--bench): Muestra por stderr las métricas (porcentaje de desorden, estrategia usada, conteo total y desglose de operaciones).   

4. Las 4 Estrategias de Algoritmos Exigidas
    - Simple $O(n^2)$: Ej. Selection Sort, Bubble Sort o Insertion Sort adaptado a stacks.   
    - Intermedio $O(n\sqrt{n})$: Ej. Chunking Sort dividiendo el stack en $\sqrt{n}$ bloques/mallas.   
    - Complejo $O(n \log n)$: Ej. Radix Sort, Merge Sort o Quick Sort adaptado a stacks.   
    - Adaptativo (Por defecto): Calcula el índice de desorden antes de cualquier movimiento:   
        - Desorden $< 0.2$: Debe ejecutar en $O(n)$.   
        - Desorden $0.2 \le d < 0.5$: Debe ejecutar en $O(n\sqrt{n})$.   
        - Desorden $\ge 0.5$: Debe ejecutar en $O(n \log n)$.   

5. Umbrales de Rendimiento para la Evaluación
    - 100 números:
        - $< 2000$ ops (Aprobado justo)   
        - $< 1500$ ops (Bueno)   
        - $< 700$ ops (Excelente)  
    - 500 números:
        - $< 12000$ ops (Aprobado justo)   
        - $< 8000$ ops (Bueno)   
        - $< 5500$ ops (Excelente)   

6. Parte Bonus (checker)
    - Crear el binario checker que reciba el stack inicial como argumento.   
    - Lee las instrucciones emitidas por stdin y las ejecuta.   
    - Imprime OK\n si a queda ordenado y b vacío; si no, imprime KO\n.   
    
### 🔄 Esquema de Flujo de Trabajo (Fases del Proyecto)

```mermaid
flowchart TD
    F1["FASE 1: Arquitectura & Parsing de Entrada"]
    F2["FASE 2: Estructura de Datos y Operaciones"]
    F3["FASE 3: Medición y Cálculo de Desorden"]
    F4["FASE 4: Desarrollo de los 4 Algoritmos"]
    F5["FASE 5: Selector, Flags y Modo Benchmark"]
    F6["FASE 6: Bonus, Readme y Pruebas Finales"]

    F1 --> F2
    F2 --> F3
    F3 --> F4
    F4 --> F5
    F5 --> F6
```
## Detalle por Fases:
## - FASE 1: Parsing y Validación de Entradas
    - Diseñar la lectura de argc / argv.   
    - Crear funciones de verificación: detección de signos inválidos, no numéricos, límites de INT_MIN / INT_MAX y búsqueda de valores duplicados.   
    - Controlar la impresión adecuada de Error\n.   

## - FASE 2: Estructuras y Primitivas del Stack
- Definir la estructura t_stack (usualmente mediante listas doblemente enlazadas con índices/rangos simplificados):

```c
function compute_disorder(stack a):
mistakes = 0
total_pairs = 0
for i from 0 to size(a)-1:
for j from i+1 to size(a)-1:
total_pairs += 1
if a[i] > a[j]:
mistakes += 1
return mistakes / total_pairs
```
### 🧮 Función para el Cálculo del Índice de Desorden (con Listas Enlazadas)

Esta función traduce el pseudocódigo del subject a **C estricto bajo la Norma de 42**[cite: 6, 14]:
* Sustituye los bucles `for` por `while`.
* Respeta el límite de variables locales (máximo 4 variables declaradas al inicio)[cite: 6].
* Utiliza tipo `long` para evitar desbordamientos aritméticos al acumular comparaciones de pares.
* Aplica conversión explícita (*casting*) a `double` para devolver el ratio en el intervalo $[0.0, 1.0]$ sin truncar a entero.

---

#### Definición de la estructura de referencia (`push_swap.h`)
```c
typedef struct s_stack
{
    int             value;
    int             index;
    struct s_stack  *next;
    struct s_stack  *prev;
}   t_stack;
```
Implementacion de funcion de calculo de desorden:

```c
double	compute_disorder(t_stack *a)
{
	t_stack	*current;
	t_stack	*runner;
	long	mistakes;
	long	total_pairs;

	if (!a || !a->next)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	current = a;
	while (current && current->next)
	{
		runner = current->next;
		while (runner)
		{
			total_pairs++;
			if (current->value > runner->value)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
	}
	return ((double)mistakes / (double)total_pairs);
}
```
    💡 Puntos clave a recordar
    Momento de ejecución: Debe calcularse sobre el stack a antes de emitir o ejecutar cualquier movimiento (pa, pb, ra, etc.)[cite: 14].

    Escala de salida:

    0.0: Stack perfectamente ordenado de menor a mayor[cite: 14].

    1.0: Stack en orden estrictamente inverso (desorden máximo)[cite: 14].

    Valor intermedio: Determina el umbral para el algoritmo adaptativo (< 0.2, 0.2 - 0.5, ≥ 0.5).

- Programar de forma aislada las 11 instrucciones requeridas (sa, sb, pa, pb, ra, rb, rra, rrb, etc.) para asegurar que modifiquen el stack de forma impecable:

### 🔄 Operaciones Permitidas en Push_swap

#### 1. Swap (Intercambio)
* `sa` (**swap a**): Intercambia los dos primeros elementos en la cima del stack a[cite: 12]. No realiza ninguna acción si el stack tiene un elemento o está vacío[cite: 12].
* `sb` (**swap b**): Intercambia los dos primeros elementos en la cima del stack b[cite: 12]. No realiza ninguna acción si el stack tiene un elemento o está vacío[cite: 12].
* `ss`: Ejecuta `sa` y `sb` de forma simultánea[cite: 12].

#### 2. Push (Empujar / Transferir)
* `pa` (**push a**): Toma el primer elemento disponible en la cima del stack b y lo coloca en la cima del stack a[cite: 13]. No realiza ninguna acción si b está vacío[cite: 13].
* `pb` (**push b**): Toma el primer elemento disponible en la cima del stack a y lo coloca en la cima del stack b[cite: 13]. No realiza ninguna acción si a está vacío[cite: 13].

#### 3. Rotate (Rotación hacia arriba)
* `ra` (**rotate a**): Desplaza hacia arriba todos los elementos del stack a en una posición[cite: 13]. El elemento situado en la cima pasa a ser el último[cite: 13].
* `rb` (**rotate b**): Desplaza hacia arriba todos los elementos del stack b en una posición[cite: 13]. El elemento situado en la cima pasa a ser el último[cite: 13].
* `rr`: Ejecuta `ra` y `rb` de forma simultánea[cite: 13].

#### 4. Reverse Rotate (Rotación inversa hacia abajo)
* `rra` (**reverse rotate a**): Desplaza hacia abajo todos los elementos del stack a en una posición[cite: 13]. El elemento situado en el fondo pasa a ser la nueva cima[cite: 13].
* `rrb` (**reverse rotate b**): Desplaza hacia abajo todos los elementos del stack b en una posición[cite: 13]. El elemento situado en el fondo pasa a ser la nueva cima[cite: 13].
* `rrr`: Ejecuta `rra` y `rrb` de forma simultánea[cite: 13].   

## - FASE 3: Cálculo del Índice de Desorden
    - Implementar la función compute_disorder para evaluar el porcentaje de errores/inversiones en el orden del stack inicial.   

## - FASE 4: Algoritmos de Ordenación
    - Casos pequeños (2 a 5 elementos): Hardcodear casos óptimos muy rápidos (p. ej., ordenar 3 números en $\le 2$ movimientos).   
    - Algoritmo Simple ($O(n^2)$): Selection/Insertion sort para el flag --simple.   
    - Algoritmo Intermedio ($O(n\sqrt{n})$): Chunking sort.   
    - Algoritmo Complejo ($O(n \log n)$): Radix sort o Turk Algorithm optimizado.   
    - Algoritmo Adaptativo: Enrutador dinámico que llama a los métodos anteriores según el umbral de desorden calculado en la Fase 3.   

## - FASE 5: Modos Especiales (Flags & Benchmarks)
    - Parsear las opciones --simple, --medium, --complex y --adaptive.   
    - Implementar la flag opcional --bench para emitir el resumen de rendimiento por stderr.   

## - FASE 6: Bonus (checker), Pruebas y Documentación
    - Desarrollar el programa checker para leer comandos de stdin.   
    - Redactar el README.md obligatorio con autorías, justificaciones teóricas de algoritmos y descripciones de uso de IA.   
    - Realizar pruebas masivas para garantizar 0 fugas de memoria (leaks) y cumplir los márgenes de operaciones requeridos para 100 y 500 enteros.   


Para conseguir la puntuación de Rendimiento Excelente en todos los rangos (<700 operaciones para 100 números y  <5500 operaciones para 500 números), se deben elegir muy bien los algoritmos para cada una de las 4 estrategias exigidas por el subject.   

### 📊 Esquema General de Algoritmos Posibles
```mermaid
flowchart TD
    ROOT["Estrategias de Ordenación"]

    S1["1. Simple O(n²)"]
    S2["2. Intermedio O(n√n)"]
    S3["3. Complejo O(n log n)"]
    S4["4. Adaptativo (Custom)"]

    ROOT --> S1
    ROOT --> S2
    ROOT --> S3
    ROOT --> S4

    S1_1["Selection Sort"]
    S1_2["Insertion Sort"]
    S1_3["Bubble Sort"]
    S1 --> S1_1
    S1 --> S1_2
    S1 --> S1_3

    S2_1["Chunking Sort"]
    S2_2["Bucket Sort (√n buckets)"]
    S2_3["Block Partition"]
    S2 --> S2_1
    S2 --> S2_2
    S2 --> S2_3

    S3_1["Radix Sort (LSD)"]
    S3_2["Turk Algorithm"]
    S3_3["Quick Sort / Merge Sort"]
    S3 --> S3_1
    S3 --> S3_2
    S3 --> S3_3

    S4_1["Matriz de Decisión según Desorden<br/>• &lt; 0.2: O(n)<br/>• 0.2 - 0.5: O(n√n)<br/>• ≥ 0.5: O(n log n)"]
    S4 --> S4_1
```

### 🔍 Análisis de Algoritmos por Categóría
1. Estrategia Simple: 
O(n 2)

    - Opción A: Selection Sort Adaptado

        Cómo funciona: Busca el elemento mínimo en la pila a, lo rota hasta la cima y lo pasa (pb) a la pila b. Al terminar, devuelve todo a a (pa).

        Rendimiento: Pobre para listas grandes ( >2000 ops en 100 números). Cumple solo el requisito teórico.   

        Dificultad de implementación: Muy Baja (1/5).

    - Opción B: Insertion Sort Adaptado

        Cómo funciona: Toma elementos de a a b manteniéndolos ordenados en b insertándolos en su posición correcta.

        Rendimiento: Algo mejor en casos parcialmente ordenados.

        Dificultad de implementación: Baja (2/5).

💡 Recomendación para el flag --simple: Selection Sort. Dado que se usará para probar la flag --simple, lo ideal es la menor complejidad de código posible.

2. Estrategia Intermedia: 
O(n n)

    - Opción A: Chunking Sort (Por Bloques / Rangos)

        Cómo funciona: Divide los valores normalizados (índices de 0 a N−1) en N bloques. Envía a b primero los elementos del bloque más pequeño, usando rb para colocar los mayores arriba y los menores abajo dentro de b. Luego se devuelven a a de forma óptima.

        Rendimiento: Muy Bueno (~600 ops para 100 números, ~5500 ops para 500 números).

        Dificultad de implementación: Media (3/5).

    - Opción B: Bucket Sort adaptado a Stacks

        Cómo funciona: Similar a Chunking, pero repartiendo en n intervalos rígidos.

        Rendimiento: Bueno, pero genera más operaciones extras en las fronteras entre buckets.

        Dificultad de implementación: Media-Alta (3.5/5).

💡 Recomendación para el flag --medium: Chunking Sort. Es la implementación estándar para cumplir O(n n), ofreciendo un excelente equilibrio entre número de operaciones y sencillez conceptual.   

3. Estrategia Compleja: 
O(nlogn)
    - Opción A: Radix Sort (LSD en base 2 o base 4)

        Cómo funciona: Analiza los bits de los números ordenados por índice. Pasa a b los números que tienen un 0 en el bit actual y mantiene en a los que tienen 1.

        Rendimiento: Regular/Aceptable (~1100 ops en 100 núm, ~6700 ops en 500 núm). Pasa el corte del subject, pero no llega al nivel Excelente.   

        Dificultad de implementación: Muy Baja (1.5/5).

    - Opción B: Turk Algorithm (Algoritmo del Turco / Push Cost Algorithm)

        Cómo funciona: Asigna un "coste de operaciones" a cada nodo de a para ser insertado en su posición correcta dentro de b (combinando rr, rrr, ra, rb, etc.). Envía siempre el nodo con menor coste acumulado.

        Rendimiento: EXCELENTE (~550-620 ops para 100 números; ~4800-5300 ops para 500 números).

        Dificultad de implementación: Media-Alta (4/5).

    - Opción C: Quick Sort / Merge Sort adaptado

        Cómo funciona: Particiona recursivamente las pilas usando pivotes.

        Rendimiento: Bueno, pero la sobrecoste de llamadas recursivas y manejo de sub-stacks en C complica mucho el código.

        Dificultad de implementación: Alta (4.5/5).

💡 Recomendación para el flag --complex: Turk Algorithm. Es el mejor candidato si el objetivo es alcanzar el rango Excelente en operaciones.   

4. Estrategia Adaptativa (Custom / Por Defecto)
   
El subject exige que la estrategia por defecto elija internamente el método según el índice de desorden:   

- Desorden  <0.2 (O(n) exigido):   

    Algoritmo: Adaptive Insertion / Linear Fix. Identifica los 1 o 2 elementos fuera de sitio mediante una pasada lineal y realiza los swaps/rotaciones mínimos necesarios.

    Rendimiento: Extremadamente bajo en movimientos (<2n operaciones).

- Desorden  0.2≤d<0.5 (O(n n) exigido):   

    Algoritmo: Chunking Sort configurado con tamaño de bloque óptimo (≈ n ).

- Desorden ≥0.5 (O(nlogn) exigido):   

    Algoritmo: Turk Algorithm (o Radix totalmente optimizado).

### Matriz de comparativa de algoritmos

| Algoritmo | Categoría Exigida | Rendimiento ops (100 / 500) | Calificación de Rendimiento | Dificultad | Puntuación Global (Balón de Oro) |
| :--- | :--- | :--- | :--- | :---: | :--- |
| **Selection Sort** | Simple $O(n^2)$ | $>2500$ / $>30000$ | Insuficiente (solo para flag) | 1 / 5 | ⭐⭐⭐ (Ideal para cumplir `--simple`) |
| **Radix Sort (Base 2)** | Complejo $O(n \log n)$ | $\approx 1100$ / $\approx 6800$ | Aprobado Justo / Bueno | 1.5 / 5 | ⭐⭐⭐ (Muy fácil pero no "Excelente") |
| **Chunking Sort** | Intermedio $O(n\sqrt{n})$ | $\approx 600$ / $\approx 5500$ | Excelente | 3 / 5 | ⭐⭐⭐⭐⭐ (Imprescindible) |
| **Turk Algorithm** | Complejo / Custom | $\approx 580$ / $\approx 5100$ | Excelente Top | 3.8 / 5 | ⭐⭐⭐⭐⭐ (El mejor para nota máxima) |
| **Quick/Merge Sort** | Complejo $O(n \log n)$ | $\approx 700$ / $\approx 6000$ | Bueno | 4.5 / 5 | ⭐⭐ (Demasiado complejo en C) |

### 🏆 Veredicto y Hoja de Ruta para Desarrollar
Para conseguir la nota máxima/excelente con la relación rendimiento/esfuerzo más óptima:

- Estrategia Simple (--simple): Implementa Selection Sort. Tardarás 1 hora en programarlo y cumple el requisito.   

- Estrategia Intermedia (--medium): Implementa Chunking Sort. Cubrirá el requisito de 
O(n n) con métricas en el límite de la excelencia.   


- Estrategia Compleja (--complex): Implementa el Turk Algorithm. Garantiza entrar holgadamente en el rango Excelente (<700 en 100 números y <5500 en 500 números).   

- Estrategia Adaptativa (--adaptive): Enruta según el índice de desorden:   

        <0.2→ Corrección lineal O(n^2)   

        0.2 a 0.5→ Chunking Sort (O(n n))   

        ≥0.5→ Turk Algorithm (O(n log n))   


# Profundizando en Algoritmos: ("elegidos")
## --simple: $\mathcal{O}(n^2)$ - Selection Sort:

El algoritmo Selection Sort (Ordenamiento por Selección) es la estrategia más directa e intuitiva de todas para cumplir con el requisito de O(n^2) del flag --simple.   
- 💡 ¿Qué hace? (La idea central)

En lugar de intentar trucos matemáticos complejos, hace exactamente lo que haría una persona sin experiencia: busca el número más pequeño de la pila A, lo sube a la cima, lo aparta a la pila B, y repite el proceso hasta vaciar A. Al final, devuelve todo a la pila B en orden perfecto
- ⚙️ ¿Cómo funciona? (Mecánica de Stacks)

Dado que no puedes acceder directamente a posiciones intermedias de un stack con índices tipo array (como a[i]), tienes que rotar la pila para traer el elemento deseado hasta la cima.   
    - Localizar: Recorres la pila A de arriba a abajo y anotas cuál es el número más pequeño y en qué posición está.   
    - Calcular la ruta más corta hacia la cima: 
        - Si el mínimo está en la mitad superior del stack, rotas hacia arriba usando ra.   
        - Si está en la mitad inferior, rotas hacia abajo usando rra. 
    - Enviar a B: Una vez que el mínimo está en la cima de A, ejecutas pb. En B, los números quedan almacenados de mayor a menor (o en el orden inverso en que fueron empujados).   
    - Repetir: Haces lo mismo hasta que en A no quede ningún elemento (o queden solo 2 o 3 para acelerar).   
    - Vaciar B de vuelta a A: Pasas secuencialmente todos los elementos de B a A mediante pa. 
    Como salieron en orden ordenado, A queda completamente ordenado de menor a mayor de forma ascendente.   

- Paso a paso con un ejemplo visual
    - Supongamos que el stack a tiene los valores: [4, 2, 5, 1, 3] (donde 4 es la cima).
        - Paso 1: Buscar y extraer el 1 
            
            Pila inicial: a = [4, 2, 5, 1, 3], b = []   
            El mínimo es 1 (está en la parte baja).
            
            Hacemos rra $\rightarrow$ a = [3, 4, 2, 5, 1]   
            Hacemos rra $\rightarrow$ a = [1, 3, 4, 2, 5] (¡el 1 ya está en la cima!)   
            Hacemos pb $\rightarrow$ a = [3, 4, 2, 5], b = [1]   
        
        - Paso 2: Buscar y extraer el 2 
            
            El mínimo ahora en a es 2.
            
            Hacemos ra $\rightarrow$ a = [4, 2, 5, 3]   
            Hacemos ra $\rightarrow$ a = [2, 5, 3, 4] (el 2 está en la cima)   
            Hacemos pb $\rightarrow$ a = [5, 3, 4], b = [2, 1]   
        
        - Paso 3: Buscar y extraer el 3
            
            El mínimo ahora es 3.
            
            Hacemos ra $\rightarrow$ a = [3, 4, 5]   
            Hacemos pb $\rightarrow$ a = [4, 5], b = [3, 2, 1]   
            
        - Paso 4: Buscar y extraer el 4
        
            El mínimo es 4 (ya está en la cima).
            
            Hacemos directamente pb $\rightarrow$ a = [5], b = [4, 3, 2, 1]   
            
        - Paso 5: Mover el último elemento (el 5)
        
            Hacemos pb $\rightarrow$ a = [], b = [5, 4, 3, 2, 1]   
            
        - Paso 6: Devolver todo a A
            
            Hacemos pa 5 veces consecutivas:   
            
            pa $\rightarrow$ pasa el 5   
            pa $\rightarrow$ pasa el 4   
            pa $\rightarrow$ pasa el 3   
            pa $\rightarrow$ pasa el 2   
            pa $\rightarrow$ pasa el 1   
            Resultado final: a = [1, 2, 3, 4, 5] ordenado ascendentemente y b = [].   
            
    - ⚖️ Pros y Contras en Push_swap
        
        - Ventajas:
        
        Es el más fácil y rápido de programar de todo el proyecto (se hace con unas 30 líneas de código).Es conceptualmente infalible (siempre termina ordenando bien).Cumple a la perfección el requisito de algoritmo $\mathcal{O}(n^2)$ para la bandera --simple.   
        
        - Desventajas:
        
        Consume una cantidad enorme de operaciones en pilas grandes (para 100 números puede llegar a superar las 2500 operaciones), por lo que no sirve para obtener la puntuación de rendimiento excelente en la parte general, utilizándose exclusivamente cuando se fuerza la bandera --simple.

### Diagrama de flujo del Algoritmo Selection Sort
```mermaid
graph TD
    START([Inicio: Stack A con N elementos, Stack B vacio]) --> CHECK_A{Esta A vacio}

    CHECK_A -- No --> FIND_MIN[1. Buscar valor minimo y posicion en A]
    FIND_MIN --> CHECK_POS{Posicion del minimo}

    CHECK_POS -- Mitad superior --> ROT_UP[Rotar hacia arriba con ra hasta la cima]
    CHECK_POS -- Mitad inferior --> ROT_DOWN[Rotar hacia abajo con rra hasta la cima]

    ROT_UP --> DO_PB[2. Empujar minimo a B con pb]
    ROT_DOWN --> DO_PB
    DO_PB --> CHECK_A

    CHECK_A -- Si --> CHECK_B{Esta B vacio}

    CHECK_B -- No --> DO_PA[3. Devolver elementos a A con pa]
    DO_PA --> CHECK_B

    CHECK_B -- Si --> END([Fin: Stack A ordenado ascendentemente])

    style START fill:none,stroke:#4b5563,stroke-width:1.5px
    style END fill:none,stroke:#059669,stroke-width:1.5px
```


## --medium: $\mathcal{O}(n\sqrt{n})$ - Chunking Sort:

El algoritmo Chunking Sort (ordenación por bloques o fragmentos) es la estrategia ideal para cubrir el requisito de complejidad $\mathcal{O}(n\sqrt{n})$ asociado al flag --medium.   

- 💡 ¿Qué hace? (La idea central)

En lugar de buscar los números uno a uno de forma estricta como en Selection Sort, divide todos los números en grupos ordenados por tamaño llamados chunks (bloques).   
El objetivo es trasladar los números de A a B por franjas (primero los más pequeños, luego los medianos, etc.). 
Al colocarlos en B de manera semiclasificada, devolverlos a A requiere muchas menos rotaciones, reduciendo drásticamente las operaciones totales.   

- ⚙️ El prerrequisito clave: Indexación (Normalización)

Para que este algoritmo funcione de forma predecible sin importar los valores originales (puedan ser números negativos o muy altos), primero se reemplaza cada número por su índice normalizado de $0$ a $n-1$:

Si la entrada es [-50, 1000, 4, 0], sus índices asignados son [0, 3, 2, 1].
Así, un stack de 100 números siempre contendrá los índices del 0 al 99.

- 🔧 ¿Cómo funciona paso a paso?

    - Paso 1: Definir el tamaño del bloque
    
        El subject indica dividir los elementos en aproximadamente $\sqrt{n}$ bloques:   
    
        - Para $100$ números: bloques de tamaño $\approx 15$ o subdividido en 5 a 7 chunks.
        
        - Para $500$ números: bloques de tamaño $\approx 30\text{--}40$ o subdividido en 11 a 13 chunks.
    
    - Paso 2: Empujar de A a B por ventanas/bloques móviles
    
        - Se define una ventana que acepta índices dentro de un rango actual, 
        por ejemplo $[0 \dots \text{chunk\_size}]$.
        
        Miras la cima de A.   
        
        - Si el índice en la cima pertenece al bloque actual:Haces pb.   
        
        Optimización clave: 
        
        - Si el elemento empujado está en la mitad inferior de ese bloque, ejecutas rb para mandarlo al fondo de B. 
        
        Así, los más pequeños van al fondo de B y los medianos quedan arriba en B.   
        
        - Avanzas el rango de la ventana.
        
        - Si el número no pertenece al bloque actual, rotas con ra para buscar otro que sí pertenezca.   
        
        - Repites hasta que todo el stack a quede vacío.   
    
    - Paso 3: Recuperar todo de B hacia A
    
        Ahora en B los números no están estrictamente ordenados, pero sí están agrupados por cercanía:
        
        - Buscas el elemento máximo actual que queda en B.   
        
        Como los números están agrupados en franjas, el máximo siempre estará muy cerca de la cima o del fondo de B:
        
        - Si está cerca de la cima, rotas con rb.   
        
        - Si está cerca del fondo, rotas con rrb.   
        
        - Una vez en la cima de B, lo devuelves con pa.   
        
        Al devolver siempre el máximo disponible en cada paso, los elementos van cayendo en A en orden descendente inverso, de modo que a queda ordenado ascendentemente de menor a mayor.   
        
- 🚶 Ejemplo visual simplificado
    
    - Supongamos 6 números ya indexados del 0 al 5:a = [2, 5, 0, 4, 1, 3], con bloques de tamaño 3:
        - Bloque 1: valores 0, 1, 2
        - Bloque 2: valores 3, 4, 5
        - Fase de vaciado a B (por bloques):
            - El 2 pertenece al bloque 1 $\rightarrow$ pb.   
            - El 5 pertenece al bloque 2 $\rightarrow$ ra para saltarlo temporalmente.   
            - El 0 pertenece al bloque 1 $\rightarrow$ pb, y como es muy pequeño se hace rb.   
            - El 1 pertenece al bloque 1 $\rightarrow$ pb.   Se pasa al Bloque 2 y se empujan 4, 5, 3 a B usando pb.   
            - Resultado intermedio: a = [ ], b contiene los números separados en dos mitades reconocibles.   
        - Fase de retorno a A: 
            - Máximo en B es 5: se rota b hasta la cima y se hace pa.   
            - Máximo en B es 4: se rota a la cima y se hace pa.   
            - Máximo en B es 3: se hace pa.   
            - Se repite con 2, 1, 0.   
            - Resultado final: A = [0, 1, 2, 3, 4, 5] ordenado.   
            
    ⚖️ Pros y Contras en Push_swap
    
    - Ventajas:
    
        - Gran eficiencia operativa: Suele ordenar 100 números en unas $\approx 600$ operaciones (entrando de lleno en el rango Excelente).   
    
        - Simplicidad de código: No requiere calcular matrices de coste multidimensionales como el algoritmo del Turco ni manejar bits complejos como Radix.Satisface de forma directa y justificada la complejidad $\mathcal{O}(n\sqrt{n})$ solicitada en el subject.   
    
    - Desventajas: 
    
        - Para conjuntos muy grandes (500 números) requiere calibrar con cuidado el tamaño del bloque ($\sqrt{n}$) para mantenerse de forma consistente por debajo de las $5500$ operaciones requeridas para el nivel Excelente.   

### Diagrama de flujo del Algoritmo Chunking Sort
```mermaid
graph TD
    START([Inicio: Stack A con N elementos, Stack B vacio]) --> NORM[1. Normalizacion e Indexacion: Asignar indices de 0 a N-1]
    NORM --> CHUNK_DEF[2. Parametros: Definir tamano de bloque y ventana inicial]
    CHUNK_DEF --> CHECK_A{Esta A vacio}

    CHECK_A -- No --> EVAL_TOP{Elemento cima en rango}
    EVAL_TOP -- Si --> DO_PB[Empujar a B con pb]
    DO_PB --> SPLIT_B{Indice en mitad menor del bloque}
    SPLIT_B -- Si --> ROT_B[Rotar B con rb]
    SPLIT_B -- No --> ADVANCE[Mantener en cima de B]
    ROT_B --> ADVANCE
    ADVANCE --> SLIDE[Avanzar ventana de rango]
    SLIDE --> CHECK_A

    EVAL_TOP -- No --> ROT_A[Rotar A con ra]
    ROT_A --> CHECK_A

    CHECK_A -- Si --> CHECK_B{Esta B vacio}
    CHECK_B -- No --> FIND_MAX[Localizar valor maximo en B]
    FIND_MAX --> ROTATE_MAX[Rotar B por ruta mas corta rb o rrb]
    ROTATE_MAX --> DO_PA[Empujar maximo a A con pa]
    DO_PA --> CHECK_B

    CHECK_B -- Si --> END([Fin: Stack A ordenado ascendentemente])

    style START fill:none,stroke:#4b5563,stroke-width:1.5px
    style END fill:none,stroke:#059669,stroke-width:1.5px

```


## --complex: $\mathcal{O}(n \log n)$ - Turk Algorithm:

El Turk Algorithm (o Algoritmo del Turco) es un algoritmo voraz (greedy) diseñado específicamente para el modelo de instrucciones de Push_swap. 

Es la estrategia más utilizada para reventar los récords de operaciones del proyecto y situarse con holgura en el rango Excelente ($< 700$ operaciones para 100 números y $< 5500$ para 500).   

- 💡 ¿Qué hace? (La idea central)

    En lugar de forzar un orden rígido (como ordenar bit a bit o buscar mínimos globales), 

    el Turco se pregunta nodo por nodo: 
    
    "¿Cuál de todos los números de la pila a me cuesta menos movimientos colocar en su sitio exacto dentro de la pila B?"   

    Calcula las rotaciones necesarias para cada elemento de A y para su destino en B. 

    Elige el elemento más "barato", 

    aprovecha las rotaciones dobles (rr y rrr) para ahorrar instrucciones, 

    y lo empuja con pb. 

    Al final, devuelve todo a A de forma ordenada.   

- ⚙️ Mecánica de Costes y Rotaciones Dobles (El secreto del Turco)

    El motivo por el que este algoritmo es tan eficiente radica en que amortiza movimientos:

    - Si tienes que rotar a hacia arriba 2 veces (ra, ra) y la pila b hacia arriba 2 veces (rb, rb), el Turco las combina en dos movimientos dobles: rr + rr (2 operaciones en vez de 4).   
    - Si ambas deben rotar hacia abajo, usa rrr.   
    - Si una rota hacia arriba y otra hacia abajo, rota cada pila de manera independiente (ra + rrb).
    
- 🔧 ¿Cómo funciona paso a paso?

    - Paso 1: Inicialización rápida
        - Pasas los 2 primeros elementos de A a B sin pensarlo mediante dos pb.   
        - La pila B se mantendrá siempre ordenada de forma circular y descendente (el mayor arriba, el menor abajo).
    - Paso 2: Vaciar A hacia B buscando el menor coste
        - Mientras en a queden más de 3 elementos:
            - Calcular la posición destino (target) en B: 
                - Para cada número de A, buscas entre qué dos números de B debe encajar (su posición natural en orden descendente). 
                - Si el número es más grande o más pequeño que todos los de B, su destino será encima del valor máximo de B.
            - Calcular el coste de cada nodo de A:
                - ¿Cuántas rotaciones necesita ese nodo para llegar a la cima de A? (usando la ruta más corta: ra o rra).   
                - ¿Cuántas rotaciones necesita su posición destino en B para colocarse arriba del todo? (rb o rrb).   
                - Sumas ambos costes, descontando las rotaciones simultáneas posibles (rr o rrr).   
            - Ejecutar el nodo más barato:
                - Tomas el nodo que sume menos movimientos en total.
                - Realizas las rotaciones dobles (rr/rrr) que compartan.   
                - Terminas las rotaciones individuales restantes (ra, rra, rb o rrb).   
                - Haces pb.   
            - Repites el bucle hasta que en a queden exactamente 3 números.
    - Paso 3: Ordenar los 3 números de A
        - Tres números se ordenan de forma óptima en un máximo de 2 movimientos combinando sa, ra o rra según el caso.   
    - Paso 4: Devolver todo de B a A
        - Ahora B contiene casi todos los números colocados de forma circular, y A tiene 3 números ordenados:
            - Para el elemento superior de B, buscas su hueco exacto en A (el número inmediatamente mayor que él)
            - Rotas a con ra o rra hasta que ese hueco esté en la cima.   
            - Haces pa.   
            - Repites hasta vaciar B por completo.   
    - Paso 5: Alineación final
        - Todos los números están en A en orden relativo, pero quizás el número mínimo no ha quedado en la cima (por ejemplo: 3, 4, 5, 1, 2).
        - Solo queda rotar a (ra o rra) hasta dejar el valor mínimo en la cima absoluta. ¡El stack está completamente ordenado!   
        
🚶 Ejemplo conceptual en miniatura

- Imagina que en B tienes [8, 5, 2] y en A tienes los números [10, 4, 7]:
    - Para insertar el 4, su destino en B es entre el 5 y el 2. Necesita que b rote 2 veces hacia arriba (rb, rb).   
    - Para insertar el 7, su destino es entre el 8 y el 5. Solo necesita que b rote 1 vez (rb).   
    - El Turco calcula todas las distancias en ambas pilas a la vez, elige el 7 porque su combinación de movimientos totales es la más corta, alinea las dos pilas a la vez usando rotaciones combinadas y hace pb.   
    
⚖️ Pros y Contras en Push_swap

- Ventajas:
    - Rendimiento imbatible: Es el algoritmo con menor número de operaciones promedio en toda la historia de Push_swap (~550-600 ops para 100 números y ~4800-5200 ops para 500 números), superando el rango Excelente sin despeinarse.   
    - No depende de trucos de potencias de 2 o bases binarias como Radix.
    
- Desventajas:
    - Mayor complejidad de código: Requiere funciones auxiliares para calcular distancias relativas, determinar el coste óptimo y coordinar rotaciones simultáneas (rr/rrr).   
    Como vimos antes, en teoría tradicional pura sobre arrays es un algoritmo voraz de inserción ($\mathcal{O}(n^2)$), pero dentro de las restricciones de Push_swap y la sección VI.3.1 del subject, se valida y clasifica por la cantidad real de instrucciones emitidas.   
 
### Flujo completo del Turk Algorithm
```mermaid
flowchart TD
    START(["Inicio: Stack A con N elementos, Stack B vacío"]) --> INIT["1. Inicialización:<br/>Mover 2 elementos a B mediante 'pb pb'"]
    
    INIT --> CHECK_SIZE{"¿Quedan más de<br/>3 elementos en A?"}

    subgraph GREEDY_PUSH ["Bucle Voraz de Inserción (A ➔ B)"]
        CHECK_SIZE -- Sí --> TARGET["Para cada nodo de A:<br/>Calcular su 'target' en B (orden descendente circular)"]
        TARGET --> COST["Calcular coste de rotaciones totales:<br/>• Pasos a cima de A (ra o rra)<br/>• Pasos de target a cima de B (rb o rrb)<br/>• Descuento por dobles rotaciones (rr / rrr)"]
        COST --> CHEAPEST["Seleccionar el nodo con menor coste total"]
        CHEAPEST --> EXEC_ROT["Ejecutar rotaciones combinadas (rr / rrr)<br/>y restantes individuales (ra/rra/rb/rrb)"]
        EXEC_ROT --> DO_PB["Empujar nodo elegido a B ('pb')"]
        DO_PB --> CHECK_SIZE
    end

    CHECK_SIZE -- No --> SORT_THREE["2. Ordenar los 3 elementos restantes en A<br/>(Algoritmo fijo en ≤ 2 movimientos: sa, ra, rra)"]

    subgraph RESTORE ["Recuperación Ordenada (B ➔ A)"]
        SORT_THREE --> CHECK_B{"¿Está B vacío?"}
        CHECK_B -- No --> TARGET_A["Para la cima de B:<br/>Localizar su posición exacta en A"]
        TARGET_A --> ROT_A["Rotar A (ra o rra) hasta alinear el hueco"]
        ROT_A --> DO_PA["Empujar elemento a A ('pa')"]
        DO_PA --> CHECK_B
    end

    CHECK_B -- Sí --> FINAL_ALIGN["3. Alineación Final:<br/>Rotar A (ra o rra) hasta dejar el valor mínimo en la cima"]
    FINAL_ALIGN --> END(["Fin: Stack A ordenado ascendentemente"])

    style GREEDY_PUSH fill:none,stroke:#0284c7,stroke-width:1.5px
    style RESTORE fill:none,stroke:#ca8a04,stroke-width:1.5px
    style START fill:none,stroke:#4b5563,stroke-width:1.5px
    style END fill:none,stroke:#059669,stroke-width:1.5px
```




--- 
---

# ORGANIZACION DEL TRABAJO EN EQUIPO ( A REVISAR Y VALIDAR )

## Reparto de carga

```mermaid
flowchart TD
    subgraph SETUP ["0. CONCENSO INICIAL & ARQUITECTURA"]
        J1["Diseño de estructuras conjuntas<br/>• t_stack (nodos, índices, posición)<br/>• t_context (pilas a y b, metadatos)"]
    end

    subgraph WORKLOAD ["DIVISIÓN DE TAREAS EQUITATIVA"]
        direction LR

        subgraph EST_A ["👤 Estudiante A: Parsing & Control"]
            direction TB
            A1["Parsing & Validación de Entrada<br/>• Límites INT_MIN/MAX, duplicados, no numéricos"]
            A2["Normalización / Asignación de Índices<br/>• Simplificación de valores (0 a N-1)"]
            A3["Estrategia Simple O(n²)<br/>• Selection Sort & casos óptimos (3 y 5 núm)"]
            A4["Estrategia Compleja O(n log n)<br/>• Radix Sort (LSD por bits)"]
            A5["Gestión de Flags y Main<br/>• Parseo de flags, errores y free memory"]
            A6["Bonus: checker<br/>• Lectura por stdin y verificación"]
            A1 --> A2 --> A3 --> A4 --> A5 --> A6
        end

        subgraph EST_B ["👤 Estudiante B: Motor & Algoritmos"]
            direction TB
            B1["Motor de Operaciones de Stacks<br/>• pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr"]
            B2["Cálculo de Desorden<br/>• Función compute_disorder según subject"]
            B3["Estrategia Intermedia O(n√n)<br/>• Chunking Sort por rangos"]
            B4["Algoritmo Adaptativo O(n log n)<br/>• Turk Algorithm para desorden ≥ 0.5"]
            B5["Modo Benchmark (--bench)<br/>• Contador/desglose a stderr y formateo"]
            B6["Documentación & Testing<br/>• README.md y tests masivos de operaciones"]
            B1 --> B2 --> B3 --> B4 --> B5 --> B6
        end
    end

    subgraph INTEGRATION ["INTEGRACIÓN & REVISIÓN CRUZADA"]
        REV["Pruebas de leaks (Valgrind / ASan)<br/>Validación cruzada de código para la evaluación entre pares"]
    end

    SETUP --> WORKLOAD
    A6 --> INTEGRATION
    B6 --> INTEGRATION
```

| Fase / Componente | Estudiante A (Parsing & Control) | Estudiante B (Motor & Algoritmos) | Carga Relativa |
| :--- | :--- | :--- | :---: |
| **0. Arquitectura** *(Conjunto)* | Diseño del nodo `t_stack` (valor, índice, posición)[cite: 1, 2] | Diseño de `t_context` (pila a, pila b, contadores)[cite: 2] | Equitativa |
| **1. Parseo y Primitivas** | **Parsing completo:** Lectura de argumentos, límites (`INT_MIN`/`INT_MAX`), rechazo de cadenas vacías/duplicados y salida `Error\n`[cite: 2, 18, 19] | **Motor de primitivas:** Funciones de los stacks con salida formateada (`sa`, `sb`, `pa`, `pb`, `ra`, `rb`, `rra`, `rrb`, etc.)[cite: 1, 13] | Equitativa |
| **2. Normalización y Métrica** | **Indexación / Normalización:** Función que asigna a cada elemento un índice de 0 a N-1[cite: 1] | **Cálculo de desorden:** Implementación de `compute_disorder` siguiendo la fórmula del subject[cite: 14] | Equitativa |
| **3. Algoritmos Iniciales** | **Estrategia Simple (O(n²)):** Selection Sort para `--simple` y algoritmos óptimos para 3 y 5 elementos[cite: 2, 15, 18] | **Estrategia Intermedia (O(n√n)):** Chunking Sort por rangos para `--medium`[cite: 2, 15, 18] | Equitativa |
| **4. Algoritmos Avanzados** | **Estrategia Compleja (O(n log n)):** Radix Sort por bits para cubrir `--complex` de forma directa[cite: 2, 15, 18] | **Algoritmo Adaptativo:** Motor Turk Algorithm para alcanzar rango Excelente cuando el desorden es ≥ 0.5[cite: 2, 15, 22] | Equitativa |
| **5. Main, Flags y Bench** | **Main y Selector de Flags:** Parseo de argumentos de configuración, validación de incompatibilidades y liberación de memoria[cite: 2, 18] | **Modo Benchmark (`--bench`):** Desglose y recuento de movimientos por tipo a `stderr` con formato de métricas[cite: 2, 19] | Equitativa |
| **6. Bonus y Cierre** | **Bonus (`checker`):** Lectura por `stdin` y validación de ordenación (`OK` / `KO`)[cite: 25] | **Documentación y Batería de Tests:** Redacción del `README.md` (justificaciones teóricas, IA)[cite: 20, 23, 27] y scripts de prueba para 100/500 números[cite: 22] | Equitativa |


