#include "../../includes/minishell.h"

void	pipe_execution(t_tree *left, t_tree *right)
{
	int		tube[2];
	int		status;
	pid_t	pid[2];

	status = 0;
	if (!open_tubes(tube))
		return ;
	pid[0] = fork();
	if (pid[0] == 0)
		first_child(left, tube);
	pid[1] = fork();
	if (pid[1] == 0)
		second_child(right, tube);
	close_tubes(tube);
	wait_forks(pid, status);
}

void	first_child(t_tree *left, int *tube)
{
	close(tube[0]);
	dup2(tube[STDOUT_FILENO], STDOUT_FILENO);
	close(tube[1]);
	executor(left);
	free_pipe_child();
	close_all();
	exit(0);
}

void	second_child(t_tree *right, int *tube)
{
	close(tube[1]);
	dup2(tube[STDIN_FILENO], STDIN_FILENO);
	close(tube[0]);
	executor(right);
	free_pipe_child();
	close_all();
	exit(0);
}
