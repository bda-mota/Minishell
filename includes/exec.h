#ifndef EXEC_H
# define EXEC_H

# include "../libft/src/libft.h"
# include "structs.h"

/* COMMAND */
char	*check_command(t_minishell *shell);
char	*find_command(t_exec *execution, char *cmd);

/* EXECUTION */
void	direct_to_exec(t_minishell *shell);
void	execute(t_minishell *shell, char *command);

/* EXPANSION */
char	*get_expand_variable(t_token **token);

/* METACHARACTERS */

/* PATH */
void	find_path(t_minishell *shell);
void	build_path(t_minishell *shell);
void	copy_path_to_exec(t_minishell *shell);

#endif
