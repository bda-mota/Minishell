#include "../../includes/minishell.h"

int	redirs_execution(t_tree *tree)
{
	int	fd;
	int	saved_std[2];

	fd = 0;
	saved_std[0] = dup(STDIN_FILENO);
	saved_std[1] = dup(STDOUT_FILENO);
	if (open_file(tree, &fd) == -1)
	{
		dup2(saved_std[0], STDIN_FILENO);
		dup2(saved_std[1], STDOUT_FILENO);
		ft_printf_fd(STDERR_FILENO, "Babyshell: %s: %s\n",
			tree->right->content, strerror(errno));
		get_status(1);
		return (1);
	}
	dup_file(tree, &fd);
	if (tree->left)
		executor(tree->left);
	dup2(saved_std[0], STDIN_FILENO);
	dup2(saved_std[1], STDOUT_FILENO);
	close(saved_std[0]);
	close(saved_std[1]);
	return (0);
}

int	open_file(t_tree *tree, int *fd)
{
	if (tree && (tree->type == INPUT || tree->type == HEREDOC))
		*fd = open(tree->right->content, O_RDONLY);
	else if (tree && tree->type == APPEND)
		*fd = open(tree->right->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (tree && tree->type == OUTPUT)
		*fd = open(tree->right->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd == -1)
		return (-1);
	return (EXIT_SUCCESS);
}

int	dup_file(t_tree *tree, int *fd)
{
	if (tree && (tree->type == INPUT || tree->type == HEREDOC))
	{
		if (*fd != -1 && *fd != STDIN_FILENO)
		{
			dup2(*fd, STDIN_FILENO);
			close(*fd);
			return (EXIT_SUCCESS);
		}
	}
	else if (tree->type == OUTPUT || tree->type == APPEND)
	{
		if (*fd != -1 && *fd != STDOUT_FILENO)
		{
			dup2(*fd, STDOUT_FILENO);
			close(*fd);
			return (EXIT_SUCCESS);
		}
	}
	return (EXIT_FAILURE);
}
