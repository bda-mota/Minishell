#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/src/libft.h"
# include "structs.h"

int		is_builtin(char *command);
char	**split_command(char *content);
void	find_builtins(t_minishell *shell, t_tree *tree);
void	echo(char *args);
void	env(t_minishell *env);
void	pwd(void);
void	export(t_minishell *shell, char *new_variable);
char	**count_size_environ(void);
char	**copy_environ(void);
char	**create_new_environ(char **my_environ, int num_vars);
void	add_variable_to_environ(t_minishell *shell, char *new_var);
void	unset(t_minishell *env, char *remove_var);
void	cd(char *path);

#endif
