#include"../inc/built.h"

int	is_export(char *cmd)
{
	return (ft_strcmp(cmd, "export"));
}

void	print_export(t_minishell *mini)
{
	t_list	*tmp;
	t_list	*exprt;

	exprt = NULL;
	take_export(&exprt, mini->env);
	sort_list(exprt);
	tmp = exprt;
	while (tmp)
	{
		if (tmp->acs)
			ft_printf("%sdeclare - x %s%s\n", STDOUT_FILENO, GREEN,
				WHITE, tmp->pt);
		tmp = tmp->next;
	}
	ft_lstclear(&exprt);
}

void	export_var(char *str, t_minishell *mini)
{
	char	*key;
	char	*val;
	int		tp;
	int		acs;

	if (!check_export_syntax(str, mini->ext_st))
		return ;
	key = NULL;
	val = NULL;
	tp = 0;
	take_key_and_val(str, &key, &val, &tp);
	if (!ft_strcmp(key, "_"))
		return ;
	if (already_exists(mini->env, key, &acs))
	{
		if (acs && tp)
			change_env_prt(mini, key, val, tp);
		else if (!acs)
			bring_back_env_prt(mini, key, val, tp);
	}
	else
		add_new_env_prt(mini, key, val, tp);
	free(key);
	if (val)
		free(val);
}

void	my_export(t_exec *cmd, t_minishell *mini)
{
	int		i;

	i = 0;
	if (!cmd->cmd_exec[1])
		print_export(mini);
	else
	{
		while (cmd->cmd_exec[++i])
			export_var(cmd->cmd_exec[i], mini);
	}
}
