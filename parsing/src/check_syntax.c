#include"../inc/parsing.h"

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
		return (-1);
	else if (!valid_ct(line))
		return (258);
	else if (!valid_rediraction(line))
		return (258);
	else if (!valid_pipe(line))
		return (258);
	else
		return (0);
}
