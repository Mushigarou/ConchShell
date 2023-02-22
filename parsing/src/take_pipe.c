#include"../inc/parsing.h"

int	valid_pipe(char *line)
{
	int	i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		i++;
	if (line[i] == '|')
		return (0);
	while (line[++i])
	{
		if (line[i] == '|' && !in_quotes(line, i))
		{
			while (line[++i])
				if (!ft_isspace(line[i]) || line[i] == '|')
					break ;
			if (line[i] == '\0' || line[i] == '|')
				return (0);
		}
	}
	return (1);
}

int	take_pipe(t_minishell *mini, t_list **cmd, int i)
{
	ft_lstadd_back(cmd, ft_lstnew("|", PP));
	i += 1;
	return (i);
}
