#include"../inc/execution.h"

int	check_cmd(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (tmp->wt == CMD)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	count_cmd_prt(t_list *cmd)
{
	t_list	*tmp;
	int		ct;

	ct = 0;
	tmp = cmd;
	while (tmp)
	{
		if (tmp->wt == CMD || tmp->wt == FLG || tmp->wt == ARG)
			ct++;
		tmp = tmp->next;
	}
	return (ct);
}

char	**take_char_cmd(t_list *cmd)
{
	t_list	*tmp;
	char	**cm;
	int		i;
	int		j;

	cm = NULL;
	i = count_cmd_prt(cmd);
	cm = (char **)malloc(sizeof(char *) * (i + 1));
	if (!cm)
		return (NULL);
	tmp = cmd;
	j = -1;
	while (tmp)
	{
		if (tmp->wt == CMD || tmp->wt == FLG || tmp->wt == ARG)
			cm[++j] = ft_strdup(tmp->pt);
		tmp = tmp->next;
	}
	cm[i] = NULL;
	return (cm);
}
