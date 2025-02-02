# Nombre de la librería
LIBFT = ../libft.a

# Carpeta donde están los programas
SRCS = $(wildcard *.c)

# Generar ejecutables (cada .c tendrá un .out)
EXECS = $(SRCS:.c=.out)

# Compilador y flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -L. $(LIBFT)  # Enlaza con libft.a

# Regla principal: Compilar todos los ejecutables
all: $(EXECS)

# Crear ejecutables
%.out: %.c $(LIBFT)
	$(CC) $(CFLAGS) $< -o $@ $(LDFLAGS)
	@echo "✅ Ejecutable $@ creado."

# Regla para compilar la librería si no existe
$(LIBFT):
	@echo "⚠️  La librería $(LIBFT) no existe. Genera libft.a antes de compilar los programas."

# Limpiar ejecutables
clean:
	rm -f $(EXECS)
	@echo "🧹 Ejecutables eliminados."

# Limpiar todo
fclean: clean
	rm -f $(LIBFT)
	@echo "🧹 Librería $(LIBFT) eliminada."

# Recompilar desde cero
re: fclean all

# No trata estos nombres como archivos
.PHONY: all clean fclean re
