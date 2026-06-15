#!/usr/bin/env python3

#mostrar todas las tablas de multiplicar en una linea cada una
#solo se permiten usar 2 bucles while

#contador
tabla = 0


while tabla <= 10:
    print (f"Table of {tabla}: ", end="")
    multiplicador = 0

    while multiplicador <= 10:
        print (tabla * multiplicador , end=" ")
        multiplicador +=1
    print()
    tabla += 1
    