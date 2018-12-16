/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 15:14:59 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/08 19:49:13 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_count_char(char c, char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i] != '\0')
	{
		if (str[i] == c)
			count++;
	}
	return (count);
}
