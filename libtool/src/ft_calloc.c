#include"../inc/libft.h"

void	*ft_calloc(size_t c, size_t s)
{
	void	*p;

	p = malloc(c * s);
	if (!p)
		return (NULL);
	ft_bzero(p, (s * c));
	return (p);
}
