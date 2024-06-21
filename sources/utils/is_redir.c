/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:50:03 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:50:05 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_redir(t_token **token)
{
	if ((*token)->type == INPUT || (*token)->type == OUTPUT
		|| (*token)->type == APPEND)
		return (1);
	return (0);
}

int	is_redir_or_heredoc(t_token **token)
{
	if ((*token)->type == INPUT || (*token)->type == OUTPUT
		|| (*token)->type == APPEND || (*token)->type == HEREDOC)
		return (1);
	return (0);
}

int	the_branch_is_redir(t_tree *branch)
{
	if (branch->type == INPUT || branch->type == OUTPUT
		|| branch->type == APPEND || branch->type == HEREDOC)
		return (1);
	return (0);
}
