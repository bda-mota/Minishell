/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:17:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/02 11:38:36 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_list(t_token **lst)
{
	t_token	*current;

	current = *lst;
	while (current)
	{
		printf("- - - - - - - - - - - - - - \n");
		printf("token: %s\n", current->content);
		printf("type: %d\n", current->type);
	//	printf("type: %d\n", current->type);
		current = current->next;
	}
}
