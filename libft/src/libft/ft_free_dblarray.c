/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dblarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 12:05:16 by rsathiad          #+#    #+#             */
/*   Updated: 2018/11/08 19:49:49 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_free_dblarray(char **array)
{
	int		i;
	char	**list;

	i = 0;
	if (!array)
		return ;
	list = array;
	while (list[i] != NULL)
	{
		free(list[i]);
		list[i] = NULL;
		i++;
	}
	free(list);
	return ;
}
