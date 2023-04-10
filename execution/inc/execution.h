
#ifndef EXECUTION_H
# define EXECUTION_H

# include "libft.h"
# include "parsing.h"
# include "built.h"
# include "mini_shell.h"

typedef struct s_redrc
{
	char	*file_name;
	int		type;
	struct s_redrc	*next;
}	t_redrc;

typedef struct s_exec
{
	char	**cmd_exec;
	t_redrc	redrc; // par default *(NULL)
	struct s_exec	*next;  // if (next == 1) {means there is a pipe}
}	t_exec;

// ************ Execution **************
void	execute_cmds(t_minishell *mini);
// **	Converts env variable from (t_list *) to a (char **)
char	**convert_env(t_list *env);
// **	Returns path variable splitted
char 	*get_cmd_path(t_minishell *mini, char *cmd);

#endif
