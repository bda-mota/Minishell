#include "../../includes/minishell.h"

int	pipe_execution(t_tree *left, t_tree *right)
{
	int		tube[2];
	int		status[2];
	pid_t	pid[2];

	if (!open_tubes(tube))
		return (-1);
	pid[0] = fork();
	//is_fork(pid[0]);
	if (pid[0] == 0)
		first_child(left, tube);
	pid[1] = fork();
	//is_fork(pid[1]);
	if (pid[1] == 0)
		second_child(right, tube);
	close_tubes(tube);
	waitpid(pid[0], &status[0], 0);
	waitpid(pid[1], &status[1], 0);
	return (get_status(WEXITSTATUS(status[1])));
}

void	first_child(t_tree *left, int *tube)
{
	int	status;

	close(tube[0]);
	dup2(tube[STDOUT_FILENO], STDOUT_FILENO);
	close(tube[1]);
	status = executor(left);
	free_pipe_child();
	close_all();
	close(STDOUT_FILENO);
	exit(status);
}

void	second_child(t_tree *right, int *tube)
{
	int	status;

	close(tube[1]);
	dup2(tube[STDIN_FILENO], STDIN_FILENO);
	close(tube[0]);
	status = executor(right);
	free_pipe_child();
	close_all();
	close(STDIN_FILENO);
	exit(status);
}
