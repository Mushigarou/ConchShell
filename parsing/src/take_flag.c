#include"../inc/parsing.h"

int	take_flag(t_minishell *mini, t_list **cmd, int i)
{
	char	*flg;
	int		j;

	j = i + 1;
	if (mini->line[j] == '-')
		j++;
	while (mini->line[j])
	{
		if (ft_isspace(mini->line[j]) || (!ft_isalnum(mini->line[j])
				&& mini->line[j] != '='))
			break ;
		j++;
	}
	flg = ft_substr(mini->line, i, j - i);
	ft_lstadd_back(cmd, ft_lstnew(flg, FLG));
	free(flg);
	return (j);
}
