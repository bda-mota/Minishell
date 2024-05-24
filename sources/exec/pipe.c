#include "../../includes/minishell.h"

// void	pipe_execution(t_tree *node, t_exec **execution)
// {
// 	int		tube[2];
// 	pid_t	pid;
// 	t_tree	*aux;

// 	aux = node;
// 	if (pipe(tube) == -1)
// 	{
// 		printf("Erro ao abrir o tubo\n");
// 		return ;
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		close(tube[0]);
// 		close(tube[1]);
// 		printf("Erro ao abrir o fork\n");
// 		return ;
// 	}
// 	if (pid == 0)// p nó à direita
// 	{
// 		close (tube[0]);
// 		dup2(tube[1], STDOUT_FILENO);
// 		close (tube[1]);
// 		implement(execution, node->left->content);
// 		exit(EXIT_SUCCESS);
// 	}
// 	else //p nó à esquerda
// 	{
// 		waitpid(pid, NULL, 0);
// 		close (tube[1]);
// 		dup2(tube[0], STDIN_FILENO);
// 		implement(execution, node->right->content);
// 		close (tube[0]);
// 	}
// }
