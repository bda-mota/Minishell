/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:43:25 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 19:26:03 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "../libft/src/libft.h"
# include "structs.h"

/* ==== HEREDOC ==== */
int		open_heredoc(char *file);
int		has_heredoc(t_token *token);
int		heredoc(t_token **token);
int		if_sigint_heredoc(int *std, char *file, int fd, int status);
void	heredoc_on_file(t_token **token, int *fd_heredoc);
void	remove_quotes_from_delim(char *delimiter);
void	write_on_heredoc(char *line, int fd_heredoc);
void	update_heredoc(t_token **heredoc, char *file);
char	*generate_file_name(void);
char	*expand_heredoc(char *line, int *pos);
t_token	*find_heredoc(t_token **heredoc);

#endif
