#include "split_array.h"
#include "string_extract.h"



char **ft_split_copy(char const *s, char c)
{
	char *str = s;
	struct StringExtractor se = StringExtractor(str);
	struct SplitArray result = SplitArray();
	
	while(is_end(se) == 0)
	{
		add_to_split_array(&result,extract(&se,c));
	}
	add_null_to_split_array(&result);
	return result.array;
}


