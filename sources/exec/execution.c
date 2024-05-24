#include "../../includes/minishell.h"

void	direct_to_exec(t_minishell *shell)
{
	t_tree	*aux;

	aux = traverse_tree(&shell->tree);
	if (aux->type == PIPE)
	{
		return ;
		//pipe_execution(aux, shell->exec);
	}
	else
	{
		//checar se é builtin, se não for mandar para execute
		execute(shell, aux->content);
	}
}

void	execute(t_minishell *shell, char *command)
{
	char	*executable;
	int		pid;

	shell->exec = ft_calloc(1, sizeof(t_exec));
	if (shell->exec == NULL)
		printf("Error ao alocar exec\n");
	pid = fork();
	if (pid == 0)
	{
		shell->exec->command_child = ft_split(command, ' ');
		if (shell->exec->command_child == NULL)
			printf("Error ao dar split\n");
		executable = check_command(shell);
		if (executable == NULL)
			return ;
		execve(executable, shell->exec->command_child, shell->env_copy);
	}
	wait(NULL);
}
