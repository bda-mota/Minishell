#include "../../includes/minishell.h"

char	*check_command(t_minishell *shell)
{
	char	*command;
	char	*complete_command;

	command = shell->exec->command_child[0];
	if (access(command, X_OK) == 0)
		return (command);
	copy_path_to_exec(shell);
	complete_command = find_command(shell->exec, command);
	return (complete_command);
}

char	*find_command(t_exec *execution, char *cmd)
{
	int		i;
	char	*aux_cmd;
	char	**take_first;

	i = 0;
	take_first = ft_split(cmd, ' ');
	if (take_first == NULL)
		printf("error\n");
	while (execution->path_cmd[i])
	{
		aux_cmd = ft_strjoin(execution->path_cmd[i], take_first[0]);
		if (access(aux_cmd, X_OK) == 0)
		{
			ft_free_matrix(take_first);
			return (aux_cmd);
		}
		free(aux_cmd);
		i++;
	}
	ft_free_matrix(take_first);
	display_error_exec("command not found", cmd);
	return (NULL);
}
