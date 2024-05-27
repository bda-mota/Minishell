#ifndef EXEC_H
# define EXEC_H

# include "../libft/src/libft.h"
# include "structs.h"

/* COMMAND */
char	*check_command(t_minishell *shell);
char	*find_command(t_exec *execution, char *cmd);

/* EXECUTION */
int		direct_to_exec(t_tree *tree);
void	execute(t_tree *tree, char *command);

/* PIPE */
void	pipe_execution(t_tree *left, t_tree *right);

/* EXPANSION */
char	*get_expand_variable(t_token **token);

/* METACHARACTERS */

/* PATH */
void	find_path(t_minishell *shell);
void	build_path(t_minishell *shell);
void	copy_path_to_exec(t_minishell *shell);

#endif
