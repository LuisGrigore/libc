/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrigore <lgrigore@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:49:23 by lgrigore          #+#    #+#             */
/*   Updated: 2025/02/05 12:46:45 by lgrigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int  count_words(const char *s, char c) {
    int count = 0;
    int in_word = 0;
    while (*s) {
        if (*s != c && in_word == 0) {
            in_word = 1;
            count++;
        } else if (*s == c) {
            in_word = 0;
        }
        s++;
    }
    return count;
}

static char *word_dup(const char *s, int start, int end) {
    char *word = (char *)malloc((end - start + 1) * sizeof(char));
    if (!word)
        return NULL;
    int i = 0;
    while (start < end)
        word[i++] = s[start++];
    word[i] = '\0';
    return word;
}

char **ft_split(char const *s, char c) {
    if (!s)
        return NULL;
    char **result = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!result)
        return NULL;
    int i = 0, j = 0, k = 0;
    while (s[i]) {
        if (s[i] != c) {
            j = i;
            while (s[j] && s[j] != c)
                j++;
            result[k++] = word_dup(s, i, j);
            i = j;
        } else {
            i++;
        }
    }
    result[k] = NULL;
    return result;
}
