/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 20:37:56 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/23 20:49:34 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	check_spaces_on_exit(char *args)
{
	int	i;
	int	sign;

	i = 0;
	sign = 0;
	if (args[i] == '-')
		sign = 1;
	while (args[i] && i < 19 + sign)
	{
		if (ft_isspace(args[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
