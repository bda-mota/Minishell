#ifndef EXEC_H
# define EXEC_H

# include "../libft/src/libft.h"
# include "structs.h"

/* COMMAND */
char	*check_command(t_tree *tree);
char	*find_command(t_tree *tree, char *cmd);

/* EXECUTION */
int		direct_to_exec(t_tree *tree);
void	execute(t_tree *tree, char *command);

/* PIPE */
void	pipe_execution(t_tree *left, t_tree *right);

/* METACHARACTERS */

/* PATH */
void	find_path(t_minishell *shell);
void	build_path(t_minishell *shell);
void	copy_path_to_exec(t_tree *tree);

#endif
