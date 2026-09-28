# ==============================================================================
# VARIABLES PRINCIPALES
# ==============================================================================

# Nombre del archivo final a generar
NAME		= libft.a

# Compilador y flags exigidas por la norma de 42
CC			= cc
CFLAGS		= -Wall -Wextra -Werror

# Herramienta para crear librerías estáticas (.a)
AR			= ar rcs

# Comando para borrar archivos
RM			= rm -f

# ==============================================================================
# ARCHIVOS DEL PROYECTO
# ==============================================================================

# Lista de todos los archivos .c de tu proyecto
SRCS		= ft_isalpha.c \
			  ft_isdigit.c \
			  ft_isalnum.c \
			  ft_isascii.c \
			  ft_isprint.c \
			  ft_strlen.c \
			  ft_memset.c \
			  ft_bzero.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_strlcpy.c \
			  ft_strlcat.c

# Convierte automáticamente cada nombre de la lista SRCS de .c a .o
OBJS		= $(SRCS:.c=.o)

# ==============================================================================
# REGLAS
# ==============================================================================

# Regla principal por defecto
all: $(NAME)

# Regla para compilar la librería final uniendo todos los .o
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

# Regla implícita: cómo transformar un archivo .c en un .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Elimina solo los archivos objeto (.o)
clean:
	$(RM) $(OBJS)

# Elimina los .o y el archivo ejecutable/librería
fclean: clean
	$(RM) $(NAME)

# Recompila todo desde cero
re: fclean all

# Evita conflictos con archivos que se llamen igual que las reglas
.PHONY: all clean fclean re
