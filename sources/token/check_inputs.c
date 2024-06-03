#include "../../includes/minishell.h"

int	check_blocks_aux(char *input)
{
	int	i;
	int	block;

	i = 0;
	block = 0;
	while (input[i])
	{
		if (input[i] == '(')
			block++;
		if (block == 0 && input[i] == ')')
			return (-1);
		if (block != 0 && input[i] == ')')
			block--;
		i++;
	}
	return (block);
}

int	check_blocks(char *input)
{
	int	i;
	int	block;

	i = 0;
	block = 0;
	while (input[i])
	{
		if (input[i] == '(')
		{
			block = check_blocks_aux(&input[i]);
			break ;
		}
		else if (input[i] == ')')
		{
			block -= 1;
			break ;
		}
		i++;
	}
	if (block == 0 && block % 2 == 0)
		return (1);
	display_error_tokens("sintaxe", '(');
	return (0);
}

int	check_sintax(char *input)
{
	if (!check_untreatable(input))
		return (1);
	else if (!check_blocks(input))
		return (1);
	else if (!check_quotes(input))
		return (1);
	return (0);
}

int	check_untreatable(char *input)
{
	if (ft_strstr(input, "<<<"))
		display_error_tokens("sintaxe", '<');
	else if (ft_strstr(input, ">>>"))
		display_error_tokens("sintaxe", '>');
	else if (ft_strstr(input, "||"))
		display_error_tokens("||", '|');
	else if (ft_strstr(input, "|||"))
		display_error_tokens("sintaxe", '|');
	else if (ft_strstr(input, "&&"))
		display_error_tokens("&&", '&');
	else
		return (1);
	return (0);
}
