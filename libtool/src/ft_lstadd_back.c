#include"../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cr;

	if (lst)
	{
		if (*lst)
		{
			cr = ft_lstlast(*lst);
			if (!cr)
				return ;
			cr->next = new;
		}
		else
			*lst = new;
	}
}
