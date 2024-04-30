#include "../includes/minishell.h"

void	display_error(char *error, char c)
{
	if (ft_strcmp(error, "sintaxe") == 0)
	{
		ft_putstr_fd(WARNING_SINTAXE, 2);
		write(2, &c, 1);
	}
	if (ft_strcmp(error, "||") == 0)
	{
		ft_putstr_fd(WARNING_OR, 2);
		write(2, &c, 1);
	}
	exit(1);
}

void	found_sintaxe(char *str, t_token **token_h, t_token **token_t)
{
	deallocate_lst(token_t, token_h);
	rl_clear_history();
	if (ft_strstr(str, "|||"))
		display_error("sintaxe", '|');
	else if (ft_strstr(str, "<<<"))
		display_error("sintaxe", '<');
	else if (ft_strstr(str, ">>>"))
		display_error("sintaxe", '>');
}
