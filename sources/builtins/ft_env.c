/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:45:45 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:45:47 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_env(char **env_copy)
{
	int	i;

	i = 0;
	while (env_copy[i])
	{
		if (ft_strchr(env_copy[i], '='))
			ft_printf_fd(STDOUT_FILENO, "%s\n", env_copy[i]);
		i++;
	}
	get_status(0);
}
