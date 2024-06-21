/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:46:27 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:46:28 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	close_all(void)
{
	int	i;

	i = 0;
	while (i < 1024)
		close(i++);
}

void	fork_error(void)
{
	ft_printf_fd(STDERR_FILENO, "Error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

void	close_tubes(int *tube)
{
	close(tube[0]);
	close(tube[1]);
}

int	open_tubes(int *tube)
{
	if (pipe(tube) == -1)
	{
		printf("Erro ao abrir o tubo\n");
		return (0);
	}
	return (1);
}
