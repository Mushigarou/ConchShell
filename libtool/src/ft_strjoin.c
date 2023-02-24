#include"../inc/libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*d;

	if (!s1 && s2)
		return (d = ft_strdup(s2), free(s2), d);
	if (!s2 && s1)
		return (d = ft_strdup(s1), free(s1), d);
	if (s1 && s2)
	{
		i = -1;
		j = -1;
		d = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (!d)
			return (NULL);
		while (s1[++i])
			d[i] = s1[i];
		while (s2[++j])
			d[i + j] = s2[j];
		d[i + j] = '\0';
		return (free(s1), free(s2), d);
	}
	return (NULL);
}
