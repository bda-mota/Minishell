#include "../../includes/minishell.h"

void	handle_block(t_token **token, char *input, size_t *i)
{
	size_t	j;
	size_t	len;
	char	*content;

	j = 0;
	len = 0;
	while (input[*i] && input[*i] != ')')
	{
		(*i)++;
		len++;
	}
	content = ft_calloc(sizeof(char), len + 2);
	if (!content)
		return ;
	(*i) -= len;
	while (input[*i] && j <= len)
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, BLOCK));
}

void	handle_word(t_token **token, char *input, size_t *i)
{
	size_t	len;
	size_t	j;
	char	*content;

	j = 0;
	len = 0;
	while (input[*i] && catalog_inputs(input, i) == WORD)
	{
		(*i)++;
		len++;
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

void	handle_double_quote(t_token **token, char *input, size_t *i, size_t size)
{
	size_t	j;
	char	*content;

	j = 0;
	content = ft_calloc(sizeof(char), (size + 1));
	if (!content)
		return ;
	while (input[*i] && j < size)
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, DOUBLE));
}

void	handle_simple_quote(t_token **token, char *input, size_t *i, size_t size)
{
	size_t	j;
	char	*content;

	j = 0;
	content = ft_calloc(sizeof(char), (size + 1));
	if (!content)
		return ;
	while (input[*i] && j < size)
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, SIMPLE));
}
