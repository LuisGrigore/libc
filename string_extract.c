#include "string_extract.h"
#include "libft.h"
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

char *start_end_substr(char *str, int start, int end)
{
    unsigned int u_start;
    size_t len;

	
	u_start = (unsigned int)start;
	len = (size_t)(end - start);

    if (str == NULL || start >= end) {
        return NULL;
    }
    return ft_substr(str, u_start, len);
}

void trunc_regx(struct StringExtractor *se, char regx)
{
    while(se->str[se->j] == regx && se->str[se->j] != '\0')
    {
        se->j++;
        se->i = se->j;
    }
}

void advance_j(struct StringExtractor *se, char regx)
{
    while(se->str[se->j] != regx && se->str[se->j] != '\0')
    {
        se->j++;
    }
}

char *extract(struct StringExtractor *se, char regx)
{
    char *res;

    trunc_regx(se, regx);
	
    advance_j(se, regx);

    if(se->str[se->j] == '\0')
    {
        res = start_end_substr(se->str, se->i, se->j);
    }
    else
    {
        res = start_end_substr(se->str, se->i, se->j);
    }

    return res;
}

int is_end(struct StringExtractor se)
{
    if(se.str[se.j] == '\0')
    {
        return 1;
    }
    return 0;
}
