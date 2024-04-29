#include "../../includes/minishell.h"

// static int	check_quote(int quote)
// {
// 	if (quote != 2)
// 	{
// 		printf("Syntax error\n");
// 		return (0);
// 	}
// 	return (1);
// }

int	ft_handle_quote(char *input, size_t *i)
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

void	handle_quote(t_token **token_h, char *input, size_t *i, size_t size)
{
	size_t	j;
	char	*token;

	j = 0;
	token = malloc(sizeof(char) * (size + 1));
	if (!token)
		return ;
	while (input[*i] && j < size)
	{
		token[j] = input[*i];
		(*i)++;
		j++;
	}
	(*i)--;
	token[j] = '\0';
	insert_token(token_h, token);
}

void	handle_word(t_token **token_h, char *input, size_t *i)
{
	size_t	len;
	size_t	j;
	char	*token;

	j = 0;
	len = 0;
	while (input[*i] && catalog_inputs(input, i) == WORD)
	{
		(*i)++;
		len++;
	}
	token = ft_calloc(sizeof(char), len + 1);
	if (!token)
		return ;
	(*i) = (*i) - len;
	while (input[*i] && j <= len)
	{
		token[j] = input[*i];
		j++;
		(*i)++;
	}
	(*i)--;
	insert_token(token_h, token);
}

void	handle_inputs(t_token **token_h, char *input, size_t *i)
{
	int		j;
	char	*token;

	j = 0;
	token = ft_strdup("");
	if (input[*i] && catalog_inputs(input, i) == PIPE)
	{
		token[j] = input[*i];
		(*i)++;
		j++;
	}
	else if (input[*i] && (catalog_inputs(input, i) == INPUT
			|| catalog_inputs(input, i) == OUTPUT))
	{
		token[j] = input[*i];
		(*i)++;
		j++;
	}
	(*i)--;
	token[j] = '\0';
	insert_token(token_h, token);
}
