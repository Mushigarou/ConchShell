#ifndef MINI_SHELL_H
# define MINI_SHELL_H

# include"../../parsing/inc/parsing.h"
# include"../../execution/inc/execution.h"
# include"../../libtool/inc/libft.h"

void	mini_shell(t_minishell *mini);
void	out(t_minishell *mini);
char	*inisialise_prompt(void);
void	take_cmd(t_minishell *mini);
void	take_and_do_cmd(t_minishell *mini);

#endif
