#include"../inc/parsing.h"

t_list	*take_env(char **en)
{
	t_list	*env;
	int		i;

	i = -1;
	while (en[++i])
		ft_lstadd_back(&env, ft_lstnew(en[i], ENV));
	return (env);
}
