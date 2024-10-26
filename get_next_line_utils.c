#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

static char	*concat(char *final, char *str, int index)
{
	int	strindex;

	strindex = 0;
	while (str[strindex] != '\0')
	{
		final[index] = str[strindex];
		index++;
		strindex++;
	}
	return (final);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		size;
	int		index;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	index = 0;
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = (char *)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str = concat(str, (char *)s1, index);
	index = ft_strlen((char *)s1);
	str = concat(str, (char *)s2, index);
	index = index + ft_strlen((char *)s2);
	str[index] = '\0';
	return (str);
}