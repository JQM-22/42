# Parte obligatoria

Nombre de programa libftprintf.a&#x20;

Archivos a entregar Makefile, \*.h, _/_.h, \*.c, _/_.c Makefile NAME, all, clean, fclean, re&#x20;

Funciones autorizadas malloc, free, write, va\_start, va\_arg, va\_copy, va\_end Se permite usar libft Yes

&#x20;Descripción Escribe una librería que contenga la función ft\_printf(), que imite el printf() original&#x20;

Se debe reprogramar la función printf() de la libc.&#x20;

El prototipo de ft\_printf() es: int ft\_printf(char const \*, ...);&#x20;

Estos son los requisitos:&#x20;

• No se debe implementar la gestión del ‘buffer’ del printf() original.&#x20;

• Se deben implementar las siguientes conversiones: cspdiuxX % • La función se comparará con el printf() original para verificar su comportamiento.&#x20;

• Hay que usar el comando ar para crear la librería. El uso de libtool está prohibido.&#x20;

• El archivo libftprintf.a deberá ser creado en la raíz de tu repositorio.



#### Se deben implementar las siguientes conversiones:

\
• %c para imprimir un solo carácter.\
• %s para imprimir una cadena de caracteres (como se define por defecto en C).\
• %p el puntero void \* dado como argumento se imprime en formato hexadecimal.\
• %d para imprimir un número decimal (base 10).\
• %i para imprimir un entero en base 10.\
• %u para imprimir un número decimal (base 10) sin signo.\
• %x para imprimir un número hexadecimal (base 16) en minúsculas.\
• %X para imprimir un número hexadecimal (base 16) en mayúsculas.\
• % % para imprimir el símbolo del porcentaje.

