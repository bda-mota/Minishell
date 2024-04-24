/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:17:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/04/24 14:32:27 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_list(t_token **lst)
{
	while (*lst)
	{
		printf("token: %s\n", (*lst)->content);
		lst = (*lst)->next;
	}
}
