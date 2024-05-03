#include "../includes/minishell.h"

void	display_error(char *error, char c)
{
	if (ft_strcmp(error, "sintaxe") == 0)
	{
		ft_putstr_fd(WARNING_SINTAXE, 2);
		write(2, &c, 1);
		write(2, "\n", 1);
	}
	if (ft_strcmp(error, "||") == 0 || ft_strcmp(error, "&&") == 0)
		ft_putstr_fd(WARNING_OR, 2);
}

void	found_sintaxe(char *str, t_token **token_tail, t_token **token_h)
{
	deallocate_lst(token_tail, token_h);
	rl_clear_history();
	if (ft_strstr(str, "<<<"))
		display_error("sintaxe", '<');
	else if (ft_strstr(str, ">>>"))
		display_error("sintaxe", '>');
	else if (ft_strstr(str, "||"))
		display_error("||", '|');
	else if (ft_strstr(str, "|||"))
		display_error("sintaxe", '|');
	else if (ft_strstr(str, "&&"))
		display_error("&&", '&');
}
