#ifndef EXEC_H
# define EXEC_H

# include "../libft/src/libft.h"
# include "structs.h"

/* PATH */
void	find_path(t_exec **execution);
void	build_path(t_exec **execution);
char	*add_command_to_path(t_exec **execution, char *cmd);

/* EXPANSION */
char	*get_expand_variable(t_token **token);

/* EXECUTION */
void	direct_to_exec(t_tree **root, t_exec **execution);
void	implement(t_exec **execution, char *command);
char	*check_command(t_exec *execution);

/* METACHARACTERS */
void	pipe_execution(t_tree *node, t_exec **execution);

#endif
