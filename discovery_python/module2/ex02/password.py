#!/usr/bin/env python3  
#hacerlo ejecutalbe
#dar permisos de ejecucion en bash: chmod +x password.py

password = "python is awesome"
pass_client = input("Enter password: ")

if password == pass_client :
    print ("ACCESS GRANTED")
else:
    print ("ACCESS DENIED")
