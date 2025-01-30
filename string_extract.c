#include "string_extract.h"
#include "libft.h"
struct StringExtractor StringExtractor(const char * str)
{
    struct StringExtractor string_extractor;
    string_extractor.str = str;
    string_extractor.i = 0;
    string_extractor.j = 0;
    return string_extractor;
}

char *start_end_substr(const char *str, unsigned int start, unsigned int end)
{
    size_t len;

	len = (size_t)(end - start);

    if (str == NULL || start >= end) {
        return NULL;
    }
    return ft_substr(str, start, len);
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
