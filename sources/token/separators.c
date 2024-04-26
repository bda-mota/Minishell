#include "../../includes/minishell.h"

static int	check_quote(int quote)
{
	if (quote != 2)
	{
		printf("Syntax error\n");
		return (0);
	}
	return (1);
}

int	ft_handle_quote(char *input, size_t i)
{
	size_t	j;
	int		quote;

	j = 0;
	quote = 0;
	if (input[i] && input[i] == 34)
	{
		quote++;
		i++;
		while (input[i] && input[i] != '"')
		{
			j++;
			i++;
		}
		if (input[i] == '"')
			quote++;
		if (check_quote(quote) == 0)
			return (0);
	}
	return (j);
}

void	handle_word(t_token **token_h, char *input, size_t *i, size_t size)
{
	int		j;
	char	*token;

	j = 0;
	token = ft_strdup("");
	(void)size;
	while (input[*i] && (catalog_inputs(input[*i]) == WORD
			|| catalog_inputs(input[*i]) == SSPACE))
	{
		token[j] = input[*i];
		(*i)++;
		j++;
	}
	(*i)--;
	token[j] = '\0';
	insert_token(token_h, token);
}

void	handle_inputs(t_token **token_h, char *input, size_t *i)
{
	int		j;
	char	*token;

	j = 0;
	token = ft_strdup("");
	if (input[*i] && catalog_inputs(input[*i]) == PIPE)
	{
		token[j] = input[*i];
		(*i)++;
		j++;
	}
	if (input[*i] && (catalog_inputs(input[*i]) == INPUT
			|| catalog_inputs(input[*i]) == OUTPUT))
	{
		token[j] = input[*i];
		(*i)++;
		j++;
	}
	(*i)--;
	token[j] = '\0';
	insert_token(token_h, token);
}
