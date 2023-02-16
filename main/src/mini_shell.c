#include"../inc/mini_shell.h"

char	*pass_to_readline(void)
{
	char	cd[PATH_MAX];
	char	*ttl;
	int		i;

	i = 0;
	if (getcwd(cd, PATH_MAX) < 0)
		exit(errno);
	else
	{
		while (cd[i])
			i++;
		while (cd[i] != '/')
			i--;
		ttl = ft_strjoin("(", cd + i + 1);
		ttl = ft_strjoin(ttl, ")~> ");
	}
	return (ttl);
}

int	valid_ct(char *cl)
{
	int	i;
	int	j;
	int	ct;

	i = -1;
	while (cl[++i])
	{
		if (cl[i] == 34 || cl[i] == 39)
		{
			ct = cl[i];
			j = i;
			while (cl[++j])
				if (cl[j] == ct)
					break ;
			if (cl[j] == '\0')
				return (1);
			else
				i = j;
		}
	}
	return (0);
}

int	is_spc_cr(char c)
{
	if (c == 32 || c == 34 || c == 39 || c == '|' || c == '<' || c == '>'
		|| c == '-' || c == '$' || c == '\n' || c == '\0')
		return (1);
	else
		return (0);
}

t_list	*cmd_line(char *cl)
{
	t_list	*cml;
	t_list	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (cl[i])
	{
		if (ft_isalpha(cl[i]))
		{
			while (cl[i] && )
				i++;
		}
	}
	tmp = cml;
	while (tmp)
	{
		printf("->(%s)\n", tmp->pt);
		tmp = tmp->next;
	}
	return (cml);
}

int	main(int ac, char **av, char **en)
{
	t_list	*env;
	t_list	*tmp;
	char	*cd;
	char	*ln;

	if (ac == 1)
	{
		while (1)
		{
			cd = pass_to_readline();
			ln = readline(cd);
			if (!ln)
				return (errno);
			env = cmd_line(ln);
		}
	}
}
