/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:49:35 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:49:37 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**copy_environ(void)
{
	char	**env;
	char	**environ_copy;
	int		i;

	env = __environ;
	environ_copy = count_size_environ();
	i = 0;
	while (env[i])
	{
		environ_copy[i] = ft_strdup(env[i]);
		if (!environ_copy[i])
		{
			while (i--)
				free(environ_copy[i]);
			free(environ_copy);
			return (NULL);
		}
		i++;
	}
	return (*get_env_copy(environ_copy));
}

char	**count_size_environ(void)
{
	char	**env;
	char	**environ_size;
	int		num_vars;

	env = __environ;
	environ_size = NULL;
	num_vars = 0;
	while (env[num_vars])
		num_vars++;
	environ_size = ft_calloc(num_vars + 1, sizeof(char *));
	if (!environ_size)
		return (NULL);
	return (environ_size);
}
