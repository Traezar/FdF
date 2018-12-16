/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 00:04:31 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/19 22:20:42 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;

	i = -1;
	p1 = (unsigned char *)dst;
	p2 = (unsigned char *)src;
	while (++i < n && p2[i] != (unsigned char)c)
		p1[i] = (unsigned char)p2[i];
	if (i < n)
	{
		p1[i] = (unsigned char)p2[i];
		return ((void *)(dst + i + 1));
	}
	else
		return (NULL);
}
