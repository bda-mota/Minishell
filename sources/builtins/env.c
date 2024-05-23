#include "../../includes/minishell.h"

void	env(t_minishell *shell)
{
	int	i;

	i = 0;
	while (shell->env_copy[i])
	{
		ft_printf_fd("%s\n", shell->env_copy[i], 1);
		i++;
	}
}
