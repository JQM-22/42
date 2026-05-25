//Operador de Asignacion

#include<stdio.h>

int main(){

    int a;
    a = 10; //Asignacion de valor a la variable a
    
    a += 10; //Suma el valor de a con 10 y asigna el resultado a a (a = a + 10)
    a -= 5; //Resta el valor de a con 5 y asigna el resultado a a (a = a - 5)
    a *= 2; //Multiplica el valor de a por 2 y asigna el resultado a a (a = a * 2)
    a /= 2; //Divide el valor de a entre 2 y asigna el resultado a a (a = a / 2)

    printf("El valor de a es: %d\n", a);



    return 0;
}