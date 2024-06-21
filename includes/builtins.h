#ifndef BUILTINS_H
# define BUILTINS_H

# include "../libft/src/libft.h"
# include "structs.h"

typedef struct s_var
{
	int		args;
	int		start;
	int		simple_quote;
	int		double_quote;
	char	**environ;
}	t_var;

/* ==== GET_INPUT ==== */

void	free_split_command(char **cmd_args);
int		execute_builtins(t_tree *tree);
char	**split_command(char *content);
int		is_builtin(char *content);

/* ==== BUILTINS ==== */

void	ft_echo(char *args);
void	ft_env(char **env_copy);
void	ft_pwd(void);
void	ft_export(char **env_copy, char *new_variable);
void	ft_unset(char **env_copy, char *variables);
void	ft_cd(char *path);
int		ft_exit(char *args);

/* ==== EXPORT_UTILS ==== */

void	change_variables(char *new_variable);
void	print_variables(char	**env_copy);
int		processed_var(char **environ, char *new_variable, int start, int args);
void	variable_to_environ(char **env_copy, char *new_var);
int		update_variable(char **env_copy,
			char *var_name, char *new_var, int var_len);
void	add_new_variable(char **env_copy, char *new_var);
char	**create_new_environ(char **my_environ, int num_vars);
char	*copy_var(char *new_var, int size);
int		check_variable_name(char *new_var);
char	**copy_environ(void);
char	**count_size_environ(void);
void	order_env(char **env_copy);
void	swap_strings(char **str1, char **str2);
char	*build_var(char *env_copy, char *new_var, int var_len);

/* ==== UTILS_QUOTES ==== */

int		quotes(char c, int *simple_quote, int *double_quote);
int		ft_strlen_without_quotes(const char *str);
void	ft_strcpy_without_quotes(char *dest, const char *src);

#endif
