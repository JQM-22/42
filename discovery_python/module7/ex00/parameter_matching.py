#!/usr/bin/env python3

import sys

                              #al introducir el nombre del script paraa ejecutar, se introduce el parametro 1
if len(sys.argv) != 2 :       #comprobacion de que se introduce 1 parametro (script + parametro =2)
    print ("none")
else:                         #si se cumple, comprobacion de que parametro = palabra usurario
    parametro = sys.argv[1]   #parametro correcto es el 1 de la lista sys.argv
    palabra_usuario = input ("What was the parameter? ")   #se pide palabra a usuario

    if parametro == palabra_usuario :     #si se cumple la condicion OK si no NOPE
        print ("Good job!")
    else:
        print ("Nope, sorry...")

   
