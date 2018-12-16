/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/10 23:46:11 by rsathiad          #+#    #+#             */
/*   Updated: 2018/07/16 13:35:18 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char	*p1;

	p1 = (char *)malloc(size + 1);
	if (!p1)
		return (NULL);
	ft_memset(p1, '\0', size + 1);
	return (p1);
}
