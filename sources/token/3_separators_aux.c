#include "../../includes/minishell.h"

int	check_blocks(char *input, t_token **token_tail, t_token **token_h)
{
	int	i;
	int	block;

	i = 0;
	block = 0;
	while (input[i])
	{
		if (block == 0 && input[i] == '(')
			block++;
		if (block == 0 && input[i] == ')')
		{
			block -= 1;
			break ;
		}
		if (block == 1 && input[i] == ')')
			block--;
		i++;
	}
	if (block >= 0 && block % 2 == 0)
		return (1);
	deallocate_lst(token_tail, token_h);
	display_error("sintaxe", '(');
	return (0);
}

int	check_double_quotes(char *input, t_token **token_tail, t_token **token_h)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (input[i])
	{
		if (input[i] == '"')
			quotes++;
		i++;
	}
	if (quotes % 2 == 0)
		return (1);
	deallocate_lst(token_tail, token_h);
	display_error("sintaxe", '"');
	return (0);
}

int	check_simple_quotes(char *input, t_token **token_tail, t_token **token_h)
{
	int	i;
	int	quotes;

	i = 0;
	quotes = 0;
	while (input[i])
	{
		if (input[i++] == '"')
		{
			while (input[i] && input[i] != '"')
				i++;
		}
		if (input[i] == '\'')
			quotes++;
		i++;
	}
	if (quotes % 2 == 0)
		return (1);
	deallocate_lst(token_tail, token_h);
	display_error("sintaxe", '\'');
	return (0);
}

int	count_double_quote(char *input, size_t *i)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = *i;
	if (input[k] && input[k] == 34)
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
	if (input[k] && input[k] == 39)
	{
		k++;
		j++;
		while (input[k] && input[k] != 39)
		{
			j++;
			k++;
		}
		if (input[k] == 39)
			j++;
	}
	return (j);
}

