#include "../../includes/minishell.h"

static void	handle_word_aux(char *input, size_t *i, size_t *len);
static void	quote_aux(char *input, size_t *i, size_t *len);
static void	ignore_quotes(char *input, size_t *i);

void	handle_word(t_token **token, char *input, size_t *i)
{
	size_t	len;
	size_t	j;
	char	*content;

	j = 0;
	len = 0;
	handle_word_aux(input, i, &len);
	content = ft_calloc(sizeof(char), len + 1);
	if (!content)
		return ;
	(*i) -= len;
	while (input[*i] && j < len)
	{
		ignore_quotes(input, i);
		content[j++] = input[(*i)++];
	}
	(*i)--;
	insert_token(token, create_token(content, WORD));
}

static void	handle_word_aux(char *input, size_t *i, size_t *len)
{
	while (input[*i] && (catalog_inputs(input, i) == WORD
			|| catalog_inputs(input, i) == DOUBLE
			|| catalog_inputs(input, i) == SIMPLE))
	{
		quote_aux(input, i, len);
		if (input[*i])
		{
			(*i)++;
			(*len)++;
		}
	}
}

static void	ignore_quotes(char *input, size_t *i)
{
	if (input[*i] == '"' && input[*i + 1] == '"')
		(*i) += 2;
	else if (input[*i] == '\'' && input[*i + 1] == '\'')
		(*i) += 2;
}

static void	quote_aux(char *input, size_t *i, size_t *len)
{
	if (input[*i] == '"')
	{
		(*i)++;
		(*len)++;
		while (input[*i] && input[*i] != '"')
		{
			(*i)++;
			(*len)++;
		}
	}
	else if (input[*i] && input[*i] == '\'')
	{
		(*i)++;
		(*len)++;
		while (input[*i] && input[*i] != '\'')
		{
			(*i)++;
			(*len)++;
		}
	}
}
