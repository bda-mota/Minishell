#include "../../includes/minishell.h"

int	executor(t_tree *tree)
{
	if (tree->type == PIPE)
	{
		pipe_execution(tree->left, tree->right);
		return (0);
	}
	if (the_branch_is_redir(tree))
	{
		redirs_execution(tree, tree->right);
		executor(tree->left);
		return (0);
	}
	else
	{
		if (is_builtin(tree->content))
		{
			execute_builtins(tree);
			return (0);
		}
		execute(tree, tree->content);
	}
	return (0);
}

void	execute(t_tree *tree, char *command)
{
	int	pid;
	int	status;

	status = 0;
	tree->command_child = ft_split(command, ' ');
	if (tree->command_child == NULL)
		printf("Error ao dar split\n");
	check_command(tree);
	if (tree->executable == NULL)
		return ;
	pid = fork();
	if (pid == 0)
	{
		execve(tree->executable, tree->command_child, *get_env_copy(NULL));
		free_fail_execve(tree->command_child, tree->executable);
		ft_printf_fd("Babyshell: %s\n", strerror(errno), 2);
		status = 126;
		exit(126);
	}
	waitpid(pid, &status, 0);
	free_simple_child(tree->command_child, tree->executable);
	set_status(status);
}

void	set_status(int status)
{
	if (WIFEXITED(status))
	{
		status = WEXITSTATUS(status);
		get_status(status);
	}
	else
		get_status(0);
}
