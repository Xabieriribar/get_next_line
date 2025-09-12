#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int	list;
	char	*next_line;
	int	fd;

	list = 0;
	fd = open("test/text.txt", O_RDONLY);
	while ((next_line = get_next_line(fd)))
	 {
		printf("%d -> %s", list++, next_line);
	 }
	return (0);
}
