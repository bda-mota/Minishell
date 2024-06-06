#ifndef EXEC_H
# define EXEC_H

# include "../libft/src/libft.h"
# include "structs.h"

/* ==== FREE CHILD ==== */
void	free_pipe_child(void);
void	free_simple_child(char **child, char *executable);
void	free_fail_execve(char **child, char *executable);

/* ==== COMMAND ==== */
void	check_command(t_tree *tree);
void	find_command(t_tree *tree, char *cmd);

/* ==== EXECUTION ==== */
int		executor(t_tree *tree);
void	execute(t_tree *tree, char *command);
void	set_status(int status);

/* ==== HEREDOC ==== */
int		has_heredoc(t_token *token);


/* ==== REDIRECTS ==== */
void	redirs_execution(t_tree *tree, t_tree *right);
int		open_file(t_tree *tree, int *fd);
int		dup_file(t_tree *tree, int *fd);

/* ==== PIPE ==== */
void	pipe_execution(t_tree *left, t_tree *right);
void	first_child(t_tree *left, int *tube);
void	second_child(t_tree *right, int *tube);
void	close_tubes(int *tube);
void	wait_forks(pid_t *pid, int status);
int		open_tubes(int *tube);
int		open_fork(pid_t *pid);
void	close_all(void);

/* ==== EXPANSION ==== */
char	*get_expand_variable(t_token **token);

/* ==== PATH ==== */
void	find_path(t_minishell *shell);
void	build_path(t_minishell *shell);

#endif
