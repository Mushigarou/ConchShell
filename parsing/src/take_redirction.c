#include"../inc/parsing.h"

void	take_redirection(t_minishell *mini, t_list **cmd, int *i)
{
	int	tp;

	if (mini->line[*i] == '<')
		take_input(mini, cmd, i);
	else
		take_output(mini, cmd, i);
}
