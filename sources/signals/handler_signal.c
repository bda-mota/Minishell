#include "../../includes/minishell.h"

void	signal_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		get_status(130);

	}
	if (signal == SIGQUIT)
		return ;
}

int	is_fork(int pid)
{
	if (pid == 0)
	{
		printf("estamos dentro do fork :D\n");
		ft_putchar_fd('\n', 1);
	}
	else
		printf("não estamos no fork, okay?\n");
	return (0);
}

// void	is_heredoc(int heredoc)
// {
// 	static int	in_heredoc;

// 	if (heredoc != -1)
// 		in_heredoc = heredoc;
// 	if (heredoc == 1)
// 	{
// 		return ;
// 	}
// }
