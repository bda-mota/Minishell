#include "../../includes/minishell.h"

int	is_fork(int fork)
{
	static int	in_fork;

	if (fork != -1)
		in_fork = fork;
	rl_clear_history();
	return (in_fork);
}

int	is_heredoc(int heredoc)
{
	static int	in_heredoc;

	if (heredoc != -1)
		in_heredoc = heredoc;
	rl_clear_history();
	return (in_heredoc);
}
