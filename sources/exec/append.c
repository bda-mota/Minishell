#include "../../includes/minishell.h"

// void	append_execution(t_tree *left, t_tree *right)
// {
// 	int	fd_in;
// 	int	fd_out;

// 	//abrindo só arquivo de entrada sem ser comando de execução
// 	if (access(left->content, F_OK) == 0)
// 		fd_in = open(left->content, O_RDONLY);
// 	dup2(fd_in, STDIN_FILENO);
// 	close(fd_in);
// 	fd_out = open(right->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
// 	if (fd_out == -1)
// 	{
// 		printf("Error ao abrir o arquivo - right\n");
// 		return ;
// 	}
// 	dup2(fd_out, STDOUT_FILENO);
// 	close(fd_out);
// }

/*
void	append_execution(t_tree *left, t_tree *right)
{
	int	fd_in;
	int	fd_out;
	int	tube[2];

	//abrindo só arquivo de entrada sem ser comando de execução
	open_tubes(tube);
	fd_in = open(left->content, O_RDONLY);
	printf("fd_in = %d\n", fd_in);
	if (fd_in == -1)
	{
		printf("Error ao abrir o arquivo - left\n");
		return ;
	}
	dup2(fd_in, STDIN_FILENO);
	close(fd_in);
	fd_out = open(right->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd_out == -1)
	{
		printf("Error ao abrir o arquivo - right\n");
		return ;
	}
	dup2(fd_out, STDOUT_FILENO);
	close(fd_out);
}
*/
