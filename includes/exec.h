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
char	**count_size_environ(void);
char	**copy_environ(void);
char	**create_new_environ(char **my_environ, int num_vars);
char	**add_variable_to_environ(char **my_environ, char *new_var);

/* EXECUTION */
void	implement(t_exec **execution, char *command);
char	*check_command(t_exec *execution);

#endif
