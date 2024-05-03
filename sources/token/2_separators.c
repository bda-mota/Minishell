#include "../../includes/minishell.h"

void	handle_block(t_token **token_h, char *input, size_t *i)
{
	size_t	j;
	size_t	len;
	char	*token;

	j = 0;
	len = 0;
	while (input[*i] && input[*i] != ')')
	{
		(*i)++;
		len++;
	}
	token = ft_calloc(sizeof(char), len + 2);
	if (!token)
		return ;
	(*i) -= len;
	while (input[*i] && j <= len)
		token[j++] = input[(*i)++];
	(*i)--;
	insert_token(token_h, token, BLOCK);
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
	(*i) -= len;
	while (input[*i] && j < len)
		token[j++] = input[(*i)++];
	(*i)--;
	insert_token(token_h, token, WORD);
}

void	handle_double_quote(t_token **token_h, char *input, size_t *i, size_t size)
{
	size_t	j;
	char	*token;

	j = 0;
	token = ft_calloc(sizeof(char), (size + 1));
	if (!token)
		return ;
	while (input[*i] && j < size)
		token[j++] = input[(*i)++];
	(*i)--;
	insert_token(token_h, token, DOUBLE);
}

void	handle_simple_quote(t_token **token_h, char *input, size_t *i, size_t size)
{
	size_t	j;
	char	*token;

	j = 0;
	token = ft_calloc(sizeof(char), (size + 1));
	if (!token)
		return ;
	while (input[*i] && j < size)
		token[j++] = input[(*i)++];
	(*i)--;
	insert_token(token_h, token, DOUBLE);
}
