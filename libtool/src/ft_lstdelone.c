#include"../inc/libft.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst->pt)
		free(lst->pt);
	if (lst)
		free(lst);
	return ;
}
