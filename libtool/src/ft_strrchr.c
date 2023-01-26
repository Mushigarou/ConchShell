#include"../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	i = ft_strlen(s);
	while (i)
		if (s[i--] == (char)c)
			return (&((char *)s)[i + 1]);
	if (s[i] == (char)c)
		return (&((char *)s)[i]);
	return (NULL);
}
