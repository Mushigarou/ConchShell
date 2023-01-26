#include"../inc/libft.h"

size_t	ft_strlcpy(char	*d, char *s, size_t ds)
{
	size_t	i;

	i = 0;
	if (ds == 0)
		return (ft_strlen(s));
	while (s[i] && i < ds - 1)
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (ft_strlen(s));
}
