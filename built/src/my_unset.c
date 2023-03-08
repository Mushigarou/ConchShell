#include"../inc/built.h"

int	is_unset(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->wt == CMD)
			if (!ft_strncmp(tmp->pt, "unset", 5))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}
