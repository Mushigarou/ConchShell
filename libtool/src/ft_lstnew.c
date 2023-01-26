#include"../inc/libft.h"

t_list	*ft_lstnew(long content, int idx)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->idx = idx;
	new->st = 0;
	new->st_cnt = 0;
	new->next = NULL;
	return (new);
}
