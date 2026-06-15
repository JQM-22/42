#!/usr/bin/env python3

Original_array = [2, 8, 9, 48 ,8 ,22 ,-12 ,2]
New_array = [] #lista vacia para ir metiendo resultados

#para revisar cada numero de la lista se usa "for" 
for numero in Original_array:
    if numero > 5 : #se revisa que cumpla condicion
        nuevo_valor = numero + 2 #y se le suma 2
        New_array.append (nuevo_valor) #se añade el valor a la array vacia
New_array2 = set (New_array)  #al convertir a "set" elimina los duplicados automaticamente
print (Original_array)
print (New_array2)  #imprime la nueva array sin duplicados