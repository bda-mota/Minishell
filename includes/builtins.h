#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/src/libft.h"
# include "structs.h"

int		is_builtin(char *content);
void	free_split_command(char **cmd_args);
char	**split_command(char *content);
void	execute_builtins(t_tree *tree);
void	echo(char *args);
void	env(char **env_copy);
void	pwd(void);
void	export(char **env_copy, char *new_variable);
char	**count_size_environ(void);
char	**copy_environ(void);
char	**create_new_environ(char **my_environ, int num_vars);
void	add_variable_to_environ(char **env_copy, char *new_var);
void	unset(char **env_copy, char *remove_var);
void	cd(char *path);

#endif
