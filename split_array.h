#ifndef SPLIT_ARRAY_H
#define SPLIT_ARRAY_H

#include <stdlib.h> 

struct SplitArray{
	char ** array;
	size_t size;
	char ** last;
};
struct SplitArray	*add_to_split_array(struct SplitArray *split_array, char* str);
void	add_null_to_split_array(struct SplitArray *split_array);
struct SplitArray	SplitArray();
#endif