/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:17:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/25 19:37:26 by bda-mota         ###   ########.fr       */
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
	//	printf("type: %d\n", current->type);
		current = current->next;
	}
}
