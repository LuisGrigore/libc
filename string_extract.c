#include "string_extract.h"
#include <stdlib.h>
#include <stdio.h>

struct StringExtractor StringExtractor(char * str)
{
    struct StringExtractor se;
    se.str = str;
    se.i = 0;
    se.j = 0;
    return se;
}

struct StringExtractor reset(struct StringExtractor se)
{
    se.i = 0;
    se.j = 0;
    return se;
}

char *substr(char *str, int start, int end)
{
    int size = end - start;
    char *result = (char*) malloc((size + 1) * sizeof(char));  // Fix malloc size calculation
    int i = 0;
    while(i < size)
    {
        result[i] = str[start + i];
        i++;
    }
    result[size] = '\0';
    return result;
}

void trunc_regx(struct StringExtractor *se, char regx)
{
    while(se->str[se->j] == regx && se->str[se->j] != '\0')  // Avoid out-of-bounds access
    {
        se->j++;
        se->i = se->j;
    }
}

void advance_j(struct StringExtractor *se, char regx)
{
    while(se->str[se->j] != regx && se->str[se->j] != '\0')  // Avoid out-of-bounds access
    {
        se->j++;
    }
}

char *extract(struct StringExtractor *se, char regx)
{
    char *res;

    trunc_regx(se, regx);
	
    advance_j(se, regx);

    if(se->str[se->j] == '\0')  // Check if at the end of string before accessing se->j+1
    {
        res = substr(se->str, se->i, se->j);  // Don't go out of bounds
    }
    else
    {
        res = substr(se->str, se->i, se->j);
    }

    return res;
}

int is_end(struct StringExtractor se)
{
    if(se.str[se.j] == '\0')  // Check if at the end of string
    {
        return 1;
    }
    return 0;
}
