#include "../../includes/minishell.h"

int	validate_block(char *input)
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
			block = validate_block(&input[i]);
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
	display_error("sintaxe", '(');
	return (0);
}

int	check_double_quotes(char *input)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (input[i])
	{
		if (input[i] == '\'')
		{
			i++;
			//while (input[i] && input[i] != '"')
			//	i++;
		}
		if (input[i] == '"')
			quotes++;
		i++;
	}
	if (quotes % 2 == 0)
		return (1);
	display_error("sintaxe", '"');
	return (0);
}

int	check_simple_quotes(char *input)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (input[i])
	{
		if (input[i] == '"')
		{
			i++;
			// while (input[i] && input[i] != '"')
			// 	i++;
		}
		if (input[i] == '\'')
			quotes++;
		i++;
	}
	if (quotes % 2 == 0)
		return (1);
	display_error("sintaxe", '\'');
	return (0);
}

int	count_double_quote(char *input, size_t *i)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = *i;
	if (input[k] && input[k] == '"')
	{
		k++;
		j++;
		while (input[k] && input[k] != '"')
		{
			j++;
			k++;
		}
		if (input[k] == '"')
			j++;
	}
	return (j);
}

int	count_simple_quote(char *input, size_t *i)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = *i;
	if (input[k] && input[k] == '\'')
	{
		k++;
		j++;
		while (input[k] && input[k] != '\'')
		{
			j++;
			k++;
		}
		if (input[k] == '\'')
			j++;
	}
	return (j);
}

