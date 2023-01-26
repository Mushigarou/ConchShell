#include"../inc/libft.h"

void	*ft_memset(void *p, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((unsigned char *)p)[i++] = (unsigned char)c;
	return (p);
}
