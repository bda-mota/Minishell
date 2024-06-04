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

void	ft_echo(char *args);
void	ft_env(char **env_copy);
void	ft_pwd(void);
void	ft_export(char **env_copy, char *new_variable);
void	ft_unset(char **env_copy, char *remove_var);
void	ft_cd(char *path);

/* EXPORT_UTILS */

void	add_new_variable(char **env_copy, char *new_var);
int		update_variable(char **env_copy,
			char *var_name, char *new_var, int var_len);
void	add_variable_to_environ(char **env_copy, char *new_var);
void	swap_strings(char **str1, char **str2);
void	order_env(char **env_copy);
char	**count_size_environ(void);
char	**copy_environ(void);
char	**create_new_environ(char **my_environ, int num_vars);

#endif
