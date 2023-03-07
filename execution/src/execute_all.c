#include"../inc/execution.h"

int	error(char *er)
{
	ft_printf("MiniShell : %s : %s\n", STDERR_FILENO, strerror(errno), er);
	return (errno);
}

void	cmd_not_found(char **en, char **cm)
{
	ft_printf("Minishell : command not found : %s\n", STDERR_FILENO, cm[0]);
	deallocate(en);
	deallocate(cm);
	exit(127);
}

void	do_single_cmd(t_list *cmd, t_minishell *mini)
{
	char	**en;
	char	**cm;
	char	*cm_pth;

	en = NULL;
	cm = NULL;
	cm_pth = NULL;
	if (check_in_rdrct(cmd))
		take_input(cmd, mini);
	if (check_out_rdrct(cmd))
		take_output(cmd);
	if (check_cmd(cmd))
	{
		en = take_char_env(mini->env);
		cm = take_char_cmd(cmd);
		cm_pth = take_path(cm[0], mini);
		if (!cm_pth)
			cmd_not_found(en, cm);
		execve(cm_pth, cm, en);
		exit(error("execve"));
	}
	else
		exit(EXIT_SUCCESS);
}

void	execute_one(t_list *cmd, t_minishell *mini)
{
	int		pid;

	pid = fork();
	if (!pid)
		do_single_cmd(cmd, mini);
	else
		waitpid(pid, &mini->ext_st, 0);
}

void	execute_all(t_list **cmd, int ct, t_minishell *mini)
{
	if (ct == 1)
		execute_one(cmd[0], mini);
}
