#include "../../includes/minishell.h"

void	handle_pipe(t_token **token_h, char *input, size_t *i)
{
	size_t	j;
	char	*token;


	j = 0;
	token = ft_calloc(sizeof(char), 2);
	if (!token)
		return ;
	if (input[*i] && catalog_inputs(input, i) == PIPE)
		token[j++] = input[(*i)++];
	(*i)--;
	insert_token(token_h, token, PIPE);
}

void	handle_input(t_token **token_h, char *input, size_t *i)
{
	size_t		j;
	char		*token;

	j = 0;
	token = ft_calloc(sizeof(char), 2);
	if (!token)
		return ;
	if (input[*i] && (catalog_inputs(input, i) == INPUT))
		token[j++] = input[(*i)++];
	(*i)--;
	insert_token(token_h, token, INPUT);
}

void	handle_output(t_token **token_h, char *input, size_t *i)
{
	size_t		j;
	char		*token;

	j = 0;
	token = ft_calloc(sizeof(char), 2);
	if (!token)
		return ;
	if (input[*i] && (catalog_inputs(input, i) == OUTPUT))
		token[j++] = input[(*i)++];
	(*i)--;
	insert_token(token_h, token, OUTPUT);
}

void	handle_append(t_token **token_h, char *input, size_t *i)
{
	size_t	j;
	char	*token;

	j = 0;
	token = ft_calloc(sizeof(char), 3);
	if (!token)
		return ;
	while (input[*i] && j < 2)
		token[j++] = input[(*i)++];
	(*i)--;
	insert_token(token_h, token, APPEND);
}

void	handle_heredoc(t_token **token_h, char *input, size_t *i)
{
	size_t	j;
	char	*token;

	j = 0;
	token = ft_calloc(sizeof(char), 3);
	if (!token)
		return ;
	while (input[*i] && j < 2)
		token[j++] = input[(*i)++];
	(*i)--;
	insert_token(token_h, token, HEREDOC);
}