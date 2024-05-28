#include "../../includes/minishell.h"

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
