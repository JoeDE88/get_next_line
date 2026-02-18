#include "get_next_line.h"

int	main(void)
{
	char	*str;
	int	fd = open("text.txt", O_RDONLY);

	str = get_next_line(fd);
	printf("string: %s", str);
	str = get_next_line(fd);
	printf("string: %s", str);
	str = get_next_line(fd);
	printf("string: %s", str);
	str = get_next_line(fd);
	printf("string: %s", str);
	str = get_next_line(fd);
	printf("string: %s", str);
	/*
	free(str);
	str = get_next_line(fd);
	printf("string: %s\n", str);
	free(str);
	str = get_next_line(fd);
	printf("string: %s\n", str);
	*/
	free(str);
	close(fd);
}
