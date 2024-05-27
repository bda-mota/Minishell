#include "../../includes/minishell.h"

// int	direct_to_exec(t_tree *tree)
// {
// 	if (tree->type == PIPE)
// 	{
// 		pipe_execution(tree->left, tree->right);
// 		return (0);
// 		//return (pipe_execution(tree->left, tree->right));
// 	}
// 	else
// 	{
// 		//checar se é builtin, se não for mandar para execute
// 		execute(tree, tree->content);
// 		return (0);
// 	}
// }

// //mudar
// void	execute(t_tree *tree, char *command)
// {
// 	char	*executable;
// 	int		pid;

// 	shell->exec = ft_calloc(1, sizeof(t_exec));
// 	if (shell->exec == NULL)
// 		printf("Error ao alocar exec\n");
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		shell->exec->command_child = ft_split(command, ' ');
// 		if (shell->exec->command_child == NULL)
// 			printf("Error ao dar split\n");
// 		executable = check_command(shell);
// 		if (executable == NULL)
// 			return ;
// 		execve(executable, shell->exec->command_child, shell->env_copy);
// 	}
// 	wait(NULL);
// }
