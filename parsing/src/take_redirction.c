#include"../inc/parsing.h"

int	take_rediraction(t_minishell *mini, t_list **cmd, int i)
{
	if (mini->line[i] == '<')
		i = take_input(mini, cmd, i);
	else
		i = take_output(mini, cmd, i);
	return (i);
}
