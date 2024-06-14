#include "../../includes/minishell.h"

int	check_quotes(char *input)
{
	int	i;
	int	d_quotes;
	int	s_quotes;

	i = 0;
	d_quotes = 0;
	s_quotes = 0;
	while (input[i])
	{
		if (input[i] == '"')
			d_quotes = check_quotes_aux(input, &i, '"');
		if (input[i] == '\'')
			s_quotes = check_quotes_aux(input, &i, '\'');
		if (input[i])
			i++;
	}
	if (d_quotes % 2 != 0)
		display_error_tokens("sintaxe", '"');
	else if (s_quotes % 2 != 0)
		display_error_tokens("sintaxe", '\'');
	else
		return (1);
	return (0);
}

int	check_quotes_aux(char *input, int *i, char c)
{
	int	quote;

	quote = 1;
	(*i)++;
	if (c == '"')
	{
		while (input[*i] && input[*i] != '"')
			(*i)++;
		if (input[*i] == '"')
				quote++;
	}
	else if (c == '\'')
	{
		while (input[*i] && input[*i] != '\'')
			(*i)++;
		if (input[*i] == '\'')
				quote++;
	}
	return (quote);
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
