/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:43:06 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 14:43:08 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AST_H
# define AST_H

# include "../libft/src/libft.h"
# include "structs.h"

/* ==== BUILD TREE ==== */
void	build_tree(t_tree **root, t_token **tokens);
t_tree	*create_branch(t_token **token_list, int type);

/* ==== TREE UTILS ==== */
void	down_tree(t_tree **root);
void	aux_pull_all_together(t_token **new, t_token **curr);
t_token	*put_all_together(t_token **tokens);


/* ==== SEARCH BRANCH ==== */
t_token	**search_branchs(t_token **tokens);
t_token	*search_pipe(t_token **tokens);
t_token	*search_redirs(t_token **tokens);
t_token	*new_redir_list(t_token **token_list);
t_token	*define_ptrs(t_token *meta, t_token **curr, int type);

#endif
