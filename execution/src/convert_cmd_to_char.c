#include"../inc/execution.h"

int	cmd_len(t_list *cmd)
{
	t_list	*tmp;
	int		ct;

	ct = 0;
	tmp = cmd;
	while (tmp)
	{
		if (tmp->wt == PP)
			break ;
		if (tmp->wt == CMD || tmp->wt == ARG || tmp->wt == FLG)
			ct++;
		tmp = tmp->next;
	}
	return (ct);
}

char	**take_char_cmd(t_list *cmd)
{
	t_list	*tmp;
	char	**cmd;
	int		i;

	cmd = (char **)malloc(sizeof(char *) * (cmd_len(cmd) + 1));
	if (!cmd)
		return (NULL);
	i = 0;
	tmp = cmd;
	while (tmp)
	{
		if (tmp->wt == PP)
			break ;
		if (tmp->wt == CMD || tmp->wt == ARG || tmp->wt == FLG)
		{
			cmd[i] = ft_strdup(tmp->pt);
			i++;
		}
		if (i == cmd_len(cmd))
			break ;
		tmp = tmp->next;
	}
	cmd[i] = NULL;
	return (cmd);
}
