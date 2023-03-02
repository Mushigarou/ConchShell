#include"../inc/execution.h"

int	env_len(t_list *en)
{
	t_list	*tmp;
	int		ct;

	ct = 0;
	tmp = en;
	while (tmp)
	{
		if (tmp->acs)
			ct++;
		tmp = tmp->next;
	}
	return (ct);
}

char	**take_char_env(t_list *en)
{
	t_list	*tmp;
	char	**env;
	int		i;

	env = (char **)malloc(sizeof(char *) * (env_len(en) + 1));
	if (!env)
		return (NULL);
	i = 0;
	tmp = en;
	while (tmp)
	{
		if (tmp->acs)
		{
			env[i] = ft_strdup(tmp->pt);
			i++;
		}
		if (i == env_len(en))
			break ;
		tmp = tmp->next;
	}
	env[i] = NULL;
	return (env);
}
