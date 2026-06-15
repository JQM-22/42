#!/usr/bin/env python3

import sys

                                               #1 contamos el num de argumentos que mete el usuario
                                               #restamos 1 porque sys.argv[0] es el nombre del script

param = len(sys.argv) -1

                                               #2 comprobacion de que hay al menos 1, sin contar nombre
if param == 0 :
    print ("none")

                                               #3 si hay parametros, ejecutar logica
else :
    print (f"parameters: {param}")             #primera parte, total de parametros

    for elemento in sys.argv[1:]:              #segunda parte, para elemento, dentro de sys... a partir del 1, 
        longitud = len(elemento)               #mide la longitud
        print (f"{elemento}: {longitud}")      #imprime cada uno, hace el salto de linea automatico

