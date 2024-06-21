/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_token.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:48:47 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:48:49 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_token	*create_token(char *content, int type)
{
	t_token	*new_node;

	new_node = malloc(sizeof(t_token));
	if (!new_node)
		return (NULL);
	new_node->content = ft_strdup(content);
	new_node->type = type;
	new_node->next = NULL;
	new_node->prev = NULL;
	free(content);
	return (new_node);
}

void	insert_token(t_token **token, t_token *new_node)
{
	t_token	*curr;

	if (*token == NULL)
		*token = new_node;
	else
	{
		curr = *token;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_node;
		new_node->prev = curr;
	}
}

void	deallocate_lst(t_token **token)
{
	t_token	*curr;
	t_token	*temp;

	if (*token == NULL)
		return ;
	curr = *token;
	while (curr != NULL)
	{
		temp = curr->next;
		free(curr->content);
		free(curr);
		curr = temp;
	}
	*token = NULL;
}

t_token	*get_last_node(t_token **list)
{
	t_token	*last_node;

	last_node = *list;
	if (*list == NULL)
		return (NULL);
	while (last_node->next != NULL)
		last_node = last_node->next;
	return (last_node);
}

t_token	*get_first_node(t_token **list)
{
	t_token	*first_node;

	first_node = *list;
	if (*list == NULL)
		return (NULL);
	while (first_node->prev != NULL)
		first_node = first_node->prev;
	return (first_node);
}
