#include "../../includes/minishell.h"

void	handle_pipe(t_token **token, char *input, size_t *i)
{
	size_t	j;
	char	*content;

	j = 0;
	content = ft_calloc(sizeof(char), 2);
	if (!content)
		return ;
	if (input[*i] && catalog_inputs(input, i) == PIPE)
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, PIPE));
}

void	handle_input(t_token **token, char *input, size_t *i)
{
	size_t		j;
	char		*content;

	j = 0;
	content = ft_calloc(sizeof(char), 2);
	if (!content)
		return ;
	if (input[*i] && (catalog_inputs(input, i) == INPUT))
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, INPUT));
}

void	handle_output(t_token **token, char *input, size_t *i)
{
	size_t		j;
	char		*content;

	j = 0;
	content = ft_calloc(sizeof(char), 2);
	if (!content)
		return ;
	if (input[*i] && (catalog_inputs(input, i) == OUTPUT))
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, OUTPUT));
}

void	handle_append(t_token **token, char *input, size_t *i)
{
	size_t	j;
	char	*content;

	j = 0;
	content = ft_calloc(sizeof(char), 3);
	if (!content)
		return ;
	while (input[*i] && j < 2)
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, APPEND));
}

void	handle_heredoc(t_token **token, char *input, size_t *i)
{
	size_t	j;
	char	*content;

	j = 0;
	content = ft_calloc(sizeof(char), 3);
	if (!content)
		return ;
	while (input[*i] && j < 2)
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, HEREDOC));
}
