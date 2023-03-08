#include"../inc/built.h"

int	is_env(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->wt == CMD)
			if (!ft_strncmp(tmp->pt, "env", 4))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	my_env(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->acs)
			ft_printf("%s\n", STDOUT_FILENO, tmp->pt);
		tmp = tmp->next;
	}
}
