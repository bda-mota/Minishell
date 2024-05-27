#include "../../includes/minishell.h"

//tratar erros de fork e pipe
//tratar erros de execve
//tratar erros de dup2
//tratar erros de close
//tratar erros de wait
void	pipe_execution(t_tree *left, t_tree *right)
{
	int		tube[2];
	pid_t	pid[2];

	if (pipe(tube) == -1)
	{
		printf("Erro ao abrir o tubo\n");
		return ;
	}
	pid[0] = fork();
	if (pid[0] == 0)
	{
		close (tube[0]);
		dup2(tube[STDOUT_FILENO], STDOUT_FILENO);
		close (tube[1]);
		direct_to_exec(left);
	}
	pid[1] = fork();
	if (pid[1] == 0)
	{
		close (tube[1]);
		dup2(tube[STDIN_FILENO], STDIN_FILENO);
		close (tube[0]);
		direct_to_exec(right);
	}
}
