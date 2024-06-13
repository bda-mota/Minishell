#ifndef EXEC_H
# define EXEC_H

# include "../libft/src/libft.h"
# include "structs.h"

/* ==== FREE CHILD ==== */
void	free_pipe_child(void);
void	free_simple_child(char **child, char *executable);
void	free_fail_execve(char **child, char *executable);

/* ==== COMMAND ==== */
int		check_command(t_tree *tree, char *command);
void	find_command(t_tree *tree, char *cmd);
void	remove_quotes_cmd(char **cmd);
int		is_directory(const char *path);


/* ==== EXECUTION ==== */
int		executor(t_tree *tree);
void	execute(t_tree *tree, char *command);
void	set_status(int status);

/* ==== REDIRECTS ==== */
int		redirs_execution(t_tree *tree);
void	insert_redir(t_redir **redirs, t_redir *new_redir);
void	deallocate_redirs(t_redir **redirs);
int		dup_file(t_tree *tree, int *fd);
int		open_file(t_tree *tree, int *fd);
t_redir	*create_redir(int *fd, int type);

/* ==== PIPE ==== */
int		pipe_execution(t_tree *left, t_tree *right);
int		open_tubes(int *tube);
void	first_child(t_tree *left, int *tube);
void	second_child(t_tree *right, int *tube);
void	close_tubes(int *tube);
void	wait_forks(pid_t *pid, int status);
void	close_all(void);
void	fork_error(void);

/* ==== PATH ==== */
void	find_path(t_minishell *shell);
void	build_path(t_minishell *shell);

#endif
