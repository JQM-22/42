#!/usr/bin/env python3

#variable
n = int (input("enter a number less than 25 \n"))

#si mayor que 25 error
if n > 25 :
    print ("Error")

#si no, bucle mientras se cumpla la condicion
else:
    while n <= 25:
        print (f"Inside the loop, my variable is {n}")
        n += 1
