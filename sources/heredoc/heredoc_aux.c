/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:47:50 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 19:39:43 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	has_heredoc(t_token *token)
{
	t_token	*curr;

	curr = token;
	while (curr)
	{
		if (curr->type == HEREDOC)
			return (0);
		curr = curr->next;
	}
	return (1);
}

t_token	*find_heredoc(t_token **heredoc)
{
	t_token	*curr;

	curr = *heredoc;
	while (curr)
	{
		if (curr->type == HEREDOC)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void	update_heredoc(t_token **heredoc, char *file)
{
	t_token	*delimiter;

	delimiter = (*heredoc)->next;
	free(delimiter->content);
	delimiter->content = file;
}

int	if_sigint_heredoc(int *std, char *file, int status)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	if (status == 130)
	{
		dup2(*std, STDIN_FILENO);
		free(file);
		close(*std);
		deallocate_lst(&shell->token);
		return (1);
	}
	return (0);
}

char	*generate_file_name(void)
{
	char		*dir_name;
	char		*nbr;
	char		*file_name;
	static int	i;

	dir_name = "/tmp/heredoc";
	nbr = ft_itoa(i);
	file_name = ft_strjoin(dir_name, nbr);
	free(nbr);
	i++;
	return (file_name);
}
