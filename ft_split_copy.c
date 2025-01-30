#include "split_array.h"
#include "string_extract.h"

char **ft_split_copy(char const *s, char c)
{
	struct StringExtractor string_extractor;
	struct SplitArray split_array;

	string_extractor = StringExtractor(s);
	split_array = SplitArray();
	
	while(is_end(string_extractor) == 0)
	{
		add_to_split_array(&split_array, extract(&string_extractor,c));
	}
	add_null_to_split_array(&split_array);
	return split_array.array;
}


