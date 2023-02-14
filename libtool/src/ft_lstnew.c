#include"../inc/libft.h"

t_list	*ft_lstnew(char *wrd, int tp)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->pt = ft_strdup(wrd);
	new->wt = tp;
	new->acs = 1;
	new->next = NULL;
	return (new);
}
