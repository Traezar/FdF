/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 05:15:38 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/19 22:24:12 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int					i;
	unsigned char		*p1;
	unsigned char		*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (*s1 == ' ' && *s2 == ' ')
		return (p1[i] - p2[i]);
	while (p1[i] != '\0' && p1[i] == p2[i])
		i++;
	i = p1[i] - p2[i];
	return (i);
}
