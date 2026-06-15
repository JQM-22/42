#!/usr/bin/env python3  
#hacerlo ejecutalbe
#dar permisos de ejecucion en bash: chmod +x mult.py

num1 = int(input("Enter the first number: "))
num2 = int(input("Enter the second number: "))
result = (num1 * num2)

if result > 0:
    print(f"{num1} x {num2} = {result} \nThe result is positive")
elif result < 0:
    print(f"{num1} x {num2} = {result} \nThe result is negative")
else:
    print(f"{num1} x {num2} = {result} \nThe result is positive and negative")
    