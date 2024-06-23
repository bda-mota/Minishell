/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:49:59 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:50:00 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_shell(t_minishell *shell)
{
	shell->complete_path = NULL;
	shell->paths = NULL;
	shell->env_copy = NULL;
	shell->status = 0;
	shell->cmd_args = NULL;
	get_status(0);
}

void	init_structs(t_minishell *shell)
{
	shell->token = NULL;
	shell->tree = NULL;
}
