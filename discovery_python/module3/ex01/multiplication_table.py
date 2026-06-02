#!/usr/bin/env python3

#variable
n = int (input("Enter a number\n"))

#contador de 0 - 9
i = 0

#salida > tabla de multiplicar de n
#bucle
while i <= 9:
    print (f"{i} x {n} = {i * n}")
    i += 1                            #i se incrementa en 1 cada iteracion