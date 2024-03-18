#include <stdlib.h>
#include <unistd.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = 0;
	while (s[l])
		l++;
	str = malloc(sizeof(char) * l + 1);
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
