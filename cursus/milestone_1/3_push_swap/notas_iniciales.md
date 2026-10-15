# PUSH-SWAP (Pasos Generales)

1. Parseo (Parse): Llenar la pila a (stack a) con los valores de entrada.   

2. Push/Swap: Diferentes métodos para mover valores en las pilas a/b (sa, sb, ss, ...).   
    - Push: pa, pb   
    - Swap: sa, sb, ss   
    - Rotate: ra, rb, rr   
    - Reverse (Rotate): rra, rrb, rrr (en la pizarra indica la acción de invertir o rotar al revés).   

3. Algoritmos de ordenación (Sorting algos):Simple, medio, complejo, personalizado (simple, medium, complex, custom).   

4. Desorden (Disorder): “¿Qué tan lejos está a de estar ordenada?”   

Detalles de Parseo y Estructura de Datos
- Parseo (Parse):
    - Los valores no deben repetirse.   
    - Uso de ft_atoi(av[x]) $\rightarrow$ llenar la pila (fill stack).   
    - Banderas / pruebas de rendimiento (flags / bench)
    - Estructura de la pila (stack structure):Ctypedef struct s_stack
     
```C
typedef struct s_stack
{
    int value;
    int index;
    int position;
} t_stack;
```
(Nota: También muestra conectar t_list->content = t_stack si usas listas enlazadas tipo t_list).


Nota sobre la marcha de lo que escucho:
- investigar, algoritmo turco, metodo simple de min max

github con explicaciones
kurro