#include "../../includes/minishell.h"

void	signal_handler(int signal)
{
	char		**env_copy;

	env_copy = *get_env_copy(NULL);
	if (signal == SIGINT)
	{
		if (is_fork(-1) == 1)
		{
			printf("estamos dentro do fork :D\n");
			if (env_copy)
			{
				ft_free_matrix(env_copy);
				*get_env_copy(NULL) = NULL;
			}
		}
		else
		{
			printf("não estamos no fork, okay?\n");
			ft_putchar_fd('\n', 1);
			rl_on_new_line();
			rl_replace_line("", 0);
			rl_redisplay();
			get_status(130);
		}
	}
	if (signal == SIGQUIT)
		return ;
}

int	is_fork(int fork)
{
	static int	in_fork;

	if (fork != -1)
		in_fork = fork;
	return (in_fork);
}

int	is_heredoc(int heredoc)
{
	static int	in_heredoc;

	if (heredoc != -1)
		in_heredoc = heredoc;
	return (in_heredoc);
}
