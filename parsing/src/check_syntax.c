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
				if (!ft_isspace(line[i]))
					break ;
			if (line[i] == '\0')
				return (0);
		}
	}
	return (1);
}

int	empty_line(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
		if (!ft_isspace(line[i]))
			break ;
	if (line[i] == '\0')
		return (1);
	else
		return (0);
}

int	check_syntax(char *line)
{
	if (empty_line(line))
		return (0);
	else if (!valid_ct(line))
		return (256);
	else if (!valid_redirection(line))
		return (256);
	else if (!valid_pipe(line))
		return (256);
	else
		return (1);
}
