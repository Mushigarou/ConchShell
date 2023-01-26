#include"../inc/libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*tl;

	if (!lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tl = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tl;
	}	
}
