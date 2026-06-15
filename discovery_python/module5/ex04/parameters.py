#!/usr/bin/env python3

import sys  #requiere libreria sys para sys.argv

num_elem = len(sys.argv)
num_param = (num_elem) - 1

print (f"Number of parameters: {num_param}.")

#en el enunciado del ejercicio NO pide que se solicite input
#debe ejecutarse ./parameters.py seguido de las palabras que sean