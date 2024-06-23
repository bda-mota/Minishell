/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-mota <bda-mota@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:49:53 by bda-mota          #+#    #+#             */
/*   Updated: 2024/06/21 19:39:15 by bda-mota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int check_spaces(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ')
            return (1);
        i++;
    }
    return (0);
}