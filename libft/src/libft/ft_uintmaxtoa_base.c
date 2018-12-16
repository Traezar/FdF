/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintmaxtoa_base.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:10:57 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/15 00:01:29 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int		conv_ex(uintmax_t nb, int is_cap)
{
	char c;

	c = 0;
	if (is_cap == 1)
		c = 'A';
	else
		c = 'a';
	if (nb >= 10)
		return (nb - 10 + c);
	else
		return (nb + '0');
}

char			*ft_uintmaxtoa_base(uintmax_t num, unsigned int base,
								int is_cap)
{
	int			i;
	char		*str;
	uintmax_t	tmp;

	i = 0;
	tmp = num;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = ft_strnew(++i)))
		return (NULL);
	str[i--] = '\0';
	while (i >= 0)
	{
		tmp = num % base;
		str[i--] = conv_ex(tmp, is_cap);
		num /= base;
	}
	return (str);
}
