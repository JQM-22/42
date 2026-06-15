#!/usr/bin/env python3
import math #necesita libreria para operacion de redondeo

n = float(input("Give me a number: "))
resultado = math.ceil(n) 
#si fuese redondeo hacia abajo "math.floor(n)"

print (resultado)