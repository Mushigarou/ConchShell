#include"../inc/built.h"

int	is_env(char *cmd)
{
	return (ft_strcmp(cmd, "env"));
}

void	my_env(t_list *env)
{
	t_list	*tmp;

	tmp = env;
	while (tmp)
	{
		if (tmp->acs && ft_strchr(tmp->pt, '='))
			ft_printf("%s\n", STDOUT_FILENO, tmp->pt);
		tmp = tmp->next;
	}
}
