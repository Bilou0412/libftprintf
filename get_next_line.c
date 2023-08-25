#include"libft.h"

char	*get_next_line(int fd, int *error)
{
	int		i;
	int		rd;
	char	character;
	char	*buffer;

	i = 0;
	rd = 0;
	buffer = malloc(100000);
	if (!buffer)
		return (*error = 1, NULL);
	rd = read(fd, &character, 1);
	while (rd > 0)
	{
		buffer[i++] = character;
		if (character == '\n')
			break ;
		rd = read(fd, &character, 1);
	}
	buffer[i] = '\0';
	if (rd == -1)
		return (*error = 1, free(buffer), NULL);
	if (i == 0 || (!buffer[i - 1] && !rd))
		return (free(buffer), NULL);
	return (buffer);
}