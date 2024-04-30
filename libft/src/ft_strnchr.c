/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:50:32 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/30 15:41:10 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnchr(char *str, char c, int len)
{
	if (len == 1)
	{
		if (*str == c)
			return (1);
	}
	else if (len == 2)
	{
		if (*str == c && *(str + 1) == c)
			return (1);
	}
	return (0);
}
