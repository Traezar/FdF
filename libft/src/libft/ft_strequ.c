/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 09:28:57 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/20 16:34:29 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int		i;

	if (!s1 || !s2)
		return (0);
	i = ft_strcmp(s1, s2);
	if (i == 0)
		return (1);
	return (0);
}
