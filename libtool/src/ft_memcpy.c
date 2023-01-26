#include"../inc/libft.h"

void	*ft_memcpy(void *d, const void *s, size_t l)
{
	size_t	i;

	i = 0;
	if (!d && !s)
		return (NULL);
	while (i < l)
	{
		((char *)d)[i] = ((char *)s)[i];
		i++;
	}
	return (d);
}
