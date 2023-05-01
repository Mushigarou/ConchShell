#include"../inc/libft.h"

void	ft_lstdelone(t_list *lst)
{
	if (lst->pt)
	{
		if (ft_strncmp("/tmp/heredoc_", lst->pt, 13))
			unlink(lst->pt);
		free(lst->pt);
	}
	if (lst)
		free(lst);
	return ;
}
