/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:28:44 by bda-mota          #+#    #+#             */
/*   Updated: 2024/05/06 14:47:38 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find == NULL)
		return (0);
	while (str[i])
	{
		j = 0;
		while (to_find[j] && str[i + j] && to_find[j] == str[i + j])
			j++;
		if (to_find[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}
