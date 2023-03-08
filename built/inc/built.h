#ifndef BUILT_H
# define BUILT_H

# include"../../libtool/inc/libft.h"
# include"../../parsing/inc/parsing.h"
# include"../../execution/inc/execution.h"

/*check if the flag -n chould work*/
int		check_echo_flg(char *flg);
/*repreduce the echo bihavior*/
void	my_echo(t_list *cmd, t_minishell *mini);
/*check if the command is echo*/
int		is_echo(t_list *cmd);

#endif
