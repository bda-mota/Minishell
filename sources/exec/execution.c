#include "../../includes/minishell.h"

//return (pipe_execution(tree->left, tree->right));
//fazer todas as funções serão do tipo int para exit status

int	direct_to_exec(t_tree *tree)
{
	if (tree->type == PIPE)
	{
		pipe_execution(tree->left, tree->right);
		return (0);
	}
	if (the_branch_is_redir(tree))
	{
		redirs_execution(tree, tree->right);
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
		//tratamento se o execve dar b.o -> free
	}
	free_simple_child(tree->command_child, tree->executable);
	wait(NULL);
}
