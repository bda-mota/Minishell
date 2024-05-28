#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/src/libft.h"
# include "structs.h"

/* GET_INPUT */

void	free_split_command(char **cmd_args);
void	execute_builtins(t_tree *tree);
char	**split_command(char *content);
int		is_builtin(char *content);

/* BUILTINS */

void	echo(char *args);
void	env(char **env_copy);
void	pwd(void);
void	export(char **env_copy, char *new_variable);
void	unset(char **env_copy, char *remove_var);
void	cd(char *path);

/* EXPORT_UTILS */

void	add_variable_to_environ(char **env_copy, char *new_var);
void	swap_strings(char **str1, char **str2);
void	order_env(char **env_copy);
char	**count_size_environ(void);
char	**copy_environ(void);
char	**create_new_environ(char **my_environ, int num_vars);

#endif
