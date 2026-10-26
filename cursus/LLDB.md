# Pasos para LLDB

## Compilar con información de depuración:

```bash
cc -g ft_putnbr.c
```

## Cargar el ejecutable en el depurador con argumentos (si los tiene):

```bash
lldb ./a.out <argumento> ...
```

## Poner puntos de interrupción (breakpoints):

``` bash
b main (función main)

b 10 (nº línea)

b ft_putchar (nombre función)
```

## Ejecutar el programa:

```bash
run
```
(ejecutar)

## Modo interfaz gráfica interactiva:

```bash
gui
```
(abrir la interfaz gráfica)

```bash
s : step (paso a paso)
```
```bash
ESC + ESC : Salir de la interfaz gráfica
```
## Salir de LLDB:
```bash
(lldb) exit
```
(salir de la terminal lldb)