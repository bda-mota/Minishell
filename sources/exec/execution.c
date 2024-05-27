#include "../../includes/minishell.h"

int	direct_to_exec(t_tree *tree)
{
	if (tree->type == PIPE)
	{
		pipe_execution(tree->left, tree->right);
		return (0);
		//return (pipe_execution(tree->left, tree->right));
	}
	else
	{
		//checar se é builtin, se não for mandar para execute
		execute(tree, tree->content);
		return (0);
	}
}

void	execute(t_tree *tree, char *command)
{
	char	*executable;
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		tree->command_child = ft_split(command, ' ');
		if (tree->command_child == NULL)
			printf("Error ao dar split\n");
		executable = check_command(tree);
		if (executable == NULL)
			return ;
		execve(executable, tree->command_child, get_copy(NULL));
		//tratamento se o execve dar b.o;
	}
	//free_execution(tree, NULL);
	wait(NULL);
}
