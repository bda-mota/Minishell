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
