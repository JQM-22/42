#!/usr/bin/env python3  
#hacerlo ejecutalbe
#dar permisos de ejecucion en bash: chmod +x isneg.py

numero = int(input("Ingresa un numero: "))

if numero < 0 :
    print(f"{numero} \nThis number is negative.")
elif numero > 0 :
    print(f"{numero} \nThis number is positive.")
else:
    print(f"{numero} \nThis number is both positive and negative.")
