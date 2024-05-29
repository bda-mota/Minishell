#ifndef EXEC_H
# define EXEC_H

# include "../libft/src/libft.h"
# include "structs.h"

/* FREE CHILD */
void	free_pipe_child(void);
void	free_simple_child(char **child, char *executable);

/* COMMAND */
void	check_command(t_tree *tree);
void	find_command(t_tree *tree, char *cmd);

/* EXECUTION */
int		direct_to_exec(t_tree *tree);
void	execute(t_tree *tree, char *command);

/* PIPE */
void	pipe_execution(t_tree *left, t_tree *right);
void	close_tubes(int *tube);
void	wait_forks(pid_t *pid);
int		open_tubes(int *tube);
int		open_fork(pid_t *pid);
void	close_all(void);

/* APPEND */
void	append_execution(t_tree *left, t_tree *right);

/* EXPANSION */
char	*get_expand_variable(t_token **token);

/* PATH */
void	find_path(t_minishell *shell);
void	build_path(t_minishell *shell);

#endif
