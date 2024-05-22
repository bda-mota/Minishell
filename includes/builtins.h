#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/src/libft.h"
# include "structs.h"

void	find_builtins(t_token **token);
void	echo(t_token **tokens);
void	env(char **environ_copy);
void	pwd(void);
void	export(char *new_variable);
char	**count_size_environ(void);
char	**copy_environ(void);
char	**create_new_environ(char **my_environ, int num_vars);
char	**add_variable_to_environ(char **my_environ, char *new_var);
char	**unset(char **environ_copy, char *remove_var);

#endif