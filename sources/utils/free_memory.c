#include "../../includes/minishell.h"

void	free_minishell(t_minishell *shell)
{
	char	**env_copy;

	env_copy = *get_env_copy(NULL);
	if (shell->input)
		free(shell->input);
	if (env_copy)
		ft_free_matrix(env_copy);
	if (shell->paths)
	{
		ft_free_matrix(shell->paths);
		shell->paths = NULL;
	}
	if (shell->tree)
		down_tree(&shell->tree);
	if (shell->cmd_args)
		free_split_command(shell->cmd_args);
	close_all();
}

void	free_execution(void)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	if (shell->input)
		free (shell->input);
	if (shell->paths)
	{
		ft_free_matrix(shell->paths);
		shell->paths = NULL;
	}
	if (shell->tree)
		down_tree(&shell->tree);
}


void	free_simple_child(char **child, char *executable)
{
	if (child)
		ft_free_matrix(child);
	if (executable)
		free(executable);
}

void	free_pipe_child(void)
{
	t_minishell	*shell;
	char		**env_copy;

	env_copy = *get_env_copy(NULL);
	shell = get_minishell(NULL);
	if (shell->input)
		free(shell->input);
	if (env_copy)
		ft_free_matrix(env_copy);
	if (shell->paths)
		ft_free_matrix(shell->paths);
	if (shell->tree && shell->tree->executable)
		free(shell->tree->executable);
	if (shell->tree && shell->tree->command_child)
		ft_free_matrix(shell->tree->command_child);
	if (shell->tree)
		down_tree(&shell->tree);
	rl_clear_history();
}

void	free_fail_execve(char **child, char *executable)
{
	t_minishell	*shell;
	char		**env_copy;
	int			status;

	env_copy = *get_env_copy(NULL);
	shell = get_minishell(NULL);
	free_simple_child(child, executable);
	if (shell->paths)
		ft_free_matrix(shell->paths);
	if (shell->input)
		free(shell->input);
	if (env_copy)
		ft_free_matrix(env_copy);
	if (shell->tree)
		down_tree(&shell->tree);
	rl_clear_history();
	status = get_status(-1);
	exit(status);
}
