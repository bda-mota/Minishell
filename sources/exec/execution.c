#include "../../includes/minishell.h"

static void	print_execve_error(char *command, int type);

int	executor(t_tree *tree)
{
	if (tree->type == PIPE)
	{
		return (pipe_execution(tree->left, tree->right));
	}
	if (the_branch_is_redir(tree))
	{
		return (redirs_execution(tree));
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
	check_command(tree, command);
	pid = fork();
	if (pid == -1)
		fork_error();
	if (pid == 0)
	{
		execve(tree->executable, tree->command_child, *get_env_copy(NULL));
		treat_errors(tree, &status);
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

void	treat_errors(t_tree *tree, int *status)
{
	if (access(tree->executable, F_OK) == -1
		&& (ft_strncmp(tree->executable, "./", 2) == 0
			|| ft_strncmp(tree->executable, "../", 3) == 0
			|| ft_strncmp(tree->executable, "/", 1) == 0))
		print_execve_error(tree->executable, 1);
	else if (access(tree->executable, X_OK) == -1
		&& access(tree->executable, F_OK) == 0)
	{
		ft_printf_fd(STDERR_FILENO, "Babyshell: %s: Permission denied\n",
			tree->executable);
		get_status(126);
	}
	else if (access(tree->executable, F_OK) == 0)
	{
		ft_printf_fd(STDERR_FILENO, "Babyshell: %s: Is a directory\n",
			tree->executable);
		get_status(126);
	}
	else
		print_execve_error(tree->executable, 127);
	*status = get_status(-1);
	free_fail_execve(tree->command_child, tree->executable);
}

static void	print_execve_error(char *command, int type)
{
	if (type == 1)
	{
		ft_printf_fd(STDERR_FILENO, "Babyshell: %s: No such file or directory\n",
			command);
		get_status(1);
	}
	else if (type == 127)
	{
		ft_printf_fd(STDERR_FILENO, "Babyshell: %s: command not found\n",
			command);
		get_status(127);
	}
}
