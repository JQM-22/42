#!/usr/bin/env python3

import sys

# 1. Contamos cuántos parámetros reales introdujo el usuario
num_param = len(sys.argv) - 1

# 2. Si hay exactamente 1 parámetro, guardamos el texto original
# NO usamos .lower() para mantener las mayúsculas intactas
if num_param == 1:
    texto = sys.argv[1]
else:
    texto = ""

# 3. Condición combinada: si no hay 1 parámetro O si la "z" minúscula no está en el texto
if num_param != 1 or "z" not in texto:
    print("none")
else:
    # 4. Contamos ÚNICAMENTE las "z" minúsculas
    cantidad_z = texto.count("z")
    
    # 5. Imprimimos las "z" correspondientes seguidas de un salto de línea
    print("z" * cantidad_z)

    #REVISAR