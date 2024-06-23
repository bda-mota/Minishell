/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_metha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:48:36 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:48:37 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
