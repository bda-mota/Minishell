/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:43:25 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:43:27 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "../libft/src/libft.h"
# include "structs.h"

/* ==== HEREDOC ==== */
int		open_heredoc(char *file);
int		has_heredoc(t_token *token);
void	heredoc(t_token **token);
void	remove_quotes_from_delim(char *delimiter);
void	write_on_heredoc(char *line, int fd_heredoc);
void	update_heredoc(t_token **heredoc, char *file);
void	finish_heredoc(t_token **heredoc, int *fd, char *line, char *file);
char	*generate_file_name(void);
char	*expand_heredoc(char *line, int *pos);
t_token	*find_heredoc(t_token **heredoc);

#endif
