#include"../inc/built.h"

int	is_pwd(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->wt == CMD)
			if (!ft_strncmp(tmp->pt, "pwd", 4))
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	my_pwd(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strncmp(tmp->pt, "PWD=", 4))
		{
			ft_printf("%s\n", STDOUT_FILENO, tmp->pt + 4);
			break ;
		}
		tmp = tmp->next;
	}
}
