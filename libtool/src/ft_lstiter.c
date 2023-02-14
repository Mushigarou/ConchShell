#include"../inc/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(char *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(f)(lst->pt);
		lst = lst->next;
	}
}
