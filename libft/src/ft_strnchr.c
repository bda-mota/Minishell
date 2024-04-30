/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:50:32 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/30 14:55:22 by bda-mota         ###   ########.fr       */
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
		while (*str && *(str + 1))
		{
			if (*str == c && *(str + 1) == c)
				return (1);
			str++;
		}
	}
	return (0);
}
