/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:17:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/05/03 13:35:40 by bda-mota         ###   ########.fr       */
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
		printf("type: %s\n", current->type);
		printf("- - - - - - - - - - - - - - \n");
		current = current->next;
	}
}

// static char *find_type(int type)
// {

// }
