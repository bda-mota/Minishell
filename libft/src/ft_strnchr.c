/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:50:32 by bda-mota          #+#    #+#             */
/*   Updated: 2024/04/29 14:56:38 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnchr(char *str, char c, int len)
{
	int	i;

	i = 0;
	while (*str && i < len)
	{
		if (*str == c)
			return (1);
		str++;
		i++;
	}
	return (0);
}
