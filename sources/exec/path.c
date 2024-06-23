/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:46:37 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:46:39 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	find_path(t_minishell *shell)
{
	int		i;
	char	**env;

	i = 0;
	env = *get_env_copy(NULL);
	shell->complete_path = NULL;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			shell->complete_path = get_path(env[i] + 5);
			break ;
		}
		i++;
	}
	if (shell->complete_path == NULL)
		return ;
	build_path(shell);
}

void	build_path(t_minishell *shell)
{
	int		i;
	char	*aux;

	i = 0;
	shell->paths = ft_split(shell->complete_path, ':');
	if (shell->paths == NULL)
		printf("error ao dar split\n");
	while (shell->paths[i])
	{
		aux = ft_strdup(shell->paths[i]);
		if (aux == NULL)
			break ;
		free(shell->paths[i]);
		shell->paths[i] = ft_strjoin(aux, "/");
		free(aux);
		i++;
	}
}