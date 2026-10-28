| Fase | Tareas Estudiante A | Tareas Estudiante B (Tú) | Mecánica de Trabajo | Dependencia / Desbloqueo |
| :--- | :--- | :--- | :--- | :--- |
| **Fase 0: Base Común** | • Estructura `t_node` y cabecera `push_swap.h`<br>• Operaciones atómicas (`sa/sb/ss`, `pa/pb`, `ra/rb/rr`, `rra/rrb/rrr`) | • Estructura `t_node` y cabecera `push_swap.h`<br>• Operaciones atómicas (`sa/sb/ss`, `pa/pb`, `ra/rb/rr`, `rra/rrb/rrr`) | **Pair Programming**<br>(Misma pantalla, rama base `main`) | Ninguna. Trabajo conjunto inicial. |
| **Fase 1: Parsing vs Métricas** | • Parsing de argumentos y `ft_split`<br>• Gestión de errores (`INT_MIN`/`MAX`, duplicados)<br>• Liberación de memoria (`free_stack`) y mensaje `"Error\n"` | • Mock/Generador de stacks para pruebas unitarias<br>• Normalización de valores a índices ($0 \dots n-1$)<br>• Cálculo del *Disorder Index* (inversiones)<br>• Rutina de métricas `--bench` | **Ramas paralelas:**<br>`feat/parser-mem`<br>`feat/metrics-index` | **Independiente:** B prueba algoritmos con arrays estáticos sin esperar al parser de A. |
| **Fase 2: Algoritmos** | • Estrategia Simple: Inserción / Selección ($O(n^2)$)<br>• Estrategia Compleja: Radix por bits ($O(n \log n)$) | • Casos base manuales (2 y 3 números)<br>• Estrategia Media: Chunks / K-Sort ($O(n\sqrt{n})$)<br>• Router adaptativo según % de desorden | **Ramas paralelas:**<br>`feat/radix-insert`<br>`feat/chunks-router` | Ambos trabajan sobre listas con índices ya normalizados. |
| **Cruce de Código** | • Code review y pruebas de estrés de `feat/chunks-router` | • Code review y pruebas de memoria de `feat/parser-mem` y `feat/radix` | **Revisión Cruzada** (Pull Requests mutuas) | Ambos deben dominar y poder defender el código del compañero. |
| **Fase 3: Integración** | • Flags de CLI (`--simple`, `--medium`, etc.)<br>• Auditoría de fugas de memoria con Valgrind | • Scripts automatizados con `shuf` y recuento de operaciones<br>• `README.md` (justificación matemática y análisis asintótico) | **Trabajo Coordinado** | Simulación de evaluación entre pares y live-coding. |


# 🗺️ Hoja de Ruta - Estudiante B

## 📌 Fase 0: Base Común (Pair Programming)
- [ ] Definir la estructura `t_node` (valor, índice, punteros `next` y `prev`) en `push_swap.h`.
- [ ] Implementar y testear juntos las operaciones atómicas:
  - Intercambio: `sa`, `sb`, `ss`
  - Empuje: `pa`, `pb`
  - Rotación: `ra`, `rb`, `rr`
  - Rotación inversa: `rra`, `rrb`, `rrr`

---

## 📌 Fase 1.B: Métricas e Índices (Rama: `feat/metrics-index`)
- [ ] **Arnés de pruebas:** Crear un archivo de test que genere una lista enlazada a partir de un array de enteros fijo para trabajar de forma autónoma.
- [ ] **Normalización ($0 \dots n-1$):** Asignar a cada nodo su posición relativa de menor a mayor.
- [ ] **Disorder Index:** Implementar la métrica de desorden basada en el conteo de inversiones:
  $$\text{Disorder} = \frac{\text{Inversiones}}{\frac{n(n - 1)}{2}} \times 100\%$$
- [ ] **Rutina `--bench`:** Registrar y mostrar el recuento de operaciones por tipo.

---

## 📌 Fase 2.B: Algoritmos (Rama: `feat/chunks-router`)
- [ ] **Casos base:**
  - Resolver 2 números con máximo 1 operación (`sa`).
  - Resolver 3 números con árbol de decisión en máximo 2 operaciones.
- [ ] **Algoritmo de Chunks ($O(n\sqrt{n})$):**
  - Implementar la ventana deslizante para pasar elementos de `A` hacia `B` preordenados.
  - Implementar el retorno óptimo de `B` hacia `A` buscando el valor máximo por el camino más corto.
  - Calibrar el tamaño del chunk para entrar en los límites de evaluación (< 700 en 100 números, < 5500 en 500 números).
- [ ] **Router adaptativo:** Redirigir el flujo según el tamaño de la entrada y el porcentaje de desorden.

---

## 📌 Fase 3: Validación y Entrega
- [ ] **Revisión cruzada:** Auditar la rama de parsing y memoria del Estudiante A.
- [ ] **Scripts de test:** Diseñar tests automatizados con `shuf` para validar operaciones en 3, 5, 100 y 500 números.
- [ ] **Documentación (`README.md`):** Justificar la selección algorítmica y el análisis formal de complejidad temporal y espacial.
- [ ] **Defensa:** Practicar preguntas de modificación de código en vivo.