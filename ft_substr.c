/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:21:18 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/05 14:19:04 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t str_len;
    char *substring;
    size_t i;

    // Si la cadena es NULL o vacía, devuelve NULL
    if (!s || s[0] == '\0') {
        return NULL;
    }

    str_len = 0;
    while (s[str_len] != '\0') {
        str_len++;  // Calcular la longitud de la cadena
    }

    // Si el índice start es mayor o igual a la longitud de la cadena, no hay substring que devolver
    if (start >= str_len) {
        return "";
    }

    // Ajustar la longitud de la substring en caso de que supere el final de la cadena
    if (start + len > str_len) {
        len = str_len - start;
    }

    // Reservar memoria para la substring (+1 para el carácter '\0')
    substring = (char *)malloc((len + 1) * sizeof(char));
    if (!substring) {
        return NULL;  // Si malloc falla, devolver NULL
    }

    // Copiar los caracteres desde 'start' en la cadena original a la nueva substring
    i = 0;
    while (i < len) {
        substring[i] = s[start + i];
        i++;
    }

    // Añadir el terminador de cadena
    substring[len] = '\0';

    return substring;
}