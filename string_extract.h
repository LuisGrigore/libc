struct StringExtractor
{
	char* str;
	int i;
	int j;
};

struct StringExtractor StringExtractor(char * str);

struct StringExtractor reset(struct StringExtractor se);

int is_end(struct StringExtractor se);

char *extract(struct StringExtractor *se, char regx);

