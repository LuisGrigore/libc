struct StringExtractor
{
	char* str;
	unsigned int i;
	unsigned int j;
};

struct StringExtractor StringExtractor(char * str);


int is_end(struct StringExtractor se);

char *extract(struct StringExtractor *se, char regx);

