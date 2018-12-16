/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 23:48:51 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/18 12:22:19 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*ptr1;
	char	*ptr2;

	ptr1 = dst;
	ptr2 = (char *)src;
	i = 0;
	while (i < n)
	{
		*(ptr1 + i) = *(ptr2 + i);
		i++;
	}
	return (dst);
}
