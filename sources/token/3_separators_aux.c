#include "../../includes/minishell.h"

int	check_blocks(char *input, t_token **token_tail, t_token **token_h)
{
	int	i;
	int	block;

	i = 0;
	block = 0;
	while (input[i])
	{
		if (input[i] == '(')
			block++;
		if (input[i] == ')')
			block--;
		i++;
	}
	if (block % 2 == 0)
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
		if (input[i] == '"') //para lidar com as aspas simples dentro das aspas duplas -> devem ser ignoradas
			while (input[i] && input[i++] != '"')
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

int	count_quote(char *input, size_t *i)
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

int	check_sintax(char *input, t_token **token_tail, t_token **token_h)
{
	if (!check_blocks(input, token_tail, token_h))
		return (1);
	if (!check_double_quotes(input, token_tail, token_h))
		return (1);
	return (0);
}
