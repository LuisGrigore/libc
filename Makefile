# Nombre de la librería
NAME = libft.a

# Buscar automáticamente todos los archivos .c en el directorio
SRCS = $(wildcard ft_*.c)

# Generar los archivos .o correspondientes
OBJS = $(SRCS:.c=.o)

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Comando de archivado
AR = ar rcs

# Regla principal: Compilar y crear la librería
all: $(NAME)

# Crear la librería estática
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	@echo "✅ Librería $(NAME) creada con éxito."

# Compilar archivos .c a .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -f $(OBJS)
	@echo "🧹 Archivos objeto eliminados."

# Limpiar todo (objetos + librería)
fclean: clean
	rm -f $(NAME)
	@echo "🧹 Librería $(NAME) eliminada."

# Recompilar todo desde cero
re: fclean all

# No trata estos nombres como archivos
.PHONY: all clean fclean re
