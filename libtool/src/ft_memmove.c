#include"../inc/libft.h"

void	*ft_memmove(void *d, const void *s, size_t l)
{
	size_t	i;

	if (d < s && l > 0)
	{
		i = 0;
		while (i < l)
		{
			((char *)d)[i] = ((char *)s)[i];
			i++;
		}
	}
	if (s < d && l > 0)
	{
		while (--l > 0)
			((char *)d)[l] = ((char *)s)[l];
		((char *)d)[l] = ((char *)s)[l];
	}
	return (d);
}
