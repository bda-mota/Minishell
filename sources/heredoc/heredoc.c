/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:48:00 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 19:26:18 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	heredoc(t_token **token)
{
	t_token	*heredoc;
	char	*file;
	int		fd_heredoc;
	int		std;

	get_status(0);
	heredoc = *token;
	std = dup(STDIN_FILENO);
	heredoc = find_heredoc(&heredoc);
	while (heredoc)
	{
		signal_heredoc();
		file = generate_file_name();
		fd_heredoc = open_heredoc(file);
		remove_quotes_from_delim(heredoc->next->content);
		heredoc_on_file(&heredoc, &fd_heredoc);
		if (if_sigint_heredoc(&std, file, get_status(-1)) == 1)
			return (1);
		close(fd_heredoc);
		update_heredoc(&heredoc, file);
		heredoc = find_heredoc(&heredoc->next);
	}
	return (0);
}

void	heredoc_on_file(t_token **token, int *fd_heredoc)
{
	char	*line;

	line = NULL;
	while (1 && *fd_heredoc != -1 && get_status(-1) != 130)
	{
		line = readline("> ");
		if (!line || ft_strncmp(line, (*token)->next->content,
				ft_strlen((*token)->next->content) - 1) == 0)
			break ;
		if (get_status(-1) == 130)
			break ;
		write_on_heredoc(line, *fd_heredoc);
	}
	free(line);
}

void	remove_quotes_from_delim(char *delimiter)
{
	int		i;
	char	quote;

	i = 0;
	while (delimiter[i] != 0)
	{
		if (delimiter[i] == '\'' || delimiter[i] == '"')
		{
			quote = delimiter[i];
			ft_memmove(&delimiter[i], &delimiter[i + 1],
				ft_strlen(&delimiter[i]));
			while (delimiter [i] != quote)
				i++;
			ft_memmove(&delimiter[i], &delimiter[i + 1],
				ft_strlen(&delimiter[i]));
		}
		else
			i++;
	}
}

int	open_heredoc(char *file)
{
	int	fd;

	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd < 0)
	{
		ft_printf_fd(STDERR_FILENO, "Babyshell: %s\n", strerror(errno));
		return (-1);
	}
	return (fd);
}

void	write_on_heredoc(char *line, int fd_heredoc)
{
	int		i;
	char	*variable;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$' && line[i + 1] != '\0')
		{
			i++;
			variable = expand_heredoc(line, &i);
			if (variable != NULL)
				write(fd_heredoc, variable, ft_strlen(variable));
		}
		else
		{
			if (line[i])
				write(fd_heredoc, &line[i], 1);
			i++;
		}
	}
	write(fd_heredoc, "\n", 1);
	free(line);
}
