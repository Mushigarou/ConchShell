#include"../inc/built.h"

int	is_cd(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->wt == CMD)
			if (!ft_strncmp(tmp->pt, "export", 7))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	my_export(t_list *cmd, t_minishell *mini)
{
	
}
