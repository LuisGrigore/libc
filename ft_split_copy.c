#include "split_array.h"
#include "string_extract.h"

char **ft_split_copy(char const *s, char c)
{
	char *str;
	struct StringExtractor string_extractor;
	struct SplitArray split_array;

	str = s;
	string_extractor = StringExtractor(str);
	split_array = SplitArray();
	
	while(is_end(string_extractor) == 0)
	{
		add_to_split_array(&split_array, extract(&string_extractor,c));
	}
	add_null_to_split_array(&split_array);
	return split_array.array;
}


