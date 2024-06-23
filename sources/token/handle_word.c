/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:48:41 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:48:42 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	handle_word_aux(char *input, size_t *i, size_t *len);
static void	quote_aux(char *input, size_t *i, size_t *len);

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
		content[j++] = input[(*i)++];
	(*i)--;
	insert_token(token, create_token(content, WORD));
}

static void	handle_word_aux(char *input, size_t *i, size_t *len)
{
	while (input[*i] && (catalog_inputs(input, i) == WORD
			|| catalog_inputs(input, i) == DOUBLE
			|| catalog_inputs(input, i) == SIMPLE
			|| catalog_inputs(input, i) == OR))
	{
		quote_aux(input, i, len);
		if (catalog_inputs(input, i) == OR && input[*i + 1] == '|')
		{
			(*i)++;
			(*len)++;
		}
		if (input[*i])
		{
			(*i)++;
			(*len)++;
		}
	}
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
