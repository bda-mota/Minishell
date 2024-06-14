#include "../../includes/minishell.h"

void	handle_word(t_token **token, char *input, size_t *i)
{
	size_t	len;
	size_t	j;
	char	*content;

	j = 0;
	len = 0;
	while (input[*i] && (catalog_inputs(input, i) == WORD
		|| catalog_inputs(input, i) == DOUBLE || catalog_inputs(input, i) == SIMPLE))
	{
		if (input[*i] == '"')
		{
			(*i)++;
			len++;
			while (input[*i] && input[*i] != '"')
			{
				(*i)++;
				len++;
			}
		}
		else if (input[*i] && input[*i] == '\'')
		{
			(*i)++;
			len++;
			while (input[*i] && input[*i] != '\'')
			{
				(*i)++;
				len++;
			}
		}
		if (input[*i])
		{
			(*i)++;
			len++;
		}
	}
	content = ft_calloc(sizeof(char), len + 1);
	if (!content)
		return ;
	(*i) -= len;
	while (input[*i] && j < len)
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, WORD));
}

void	handle_one(t_token **token, char *input, size_t *i)
{
	size_t	j;
	int		type;
	char	*content;

	j = 0;
	content = ft_calloc(sizeof(char), 2);
	if (!content)
		return ;
	type = catalog_inputs(input, i);
	if (input[*i] && j < 1)
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, type));
}

void	handle_two(t_token **token, char *input, size_t *i)
{
	size_t	j;
	int		type;
	char	*content;

	j = 0;
	content = ft_calloc(sizeof(char), 3);
	if (!content)
		return ;
	type = catalog_inputs(input, i);
	while (input[*i] && j < 2)
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, type));
}