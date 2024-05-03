#include "../../includes/minishell.h"

int	check_sintax(char *input)
{
	if (!check_untreatable(input))
		return (1);
	else if (!check_blocks(input))
		return (1);
	else if (!check_double_quotes(input))
		return (1);
	else if (!check_simple_quotes(input))
		return (1);
	return (0);
}

int	check_untreatable(char *input)
{
	if (ft_strstr(input, "<<<"))
		display_error("sintaxe", '<');
	else if (ft_strstr(input, ">>>"))
		display_error("sintaxe", '>');
	else if (ft_strstr(input, "||"))
		display_error("||", '|');
	else if (ft_strstr(input, "|||"))
		display_error("sintaxe", '|');
	else if (ft_strstr(input, "&&"))
		display_error("&&", '&');
	else
		return (1);
	return (0);
}
