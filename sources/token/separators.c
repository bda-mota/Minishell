#include "../../includes/minishell.h"

static void	check_quote(int quote)
{
	if (quote != 2)
		printf("Syntax error\n");
}

int	ft_handle_quote(char *input, size_t *i)
{
	size_t	j;
	int		quote;

	j = 0;
	quote = 0;
	if (input[*i] && input[*i] == 34)
	{
		quote++;
		(*i)++;
		while (input[*i] && input[*i] != '"')
		{
			j++;
			(*i)++;
		}
		if (input[*i] == '"')
			quote++;
		check_quote(quote);
	}
	return (j);
}

char	*handle_word(t_token **token_h, char *input, size_t *i)
{
	int		j;
	char	*token;

	j = 0;
	while (input[*i] == WORD)
	{
		token[j] = input[*i];
		*i++;
		j++;
	}
	insert_token(token_h, token);
}
