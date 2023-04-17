#include"../inc/built.h"

int	is_pwd(char *cmd)
{
	return (ft_strcmp(cmd, "pwd"));
}

void	my_pwd(t_list *env)
{
	char	cd[PATH_MAX];
	t_list	*tmp;

	if (getcwd(cd, PATH_MAX))
	{
		ft_printf("%s\n", STDOUT_FILENO, cd);
		return ;
	}
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
